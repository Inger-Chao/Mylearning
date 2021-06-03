var fs = require('fs')
// 阻塞代码
// var data = fs.readFileSync('input.txt')
// console.log(data.toString());

fs.readFile('input.txt', function(err, data){
    if(err){
        console.error(err);
        return;
    }
    console.log(data.toString());
});
console.log("End");

