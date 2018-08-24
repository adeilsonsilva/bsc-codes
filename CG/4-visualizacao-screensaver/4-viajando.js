/** Código desenvolvido na disciplina MATA65 - Computação Gráfica, 2017.1
 *  Aluno: Adeilson Antônio da Silva
 **/
var userParams = {
    rx: 1.0,
    ry: 1.0,
    rz: 1.0,
    r0: 0.5,
    r1: 0.5,
    n1: 1.0,
    n2: 1.0,
}

var camRadius = 8;
var cameraSpeed = 0.01;

var vertexNumber = 10;
var toroidSpeed = -0.05,
    ellipseSpeed = 0.05;

var scene 			= null;
var renderer		= null;
var mesh			= null;
var controls	    = null;
var guiChanged		= false;
var clock;
var params;
var mouseX = 0, mouseY = 0;
var windowWidth, windowHeight;

var guiParams = {
    white: true,
    pink: true,
    yellow: true,
    black: true,
};

var views = [
    {
        left: 0,
        top: 0.5,
        width: 0.5,
        height: 0.5,
        background: new THREE.Color().setRGB(255, 255, 255),
        eye: [ 0, 300, 1800 ],
        up: [ 0, 1, 0 ],
        fov: 30,
        show: true,
        updateCamera: function ( camera, time, obj ) {
            camera.position.x = camRadius * Math.cos(time) + obj.position.x;
            camera.position.y = camRadius * Math.sin(time) * Math.cos(Math.PI/6) + obj.position.y;
            camera.position.z = camRadius * Math.sin(time) * Math.sin(Math.PI/6) + obj.position.z;
            camera.lookAt( obj.position );
        }
    },
    {
        left: 0.5,
        top: 0.5,
        width: 0.5,
        height: 0.5,
        background: new THREE.Color().setRGB(255, 0, 255),
        eye: [ 0, 1800, 0 ],
        up: [ 0, 0, 1 ],
        fov: 45,
        show: true,
        updateCamera: function ( camera, boxArray ) {
            var M1 = new THREE.Matrix4();
            var M2 = new THREE.Matrix4();

            for (var i = 0; i < boxArray.length; i++) {
                if (boxArray[i].distanceToPoint(camera.position) <= 0) {
                    cameraSpeed = -cameraSpeed;
                    break;
                }
            }

            M1.makeRotationY(0.01);
            camera.applyMatrix(M1);
            camera.updateMatrix(M1);

            M1.makeTranslation(cameraSpeed, cameraSpeed, 0);
            camera.applyMatrix(M1);
            camera.updateMatrix(M1);
        }
    },
    {
        left: 0,
        top: 0,
        width: 0.5,
        height: 0.5,
        background: new THREE.Color().setRGB(255, 255, 0),
        eye: [ 0, 1800, 0 ],
        up: [ 0, 0, 1 ],
        fov: 45,
        show: true,
        updateCamera: function ( camera, obj ) {
            camera.position.x = obj.position.x - 1;
            camera.position.y = obj.position.y - 1;
            camera.position.z = obj.position.z - 1;
            camera.lookAt( obj.position );
        }
    },
    {
        left: 0.5,
        top: 0,
        width: 0.5,
        height: 0.5,
        background: new THREE.Color().setRGB(0, 0, 0),
        eye: [ 0, 1800, 0 ],
        up: [ 0, 0, 1 ],
        fov: 45,
        show: true,
        updateCamera: function ( camera, obj ) {
            camera.lookAt( obj.position );
        }
    },
];

function initGUI()
{
    var gui = new dat.GUI();

    gui.add( guiParams, 'white', true ).name("Controle Orbital").onChange( function (value) {
        views[0].show = value;
    });
    gui.add( guiParams, 'pink', true ).name("Controle de voo").onChange( function (value) {
        views[1].show = value;
    });
    gui.add( guiParams, 'yellow', true ).name("Movimentação").onChange( function (value) {
        views[2].show = value;
    });
    gui.add( guiParams, 'black', true ).name("LookAt").onChange( function (value) {
        views[3].show = value;
    });
}

