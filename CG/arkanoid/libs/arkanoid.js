/** Implementação do jogo Arkanoid utilizando Three.js
 *  Trabalho desenvolvido para a disciplina MATA65 - Computação Gráfica
 *  Autor: Adeilson Silva
 */

'use strict'

Physijs.scripts.worker = '../libs/physijs_worker.js';
Physijs.scripts.ammo = '../libs/ammo.js';


/* Original game resolution was 224 x 256 */
var WIN_H = 224 * 2;
var WIN_W = 256 * 1.25;

var BLOCKS_INITIAL_X = -0.9;
var BLOCKS_INITIAL_Y =  0.9;

var BLOCKS_AREA = 0.3;
var BLOCK_H = 0.075; 
var BLOCK_W = 0.1;

var BAR_JUMP = 0.2;

var Blocks = [];

function init() {

    //var scene = new THREE.Scene();
    var scene = new Physijs.Scene({reportSize: 10, fixedTimeStep: 1 / 60});
    var renderer = new THREE.WebGLRenderer();

    renderer.setClearColor(new THREE.Color(0.0, 0.0, 0.0));
    renderer.setSize(WIN_W, WIN_H);
    scene.setGravity(new THREE.Vector3(0, 0, 0));
    
    var camera = new THREE.OrthographicCamera( -1.0, 1.0, 1.0, -1.0, -1.0, 1.0 );
    scene.add( camera );

    /* Add bar to scene */
    var barGeometry = new THREE.BoxGeometry(0.4, 0.04, 0); /* Width, Height and Depth */
    var barMaterial = new THREE.MeshBasicMaterial({color: 0x44ff44});
    var bar = new THREE.Mesh(barGeometry, barMaterial);
    
    bar.position.y = -0.8;

    scene.add(bar);

    /* Add ball to scene */
    var ballGeometry = new THREE.SphereGeometry(0.03, 20, 20);
    var ballMaterial = new THREE.MeshBasicMaterial({color: 0x44ff44});
    //var ball = new THREE.Mesh(ballGeometry, ballMaterial);
    var ball = new Physijs.SphereMesh(ballGeometry, ballMaterial);

    ball.position.y = -0.7;
    
    ball.rays = [
        new THREE.Vector3(1, 0, 0),
        new THREE.Vector3(0, 1, 0),
        new THREE.Vector3(1, 1, 0),
        new THREE.Vector3(-1, 0, 0),
        new THREE.Vector3(0, -1, 0),
        new THREE.Vector3(-1, -1, 0),
    ];

    ball.caster = new THREE.Raycaster();

    ball.checkCollision = function() {
        var maxDistance = 0.025;
    };

    scene.add(ball);

    /* Add blocks to scene */
    for (var i = BLOCKS_INITIAL_Y; i > Math.abs(BLOCKS_AREA); i -= BLOCK_H) {
        for (var j = BLOCKS_INITIAL_X; j < Math.abs(BLOCKS_INITIAL_X); j += BLOCK_W) {
            var blockGeometry = new THREE.BoxGeometry(BLOCK_W, BLOCK_H, 0); /* Width, Height and Depth */
            var blockMaterial = new THREE.MeshBasicMaterial({color: 0x0066ff});
            //var block = new THREE.Mesh(blockGeometry, blockMaterial);
            var block = new Physijs.PlaneMesh(blockGeometry, blockMaterial);

            block.position.y = i;
            block.position.x = j;
        
            scene.add(block);
            Blocks.concat(block);

            var constraint = new Physijs.PointConstraint(ball,
                    block, block.position);
            scene.addConstraint(constraint);
        }
    }

    var coords = { x: 0, y: -0.75};
    var tween = new TWEEN.Tween(coords)
            .to({x: 0, y: 0.9}, 1000)
                .onUpdate(function() {
                              if (ball.position.y <= 1.0) {
                                    ball.position.y = this.y;
                                    ball.checkCollision();
                              }
                          })
        .start();
    tween.easing(TWEEN.Easing.Sinusoidal.InOut);

    document.getElementById("WebGL-output").appendChild(renderer.domElement);
    
    render();

    function render () {
        renderer.clear();
        requestAnimationFrame(render);
        TWEEN.update();
        renderer.render(scene, camera);
    }

    document.addEventListener("keydown", function(event) {
        /* Right arrow key */
        if (event.keyCode == 39 && bar.position.x + BAR_JUMP < 1.0) {
            bar.position.x += BAR_JUMP;
        }

        /* Left arrow key */
        if (event.keyCode == 37 && bar.position.x - BAR_JUMP > -1.0) {
            bar.position.x -= BAR_JUMP;
        }

        /* UP arrow key */
        if (event.keyCode == 38 && ball.position.y == -0.7) {
            //tween.to({x: 0, y: 0.9}, 1000);
        }
    });

};


