let orgs = [];
let id_organizador = 0;

module.exports = class orgController {
  static async createOrg(req, res) {
    const { nome, email, senha, telefone } = req.body;

    if (!nome || !email || !senha || !telefone) {
      return res
        .status(400)
        .json({ error: "Todos os campos devem ser preenchidos" });
    } else if (isNaN(telefone) || telefone.length !== 11) {
      return res
        .status(400)
        .json({
          error: "Telefone inválido. Deve conter exatamente 11 dígitos numéricos",
        });
    } else if (!email.includes("@")) {
      return res.status(400).json({ error: "Email inválido. Deve conter @" });
    }

    // Verifica se já existe um usuário com o mesmo telefone
    const existingOrg = orgs.find((org) => orgs.telefone === telefone);
    if (existingOrg) {
      return res.status(400).json({ error: "Telefone já cadastrado" });
    }

    // Cria e adiciona novo usuário
    id_organizador = id_organizador + 1;
    const newOrg = { nome, email, senha, telefone, id_organizador};
    orgs.push(newOrg);

    return res
      .status(201)
      .json({ message: "Usuário criado com sucesso", orgs : newOrg });
  }

  static async getAllOrgs(req, res) {
    return res
      .status(200)
      .json({ message: "Obtendo todos os usuários", orgs });
  }

  static async updateOrg(req, res) {
    // desestrutura e recupera os dados enviados via corpo da requisição
    const { nome, email, senha, telefone } = req.body;
    if (!nome || !email || !senha || !telefone) {
      // valida se todos os campos foram preenchidos
      return res
        .status(400)
        .json({ error: "Todos os campos devem ser preenchidos" });
    }
    // procura indice do user no array 'users' pelo cpf
    const orgIndex = orgs.findIndex((org) => org.telefone === telefone);
    // se não for encontrado o 'userindex' equivale a -1
    if (orgIndex === -1) {
      return res.status(400).json({ error: "Usuário não encontrado" });
    }
    // atualiza os dados do usuario na array 'users'
    orgs[orgIndex] = { nome, email, senha, telefone };
    return res
      .status(200)
      .json({ message: "Usuário atualizado", org: orgs[orgIndex] });
  }

  static async deleteOrg(req, res) {
    const orgId = req.params.id_organizador;
    const orgIndex = orgs.findIndex((org) => org.id_organizador == orgId);
    // se não for encontrado o 'userindex' equivale a -1
    if (orgIndex === -1) {
      return res.status(400).json({ error: "Usuário não encontrado" });
    }
    // removendo usuário da array 'users'
    orgs.splice(orgIndex, 1) // começa no indice 'userIndex', e apaga somente '1'
    return res.status(200).json({ message: "Usuário apagado", orgs });
  }
};