function drawSuperEllipse(rx, ry, rz, n1, n2, color)
{
    var superEllipse = new THREE.Geometry();
    var index = 0;
    var grid = [];

    var deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = -Math.PI/2 ; phi <= Math.PI/2 ; phi += deltaPhi) {
        var verticesRow = [];
        for (beta = -Math.PI ; beta <= Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = rx * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), n2 );
            var y = ry * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 );
            var z = rz * Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), n1 );

            superEllipse.vertices.push(new THREE.Vector3( x,  y, z ));
            verticesRow.push( index ++ );
        }
        grid.push( verticesRow );
    }

    var countFaces=0;
    for (i = 0 ; i < grid.length - 1 ; i++) {
        for (j = 0 ; j < vertexNumber ; j++) {
            var a = grid[ i ][ j + 1 ];
			var b = grid[ i ][ j ];
			var c = grid[ i + 1 ][ j ];
			var d = grid[ i + 1 ][ j + 1 ];

            superEllipse.faces.push(new THREE.Face3( a, b, d ));
            superEllipse.faces[countFaces].vertexColors[0] = color;
            superEllipse.faces[countFaces].vertexColors[1] = color;
            superEllipse.faces[countFaces].vertexColors[2] = color;
            countFaces++;

            superEllipse.faces.push(new THREE.Face3( b, c, d ));
            superEllipse.faces[countFaces].vertexColors[0] = color;
            superEllipse.faces[countFaces].vertexColors[1] = color;
            superEllipse.faces[countFaces].vertexColors[2] = color;
            countFaces++;
        }
    }

    var ellipseMaterial = new THREE.MeshBasicMaterial({
        vertexColors: THREE.VertexColors,
        wireframe: true
    });

    var superEllipseMesh = new THREE.Mesh(superEllipse, ellipseMaterial);

    return superEllipseMesh;

}

function drawSuperToroid(r0, r1, n1, n2, color)
{
    var superToroid = new THREE.Geometry();

    var index = 0;
    var grid = [];

    var deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = 0 ; phi <= 2 * Math.PI ; phi += deltaPhi) {
        var verticesRow = [];
        for (beta = 0 ; beta <= 2 * Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * (r0 + r1 * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), n2 ));
            var y = Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), n1 ) * (r0 + r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 ));
            var z = r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 );

            superToroid.vertices.push(new THREE.Vector3( x,  y, z ));
            verticesRow.push( index ++ );
        }
        grid.push( verticesRow );
    }

    var countFaces=0;
    for (i = 0 ; i < vertexNumber ; i++) {
        for (j = 0 ; j < vertexNumber ; j++) {
            var a = grid[ i ][ j + 1 ];
			var b = grid[ i ][ j ];
			var c = grid[ i + 1 ][ j ];
			var d = grid[ i + 1 ][ j + 1 ];

            superToroid.faces.push(new THREE.Face3(a, b, c));
            superToroid.faces[countFaces].vertexColors[0] = color;
            superToroid.faces[countFaces].vertexColors[1] = color;
            superToroid.faces[countFaces].vertexColors[2] = color;
            countFaces++;

            superToroid.faces.push(new THREE.Face3(b, c, d));
            superToroid.faces[countFaces].vertexColors[0] = color;
            superToroid.faces[countFaces].vertexColors[1] = color;
            superToroid.faces[countFaces].vertexColors[2] = color;
            countFaces++;
        }
    }

    var toroidMaterial = new THREE.MeshBasicMaterial({
        vertexColors: THREE.VertexColors,
        wireframe: true
    });

    var superToroidMesh = new THREE.Mesh(superToroid, toroidMaterial);

    return superToroidMesh;
}

/**
 * Detects collision between two boxes
 * @param   THREE.Box3 box
 * @param   Array() of THREE.Box3
 * @returns bool
 */
function detectCollision(box, boxArray)
{
    for (var i = 0; i < boxArray.length; i++) {
        if (box.intersectsBox(boxArray[i])) {
            return true;
        }
    }

    return false;
}

/**
 * Detects collision between two boxes
 * @param   THREE.Box3 boxA
 * @param   THREE.Box3 boxB
 * @returns bool
 */
function detectCollisionBox(boxA, boxB)
{
    return boxA.intersectsBox(boxB);
}

