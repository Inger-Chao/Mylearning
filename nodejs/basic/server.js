var http = require("http");
// listen 绑定端口
http.createServer(function (request, response) {

  response.writeHead(200, {'Content-Type': 'text/plain'});
  response.end("Hello World");
}).listen(4396);
// 控制台 log
console.log('Server running at http://127.0.0.1:4396/');
