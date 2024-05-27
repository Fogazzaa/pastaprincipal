
// Declaração de Vmariáveis para Números Decimais

float sal_atual, novo_sal;

// Código que será executado uma única vez

void setup() {
  sal_atual = 1200;

  // Verificando o valor do salário com a Condicional

  if (sal_atual <= 500 && sal_atual > 0) 
  {  // Início
    novo_sal = sal_atual * 1.2;
  }  // Fim

  else if (sal_atual > 500) 
  {
    novo_sal = sal_atual * 1.1;
  }

  else 
  {
    novo_sal = 0;
  }

  // Inicia a comunicação com o Monitor Serial

  Serial.begin(9600);
}

// Código que será executado repetidamente

void loop() {
  // Mostra a frase no monitor

  if (novo_sal == 0) 
  {
    Serial.println("Digite um Salário Válido !");
  }

  else {

    // Exibindo novo salário

    Serial.print("Novo Salário : ");
      Serial.println(novo_sal);
        Serial.println("-----------------------");
  }

  // Espera 1 segundo antes de seguir o loop

  delay(1000);
}
