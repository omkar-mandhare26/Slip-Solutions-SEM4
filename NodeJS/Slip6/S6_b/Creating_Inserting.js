import mysql from "mysql";

let rno = [1, 2, 3, 4, 5];
let names = ["Omkar", "Vedant", "Ved", "Aarush", "Martin"];
let classes = ["SY", "TY", "FY", "SY", "FY"];


let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    database: "emp_data"
})

conn.connect((err) => {
    if (err) throw err;
    console.log("Connected to DB Successfully!");

    let createTable = "CREATE TABLE student(rollno int, sname text,sclass text,PRIMARY KEY(rollno));";
    conn.query(createTable, (err, data) => {
        if (err) throw err;
    });

    let values = [];
    for (let i = 0; i < rno.length; i++) {
        values.push([rno[i], names[i], classes[i]]);
    }

    const insertData = `INSERT INTO student(rollno, sname, sclass) VALUES ?`;
    conn.query(insertData, values, (err, data) => {
        if (err) throw err;
    });

});