const mysql = require("mysql");
const http = require("http");
const PORT = 8000;

let conn = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "mysql",
    database: "emp_data"
});

conn.connect((err) => {
    if (err) throw err;
    console.log(`Connected To DB Successfully!`);

    let sql = `SELECT * FROM employees ORDER BY salary DESC;`;
    conn.query(sql, (err, data) => {
        if (err) throw err;
        http.createServer((req, res) => {
            if (req.url == "favicon.ico") res.end();
            if (req.url == '/') {
                res.write(table(data));
                res.end();
            }
        }).listen(PORT, () => {
            console.log(`Server Running on Port ${PORT}`);
        });
    });
});


function table(data) {
    let content = `<table border=1>
    <tr>
        <th>Employee ID</th>
        <th>Employee Name</th>
        <th>Employee Salary</th>
    </tr>
    `;

    for (let i = 0; i < data.length; i++) {
        content += `
        <tr>
            <td>${data[i].e_id}</td>
            <td>${data[i].e_name}</td>
            <td>${data[i].salary}</td>
        </tr>
        `;
    }
    content += `</table>`;
    return content;
}