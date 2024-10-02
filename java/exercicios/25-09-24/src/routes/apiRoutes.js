const router = require('express').Router()

const userController = require("../controllers/userController")
const orgController = require("../controllers/orgController")

router.post('/user',userController.createUser);
router.get('/user', userController.getAllUsers);
router.put('/user', userController.updateUser);
router.delete('/user/:cpf', userController.deleteUser);

router.post('/org',orgController.createOrg);
router.get('/org', orgController.getAllOrgs);
router.put('/org', orgController.updateOrg);
router.delete('/org/:id_organizador', orgController.deleteOrg);

module.exports = router