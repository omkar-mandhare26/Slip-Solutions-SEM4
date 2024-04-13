const mysql = require("mysql");

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

const exeQuery = (SQL) => {
    conn.query(sql, (err, data) => {
        if (err) throw err;
        console.log(`Table Created Successfully!`);
    });
}

let sql = `CREATE TABLE dept(dept_id int,dept_name text,PRIMARY KEY(dept_id));`;
exeQuery(sql);

sql = `CREATE TABLE emp(emp_id int,emp_name text,emp_salary int,d_id int,PRIMARY KEY(emp_id),FOREIGN KEY (d_id) REFERENCES dept(dept_id));`;
exeQuery(sql);

conn.end((err) => {
    if (err) throw err;
    console.log(`Connection Ended Successfully!`);
})