var events = require('events');
var eventEmitter = new events.EventEmitter();

var connectHandler = function connected() {
    console.log('connect success');
    eventEmitter.emit('data_received');
}
// connection event -> connectHandler
eventEmitter.on('connection', connectHandler);
// eventEmitter.on('connection', function(){
//     console.log('connect success');
//     eventEmitter.emit('data_received');
// })

// data_received -> listener
eventEmitter.on('data_received', function(){
    console.log('receive data successfully');
})

eventEmitter.emit('connection');

console.log('end');