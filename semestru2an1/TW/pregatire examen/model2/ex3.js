function MyFunc() {
    const numarFormular = document.getElementById('numar').value;

    const paragrafe = document.querySelectorAll('p');

    toRemove = [];

    for (paragraf of paragrafe){
        let text = paragraf.innerHTML.split(" ");
        console.log(text.length);
        if(text.length > numarFormular)
            toRemove.push(paragraf);
    }
    console.log(toRemove);

    const corp = document.getElementById("continut");
    corp.removeChild(toRemove[0]);
    let k = 0;
    setInterval(() =>{
        if(toRemove){
            corp.removeChild(toRemove[toRemove.length - 1]);
            toRemove.pop();
            k++;
        }
        localStorage.setItem('last', JSON.stringify(k));
    }, 1000);
}

window.onload = () => {
    let lastNumber = 0;
    try{
        lastNumber = JSON.parse(localStorage.getItem('last'));
    }
    catch(erro){
        lastNumber = 0;
    }
    document.getElementById("numar").value = lastNumber;


    document.addEventListener("keypress" , (e) =>{
        if(e.key == 's')
            MyFunc();
    })
}