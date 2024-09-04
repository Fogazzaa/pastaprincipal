module.exports = class controleNumber {
  // cadastro de professor
  static async postNumber(req, res) {
    const { numero } = req.body;
    if (numero % 2 == 0) {
      res.status(400).json({ message: "PAR" });
    } else {
      res.status(200).json({ message: "IMPAR"});
    }
  }
};
