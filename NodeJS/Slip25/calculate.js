async function division(num1, num2) {
    if (num2 == 0) return Promise.reject("Cannot Divide By Zero");
    else
        return Promise.resolve(num1 / num2);
}

async function wait() { return Promise.resolve([10, 0]) };

async function cal() {
    try {
        let nums = await wait();
        let result = await division(nums[0], nums[1]);
        console.log(result);
    } catch (err) { console.log(err); }
}
cal();


/*
division(5, 0).then((data) => {
    console.log(data);
}).catch((err) => {
    console.log(`Error: ${err}`);
});
*/