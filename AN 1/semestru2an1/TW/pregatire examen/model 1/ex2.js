function renderParagrafe () {
    var now = new Date();
    var minutes = now.getMinutes();
    const N = Math.max(10, minutes);
    const clase = ['c1', 'c2', 'c3', 'c4', 'c5'];
    const prenume = "Fabian-Andrei";

    const sectiune = document.getElementById('paragrafe');

    for(let i = 0; i < N; i++){
        let randomClass = Math.floor(Math.random() * clase.length);
        
        let newP = document.createElement('p');
        newP.classList.add(clase[randomClass]);
        newP.className = clase[randomClass];
        newP.textContent = prenume;
        newP.addEventListener('click', ()=>{
            toRemove = [];
            for(let i = 0; i < [...sectiune.children].length; i++){
                if(sectiune.childNodes[i].className == newP.className){
                    toRemove.push(sectiune.childNodes[i]);
                }
            }
            for(let i = 0; i < toRemove.length; i++)
                sectiune.removeChild(toRemove[i]);
        });
        sectiune.appendChild(newP);
    }
}

window.onload = () => {
    renderParagrafe();
}