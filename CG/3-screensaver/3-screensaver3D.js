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

var vertexNumber = 100;
var toroidSpeed = -0.05,
    ellipseSpeed = 0.05;

function drawSuperEllipse(rx, ry, rz, n1, n2, color)
{
    var superEllipse = new THREE.Geometry(); 

    var deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = -Math.PI/2 ; phi <= Math.PI/2 ; phi += deltaPhi) {
        for (beta = -Math.PI ; beta <= Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = rx * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), n2 );
            var y = ry * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 );
            var z = rz * Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), n1 );

            superEllipse.vertices.push(new THREE.Vector3( x,  y, z ));
        }
    }

    var countFaces=0;
    for (i = 0 ; i <= vertexNumber ; i++) {
        for (j = 0 ; j <= vertexNumber ; j++) {

            superEllipse.faces.push(new THREE.Face3(i*vertexNumber+j, (i+1)*vertexNumber+j, (i+1)*vertexNumber+j+1)); 
            superEllipse.faces[countFaces].vertexColors[0] = color;
            superEllipse.faces[countFaces].vertexColors[1] = color;
            superEllipse.faces[countFaces].vertexColors[2] = color;
            countFaces++;

            superEllipse.faces.push(new THREE.Face3(i*vertexNumber+j, (i+1)*vertexNumber+(j+1), i*vertexNumber+(j+1))); 
            superEllipse.faces[countFaces].vertexColors[0] = color;
            superEllipse.faces[countFaces].vertexColors[1] = color;
            superEllipse.faces[countFaces].vertexColors[2] = color;
            countFaces++;
        }
    }

    var ellipseMaterial = new THREE.MeshBasicMaterial({ 
        vertexColors: THREE.VertexColors,
        wireframe: false
    }); 

    var superEllipseMesh = new THREE.Mesh(superEllipse, ellipseMaterial);

    return superEllipseMesh;

}

