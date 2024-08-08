
const terminal = require('prompt-sync')();

let celsius = parseFloat(terminal('\nDigite a temperatura em celsius: ')); // terminal

fahrenheit = ((celsius * 9/5) + 32);

console.log('\nA temperatura em fahrenheits: ', fahrenheit, '\n');

