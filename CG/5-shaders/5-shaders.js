var scene 			= null;
var renderer		= null;
var camera 			= null;
var pointLight		= null;
var orbitControls	= null;
var clock;
var texture = null;

var userParams = {
    A: 3.0, /* amplitude */
    L: 15.0, /* wavelength */
    S: 5.0, /* speed */
    guiW: 1.0,
};
userParams.W = (userParams.guiW * Math.PI) / userParams.L; /* frequency */

var gui = new dat.GUI({
    width: 500,
});

var startTime = Date.now();
console.log(startTime);

function init() {

    clock = new THREE.Clock();

    scene = new THREE.Scene();

    renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));
    renderer.setSize(window.innerWidth*0.7, window.innerHeight*0.7);

    document.getElementById("WebGL-output").appendChild(renderer.domElement);

    camera = new THREE.PerspectiveCamera(110.0, 1.0, 0.1, 2000.0);

    // Controle de Camera Orbital
    orbitControls = new THREE.OrbitControls(camera);
    orbitControls.autoRotate = false;

    // Adiciona luz ambiente
    var ambientLight = new THREE.AmbientLight(new THREE.Color(1.0, 1.0, 1.0));
    scene.add(ambientLight);

    gui.add( userParams, 'A', 0.0, 20.0 ).name("Amplitude das Ondas");
    gui.add( userParams, 'L', 0.0, 20.0 ).name("Comprimento das Ondas");
    gui.add( userParams, 'S', 0.0, 20.0 ).name("Velocidade das Ondas");
    gui.add( userParams, 'guiW', 0.0, 20.0 ).name("Frequência das Ondas");
    gui.open();

    loadMeshes();

    renderer.clear();
}

function loadMeshes() {
    // Load Mesh
    var loader = new THREE.TextureLoader();
    loader.load('models/ocean_texture.jpg', buildScene);		
}

function render() {
    var delta = clock.getDelta();
    orbitControls.update(delta);


    var elapsedMilliseconds = Date.now() - startTime;
    var elapsedSeconds = elapsedMilliseconds / 1000.;
    uniforms.time.value = elapsedSeconds;

    uniforms.A.value = userParams.A;
    uniforms.L.value = userParams.L;
    uniforms.S.value = userParams.S;
    uniforms.W.value = (userParams.guiW * Math.PI) / userParams.L;

    renderer.render(scene, camera);
    requestAnimationFrame(render);
}

function buildScene(texture) {  

    var maxCoord = 10;

	console.log("Image size: " + texture.image.width + " x " + texture.image.height);
	console.log("Pixel size: " + 1.0/texture.image.width + " x " + 1.0/texture.image.height);

    camera.position.x 	= 
        camera.position.y 	= 
        camera.position.z 	= maxCoord*1.5;
    camera.lookAt(new THREE.Vector3( 0, 0, 0 ));
    camera.updateProjectionMatrix();

    // Global Axis
    var globalAxis = new THREE.AxisHelper(maxCoord*1.3);
    //scene.add( globalAxis );

    var directionalLight = new THREE.DirectionalLight( 0xffffff );
    directionalLight.position.set(10, 100, 10);
    scene.add( directionalLight );

    var lightTarget = new THREE.Object3D();
    lightTarget.position.set(10, 10, -10);
    scene.add( lightTarget );

    directionalLight.target = lightTarget;

    var lightAxis = new THREE.AxisHelper(maxCoord*3);
    lightAxis.position.set( directionalLight.position.x, directionalLight.position.y, directionalLight.position.z);
    //scene.add( lightAxis );

    uniforms = {
        uCamPos	: 	{ type: "v3", value: camera.position },
        uLPos	:	{ type: "v3", value: directionalLight.position },
        time	:	{ type: "f",  value: 1.0 }, 
		uSampler: 	{ type: "t",  value: texture },
		uPixelSize:	{ type: "v2", 
					  value: new THREE.Vector2(1.0/texture.image.width, 1.0/texture.image.height) 
                    },
        A       :   { type: "f",  value: userParams.A },
        L       :   { type: "f",  value: userParams.L },
        S       :   { type: "f",  value: userParams.S },
        W       :   { type: "f",  value: userParams.W },
    };

    var matShader = new THREE.ShaderMaterial( {
        wireframe: false,
        uniforms: uniforms,
        vertexShader: document.getElementById( 'phong-vs' ).textContent,
        fragmentShader: document.getElementById( 'phong-fs' ).textContent
    });

//    texture.traverse(function (child) {	
//        if (child instanceof THREE.Mesh) {
//            child.material = matShader;
//            if ( (child.geometry.attributes.normal != undefined) ) {
//                child.geometry.computeFaceNormals();
//                child.geometry.computeVertexNormals();
//                child.geometry.normalsNeedUpdate = true;
//            }
//        }
//    });

    //scene.add(texture);

    // Ground
    var groundGeom = new THREE.PlaneBufferGeometry(maxCoord*25, maxCoord*25, 50, 50);
    groundGeom.computeFaceNormals();
    groundGeom.computeVertexNormals();
    groundGeom.normalsNeedUpdate = true;

    var groundMesh = new THREE.Mesh(groundGeom);
    //var groundMesh = new THREE.Mesh(groundGeom, new THREE.MeshBasicMaterial({color: 0x0000ff, wireframe: true}));
    //groundMesh.material.side 	= THREE.DoubleSide;
    //groundMesh.material.shading	= THREE.FlatShading;
    
    groundMesh.rotation.x = -Math.PI / 3;
    groundMesh.position.y -= 3.0;

    groundMesh.traverse(function (child) {	
        if (child instanceof THREE.Mesh) {
            child.material = matShader;
            if ( (child.geometry.attributes.normal != undefined) ) {
                child.geometry.computeFaceNormals();
                child.geometry.computeVertexNormals();
                child.geometry.normalsNeedUpdate = true;
            }
        }
    });

    scene.add(groundMesh);

    render();
}
