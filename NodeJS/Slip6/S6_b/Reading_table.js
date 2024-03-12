import mysql from "mysql";

let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    database: "emp_data"
});

conn.connect((err) => {
    if (err) throw err;

    conn.query("SELECT * FROM student", (err, data) => {
        if (err) throw err;

        console.log(data);
    })
})