import http from "http";
import fs from "fs";
import url from "url";
const PORT = 8000;
const indexFile = "./index.html";

http.createServer((req, res) => {
    res.writeHead(200, { "content-type": "text/html" });
    res.write(fs.readFileSync(indexFile));
    res.end();
}).listen(PORT, () => { console.log(`Server Running at Port ${PORT}`); });