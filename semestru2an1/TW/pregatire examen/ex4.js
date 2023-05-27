const cities = [
    {
      nume: "Aa",
      populatie: 14000,
      capitala: true
    },
    {
      nume: "Bb",
      populatie: 7000,
      capitala: false
    },
    {
      nume: "Cc",
      populatie: 19000,
      capitala: false
    },
    {
      nume: "Dd",
      populatie: 5000,
      capitala: false
    },
    {
      nume: "Ee",
      populatie: 8000,
      capitala: true
    },
    {
      nume: "Ff",
      populatie: 12000,
      capitala: false
    },
    {
      nume: "Gg",
      populatie: 20000,
      capitala: true
    }
  ]

const express = require('express');
const app = express();

app.get('/', function(req, res){
    res.sendFile('C:/Users/Fabi/Desktop/unibuc folder/unibuc/semestru2an1/TW/pregatire examen/ex4.html');
});

app.post('/', (req, res) =>{

    console.log(req.body);
    const {dimensiune, tip_oras} = req.body;
    console.log(dimensiune);

    res.send('sal');
});



app.listen(3000);