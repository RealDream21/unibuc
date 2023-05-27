function MyFunc(){
    const n = Math.floor(5 + Math.random() * 5);
    console.log(n);

    const unde = document.getElementById('patrate');

    for(let i = 0; i < n; i++){
        let newDiv = document.createElement('div');
        newDiv.className = 'patrat';

        newDiv.addEventListener('click', (e) => {
            e.preventDefault();
            let stil = getComputedStyle(newDiv);
            let stanga = parseInt(stil.marginLeft);
            stanga += 10;
            newDiv.style.setProperty('margin-left', stanga.toString() + 'px');
            console.log(newDiv.style.marginLeft);
        });
        unde.appendChild(newDiv);
    }
}

window.onload = () => {
    MyFunc();
    document.addEventListener('click', (e) => {
        if(e.target.tagName == 'SECTION' || e.target.tagName == 'HTML'){
            const patrate = document.querySelectorAll('.patrat');
            for(patrat of patrate){
                patrat.style.marginLeft = 0;
            }
        }
    });
}