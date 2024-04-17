function validateDOB(dob) {
    let today = new Date();
    let DOB = new Date(dob);
    let age = today.getFullYear() - DOB.getFullYear();
    if (today.getMonth() == DOB.getMonth() && DOB.getDate() < today.getDate())
        age--;
    // return age < 18;
    if (age < 18)
        return 0;
    else
        return 1;
}

function isDateValid(dateStr) {
    let date = new Date(datestr);
    if (isNaN(date))
        return 1;
    else
        return 0;
    // return isNaN(new Date(dateStr));
}

function validateSalary(salary) {
    // return salary <= 0;
    if (salary >= 0)
        return 1;
    else
        return 0;
}

function validate() {
    // for class .classname
    const dob = document.querySelector("#dob").value;
    const joiningDate = document.querySelector("#joiningDate").value;
    const salary = document.querySelector("#salary").value;

    if (validateDOB(dob))
        alert("Age Should be at least 18 years");

    if (isDateValid(joiningDate))
        alert("Enter Valid Joining Date");

    if (validateSalary(salary))
        alert("Salary Should be greater than 0");
}