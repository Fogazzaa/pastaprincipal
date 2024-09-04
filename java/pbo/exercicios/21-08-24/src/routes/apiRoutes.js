// importa o módulo router do express
const router = require("express").Router(); // router será utilizado para definir rotas específicas da aplicação

// importa a controller de professores onde contem a lógica relacionada a professores
const teacherController = require("../controllers/teacherController");

// rota post para '/teacher'
router.post("/teacher/", teacherController.postTeacher);
router.get("/teacher/", teacherController.getTeacher);

module.exports = router;
