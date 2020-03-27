function multiplicator(element) {
    return 2 * element;
}

Array.prototype.myMap = function(callbackFunction) {
  let newArray = [];
  for (var i=0; i<this.length; i++){
      newArray.push(this[i] * 2);
  }
  return newArray
}

Array.prototype.map = function(callbackFunction) {
    let newArray = [];
    for (var i=0; i<this.length; i++){
        newArray.push(callbackFunction(this[i]));
    }
    return newArray
  }

var arr = [1, 2, 3];
console.log(arr);
console.log(arr.myMap(multiplicator));