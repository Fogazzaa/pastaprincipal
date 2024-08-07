
// const terminal = require('prompt-sync')();

// let n1 = parseFloat(terminal('\nDigite um valor: ')); // terminal
// let n2 = parseFloat(terminal('\nDigite outro valor: ')); // terminal

// console.log('\nSoma: ', n1 + n2, '\n');

const terminal = require('prompt-sync')();

let n1 = parseFloat(terminal('\nDigite um valor: ')); // terminal
let n2 = parseFloat(terminal('\nDigite outro valor: ')); // terminal
let n3 = parseFloat(terminal('\nDigite outro valor: ')); // terminal

console.log('\nMédia: ', (n1 + n2 + n3) / 3, '\n');