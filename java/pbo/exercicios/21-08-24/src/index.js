
const express = require("express"); // importando o módulo express

class AppController {
  // define uma classe para organizar a lógica da aplicação

  constructor() {
    this.express = express(); // cria uma nova instância dentro da classe
    this.middlewares(); // chama o método middlewares para configurar os middlewares
    this.routes(); //chama o método routes para definir as rotas da API
  }
  middlewares() {
    this.express.use(express.json()); // permitir que a aplicação receba dados em formato JSON nas requisições
  }

  routes() { // define as rotas da nossa API
    this.express.get("/health/", (req, res) => { // define uma rota 'GET' para o caminho '/health/'
      res.send({ 
        nome : "vinicius",
        idade : "16",
        CPF : "44595804890"
       }); // essa rota é usada para verificar se a API está OK
    }); 
  }
}

/* exportando a instância de express configurada, 
para que seja acessada em outros arquivos */
module.exports = new AppController().express; 
