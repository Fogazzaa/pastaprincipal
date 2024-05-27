// Declaração de Variáveis de Entrada

int N1;
int N2;
int N3;

// Declaração de Variável de Saída

int S;
  
void setup() {

  /* Configuração Incial do Sistema
  será executada apenas no início */

  // Iniciando a Comunicação com Monitor Serial

  Serial.begin(9600);

  N1 = 1;
  N2 = 2;
  N3 = 3;
  S = 0;

  // Processamento das Entradas

  S = N1 + N2 + N3;
}

void loop() {

  // Código que será executado repetidamente

  Serial.print("A soma é : ");  // Mostra a frase no monitor
  Serial.println(S);            // Mostra o valor da soma e muda o cursor de linha
  delay(1000); // Espera 1 segundo antes de seguir o loop

}
