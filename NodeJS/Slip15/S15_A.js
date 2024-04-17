const word = "string";
const string = "This is string. This string includes word 'string' multiple times";

const findOccurrence = (str, word) => {
    let count = 0;
    let strArr = str.split(" ");
    for (let i = 0; i < strArr.length; i++) {
        if (word == strArr[i])
            count++;
    }
    console.log(count);

    return 0;
}
findOccurrence(string, word);