function init() {

    clock = new THREE.Clock();

    scene = new THREE.Scene();

    renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));

    var viewport = document.getElementById("WebGL-output");
    viewport.appendChild(renderer.domElement);

    for (var i =  0; i < views.length; ++i ) {
        var view = views[i];
        var camera = new THREE.PerspectiveCamera( 110, window.innerWidth/window.innerHeight, 0.1, 10000 );
        view.camera = camera;
        view.box = new THREE.Box3().setFromObject(camera);
    }

    // Global Axis
    var globalAxis = new THREE.AxisHelper( 1.0 );
    // scene.add( globalAxis );

    var collidableMeshList = [];

    var groupBox = new THREE.Object3D();
    var outsideBoxGroup = new THREE.Object3D();

    var boxMat = new THREE.MeshBasicMaterial( {color: 0x0000ff, wireframe:true} );

    var upperBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );
    upperBoxGeo.translate(0, 10, 0);
    var upperBoxMesh = new THREE.Mesh(upperBoxGeo, boxMat);
    var upperBox = new THREE.Box3().setFromObject(upperBoxMesh);
    collidableMeshList.push(upperBox);

    var lowerBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );
    lowerBoxGeo.translate(0, -10, 0);
    var lowerBoxMesh = new THREE.Mesh(lowerBoxGeo, boxMat);
    var lowerBox = new THREE.Box3().setFromObject(lowerBoxMesh);
    collidableMeshList.push(lowerBox);

    var leftBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );
    leftBoxGeo.translate(-10, 0, 0);
    var leftBoxMesh = new THREE.Mesh(leftBoxGeo, boxMat);
    var leftBox = new THREE.Box3().setFromObject(leftBoxMesh);
    collidableMeshList.push(leftBox);

    var rightBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );
    rightBoxGeo.translate(10, 0, 0);
    var rightBoxMesh = new THREE.Mesh(rightBoxGeo, boxMat);
    var rightBox = new THREE.Box3().setFromObject(rightBoxMesh);
    collidableMeshList.push(rightBox);

    var box = new THREE.BoxGeometry( 10, 10, 10 );
    var boxMesh = new THREE.Mesh(box, boxMat);
    var cube = new THREE.BoxHelper( boxMesh, 0x0400ff );
    groupBox.add( cube );

    var box2 = new THREE.Box3();
    box2.setFromObject(boxMesh);
    views[1].camera.position.x = box2.max.x;
    views[1].camera.position.y = box2.max.y;
    views[1].camera.position.z = box2.max.z;
    views[1].camera.lookAt( groupBox.position );

    groupBox.position.set(0, 0, 0.0);
    scene.add( groupBox );

    var toroidGroup = new THREE.Object3D();
    toroidGroup.add( drawSuperToroid( 0.6, 0.05, 0.9, 0, new THREE.Color('red') ) );
    toroidGroup.add( drawSuperToroid( 0.9, 0.05, 5.6, 9.6, new THREE.Color('green') ) );
    toroidGroup.children[1].translateX(1);
    toroidGroup.add( drawSuperToroid( 0.66, 0.02, 2, 1.5, new THREE.Color('blue') ) );
    toroidGroup.children[2].translateX(2);

    var toroidBox = new THREE.Box3().setFromObject( toroidGroup );
    var toroidBoxHelper = new THREE.BoxHelper(toroidGroup);
    scene.add(toroidGroup);

    var ellipseGroup = new THREE.Object3D();
    ellipseGroup.add( drawSuperEllipse( 0.5, 0.5, 0.5, 1, 1, new THREE.Color('red') ) );
    ellipseGroup.add( drawSuperEllipse( 1, 1, 1, 5, 5, new THREE.Color('green') ) );
    ellipseGroup.children[1].translateX(1);
    ellipseGroup.add( drawSuperEllipse( 1, 1, 1, 1, 10, new THREE.Color('blue') ) );
    ellipseGroup.children[2].translateX(2);

    var ellipseBox = new THREE.Box3().setFromObject( ellipseGroup );
    var ellipseBoxHelper = new THREE.BoxHelper(ellipseGroup);
    scene.add(ellipseGroup);

    var time = 0;
    initGUI();
    animate();

    function render () {
        windowWidth  = window.innerWidth;
        windowHeight = window.innerHeight;

        renderer.setSize ( windowWidth, windowHeight  );
        var delta = clock.getDelta();

        time += 0.01;
        views[0].updateCamera( views[0].camera, time, groupBox );
        views[1].updateCamera( views[1].camera, collidableMeshList );
        views[2].updateCamera( views[2].camera, ellipseGroup );
        views[3].updateCamera( views[3].camera, toroidGroup );

        for ( var i = 0; i < views.length; ++i ) {

            var view = views[i];
            var camera = view.camera;

            var left   = Math.floor( windowWidth  * view.left );
            var top    = Math.floor( windowHeight * view.top );
            var width  = Math.floor( windowWidth  * view.width );
            var height = Math.floor( windowHeight * view.height );

            if (view.show) {

                renderer.setViewport( left, top, width, height );
                renderer.setScissor( left, top, width, height );
                renderer.setScissorTest( true );
                renderer.setClearColor( view.background );

                camera.aspect = width / height;

                renderer.render( scene, camera );
            }

        }

    }

    function animate() {
        var M1 = new THREE.Matrix4();
        var M2 = new THREE.Matrix4();
        requestAnimationFrame(animate);

        toroidBox = toroidBox.setFromObject( toroidGroup );
        ellipseBox = ellipseBox.setFromObject( ellipseGroup );

        if (detectCollision(toroidBox, collidableMeshList)){
            toroidSpeed = -toroidSpeed;
        }

        if (detectCollision(ellipseBox, collidableMeshList)){
            ellipseSpeed = -ellipseSpeed;
        }

        M1.makeRotationY(0.01);
        toroidGroup.applyMatrix(M1);
        toroidGroup.updateMatrix(M1);

        M1.makeTranslation(toroidSpeed, toroidSpeed, 0);
        toroidGroup.applyMatrix(M1);
        toroidGroup.updateMatrix(M1);

        M2.makeRotationX(0.01);
        ellipseGroup.applyMatrix(M2);
        ellipseGroup.updateMatrix(M2);

        M2.makeTranslation(ellipseSpeed, ellipseSpeed, 0);
        ellipseGroup.applyMatrix(M2);
        ellipseGroup.updateMatrix(M2);

        render();
    }
};
