function tema1(){
    const elements = document.getElementsByTagName("li");
    const seasons = [...elements].map(element => element.innerText);
    for(let i = 0; i < elements.length; i++){
        const[season, emoji] = elements[i].innerText.split(" ");
        elements[i].innerText = `${emoji} Anotimpul ${i + 1} (urmat de ${seasons[(i + 1) % seasons.length]})`;  
    }
}

window.onload = tema1;