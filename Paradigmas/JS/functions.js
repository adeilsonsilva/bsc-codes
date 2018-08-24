/* Lista: https://gist.github.com/rodrigorgs/9c62782f65cc283b803c */

/* Questão 20 */
function mapIdTitle() {
    var newReleases = [
        {
            "id": 70111470,
            "title": "Die Hard",
            "boxart": "http://cdn-0.nflximg.com/images/2891/DieHard.jpg",
            "uri": "http://api.netflix.com/catalog/titles/movies/70111470",
            "rating": [4.0],
            "bookmark": []
        },
        {
            "id": 654356453,
            "title": "Bad Boys",
            "boxart": "http://cdn-0.nflximg.com/images/2891/BadBoys.jpg",
            "uri": "http://api.netflix.com/catalog/titles/movies/70111470",
            "rating": [5.0],
            "bookmark": [{ id:432534, time:65876586 }]
        },
        {
            "id": 65432445,
            "title": "The Chamber",
            "boxart": "http://cdn-0.nflximg.com/images/2891/TheChamber.jpg",
            "uri": "http://api.netflix.com/catalog/titles/movies/70111470",
            "rating": [4.0],
            "bookmark": []
        },
        {
            "id": 675465,
            "title": "Fracture",
            "boxart": "http://cdn-0.nflximg.com/images/2891/Fracture.jpg",
            "uri": "http://api.netflix.com/catalog/titles/movies/70111470",
            "rating": [5.0],
            "bookmark": [{ id:432534, time:65876586 }]
        }
    ];

    // ------------ INSERT CODE HERE! -----------------------------------
    // Use a função map para acumular {id, title} para cada video
    return newReleases.map( function(video) { return {id: video.id, title: video.title}} );
};
// Este código verifica se sua resposta está correta.
// Se não estiver, aparece um erro no console.
var result = _.sortBy(mapIdTitle(), v => v.id);
var expected = [{"id":675465,"title":"Fracture"},{"id":65432445,"title":"The Chamber"},{"id":70111470,"title":"Die Hard"},{"id":654356453,"title":"Bad Boys"}];
// ufbassert(expected, result);

/* Questão 21 */

function meuMap(array, f) {
    var resultado = [];

    array.forEach(function(argument) {
    	resultado.push(f(argument));
    });

    return resultado;
}

// Código de checagem
// ufbassert([], meuMap([], elem => elem * 2));
// ufbassert([1,2,3], meuMap([[1], [1, 2], [3, 2, 1]], elem => elem.length));

/* Questão 22 */

function meuFilter(array, func) {
    var resultado = [];

	array.forEach(function(argument) {
		func(argument) ? resultado.push(argument) : '';
	});

	return resultado;
}

/* Questão 23 */
meuFilter(mapIdTitle(), arg => arg.id % 2 === 0);

/* Questão 24 */
var array = mapIdTitle();
array.filter(elem => elem.rating > 1.0).map(elem => elem.id);

