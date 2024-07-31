
const idade = 7;

if(idade < 0){
    console.log('error')
}
if(idade > 0 && idade <= 12){
    console.log('criança')
}
if(idade >= 13 && idade <= 17){
    console.log('adolescente')
}
if(idade >= 18 && idade <= 64){
    console.log('adulto')
}
if(idade >= 65){
    console.log('idoso')
}