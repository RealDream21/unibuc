function LoadDivs() {
    const locDivuri = document.getElementById('dreptunghiuri');
    for(let i = 0; i < 10; i++){
        let newDiv = document.createElement('div');
        newDiv.className = 'dreptunghi';
    
        locDivuri.appendChild(newDiv);

        var elem, style;
        elem = document.querySelector('.dreptunghi');
        style = getComputedStyle(elem);

        newDiv.addEventListener('click', () =>{
            event.preventDefault();
            newDiv.style.height = '60px';
        });
    }
    document.addEventListener('click', (e) =>{
        if(e.target.tagName == 'HTML'){
            for(let i = 0; i <= locDivuri.childElementCount; i++){
                var declaration = locDivuri.childNodes[i].style;
                if(declaration){
                    declaration.setProperty("height", "50px");
                }
            }
        }
    })
}


window.onload = () =>{
    LoadDivs();
}