let body = document.getElementsByTagName("body");

body = body[0];

body.style["font-family"] = "arial, sans-serif";

let nickname = document.getElementById("nickname");
nickname.innerText = "Costel";

let favorites = document.getElementById("favorites");
favorites.innerText = "HTML & CSS";

let hometown = document.getElementById("hometown");
hometown.innerText = "Chisinau";

let myulist = document.getElementById("myulist");
let listItems = myulist.getElementsByTagName("li");

for (let i=0; i<listItems.length; i++){
    listItems[i].setAttribute("class", "list-item");
}

let img = document.createElement("img");
img.setAttribute("src", "https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRN0TyKB-bciZuiyX5ZzJyKGhLSjAPh-ZrUkhr6WJXJzY0qkteE&usqp=CAU");

body.appendChild(img);