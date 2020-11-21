const fs = require('fs');

function getNewData() {
    let obj = Object({});
    
    var data = fs.readFileSync('.stat');
    
    let i = 0;
    
    while ( data.toString('utf8').split('\n')[i]) {
        let dataArray = data.toString('utf8').split('\n')[i];
        let key = dataArray.split("=")[0];
        let value = dataArray.split("=")[1];
        obj[key] = value;
        i++;
    }
    return (obj);
}

module.exports = getNewData;