
const tamanho = 10;

let numeros = [1,2,3,4,5,6,7,8,9,10];

for (let i = 0; i < numeros.length; i++){ // 'for' passando por todas as posições

    num = numeros[i];

 if (num % 2 === 0){
    console.log('o numero '+num+' é par');
    }

 if (num % 2 === 1){
    console.log('o numero '+num+' é impar');
    }
}

// for (let i = 0; i < numeros.length; i++){ // 'for' passando por todas as posições

//  if (numeros[i] % 2 === 0){
//     console.log('o numero '+num+' é par');
//     }

//  if (numeros[i] % 2 === 1){
//     console.log('o numero '+num+' é impar');
//     }
// }
