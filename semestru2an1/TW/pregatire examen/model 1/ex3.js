function myFunc () {
    const input =  document.getElementById('date');
    const d = new Date();
    let text = d.toDateString();
    input.setAttribute('value', text);
    const culori = document.getElementById('culori');

    let ultima = JSON.parse(localStorage.getItem('lastColor'));
    if(ultima)
        input.style.color = ultima
    else
        input.style.color = culori.value;
    
    let culoricycle = [];
    for(let i = 0; i < culori.length; i++){
        culoricycle.push(culori[i].value);
    }
    let cnt = 0;

    document.addEventListener(('keypress'), () =>{
        if(event.key == 's'){
            clearInterval(myinterval);
            console.log('logged s');
        }
    });

    let myinterval = setInterval(() =>{
        cnt = (cnt + 1) % culoricycle.length;
        input.style.color = culoricycle[cnt];
        localStorage.setItem('lastColor', JSON.stringify(input.style.color));
    },3000);

    culori.addEventListener('change', () =>{
        input.style.color = culori.value;
        localStorage.setItem('lastColor', JSON.stringify(input.style.color));
    });

}

window.onload = () => {
    myFunc();
}