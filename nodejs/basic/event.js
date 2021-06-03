var events = require('events');
// EventEmitter 核心是事件出发与事件监听器功能的封装
var eventEmitter = new events.EventEmitter();

eventEmitter.on('delay_event', function(){
    console.log("delay event was invoked.");
});

setTimeout(function () {
    eventEmitter.emit('delay_event');
}, 3000);

var emitter = new events.EventEmitter();
var callback1 = function(arg1, arg2){
    console.log('listener1', arg1, arg2);
};
var callback2 = function (arg1, arg2){
    console.log('listener2', arg1, arg2);
};
var callback3 = function(arg1){
    console.log('listener3', arg1);
}
emitter.once('someEvent', callback1);
emitter.on('someEvent', callback2);
console.log(emitter.listenerCount('someEvent') + " 个监听器监听连接事件。");
emitter.emit('someEvent', 'Inger', 'Emitter1');
console.log(emitter.listenerCount('someEvent') + " 个监听器监听连接事件。");
// emitter.setMaxListeners(2);
emitter.removeListener('someEvent', callback2);
emitter.on('someEvent', callback3);
console.log(emitter.listenerCount('someEvent') + " 个监听器监听连接事件。");
emitter.emit('someEvent', 'Inger2', 'Emitter2')
emitter.emit('error', function(){
    console.log('error');
});
console.log("End");
