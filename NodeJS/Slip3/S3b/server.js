const validate = require("./validate");
const path = require('path');
const express = require("express");
const app = express();
const PORT = 8000;

app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
    const filePath = path.join(__dirname, 'index.html');
    res.sendFile(filePath);
});

app.post("/", (req, res) => {
    let data = req.body;
    console.log(data);
    console.log(validate.validateName(data.name));
    res.send("hii");
});

app.listen(PORT, () => { console.log(`Server Running on Port ${PORT}`); });
