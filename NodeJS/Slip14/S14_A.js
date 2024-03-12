import http from "http"
import fs from "fs"
import url from "url"

const PORT = 8000;
const indexFile = "./index.html";
const fileName = "./searchFile.txt";

let findWord = (word) => {
    let data = fs.readFileSync(fileName);
    return data.indexOf(word);
};

http.createServer((req, res) => {
    res.writeHead(200, { "content-type": "text/html" });
    res.write(fs.readFileSync(indexFile));
    if (req.url != '/favicon.ico') {
        let searchword = url.parse(req.url, true).query.findWord;
        let result = findWord(searchword)
        if (result == -1)
            console.log("Word not found in file");
        else
            console.log(`Word found in file at index ${result}`);
    }
    res.end();
}).listen(PORT, () => { console.log(`Server Running at Port ${PORT}`); });