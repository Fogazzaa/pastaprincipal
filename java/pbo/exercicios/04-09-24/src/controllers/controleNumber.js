
function numPrimo(numero){
  if (numero <= 1) return false; // Números menores ou iguais a 1 não são numeros
    if (numero <= 3) return true;  // 2 e 3 são numeros

    // Se o número é divisível por 2 ou 3, não é numero
    if (numero % 2 === 0 || numero % 3 === 0) return false;

    // Verifica os números a partir de 5 até a raiz quadrada do número
    for (let i = 5; i * i <= numero; i += 6) {
        if (numero % i === 0 || numero % (i + 2) === 0) return false;
    }
    return true;
}

module.exports = class controleNumber {

  // cadastro de professor
  static async postPar(req, res) { /*http://localhost:3000/controlenumeros/api/parimpar*/
    const { numero } = req.body;
    if (numero % 2 == 0) {
      res.status(400).json({ message: "PAR" });
    } else {
      res.status(200).json({ message: "IMPAR"});
    }
  }
  static async postPrimo(req, res) { /*http://localhost:3000/controlenumeros/api/primo*/
    const { numero } = req.body;
    if(numPrimo(numero)){
      res.status(200).json({message: "Número primo!!"});
    }
    else{
      res.status(200).json({message: "Número não primo!!"});
    }
  }

  static async getNumbers(req, res){
    res.status(200).json({nome:"numero"})
  }

};
