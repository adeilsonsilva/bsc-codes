/** Código desenvolvido na disciplina MATA65 - Computação Gráfica, 2017.1
 *  Aluno: Adeilson Antônio da Silva
 **/

var renderer;
var scene;
var camera;
var gui = new dat.GUI({
    width: 500
});

var userParams = {
    rx: 1.0,
    ry: 1.0,
    rz: 1.0,
    r0: 0.5,
    r1: 0.5,
    n1: 1.0,
    n2: 1.0,
}

var phi = -Math.PI/2,
    beta = -Math.PI;

var vertexNumber = 300,
    deltaPhi = 2 * Math.PI / vertexNumber;

function drawSuperToroid() {

    renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));

    renderer.setSize(500, 500);

    var oldCanvas = document.getElementsByTagName("canvas")[0];
    if ( oldCanvas != undefined ) {
        document.getElementById("WebGL-output").removeChild(oldCanvas);
        gui.destroy();
        gui = new dat.GUI({
            width: 500
        });
    }
    document.getElementById("WebGL-output").appendChild(renderer.domElement);

    scene = new THREE.Scene();

    camera = new THREE.OrthographicCamera( -1.0, 1.0, 1.0, -1.0, -1.0, 1.0 );
    scene.add( camera );

    var superToroid = new THREE.Geometry();
    superToroid.dynamic = true;

    var index = 0;
    var grid = [];

    deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = 0 ; phi <= 2 * Math.PI ; phi += deltaPhi) {
        var verticesRow = [];
        for (beta = 0 ; beta <= 2 * Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * (userParams.r0 + userParams.r1 * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), userParams.n2 ));
            var y = Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), userParams.n1 ) * (userParams.r0 + userParams.r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 ));
            var z = userParams.r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 );

            superToroid.vertices.push(new THREE.Vector3( x,  y, z ));
            verticesRow.push( index ++ );
        }
        grid.push( verticesRow );
    }

    console.log(superToroid.vertices.length);
    console.log(grid);
    var countFaces = 0;
    for (i = 0 ; i < vertexNumber ; i++) {
        for (j = 0 ; j < vertexNumber ; j++) {
            var a = grid[ i ][ j + 1 ];
			var b = grid[ i ][ j ];
			var c = grid[ i + 1 ][ j ];
			var d = grid[ i + 1 ][ j + 1 ];

			superToroid.faces.push(new THREE.Face3( a, b, c ));
            superToroid.faces[countFaces].vertexColors[0] = new THREE.Color( 1.0 - i/vertexNumber, i/vertexNumber, j/vertexNumber);
            superToroid.faces[countFaces].vertexColors[1] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            superToroid.faces[countFaces].vertexColors[2] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            countFaces++;

			superToroid.faces.push(new THREE.Face3( b, c, d ));
            superToroid.faces[countFaces].vertexColors[0] = new THREE.Color( 1.0 - i/vertexNumber, i/vertexNumber, j/vertexNumber);
            superToroid.faces[countFaces].vertexColors[1] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            superToroid.faces[countFaces].vertexColors[2] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            countFaces++;
        }
    }

    var toroidMaterial = new THREE.MeshBasicMaterial({
        vertexColors:THREE.VertexColors,
        wireframe:true
    });

    var superToroidMesh = new THREE.Mesh(superToroid, toroidMaterial);

    superToroid.rotateX(30 * Math.PI / 180);
    superToroid.rotateY(60 * Math.PI / 180);
    superToroid.rotateZ(45 * Math.PI / 180);

    scene.add( superToroidMesh );

    gui.add( userParams, 'r0', 0, 1.0 ).name("Raio 0");
    gui.add( userParams, 'r1', 0, 1.0 ).name("Raio 1");
    gui.add( userParams, 'n1', 0, 10.0 ).name("N1");
    gui.add( userParams, 'n2', 0, 10.0 ).name("N2");
    gui.open();

    animate();

    function animate () {
        requestAnimationFrame(animate);

        var vertex = 0;
        deltaPhi = 2 * Math.PI / vertexNumber;
        for (phi = 0 ; phi <= 2 * Math.PI ; phi += deltaPhi) {
            for (beta = 0 ; beta <= 2 * Math.PI; beta += deltaPhi) {
                var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
                var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

                superToroidMesh.geometry.vertices[vertex].x = Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * (userParams.r0 + userParams.r1 * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), userParams.n2 ));
                superToroidMesh.geometry.vertices[vertex].y = Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), userParams.n1 ) * (userParams.r0 + userParams.r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 ));
                superToroidMesh.geometry.vertices[vertex].z = userParams.r1 * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 );

                vertex++;
            }
        }

        //superToroid.rotateX(30 * Math.PI / 180);
        //superToroid.rotateY(60 * Math.PI / 180);
        //superToroid.rotateZ(45 * Math.PI / 180);
        superToroidMesh.rotation.x += 0.01;
        superToroidMesh.rotation.y += 0.01;
        //superToroidMesh.rotation.z += 0.01;
        superToroidMesh.geometry.verticesNeedUpdate = true;
        render();
    }

    function render () {
        renderer.clear();
        renderer.render(scene, camera);
    }
}

