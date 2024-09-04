module.exports = class teacherController {
  // cadastro de professor
  static async postTeacher(req, res) {
    const { nome, cargahoraria } = req.body;
    if (!nome || !cargahoraria) {
      res.status(400).json({ message: "deu merda" });
    } else {
      res.status(200).json({ message: "uhuuul", nome, cargahoraria });
    }
  }
  // listar professores
  static async getTeacher(req, res) {
    res.status(200).json({ nome: "dahora" });
  }
};
