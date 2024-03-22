const mysql = require("mysql");
const readline = require("readline");
let rl = readline.Interface(process.stdin, process.stdout);

const makeConnection = () => {
    let conn = mysql.createConnection({
        host: "localhost",
        user: "root",
        password: "mysql",
        database: "account"
    });

    conn.connect((err) => {
        if (err) throw err;
    });

    return conn;
}

const withdraw = (acc_no, amt) => {
    let conn = makeConnection();
    let sql = `SELECT balance FROM customers WHERE c_id=${acc_no};`;
    conn.query(sql, (err, data) => {
        if (err) throw err;
        if (!data) {
            console.log(`Not Found`);
            return;
        }
        let balance = data[0].balance;
        if (balance <= 1000 || (balance - amt) < 1000)
            console.log(`Cannot Withdraw - Minimum Balance Required 1000`);
        else {
            let newBalance = balance - amt;
            let sql = `UPDATE customers SET balance = ${newBalance} WHERE c_id=${acc_no};`;
            conn.query(sql, (err, data) => {
                if (err) throw err;
                console.log(`Amount Withdrawn Successfully!`);
            });
        }
    });
}

const checkBalance = (acc_no) => {
    let conn = makeConnection();
    let sql = `SELECT balance FROM customers WHERE c_id=${acc_no};`;
    conn.query(sql, (err, data) => {
        if (err) throw err;
        if (!data) {
            console.log(`Not Found`);
            return;
        }
        console.log(`Balance In Your Account: ${data[0].balance}`);
    });
}

rl.question("Enter Account Number: ", (acc_no) => {
    rl.question("Enter 1 for Withdraw or Enter 2 to Check Balance: ", (option) => {
        if (option == 1) {
            rl.question("Enter Amount to Withdraw: ", (amt) => {
                withdraw(acc_no, amt);
                rl.close();
            });
        }
        else if (option == 2) {
            checkBalance(acc_no);
        }
    });
});