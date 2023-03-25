let persoane = []
let informatiiPersoane = []


function getInfo(){
    let persoana = new Object();
    persoana.numePrenume = prompt("Introduceti numele si prenumele");
    
    persoana.cnp = prompt("Introduceti cnp");
    const reg_cnp = new RegExp('[1-9][0-9]{12}')

    if(!reg_cnp.test(persoana.cnp)){
        alert("CNP-ul este gresit!");
        return;
    }

    persoana.dataNasterii = prompt("Introduceti data nasterii in formatul (DD/MM/YYYY)");
    const reg_DataNasterii = new RegExp('[0-3][0-9]/[0-1][0-9]/[0-9][0-9][0-9][0-9]')

    if(!reg_DataNasterii.test(persoana.dataNasterii)){
        alert("Data nasterii este gresita!");
        return;
    }

    persoane.push(persoana);
    informatiiPersoane.push(writePersonInfo(persoana));
}

function writePersonInfo(persoana){
    to_return = `Persoana ${persoana.numePrenume}, nascuta la data de ${persoana.dataNasterii} are CNP-ul: ${persoana.cnp}`
    return to_return;
}

function showInfo(){
    const at_section = [...document.querySelectorAll("body section")];
    const pos_lista = at_section[0];
    const list = document.createElement("ol");
    //pos_lista.append(list);
    for (persoana of informatiiPersoane){
        const list_element = document.createElement("li");
        list_element.innerHTML = persoana;
        list.append(list_element)
    }
    pos_lista.append(list);

}

window.onload = function(){
    const button = document.getElementById('buton-adaugare')
    const buttonAfisare = document.getElementById('buton-afisare-informatii')
    button.onclick = () => {
        getInfo();
    }
    buttonAfisare.onclick = () =>{
        showInfo();
    }
}
