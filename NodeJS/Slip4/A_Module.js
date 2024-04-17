function concat(fname, lname) {
    return `${fname} ${lname}`;
}

function calculate_age(dob) {
    const birthDate = new Date(dob);
    const currentDate = new Date();
    age = currentDate.getFullYear() - birthDate.getFullYear();

    if (birthDate.getMonth() > currentDate.getMonth()) age--;
    else if ((birthDate.getMonth() == currentDate.getMonth()) && (birthDate.getDate < currentDate.getDate())) age--;

    return age;
}

module.exports = { concat, calculate_age };