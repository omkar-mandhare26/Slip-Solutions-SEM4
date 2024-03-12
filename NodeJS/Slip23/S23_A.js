const fs = require("fs");
const searchWord = "word";
const replaceWord = "work";
const replace = `<b>${replaceWord}</b>`;
let fileName = "./sample.txt";

function updateFile(content) {
    let tempword = "";
    let count = 1;
    for (let i = 0; i < content.length; i++) {
        if (content[i] == " ") tempword = "";
        else {
            tempword = `${tempword}${content[i]}`;
            if (tempword == str) count++;
        }
    }

    console.log(`Count of word ${str} is ${count}`);
}

fs.readFile(fileName, (err, data) => {
    if (err) return console.log(err);
    count(data.toString(), word);
});
