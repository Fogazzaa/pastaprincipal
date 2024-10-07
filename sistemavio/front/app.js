
// acessa o objeto 'document' que representa a pagina html

document
    .getElementById("formulario-registro") //  seleciona o elemento com o id indicado no <form> 'formulario-registro'
    .addEventListener("submit", function(event){ // adiciona o ouvinte do evento 'submit'
    event.preventDefault// previne o comportamento padrão do formulário, ou seja, impede que ele seja enviado e recarregue a página
    const name = document.getElementById('name'); // capturar os valores dos campos do formulário pelo id
    const cpf = document.getElementById('cpf');
    const email = document.getElementById('email');
    const password = document.getElementById('password');

    // requisição http para o endpoint de cadastro de usuário

    fetch("http://localhost:5000/api/v1/user",{
        // realiza uma chamada HTTP para o servidor (a rota definida)
        method: "POST",
        header: {
            // a requisição será em formato JSON
            "Content-Type":application/JSON,
        },
        // transforma os dados do formulário em uma string json para serem enviados no corpo da requisição
        body: JSON.stringify({name, cpf, email, password}),

        // 
    })

});