const fs = require('fs');
const request = require('request');

const download = function (url, filename, callback) {
    request.head(url, function (err, res, body) {
        request(url).pipe(fs.createWriteStream(filename)).on('close', callback);
    });
};
download('https://www.google.com/images/srpr/logo3w.png', 'google.png', function () {
    console.log('done');
});

