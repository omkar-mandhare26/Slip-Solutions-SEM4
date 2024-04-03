const EventEmitter = require('events');
const uptimeEmitter = new EventEmitter();

uptimeEmitter.on('uptime', (seconds) => {
    let min = 0;
    if (seconds >= 60) {
        seconds = math.floor(seconds % 60);
        min = math.floor(seconds / 60);
    }
    console.log(`Application uptime: ${min}:${seconds}`);
});

function emitUptime() {
    setInterval(() => {
        const seconds = process.uptime();
        uptimeEmitter.emit('uptime', seconds);
    }, 5000);
}

emitUptime();