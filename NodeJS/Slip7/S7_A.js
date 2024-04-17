const http = require("http");
const url = require("url");
const fs = require("fs");
const PORT = 8000;

const fileName = "./index.html";
const fileData = fs.readFileSync(fileName);
const resultfileData = fs.readFileSync("./result.html");

http.createServer((req, res) => {
    res.writeHead(200, { "content-type": "text/html" });
    res.write(fileData);
    if (req.url != "/favicon.ico") {
        let args = url.parse(req.url, true).query;
        fs.appendFileSync(args.fileName2, fs.readFileSync(args.fileName1).toString());
    }
    res.end();
}).listen(PORT, () => {
    console.log(`Server Running At Port: ${PORT}`);
});