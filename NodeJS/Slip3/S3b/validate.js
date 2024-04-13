const validateName = (name) => {
    let regex = /^[a-zA-Z]+$/;
    return regex.test(name);
}

const validateEmail = (email) => {
    let atCount = 0, dotCount = 0;
    for (let i = 0; i < email.length; i++) {
        if (email[i] == '@') atCount++;
        else if (email[i] == '.') dotCount++;
    }
    if (atCount > 1 || dotCount > 2) return false;
    else return true;

    let emailEndings = ["com", "gov", "org", "net"];
    emailEndings.forEach(e => {
        if (!(e.test(email.substring(email.length - 3)))) return false;
    });
    return true;

}
let r = validateEmail("omkar@gmail.xyz");
console.log(r);
// module.exports = { validateName };