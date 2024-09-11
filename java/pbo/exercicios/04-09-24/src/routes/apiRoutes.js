// importa o módulo router do express
const router = require("express").Router(); // router será utilizado para definir rotas específicas da aplicação

const controleNumber = require("../controllers/controleNumber");

router.post(
  "/parimpar/",
  controleNumber.postPar
); /*rota para par: http://localhost:3000/controlenumeros/api/parimpar */
router.post(
  "/primo/",
  controleNumber.postPrimo
); /*rota para primo: http://localhost:3000/controlenumeros/api/primo */

module.exports = router;
