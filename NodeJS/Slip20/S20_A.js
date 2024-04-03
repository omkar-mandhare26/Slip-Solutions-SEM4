const fs = require("fs");
const events = require("events");
const fileName = "./sample.txt";
const EventEmitter = new events.EventEmitter();

EventEmitter.on('readFile', () => {
    fs.readFile(fileName, (err, data) => {
        if (err) console.log(`Error While Reading File`);
        else console.log(`File Content:\n${data}`);
    });
});

EventEmitter.emit('readFile');