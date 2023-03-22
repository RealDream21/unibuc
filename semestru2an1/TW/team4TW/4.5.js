let altaTraducere = true;
let dict = {"acesta" : "this", "este": "is", "un": "a", "dictionar" : "dictionary", "glorios" : "glorious", "fascinat":"fascinated"};
while(altaTraducere){
  let phraseToTranslate = prompt("Dati fraza care trebuie tradusa").split(" ");
  let translate = "";
  for(cuvant of phraseToTranslate){
    if(Object.keys(dict).includes(cuvant)){
      translate += dict[cuvant] + " ";
    }
    else {
      translate += cuvant + "? ";
    }
  }
  let translation = ""
  alert(translate);
  let mesajAltaTraducere = prompt("Mai doriti o traducere? (DA/NU)")
  if(mesajAltaTraducere == "DA"){
    altaTraducere = true;
  }
  else{
    altaTraducere = false;
  }
}