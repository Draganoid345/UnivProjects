let squareButton = document.getElementById("square-button");
let halfButton = document.getElementById("half-button");
let percentButton = document.getElementById("percent-button");
let areaButton = document.getElementById("area-button");

squareButton.addEventListener("click", squareNumber);
halfButton.addEventListener("click", halfNumber);
percentButton.addEventListener("click", percentNumber);
areaButton.addEventListener("click", areaNumber);

function squareNumber(){
    let box = document.getElementById("square-input");
    let x = parseFloat(box.value);
    box.value = x * x;
}

function halfNumber(){
    let box = document.getElementById("half-input");
    let x = parseFloat(box.value);
    box.value = x * 0.5;
}

function percentNumber(){
    let box1 = document.getElementById("percent1-input");
    let x = parseFloat(box1.value);
    let box2 = document.getElementById("percent2-input");
    let y = parseFloat(box2.value);
    box2.value = (x * y) / 100.0;
}

function areaNumber(){
    let box = document.getElementById("area-input");
    let x = parseFloat(box.value);
    box.value = 3.14 * x * x;
}

let specialInput = document.getElementById("square-input");

specialInput.addEventListener('keypress', function (e){
    if (e.keyCode === 13){
        squareNumber();
    }
}, false);
