let n = prompt("Cate persoane sunt?");

let informatii = [];

for(let i = 0; i < n; i++){
  nume = prompt("Numele persoanei " + i);
  varsta = prompt("Varsta persoanei " + i);
  let tempobj = {name: nume, age: varsta};
  informatii.push(tempobj);
}


console.log(informatii);

let varstaMinima = prompt("Dati varsta minima");

let filteredInformatii = informatii.filter((element, index) => parseInt(element.age) > parseInt(varstaMinima));


if(filteredInformatii.length > 0){
  //alert(filteredInformatii.length + " persoane: ");
  toAlert = filteredInformatii.length + " persoane: "
  for(persoana of filteredInformatii){
    toAlert += persoana.name + " ";
    console.log(persoana);
  }
  alert(toAlert);
}
else{
  console.log("Nu exista persoane");
}

