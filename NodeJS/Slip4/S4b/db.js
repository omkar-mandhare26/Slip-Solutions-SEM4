const mysql = require("mysql");
const createConn = () => {
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
}

const getData = () => {
    let sql = `SELECT * FROM teachers;`;
    conn.query(sql, (err, data) => {
        if (err) throw err;
        console.log(data);
    });
}