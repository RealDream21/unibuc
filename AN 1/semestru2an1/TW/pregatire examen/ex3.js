function MyFunc() {
    const whereButoane = document.getElementById('butoane');

    for(let i = 0; i <= 9; i++){
        let newButton = document.createElement('button');
        newButton.innerHTML = i.toString();
        whereButoane.appendChild(newButton);
    }
}

function ApasareTasta(){
    document.addEventListener('keypress', (e) =>{
        if(e.key >= 0 && e.key <= 9){
            const culoareSelectata = document.getElementById('culoare').value;
            
            const butoane = document.getElementById('butoane');

            let toChange = [];
            for(let i = 0; i <= 9; i++){
                if(i % 2 == e.key % 2){
                    toChange.push(butoane.childNodes[i]);
                }
            }
            setInterval(() => {
                try{
                    toChange[toChange.length - 1].style.backgroundColor = culoareSelectata;
                    toChange.pop();
                }
                catch(err){
                    return;
                }
            },3000);
        }
    });
}

window.onload = () => {

    let MyCuloare = JSON.parse(localStorage.getItem('lastCuloare'));
    if(MyCuloare){
        document.querySelector('body').style.backgroundColor = MyCuloare;

    }
    MyFunc();
    ApasareTasta();
    document.getElementById('culoare').addEventListener('change', () => {
        const inputCuloare = document.getElementById('culoare');
        let lastColor = inputCuloare.value;
        localStorage.setItem('lastCuloare', JSON.stringify(lastColor));
    });
}