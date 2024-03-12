const fs = require("fs");
let dirname = "tempdir";
let fileName = "temp.txt";
let data = "Temp file created";
fs.mkdir(dirname, (err) => {
    if (err) return console.log(err);
    console.log("Directory created successfully");
    fs.writeFile(`./${dirname}/${fileName}`, data, (err) => {
        if (err) return console.log(err);
        console.log(data);
    })
})