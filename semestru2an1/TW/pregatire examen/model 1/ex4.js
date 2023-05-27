const people = [
    {
      "nume": "Ion",
      "sex": "m",
      "varsta": 3
    },
    {
      "nume": "Oana",
      "sex": "f",
      "varsta": 23
    },
    {
      "nume": "Daria",
      "sex": "f",
      "varsta": 10
    },
    {
      "nume": "Mihai",
      "sex": "m",
      "varsta": 19
    },
    {
      "nume": "Gabriel",
      "sex": "m",
      "varsta": 22
    },
    {
      "nume": "Simona",
      "sex": "f",
      "varsta": 11
    },
    {
      "nume": "Bogdan",
      "sex": "m",
      "varsta": 28
    }
  ]

function VerifyFunc() {
    const formular = document.querySelector('form');
    formular.addEventListener('submit', () => {
        event.preventDefault();
        const dateFormular = new FormData(formular);
        const nume = dateFormular.get('nume');
        let found = false;
        for(let i = 0; i < people.length; i++){
            if(people[i]["nume"] == nume){
                if(people[i]["varsta"] < 18){
                    let newP = document.createElement('p');
                    newP.innerText = `${nume} este minor`;
                    document.getElementById('raspunsuri').appendChild(newP);
                }
                else{
                    let newP = document.createElement('p');
                    newP.innerText = `${nume} este major`;
                    document.getElementById('raspunsuri').appendChild(newP);
                }
                found = true;
            }
        }
        if(found == false)
            alert('Nu a fost gasita persoana');
    });
}

window.onload = () => {
    VerifyFunc();
}