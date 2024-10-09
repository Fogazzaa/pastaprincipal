// acessa o objeto 'document' que representa a pagina html

document
  .getElementById("formulario-registro") //  seleciona o elemento com o id indicado no <form> 'formulario-registro'
  .addEventListener("submit", function (event) {
    // adiciona o ouvinte do evento 'submit'
    event.preventDefault(); // previne o comportamento padrão do formulário, ou seja, impede que ele seja enviado e recarregue a página
    const name = document.getElementById("nome").value; // capturar os valores dos campos do formulário pelo id
    const cpf = document.getElementById("cpf").value;
    const email = document.getElementById("email").value;
    const password = document.getElementById("senha").value;

    // requisição http para o endpoint de cadastro de usuário

    fetch("http://localhost:5000/api/v1/user", {
      // realiza uma chamada HTTP para o servidor (a rota definida)
      method: "POST",
      headers: {
        // a requisição será em formato JSON
        "Content-Type": "application/json",
      },
      // transforma os dados do formulário em uma string json para serem enviados no corpo da requisição
      body: JSON.stringify({ name, cpf, password, email }),
    })
      .then((response) => {
        // tratamento da resposta do servidor / api
        if (response.ok) {
          // verifica se a resposta foi bem-sucedida (status: 20*)
          return response.json();
        } // --- fechamento 'response.ok'
        // convertendo o erro em formato JSON
        return response.json().then((err) => {
          // mensagem retornada do servidor, acessa pela chave 'error'
          throw new Error(err.error);
        }); // --- fechamento 'response error'
      }) // --- fechamento 'response'
      .then((data) => {
        // executa a resposta de sucesso  - retorna ao usuario final
        // exibe alerta com o nome do usuario com o nome que acabou de ser cadastrado (front)
        alert("Usuário cadastrado com sucesso: " + data.user.name);
        // exibe o log no terminal
        console.log("Usuário Cadastrado: ", data.user);

        // limpa os campos do formulario, após o sucesso do cadastro
        document.getElementById("formulario-registro").reset()
      }) // --- fechamento 'data'
      //captura qualquer erro que ocorra durante o processo de requisição/ resposta
      .catch((error) => {
        // exibe alerta no (front) com erro processado
        alert("Erro no cadastro: " + error.message);
        console.error("Erro:", error.message);
      }); // --- fechamento 'catch(error)'
  });
