let arr = [1, 2, [3,4], 5, [6,7], [1,2,3,4], 12345];

function myFlatten(toFlatten){
  let aux = toFlatten.reduce((acc, el) =>{
    if(Array.isArray(el) == true){
      for(var element of el){
        acc.push(element);
      }
    }
    else {
      acc.push(el);
    }
    return acc;
  }, []);
  return aux;
}

arr = myFlatten(arr);
console.log(arr);