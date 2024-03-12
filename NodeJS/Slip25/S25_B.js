const fs = require('fs');

const JSON_Data = JSON.parse(fs.readFileSync("./events.json"));

const currentDay = new Date().toLocaleString('en', { weekday: 'long' });

let meetings = JSON_Data.filter((data) => { return data.day === currentDay })

console.log("Today's Meeting: ");
meetings[0]["event"].forEach(event => {
    console.log(event);
});