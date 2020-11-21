var express = require('express');
var app = express();
var cors = require('cors');
var getNewData = require('./Parser');
const { exec } = require('child_process');

app.get('/api/test', async function (req, res) {
  exec('../stats_sys/SaveData', (err, stdout, stderr) => {
    if (err) 
      return;
  });
  console.log('GET /api/test');
  res.header("Access-Control-Allow-Origin", "*");
  res.json(getNewData());
});

app.use(cors());
app.use(express.json())
app.use(express.urlencoded({ extended: true }));
app.listen(4000);
