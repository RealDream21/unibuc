function generateBox(i){
    const w = window.innerWidth
    const h = window.innerHeight
    function randPos(limit){
        return Math.random()*(limit-50)
    }
    const div = document.createElement("div")
    div.style.width="50px"
    div.style.height="50px"
    div.style.position="absolute"
    div.style.top=randPos(h) + "px"
    div.style.left=randPos(w) + "px"
    div.style.border="1px solid black"

    div.innerText = i
    document.body.append(div)
}

function m1(){
    for(let i = 0; i < 100; i++)
    {
        setTimeout(() => {
            [3*i+1, 3*i+2, 3*i+3].forEach(generateBox)
        },2000*(i+1))
    }
}

function m2(){
    let i=0
    let intervalId= setInterval(() => {
        [3*i+1, 3*i+2, 3*i+3].forEach(generateBox)
        i++
        if(i>4){
            clearInterval(intervalId)
        }
    },2000)
}

window.onload = m1
//window.onload = m2