function drawSuperToroid(r0, r1, n1, n2, color) 
{
    var superToroid = new THREE.Geometry(); 

    var deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = 0 ; phi <= 2 * Math.PI ; phi += deltaPhi) {
        for (beta = 0 ; beta <= 2 * Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), n1 ) * (r0 + r1 * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), n2 ));
            var y = Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), n1 ) * (r0 + r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 ));
            var z = r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), n2 );

            superToroid.vertices.push(new THREE.Vector3( x,  y, z ));
        }
    }

    var countFaces=0;
    for (i = 0 ; i <= vertexNumber ; i++) {
        for (j = 0 ; j <= vertexNumber ; j++) {

            superToroid.faces.push(new THREE.Face3(i*vertexNumber+j, (i+1)*vertexNumber+j, (i+1)*vertexNumber+j+1)); 
            superToroid.faces[countFaces].vertexColors[0] = color;
            superToroid.faces[countFaces].vertexColors[1] = color;
            superToroid.faces[countFaces].vertexColors[2] = color;
            countFaces++;

            superToroid.faces.push(new THREE.Face3(i*vertexNumber+j, (i+1)*vertexNumber+(j+1), i*vertexNumber+(j+1))); 
            superToroid.faces[countFaces].vertexColors[0] = color;
            superToroid.faces[countFaces].vertexColors[1] = color;
            superToroid.faces[countFaces].vertexColors[2] = color;
            countFaces++;
        }
    }

    var toroidMaterial = new THREE.MeshBasicMaterial({ 
        vertexColors: THREE.VertexColors,
        wireframe: false
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

    var scene = new THREE.Scene();

    var renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));
    renderer.setSize(window.innerWidth*0.7, window.innerHeight*0.7);

    var camera = new THREE.OrthographicCamera( -5.0, 5.0, 5.0, -5.0, -10.0, 1000 );
    //var camera = new THREE.OrthographicCamera( -12.0, 12.0, 12.0, -12.0, -1.0, 1000 );
    scene.add( camera );

    // Global Axis
    var globalAxis = new THREE.AxisHelper( 1.0 );
    //scene.add( globalAxis );

    var collidableMeshList = [];

    var groupBox = new THREE.Object3D();
    var outsideBoxGroup = new THREE.Object3D();

    var boxMat = new THREE.MeshBasicMaterial( {color: 0x0000ff,wireframe:true} );

    var upperBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );              
    upperBoxGeo.translate(0, 10, 0);
    var upperBoxMesh = new THREE.Mesh(upperBoxGeo, boxMat);
    var upperBox = new THREE.Box3().setFromObject(upperBoxMesh);
    collidableMeshList.push(upperBox);
    //scene.add(upperBoxMesh);

    var lowerBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );              
    lowerBoxGeo.translate(0, -10, 0);
    var lowerBoxMesh = new THREE.Mesh(lowerBoxGeo, boxMat);
    var lowerBox = new THREE.Box3().setFromObject(lowerBoxMesh);
    collidableMeshList.push(lowerBox);
    //scene.add(lowerBoxMesh);

    var leftBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );              
    leftBoxGeo.translate(-10, 0, 0);
    var leftBoxMesh = new THREE.Mesh(leftBoxGeo, boxMat);
    var leftBox = new THREE.Box3().setFromObject(leftBoxMesh);
    collidableMeshList.push(leftBox);
    //scene.add(leftBoxMesh);

    var rightBoxGeo = new THREE.BoxGeometry( 10, 10, 10 );              
    rightBoxGeo.translate(10, 0, 0);
    var rightBoxMesh = new THREE.Mesh(rightBoxGeo, boxMat);
    var rightBox = new THREE.Box3().setFromObject(rightBoxMesh);
    collidableMeshList.push(rightBox);
    //scene.add(rightBoxMesh);

    var box = new THREE.BoxGeometry( 10, 10, 10 );              
    var boxMesh = new THREE.Mesh(box, boxMat);
    var cube = new THREE.BoxHelper( boxMesh );
    groupBox.add( cube );
    var boxAxis = new THREE.AxisHelper( 1 );
    groupBox.add( boxAxis );

    groupBox.position.set(0, 0, 0.0);
    //scene.add( groupBox );

    var toroidGroup = new THREE.Object3D();
    toroidGroup.add( drawSuperToroid( 0.6, 0.05, 0.9, 0, new THREE.Color('red') ) );
    toroidGroup.add( drawSuperToroid( 0.9, 0.05, 5.6, 9.6, new THREE.Color('green') ) );
    toroidGroup.children[1].translateX(1);
    toroidGroup.add( drawSuperToroid( 0.66, 0.02, 2, 1.5, new THREE.Color('blue') ) );
    toroidGroup.children[2].translateX(2);

    var toroidBox = new THREE.Box3().setFromObject( toroidGroup );
    var toroidBoxHelper = new THREE.BoxHelper(toroidGroup);
    //scene.add( toroidBoxHelper );
    scene.add(toroidGroup);

    var ellipseGroup = new THREE.Object3D();
    ellipseGroup.add( drawSuperEllipse( 0.5, 0.5, 0.5, 1, 1, new THREE.Color('red') ) );
    ellipseGroup.add( drawSuperEllipse( 1, 1, 1, 5, 5, new THREE.Color('green') ) );
    ellipseGroup.children[1].translateX(1);
    ellipseGroup.add( drawSuperEllipse( 1, 1, 1, 1, 10, new THREE.Color('blue') ) );
    ellipseGroup.children[2].translateX(2);

    var ellipseBox = new THREE.Box3().setFromObject( ellipseGroup );
    var ellipseBoxHelper = new THREE.BoxHelper(ellipseGroup);
    //scene.add( ellipseBoxHelper );
    scene.add(ellipseGroup);

    document.getElementById("WebGL-output").appendChild(renderer.domElement);
    animate();

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

        //toroidBoxHelper.update();

        render();
    }

    function render () {
        renderer.clear();
        renderer.render(scene, camera);
    }

};
