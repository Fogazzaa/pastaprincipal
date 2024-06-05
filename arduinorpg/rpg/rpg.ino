// Declaração de estatísticas do herói e vilão
int vidaHeroi = 100;
int vidaVilao = 100;
int ataqueHeroi = 5;
int ataqueVilao = 5;

// Controle da condição do botão
bool controleBotaoVermelho = false;
bool controleBotaoAmarelo = false;
bool controleBotaoVerde = false;

// Definição dos pinos do tinkercad
const int pinos[] = {4, 3, 2, 5, 6, 7, 11};
const int ledVermelho = pinos[0];
const int ledAmarelo = pinos[1];
const int ledVerde = pinos[2];
const int botaoVermelho = pinos[3];
const int botaoAmarelo = pinos[4];
const int botaoVerde = pinos[5];
const int buzzer = pinos[6];

// Função do Número Aleatório
long randNumber;

// Declaração dos contadores
int contadorVermelho = 0;
int contadorAmarelo = 0;
int contadorVerde = 0;

// Declaração das mensagens do jogo
bool mensagens[] = {false, false, false, false, false, false, false};
bool mensagemfim = false;

// Definição das Notas da música do Início
const int notasMusica[] = {
  494, 16, 988, 16, 740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 523, 16,
  1047, 16, 1568, 16, 1319, 16, 1047, 32, 1568, -16, 1319, 8, 494, 16, 988, 16,
  740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 622, 32, 659, 32, 698, 32,
  698, 32, 740, 32, 784, 32, 784, 32, 831, 32, 880, 16, 988, 8
};

// Calcula o número de notas
int notas = sizeof(notasMusica) / sizeof(notasMusica[0]) / 2;
int semibreve = (60000 * 4) / 105; // Duração da semibreve em milissegundos

// Função da música
void intro() {
  for (int estaNota = 0; estaNota < notas * 2; estaNota += 2) {
    int duracaoNota = (notasMusica[estaNota + 1] > 0) ? (semibreve / notasMusica[estaNota + 1]) : (semibreve / abs(notasMusica[estaNota + 1]) * 1.5);
    tone(buzzer, notasMusica[estaNota], duracaoNota * 0.9);
    delay(duracaoNota);
    noTone(buzzer);
  }
}

// Função para configurar o setup inicial
void setup() {

  randomSeed(analogRead(0)); // Inicializa a semente aleatória

  // Configura os pinos
  for (int i = 0; i < 3; i++) pinMode(pinos[i], OUTPUT);
  for (int i = 3; i < 6; i++) pinMode(pinos[i], INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600); // Inicializa a comunicação serial
  delay(1000);

  // Mensagem de boas-vindas
  Serial.println("\nBem vindo ao meu jogo. Inicie o jogo\n"
                 "apertando o botao central. Entao\n"
                 "escolha seu player, Heroi (Verde)\n"
                 "e Vilao (Vermelho), Boa Sorte !!!\n");

  digitalWrite(ledAmarelo, HIGH);

  intro(); // Toca a música de introdução
}

void botoes() {

  bool botaoPressionadoVermelho = digitalRead(botaoVermelho) == HIGH;
  bool botaoPressionadoAmarelo = digitalRead(botaoAmarelo) == HIGH;
  bool botaoPressionadoVerde = digitalRead(botaoVerde) == HIGH;

  if (botaoPressionadoVermelho && !controleBotaoVermelho) {
    controleBotaoVermelho = true;
    contadorVermelho++;
    digitalWrite(ledVermelho, HIGH);
  } else if (!botaoPressionadoVermelho && controleBotaoVermelho) {
    controleBotaoVermelho = false;
    digitalWrite(ledVermelho, LOW);
  }

  if (botaoPressionadoAmarelo && !controleBotaoAmarelo) {
    controleBotaoAmarelo = true;
    contadorAmarelo++;
  } else if (!botaoPressionadoAmarelo && controleBotaoAmarelo) {
    controleBotaoAmarelo = false;
  }

  if (botaoPressionadoVerde && !controleBotaoVerde) {
    controleBotaoVerde = true;
    contadorVerde++;
    digitalWrite(ledVerde, HIGH);
  } else if (!botaoPressionadoVerde && controleBotaoVerde) {
    controleBotaoVerde = false;
    digitalWrite(ledVerde, LOW);
  }

}

void loop() {

  botoes();

  if (controleBotaoAmarelo && contadorAmarelo == 1 && !mensagens[0]) {
    Serial.println("\nO jogo comecou, o botao esquerdo\n"
                   "escolhe o vilao (led vermelho), e o\n"
                   "direito escolhe o heroi (led verde).\n"
                   "Faca uma boa escolha !!!\n");

    mensagens[0] = true;
    digitalWrite(ledAmarelo, LOW);
  }

  if (controleBotaoVerde && contadorVerde == 1 && !mensagens[1] && contadorAmarelo == 1) {
    Serial.println("\nVoce escolheu o heroi !!!\n"
                   "Vida : 100\n"
                   "Ataque : 5\n"
                   "Clique no botao central para\n"
                   "rolar o dado !!!\n");

    mensagens[1] = true;
  }

  if (controleBotaoVermelho && contadorVermelho == 1 && !mensagens[2] && contadorAmarelo == 1) {
    Serial.println("\nVoce escolheu o vilao !!!\n"
                   "Vida : 100\n"
                   "Ataque : 5\n"
                   "Clique no botao central para\n"
                   "rolar o dado !!!\n");

    mensagens[2] = true;
  }

  if (controleBotaoAmarelo && (contadorAmarelo > 1) && (mensagens[1] || mensagens[2]) && !mensagemfim) {
    int valorDadoHeroi = random(1, 7);
    int valorDadoVilao = random(1, 7);

    int valorAtaqueHeroi = valorDadoHeroi * ataqueHeroi;
    int valorAtaqueVilao = valorDadoVilao * ataqueVilao;

    vidaVilao -= valorAtaqueHeroi;
    vidaHeroi -= valorAtaqueVilao;

    digitalWrite(ledAmarelo, HIGH);

    Serial.print("\nO dado foi rolado !!!\n"
                 "Dado do Vilao: ");
    Serial.print(valorDadoVilao);
    Serial.print("\nDado do Heroi: ");
    Serial.print(valorDadoHeroi);
    Serial.print("\nValor do Ataque do Heroi: ");
    Serial.print(valorAtaqueHeroi);
    Serial.print("\nValor do Ataque do Vilao: ");
    Serial.print(valorAtaqueVilao);
    Serial.print("\nVida do Vilao: ");
    Serial.print(vidaVilao);
    Serial.print("\nVida do Heroi: ");
    Serial.print(vidaHeroi);
    Serial.print("\n");

    if (vidaVilao <= 0 && !mensagens[6]) {
      Serial.println("\nParabens! O Heroi venceu a batalha!\n");
      mensagens[6] = true;
      mensagemfim = true;
    }
    if (vidaHeroi <= 0 && !mensagens[7]) {
      Serial.println("\nParabens! O Vilao venceu a batalha!\n");
      mensagens[7] = true;
      mensagemfim = true;
    }
  }
}
