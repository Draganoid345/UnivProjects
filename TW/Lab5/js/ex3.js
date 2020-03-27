var film = {
    nume: 'Tom and Jerry',
    durata: 1000,
    actori: [
        'Tom',
        'Jerry',
        'Bunicuta'
    ]
}

function afis(movie){
    var str = movie.actori.join(', ');
    console.log('"' + movie.nume + '" a durat ' + movie.durata + '. Actori: ' + str);
}

afis(film);