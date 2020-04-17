let filme = [
    {
        nume: 'Tom and Jerry',
        durata: 1000,
        actori: [
            'Tom',
            'Jerry',
            'Bunicuta'
        ],
        vizionat: false
    },
    {
        nume: 'Tom and Jerry 2',
        durata: 1000,
        actori: [
            'Tom',
            'Jerry',
            'Bunicuta'
        ],
        vizionat: true
    },
    {
        nume: 'Tom and Jerry 3',
        durata: 1000,
        actori: [
            'Tom',
            'Jerry',
            'Bunicuta'
        ],
        vizionat: true
    }
]

let body = document.getElementsByTagName("body")[0];

for (let i=0; i<filme.length; i++){
    let paragraph = document.createElement("p");
    paragraph.innerText = filme[i].nume;
    if (filme[i].vizionat){
        paragraph.setAttribute("class", "seen");
    }
    else{
        paragraph.setAttribute("class", "not-seen");
    }
    body.appendChild(paragraph);
}