const router = require('express').Router()

const { route } = require('..')
const userController = require("../controllers/userController")

router.post('/user',userController.createUser);
router.get('/user', userController.getAllUsers);
router.put('/user', userController.updateUser);
router.delete('/user/:cpf', userController.deleteUser);

module.exports = router