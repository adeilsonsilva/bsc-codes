var texture = null;
var renderer;
var scene;
var camera;
var matShader = null;

var i = 0;
var start_time = null;
var display_time = 7000;
var fade_time = 1000;
var lastChange = 0;

var path = "images/";

var images = [
    "westbrook.jpg",
    "jordan.jpg",
    "kobe.jpg",
    "barkley.jpg",
    "bill-russell.jpg",
];

var textureLoader = new THREE.TextureLoader();

function init() {

    scene = new THREE.Scene();
    renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));

    camera = new THREE.OrthographicCamera( -0.5, 0.5, 0.5, -0.5, -1.0, 1.0 );
    scene.add( camera );

    start_time = get_time();
    texture = textureLoader.load(path+images[0], onLoadTexture);
    texture.needsUpdate = true;

    document.getElementById("WebGL-output").appendChild(renderer.domElement);

    // Global Axis
    var globalAxis = new THREE.AxisHelper( 1.0 );
    scene.add( globalAxis );

    renderer.clear();
    requestAnimationFrame( animate );
};


function onLoadTexture() {

    if (!texture.image) {
        console.log("ERROR: loading texture");
    } else {

        console.log("Image size: " + texture.image.width + " x " + texture.image.height);
        console.log("Pixel size: " + 1.0/texture.image.width + " x " + 1.0/texture.image.height);

        var filter = Math.floor((Math.random() * 5) + 1);

        uniforms = {
            uSampler 		: 	{ 	type: "t", value: texture },
            uPixelSize		:	{ 	
                type: "v2", 
                value: new THREE.Vector2(1.0/texture.image.width, 1.0/texture.image.height) 
            },
            uImageSize		:	{ 	
                type: "v2", 
                value: new THREE.Vector2(texture.image.width, texture.image.height) 
            },
            uApplyFilter	: 	{	type: "bool", value: true },
            uFilterType	    : 	{	type: "i", value: filter },
            uScale	        : 	{	type: "f", value: 1.0 },
            uCenter      :   {
                type: "v2",
                value: new THREE.Vector2(0.0, 0.0)
            },
        };

        matShader = new THREE.ShaderMaterial( {
            uniforms: uniforms,
            vertexShader: document.getElementById( 'suaviza-vs' ).textContent,
            fragmentShader: document.getElementById( 'suaviza-fs' ).textContent
        } );
        console.log(matShader.uniforms.uCenter.value);

        // Plane
        var planeGeometry = new THREE.PlaneBufferGeometry(1.0, 1.0, 20, 20);                 
        var plane = new THREE.Mesh( planeGeometry, matShader );
        plane.position.set(0.0, 0.0, -0.5);
        scene.add( plane );	

        renderer.setSize("512", "512");
        renderer.render(scene, camera);
    }
};

function animate() {
    update();
    render();		
    requestAnimationFrame( animate );
};

function update() {

    var update_time = get_time();

    var top_frame = Math.floor(update_time / (display_time - fade_time));
    var frame_start_time = top_frame * (display_time - fade_time);
    var time_passed = update_time - frame_start_time;

    function wrap_index(i) {
        return (i + images.length) % images.length;
    }

    if ((update_time-lastChange) >= display_time) {
        lastChange = get_time();
        texture = textureLoader.load(path+images[wrap_index(top_frame)], onLoadTexture);
    }

    if (matShader != null) {
        matShader.uniforms.uScale.value += 0.01;
        matShader.uniforms.uSampler.value = texture;
    }	
};

function render() {

    renderer.clear();
    renderer.render( scene, camera );
};

function calcCenter(x1, y1, x2, y2)
{
    return (x1 + x2)/2, (y1 + y2)/2;
}

function get_time() {
    var d = new Date();
    return d.getTime() - start_time;
}
