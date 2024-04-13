const mysql = require("mysql");
const express = require("express");
const app = express();
app.set("view engine", "ejs");

let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    port: 3306,
    database: "company"
});

conn.connect((err) => {
    if (err) throw err;
    console.log(`Connected to DB Successfully!`);
});

const exeQuery = (SQL, args) => {
    let arrayobj = [];
    let counter = 0;

    args.forEach((index) => {
        conn.query(SQL, index, (err, data) => {
            if (err) {
                console.error(err);
                return;
            }
            let obj = data[0];
            arrayobj.push(obj);
            counter++;

            if (counter === args.length) {
                console.log(arrayobj);
                app.get('/', (req, res) => {
                    res.render("index", { arrayobj });
                });
            }
        });
    });
}

let values = [101, 102, 103];
let sql = `SELECT d.dept_name,
avg(e.emp_salary) as avgSal,
max(e.emp_salary) as maxSal,
min(e.emp_salary) as minSal 
FROM emp e INNER JOIN dept d ON e.d_id = d.dept_id 
WHERE e.d_id = ?`;

exeQuery(sql, values);

app.listen(8080, () => {
    console.log(`Server Running on Port 8080`);
});

conn.end((err) => {
    if (err) throw err;
    console.log(`Connection Ended Successfully!`);
});