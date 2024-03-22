const http = require("http");
const url = require("url");
const fs = require("fs");
const mysql = require("mysql");
const PORT = 8000;
const indexFile = "./index.html";
const changePWFile = "./pwreset.html";

http.createServer((req, res) => {
    if (req.url == 'favicon.ico') res.end();
    if (req.url == "/") {
        res.writeHead(200, { "Content-Type": "text/html" });
        res.write(fs.readFileSync(indexFile));
        res.end();
    }
    else if (req.url == "/pwreset") {
        res.writeHead(200, { "Content-Type": "text/html" });
        res.write(fs.readFileSync(changePWFile));
        res.end();
    }
    else if (req.url == "/result") {
        res.writeHead(200, { "Content-Type": "text/html" });
        res.write("Hello");
        let args = url.parse(req.url, true).query;
        console.log(args);
        res.end();
    }
}).listen(PORT, () => { console.log(`Server Running on Port ${PORT}`); });

const changePW = (username, newpw) => {
    let conn = mysql.createConnection({
        host: "localhost",
        user: "root",
        password: "mysql",
        database: "user_login_system"
    });

    conn.connect((err) => {
        if (err) throw err;
        console.log(`Connected To DB Successfully!`);
        let sql = `SELECT * FROM user;`;
    });
}