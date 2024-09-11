// importa o módulo router do express
const router = require("express").Router(); // router será utilizado para definir rotas específicas da aplicação

// importa a controller de professores onde contem a lógica relacionada a professores
const controleNumber = require("../controllers/controleNumber");

// rota post para '/teacher'
router.post("/parimpar/",controleNumber.postPar);
router.post("/primo/",controleNumber.postPrimo);
router.get('/teacher/',controleNumber.getNumbers);

module.exports = router;
