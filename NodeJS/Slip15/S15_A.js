const word = "string";
const string = "This is string. This string includes word 'string' multiple times";

const findOccurrence = (str, word) => {
    let count = 0;
    let index = 0;

    while (index = str.indexOf(word, index) !== -1) {
        count++;
        index += word.length;
    }

    return count;
}

let result = findOccurrence(string, word);
// if (result == 0)
//     console.log(`Given word not found in string`);
// else
console.log(`Occurence of ${word}: ${result}`);