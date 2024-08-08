
const terminal = require('prompt-sync')();

let nota = parseFloat(terminal('\nDigite uma nota: ')); // terminal

    if(nota >= 0 && nota <= 3.9){
        console.log('\nReprovado\n');
    }
    else if(nota >= 4 && nota <= 5.9){
        console.log('\nRecuperação\n');
    }
    else if(nota >= 6 && nota <= 10){
        console.log('\nAprovado\n');
    }
