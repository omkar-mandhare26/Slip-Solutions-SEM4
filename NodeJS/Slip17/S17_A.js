const express = require('express');
const app = express();
const PORT = 8000;

app.get("/", (req, res) => { res.write(`Go to /download`); });

app.get('/download', (req, res) => {
    const fileName = './sample.txt';

    res.download(fileName, (err) => {
        if (err) {
            res.status(404).send('File not found');
        }
    });
});

app.listen(PORT, () => {
    console.log(`Server is running on Port ${PORT}`);
});