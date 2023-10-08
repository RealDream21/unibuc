const express = require('express');
const app = express();

app.get('/ruta/:delay-:val', (req, res, next) => {
  const delay = req.params['delay'];
  setTimeout(() => {
    next();
  }, delay);
});

app.get('/ruta/:val', (req, res) => {
  res.send('Ruta fara delay');
});