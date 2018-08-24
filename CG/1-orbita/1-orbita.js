/** Código desenvolvido na disciplina MATA65 - Computação Gráfica, 2017.1
 *  Aluno: Adeilson Antônio da Silva 
 **/

var userParams = { 
    SUN_RADIUS: 0.3,
    VENUS_SUN_RADIUS: 0.35,
    EARTH_SUN_RADIUS: 1,
    SUN_SPEED: 0.7,
    EARTH_SPEED: 0.035,
    VENUS_SPEED: 0.05
};

function init() {

    var scene = new THREE.Scene();

    var renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));
    renderer.setSize(window.innerWidth*0.7, window.innerHeight*0.7);

    var camera = new THREE.OrthographicCamera( -1.0, 1.0, 1.0, -1.0, -1.0, 1.0 );
    scene.add( camera );

    // Global Axis
    var globalAxis = new THREE.AxisHelper( 1.0 );
    //scene.add( globalAxis );

    // Planets size
    var radius = 0.05;
    var segments = 50; //<-- Increase or decrease for more resolution I guess

    // Planets materials
    var sunMaterial = new THREE.MeshBasicMaterial({
        color: 0xffff00
    });

    var earthMaterial = new THREE.MeshBasicMaterial({
        color: 0x0000ff
    });

    var venusMaterial = new THREE.MeshBasicMaterial({
        color: 0x00ff00
    });

    // Planets beind added to scene
    var circleGeometry = new THREE.CircleGeometry( radius, segments );
    var sun = new THREE.Mesh( circleGeometry, sunMaterial );
    scene.add( sun );

    var earth = new THREE.Mesh( circleGeometry, earthMaterial );
    scene.add( earth );
    earth.position.set(0, userParams.EARTH_SUN_RADIUS, 1, 1);

    var venus = new THREE.Mesh( circleGeometry, venusMaterial );
    scene.add( venus );
    venus.position.set(0, userParams.VENUS_SUN_RADIUS, 1, 1);
    sun.add( earth );
    sun.add( venus );

    // Draw lines representing orbits
    var earth2sun_lineGeom = new THREE.Geometry();
    earth2sun_lineGeom.vertices.push(earth.position);
    earth2sun_lineGeom.vertices.push(sun.position);
    var earth2sun_lineMat = new THREE.LineBasicMaterial({
        color: earth.material.color
    });
    earth2sun_line = new THREE.Line(earth2sun_lineGeom, earth2sun_lineMat);
    //scene.add( earth2sun_line );

    var venus2sun_lineGeom = new THREE.Geometry();
    venus2sun_lineGeom.vertices.push(venus.position);
    venus2sun_lineGeom.vertices.push(sun.position);
    var venus2sun_lineMat = new THREE.LineBasicMaterial({
        color: venus.material.color
    });
    venus2sun_line = new THREE.Line(venus2sun_lineGeom, venus2sun_lineMat);
    //scene.add( venus2sun_line );

    var earth2venus_lineGeom = new THREE.Geometry();
    earth2venus_lineGeom.vertices.push(earth.position);
    earth2venus_lineGeom.vertices.push(venus.position);
    var earth2venus_lineMat = new THREE.LineBasicMaterial({
        linewidth: 0.1,
        linecap: 'square'
    });
    earth2venus_line = new THREE.Line(earth2venus_lineGeom, earth2venus_lineMat);
    earth2venus_line.geometry.dynamic = true;
    scene.add( earth2venus_line );

    var gui = new dat.GUI({
        width: 500
    });
    gui.add( userParams, 'EARTH_SPEED', 0, 0.5 ).name("Velocidade da Terra");
    gui.add( userParams, 'EARTH_SUN_RADIUS', 0, 1 ).name("Raio da órbita da Terra");
    gui.add( userParams, 'VENUS_SPEED', 0, 0.5 ).name("Velocidade de Vênus");
    gui.add( userParams, 'VENUS_SUN_RADIUS', 0, 1 ).name("Raio da órbita de Vênus");
    gui.open();

    document.getElementById("WebGL-output").appendChild(renderer.domElement);
    animate();

    /**
     *  As funções "getColoredBufferLine", "makeColorGradient" e "_byte2Hex" foram utilizadas
     *  para colorir as linhas desenhadas, pensando numa melhor visualização da animação.
     *  O código original está disponível em: http://jsfiddle.net/L0rdzbej/276/
     **/

    function getColoredBufferLine ( steps, phase, geometry ) {

        var vertices = geometry.vertices;
        var segments = geometry.vertices.length;

        var geometry = new THREE.BufferGeometry();

        // material
        var lineMaterial = new THREE.LineBasicMaterial({ vertexColors: THREE.VertexColors });

        // attributes
        var positions = new Float32Array( segments * 3 ); // 3 vertices per point
        var colors = new Float32Array( segments * 3 );

        var frequency = 1 /  ( steps * segments );
        var color = new THREE.Color();

        var x, y, z;

        for ( var i = 0, l = segments; i < l; i ++ ) {

            x = vertices[ i ].x;
            y = vertices[ i ].y;
            z = vertices[ i ].z;

            positions[ i * 3 ] = x;
            positions[ i * 3 + 1 ] = y;
            positions[ i * 3 + 2 ] = z;

            color.set ( makeColorGradient( i, frequency, phase ) );

            colors[ i * 3 ] = color.r;
            colors[ i * 3 + 1 ] = color.g;
            colors[ i * 3 + 2 ] = color.b;

        }

        geometry.addAttribute( 'position', new THREE.BufferAttribute( positions, 3 ) );
        geometry.addAttribute( 'color', new THREE.BufferAttribute( colors, 3 ) );

        // line
        var line = new THREE.Line( geometry, lineMaterial );

        return line;

    }

    function makeColorGradient ( i, frequency, phase ) {  

        var center = 128;
        var width = 127;

        var redFrequency, grnFrequency, bluFrequency;
        grnFrequency = bluFrequency = redFrequency = frequency;

        var phase2 = phase + 2;
        var phase3 = phase + 4;

        var red   = Math.sin( redFrequency * i + phase ) * width + center;
        var green = Math.sin( grnFrequency * i + phase2 ) * width + center;
        var blue  = Math.sin( bluFrequency * i + phase3 ) * width + center;

        return parseInt( '0x' + _byte2Hex( red ) + _byte2Hex( green ) + _byte2Hex( blue ) );
    }

    function _byte2Hex (n) {
        var nybHexString = "0123456789ABCDEF";
        return String( nybHexString.substr( ( n >> 4 ) & 0x0F, 1 ) ) + nybHexString.substr( n & 0x0F, 1 );
    }

    var earthTimestamp = 0,
        venusTimestamp = 0;
    function animate() {
        requestAnimationFrame(animate);

        earthTimestamp += userParams.EARTH_SPEED;
        venusTimestamp += userParams.VENUS_SPEED;

        //sun.position.x = Math.cos(timestamp * userParams.SUN_SPEED) * userParams.SUN_RADIUS;
        //sun.position.y = Math.sin(timestamp * userParams.SUN_SPEED) * userParams.SUN_RADIUS;

        var buffer_earth2venus_lineGeom = new THREE.Geometry();
        buffer_earth2venus_lineGeom.vertices.push(earth.position);
        buffer_earth2venus_lineGeom.vertices.push(venus.position);
        //var buffer_earth2venus_line = new THREE.Line(buffer_earth2venus_lineGeom, earth2venus_lineMat);
        var buffer_earth2venus_line = getColoredBufferLine( earthTimestamp * 0.2, venusTimestamp * 1.5, buffer_earth2venus_lineGeom );
        scene.add( buffer_earth2venus_line );

        earth.position.x = userParams.EARTH_SUN_RADIUS * Math.cos(earthTimestamp) + sun.position.x;
        earth.position.y = userParams.EARTH_SUN_RADIUS * Math.sin(earthTimestamp) + sun.position.y;

        venus.position.x = userParams.VENUS_SUN_RADIUS * Math.cos(venusTimestamp) + sun.position.x;
        venus.position.y = userParams.VENUS_SUN_RADIUS * Math.sin(venusTimestamp) + sun.position.y;

        earth2sun_line.geometry.verticesNeedUpdate = true;
        venus2sun_line.geometry.verticesNeedUpdate = true;
        earth2venus_line.geometry.verticesNeedUpdate = true;

        render();
    }

    function render () {
        renderer.clear();
        renderer.render(scene, camera);
    }

};
