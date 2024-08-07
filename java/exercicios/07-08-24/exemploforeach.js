
let number = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];

// Estrutura de repetição usando ForEach

// for (let i = 0; i < numeros.length; i++)
number.forEach(num =>{ // atribui a posição a variavel, e passa por todas posições
if(num % 2 === 0){
    console.log('o número '+num+' é par \n')
}
else{
console.log('o número '+num+' é impar \n')
}
});