function addInfo(info ,...classes){
    const articles = [...document.querySelectorAll("article article")];
    utilities.forEach(element => {
        const p = document.createElement("p");
        p.innerText = info;
        p.className = classes.join(" ");
        element.append(p);
    });
}

window.onload = function(){
    addInfo('text', 'cls1', 'cls2');
}