function drawSuperEllipse() {

    renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));

    renderer.setSize(500, 500);

    var oldCanvas = document.getElementsByTagName("canvas")[0];
    if ( oldCanvas != undefined ) {
        document.getElementById("WebGL-output").removeChild(oldCanvas);
        gui.destroy();
        gui = new dat.GUI({
            width: 500
        });
    }
    document.getElementById("WebGL-output").appendChild(renderer.domElement);

    scene = new THREE.Scene();

    camera = new THREE.OrthographicCamera( -1.0, 1.0, 1.0, -1.0, -1.0, 1.0 );
    scene.add( camera );

    var superEllipse = new THREE.Geometry();
    superEllipse.dynamic = true;

    var index = 0;
	var grid = [];

    deltaPhi = 2 * Math.PI / vertexNumber;
    for (phi = -Math.PI/2 ; phi <= Math.PI/2 ; phi += deltaPhi) {
        var verticesRow = [];
        for (beta = -Math.PI ; beta <= Math.PI; beta += deltaPhi) {
            var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
            var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

            var x = userParams.rx * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), userParams.n2 );
            var y = userParams.ry * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 );
            var z = userParams.rz * Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), userParams.n1 );

            superEllipse.vertices.push(new THREE.Vector3( x,  y, z ));

            verticesRow.push( index ++ );
        }

        grid.push( verticesRow );
    }

    console.log(grid);
    var countFaces = 0;
    for (i = 0 ; i < grid.length - 1 ; i++) {
        for (j = 0 ; j < vertexNumber ; j++) {
            var a = grid[ i ][ j + 1 ];
			var b = grid[ i ][ j ];
			var c = grid[ i + 1 ][ j ];
			var d = grid[ i + 1 ][ j + 1 ];

			superEllipse.faces.push(new THREE.Face3( a, b, d ));
            superEllipse.faces[countFaces].vertexColors[0] = new THREE.Color( 1.0 - i/vertexNumber, i/vertexNumber, j/vertexNumber);
            superEllipse.faces[countFaces].vertexColors[1] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, j/vertexNumber);
            superEllipse.faces[countFaces].vertexColors[2] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            countFaces++;

			superEllipse.faces.push(new THREE.Face3( b, c, d ));
            superEllipse.faces[countFaces].vertexColors[0] = new THREE.Color( 1.0 - i/vertexNumber, i/vertexNumber, j/vertexNumber);
            superEllipse.faces[countFaces].vertexColors[1] = new THREE.Color( 1.0 - i/vertexNumber, (i+1)/vertexNumber, (j+1)/vertexNumber);
            superEllipse.faces[countFaces].vertexColors[2] = new THREE.Color( 1.0 - i/vertexNumber, i/vertexNumber, (j+1)/vertexNumber);
            countFaces++
        }
    }

    var ellipsoidMaterial = new THREE.MeshBasicMaterial({
        vertexColors:THREE.VertexColors,
        wireframe:true
    });

    var superEllipseMesh = new THREE.Mesh(superEllipse, ellipsoidMaterial);

    superEllipse.rotateX(30 * Math.PI / 180);
    superEllipse.rotateY(60 * Math.PI / 180);
    superEllipse.rotateZ(45 * Math.PI / 180);

    scene.add( superEllipseMesh );

    gui.add( userParams, 'rx', 0, 1.0 ).name("Raio em X");
    gui.add( userParams, 'ry', 0, 1.0 ).name("Raio em Y");
    gui.add( userParams, 'rz', 0, 1.0 ).name("Raio em Z");
    gui.add( userParams, 'n1', 1.0, 10.0 ).name("N1");
    gui.add( userParams, 'n2', 1.0, 10.0 ).name("N2");
    gui.open();

    animate();

    function animate () {
        requestAnimationFrame(animate);

        var vertex = 0;
        deltaPhi = 2 * Math.PI / vertexNumber;
        for (phi = -Math.PI/2 ; phi <= Math.PI/2 ; phi += deltaPhi) {
            for (beta = -Math.PI ; beta <= Math.PI; beta += deltaPhi) {
                var cosPhi = Math.cos(phi), sinPhi = Math.sin(phi);
                var cosBeta = Math.cos(beta), sinBeta = Math.sin(beta);

                superEllipseMesh.geometry.vertices[vertex].x = userParams.rx * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * Math.sign(cosBeta) * Math.pow( Math.abs(cosBeta), userParams.n2 );
                superEllipseMesh.geometry.vertices[vertex].y = userParams.ry * Math.sign(cosPhi) * Math.pow( Math.abs(cosPhi), userParams.n1 ) * Math.sign(sinBeta) * Math.pow( Math.abs(sinBeta), userParams.n2 );
                superEllipseMesh.geometry.vertices[vertex].z = userParams.rz * Math.sign(sinPhi) * Math.pow( Math.abs(sinPhi), userParams.n1 );

                vertex++;
            }
        }

        //superEllipse.rotateX(30 * Math.PI / 180);
        //superEllipse.rotateY(60 * Math.PI / 180);
        //superEllipse.rotateZ(45 * Math.PI / 180);
        superEllipseMesh.rotation.x += 0.01;
        superEllipseMesh.rotation.y += 0.01;
        //superEllipseMesh.rotation.z += 0.01;
        superEllipseMesh.geometry.verticesNeedUpdate = true;
        render();
    }

    function render () {
        renderer.clear();
        renderer.render(scene, camera);
    }

};
