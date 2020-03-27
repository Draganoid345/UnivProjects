function getCartValue(cart){
    var sum = 0;
    for (var key in cart){
        sum += parseFloat(cart[key]);
    }
    return sum;
}

// Input
var blackFridayCart = {
    telefon: "350",
    consola: "250",
    televizor: "450",
    iepurasPlus: "10.60",
    cercei: "20.34",
    geanta: "22.36"
  };
  
  // Output
//   getCartValue(blackFridayCart); // 1103.3

console.log(getCartValue(blackFridayCart));