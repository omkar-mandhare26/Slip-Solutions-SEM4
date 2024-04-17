const mysql = require("mysql");
const express = require("express");

let app = express();
app.set("view engine", "ejs");
app.use(express.static("./public"));
app.use(express.urlencoded({ extended: true }));

let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    database: "teacher_profile"
});

conn.connect((err) => {
    if (err) throw err;
    console.log("Connected to Database Successfully!");
});

let sql = `SELECT * FROM teachers;`;
conn.query(sql, (err, data) => {
    if (err) throw err;
    app.get("/", (req, res) => {
        res.render("index", { data: data });
    });
});

app.get('/insert', (req, res) => {
    res.render("insert");
})

app.post('/insert', (req, res) => {
    const { tid, tname, qualification, tsalary, department, experience } = req.body;
    console.log(req.body);
    sql = 'INSERT INTO teachers (t_id, t_name, qualif, salary, dept, exp) VALUES (?, ?, ?, ?, ?, ?)';
    conn.query(sql, [tid, tname, qualification, tsalary, department, experience], (err) => {
        if (err) throw err;
    });
    res.redirect("/");
});

app.post('/', (req, res) => {
    const key = req.body;
    console.log(key.primaykey);
    sql = `DELETE FROM teachers where t_id=${key.primaykey}`;
    conn.query(sql, (err) => {
        if (err) throw err;
        res.redirect("/");
    });
});

app.listen(8000, () => { console.log(`Server Running on Port 8000`); });