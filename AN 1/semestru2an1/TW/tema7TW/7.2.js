function afisareImagini() {
    var body = document.getElementsByTagName("body")[0];
    var nume_img = "image";
    var images = [];

    for (let i = 1; i <= 3; i++) {
        var img = document.createElement("img");
        img.style.width = "250px";
        img.style.height = "250px";
        img.src = nume_img + i + ".jpg";
        img.style.display = "inline-block";
        console.log(img.src);
        body.appendChild(img);
        images.push(img);
    }

    setTimeout(function() {
        for (var i = 0; i < images.length; i++) {
            body.removeChild(images[i]);
        }
        images = [];
    }, 3000);
}
