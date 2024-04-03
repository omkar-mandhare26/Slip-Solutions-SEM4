const word = "string";
const string = "This is string. This string includes word 'string' multiple times";

const findOccurrence = (str, word) => {
    let count = 0;
    let strArr = str.split(" ");
    for (let i = 0; i < strArr.length; i++) {
        if (word == strArr[i])
            count++;
    }

    // console.log(strArr);
    console.log(count);

    return 0;
}
// const findOccurrence = (str, word) => {
//     let count = 0;
//     let index = 0;

//     while (index = str.indexOf(word, index) !== -1) {
//         count++;
//         index += word.length;
//     }

//     return count;
// }
findOccurrence(string, word);
// let result = findOccurrence(string, word);
// console.log(`Occurence of ${word}: ${result}`);