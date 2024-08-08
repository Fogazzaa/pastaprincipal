
const terminal = require('prompt-sync')();

let n1 = parseFloat(terminal('\nDigite um valor: ')); // terminal

if(n1 % 2 === 0){
    console.log('\nO número ', n1, 'é par\n');
}
if(n1 % 2 === 1){
    console.log('\nO número', n1, 'é impar\n');
}