import mysql from "mysql";

let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    database: "emp_data"
});

conn.connect((err) => {
    if (err) throw err;
    console.log("DB Connected Successfully!");

    let SQL = "CREATE TABLE customers(id int,c_name text,c_contactNo int,c_emailId text,PRIMARY KEY(id));"
    conn.query(SQL, (err, data) => {
        if (err) throw err;
        console.log("customers Table Created Successfully!");
    });
});

