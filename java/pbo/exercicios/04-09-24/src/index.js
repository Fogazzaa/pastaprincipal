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

  routes() {
    // define as rotas da nossa API

    const apiRoutes = require("./routes/apiRoutes"); // chama/linka a a pasta routes e o apiRoutes para o arquivo index.js
    this.express.use("/controlenumeros/api/par", apiRoutes); // url default do projeto '/project-senai/api/v1'

    this.express.get("/health/", (req, res) => {
      // define uma rota 'GET' para o caminho '/health/'
      res.send({ status: "OK" }); // essa rota é usada para verificar se a API está OK
    });
  }
}

/* exportando a instância de express configurada, 
para que seja acessada em outros arquivos */
module.exports = new AppController().express;
