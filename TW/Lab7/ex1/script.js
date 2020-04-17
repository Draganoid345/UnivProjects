let button = document.getElementById("story-button");

button.addEventListener("click", makeStory);

function makeStory(){
    let str = "";
    let aux = document.getElementById("person");
    str += aux.value;
    str += " a vizitat ";
    aux = document.getElementById("adjective");
    str += aux.value;
    str += " ";
    aux = document.getElementById("places");
    str += aux.value;
    
    let story = document.getElementById("story");
    story.innerText = str;
}