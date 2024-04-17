const functions = require('./A_Module');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter First Name: ", (fname) => {
    rl.question("Enter Last Name: ", (lname) => {
        rl.question("Enter You DOB: ", (dob) => {
            console.log(`Full Name: ${functions.concat(fname, lname)}`);
            console.log(`Age: ${functions.calculate_age(dob)}`);
            rl.close();
        });
    });
});