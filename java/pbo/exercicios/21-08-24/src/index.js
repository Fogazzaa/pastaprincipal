//Importa o modulo Express
const express = require("express");

//Define uma classe para organizar a logica da aplicação
class AppController {
  constructor() {
    //Cria uma nova instancia do Express dentro da classe
    this.express = express();
    //Chama o metodo middlewares para configurar os middlewares
    this.middlewares();
    //Chama o metodo routes para definir as rotas da Api
    this.routes();
  }
  middlewares() {
    //Permitir que a aplicação receba dados em formato JSON nas requisições
    this.express.use(express.json());
  }

  //Define as rotas da nossa API
  routes() {
    const users = [];

    this.express.post("/users", (req, res) => {
      const { id, nome, email, senha } = req.body;
      users.push({ id, nome, email, senha });
      res.status(200).send({ message: "Usuario cadastrado com sucesso" });
    });

    this.express.post("/auth", (req, res) => {
      const {email, senha } = req.body;
      const login = users.find((login) => login.email == email && login.senha == senha);
      if(login) {
        res.status(200).send({ message: "Autenticaçãobem sucedida" });
      }
      else{
        res.status(404).send({ message: "Email ou senha incorreta" });
      }


    });



    this.express.get("/users/:id", (req, res) => {
      const { id } = req.params;
      const user = users.find((user) => user.id == id);
      if(user){
        res.status(200).send(user)
      }
      else{
        res.status(400).send({message: "Usuario não encontrado"})
      }
    });

    //Define uma rota GET para o caminho health
    this.express.get("/health/", (req, res) => {
      res.send({ status: "OK" });
    }); //Essa rota é usada para verificar se a Api esta ok
  }
}

//Exportando a instancia de Express configurada, para que seja acessada em outros arquivos
module.exports = new AppController().express;