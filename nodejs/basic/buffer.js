// Buffer 类：用于创建一个存放二进制数据的缓存区
// 位于 Node 内核
/*
node 支持的字符编码：ascii, utf8, utf18le...8 种
 */
// allocate
// const: read only variable, must be initialized
// var: 全局变量
// let: 局部变量，可以不初始化
const buf1 = Buffer.alloc(10);
const buf2 = Buffer.alloc(11, 1);
// allocUnsafe faster than allocate, but the returned buffer may contain older data
// that needs to overwrite by fill() or write().
const buf3 = Buffer.allocUnsafe(12);
const totalLength = buf1.length + buf2.length + buf3.length;
console.log(totalLength)
const bufA = Buffer.concat([buf1, buf2, buf3], totalLength);
console.log(bufA);

buf3.fill('h');
console.log(buf3.toString());

// Buffer.from(array<integer[]>): allocates a new buffer using an array of bytes in the range 0-255.
const buf4 = Buffer.from([0x1, 0x75, 0x3]);
console.log(buf4);
const buf5 = Buffer.from("string");
console.log(buf5.toString())
buf5[0] = 0x61;
console.log(buf5.toString());

const arr = new Uint16Array(2);
arr[0] = 1;
arr[1] = 2;
// buf6 shares the memory with arr
const buf6 = Buffer.from(arr.buffer);
console.log(buf6);
arr[1] = 3;
console.log(buf6);

const ab = new ArrayBuffer(10);
const buf7 = Buffer.from(ab, 4, 4);
console.log("the length of buffer: " + buf7.length + ", the length of ArrayBuffer: " + ab.byteLength);
const buf8 = Buffer.from('7468697320697320612074c3a97374', 'hex');
console.log(buf8.toString('latin1'));
console.log(buf8.indexOf('is'));

const buf9 = Buffer.from('buffer');

console.log("=====entries()======")
for(const pair of buf9.entries()){
    console.log(pair);
}

console.log("=====keys()======")
for(const key of buf9.keys()){
    console.log(key);
}

const json = JSON.stringify(buf4);
console.log(json);
const copy = JSON.parse(json, (key, value) => {
    return value && value.type == 'Buffer'?
        Buffer.from(value.data) :
        value;
});

console.log(copy);