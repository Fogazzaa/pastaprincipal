// Declaração de estatísticas do herói e vilão
int vidaHeroi = 100;
int vidaVilao = 100;
int ataqueHeroi = 5;
int ataqueVilao = 5;
int piscadas = 5;
int intervalo = 500;  

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

const int notaspacman[] = {
  494, 16, 988, 16, 740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 523, 16,
  1047, 16, 1568, 16, 1319, 16, 1047, 32, 1568, -16, 1319, 8, 494, 16, 988, 16,
  740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 622, 32, 659, 32, 698, 32,
  698, 32, 740, 32, 784, 32, 784, 32, 831, 32, 880, 16, 988, 8
};

const int notasdoom[][2] = {
  {82, 8}, {82, 8}, {165, 8}, {82, 8}, {82, 8}, {147, 8}, {82, 8}, {82, 8},
  {131, 8}, {82, 8}, {82, 8}, {117, 8}, {82, 8}, {82, 8}, {123, 8}, {131, 8},
  {82, 8}, {82, 8}, {165, 8}, {82, 8}, {82, 8}, {147, 8}, {82, 8}, {82, 8},
  {131, 8}, {82, 8}, {82, 8}, {117, 8}, {82, 8}, {82, 8}, {117, -2},

  {82, 8}, {82, 8}, {165, 8}, {82, 8}, {82, 8}, {147, 8}, {82, 8}, {82, 8},
  {131, 8}, {82, 8}, {82, 8}, {117, 8}, {82, 8}, {82, 8}, {123, 8}, {131, 8}
};

const int notasgodfather[] = {
  0, 4, 0, 8, 0, 8, 0, 8, 330, 8, 440, 8, 523, 8, // 1
  494, 8, 440, 8, 523, 8, 440, 8, 494, 8, 440, 8, 349, 8, 392, 8,
  330, 2, 330, 8, 440, 8, 523, 8,
  494, 8, 440, 8, 523, 8, 440, 8, 523, 8, 440, 8, 330, 8, 311, 8
};

// Calcula o número de notas
int notasPacman = sizeof(notaspacman) / sizeof(notaspacman[0]) / 2;
int semibrevePacman = (60000 * 4) / 105; // Duração da semibreve em milissegundos

int notasDoom = sizeof(notasdoom) / sizeof(notasdoom[0]) / 2;
int semibreveDoom = (60000 * 4) / 80; 

int notasGodfather = sizeof(notasgodfather) / sizeof(notasgodfather[0]) / 2;
int semibreveGodfather = (60000 * 4) / 80; 

// Função da música
void pacman() {
  if (mensagens[6] == false){
   Serial.println("\nParabens! O Heroi venceu a batalha!\n");
   mensagens[6] = true;
   mensagemfim = true;}
  for (int i = 0; i < piscadas; i++) {
    digitalWrite(ledVerde, HIGH); // Liga o LED
    delay(intervalo);           // Espera o intervalo de tempo
    digitalWrite(ledVerde, LOW);  // Desliga o LED
    delay(intervalo);           // Espera o intervalo de tempo
   }
  for (int estaNota = 0; estaNota < notasPacman * 2; estaNota += 2) {
    int duracaoNota = (notaspacman[estaNota + 1] > 0) ? (semibrevePacman / notaspacman[estaNota + 1]) : (semibrevePacman / abs(notaspacman[estaNota + 1]) * 1.5);
    tone(buzzer, notaspacman[estaNota], duracaoNota * 0.9);
    delay(duracaoNota);
    noTone(buzzer);
  }
}

void doom() {
  for (int estaNota = 0; estaNota < notasDoom; estaNota++) {
    int frequenciaNota = notasdoom[estaNota][0];
    int duracaoNota = (notasdoom[estaNota][1] > 0) ? (semibreveDoom / notasdoom[estaNota][1]) : (semibreveDoom / abs(notasdoom[estaNota][1]) * 1.5);
    if (frequenciaNota == -1) {
      delay(-duracaoNota); // pausa
    } else {
      tone(11, frequenciaNota, duracaoNota * 0.9); // 11 é o pino do buzzer
      delay(duracaoNota * 0.5);
      noTone(11);
    }
  }
}

void godfather() {
    if (mensagens[7] == false){
     Serial.println("\nParabens! O Vilao venceu a batalha!\n");
      mensagens[7] = true;
      mensagemfim = true;}
      for (int i = 0; i < piscadas; i++) {
    digitalWrite(ledVermelho, HIGH); // Liga o LED
    delay(intervalo);           // Espera o intervalo de tempo
    digitalWrite(ledVermelho, LOW);  // Desliga o LED
    delay(intervalo);           // Espera o intervalo de tempo
   }
  for (int estaNota = 0; estaNota < notasGodfather * 2; estaNota += 2) {
    int duracaoNota = (notasgodfather[estaNota + 1] > 0) ? (semibreveGodfather / notasgodfather[estaNota + 1]) : (semibreveGodfather / abs(notasgodfather[estaNota + 1]) * 1.5);
    if (notasgodfather[estaNota] == 0) {
      delay(duracaoNota); // pausa
    } else {
      tone(buzzer, notasgodfather[estaNota], duracaoNota * 0.9);
      delay(duracaoNota);
      noTone(buzzer);
    }
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

  doom(); // Toca a música de introdução
}

void botoes() {

  bool botaoPressionadoVermelho = digitalRead(botaoVermelho) == HIGH;
  bool botaoPressionadoAmarelo = digitalRead(botaoAmarelo) == HIGH;
  bool botaoPressionadoVerde = digitalRead(botaoVerde) == HIGH;

  if (botaoPressionadoVermelho && !controleBotaoVermelho) {
    controleBotaoVermelho = true;
    contadorVermelho++;
    digitalWrite(ledVermelho, HIGH);
    delay(1000);
  } else if (!botaoPressionadoVermelho && controleBotaoVermelho) {
    controleBotaoVermelho = false;
    delay(1000);
  }

  if (botaoPressionadoAmarelo && !controleBotaoAmarelo) {
    controleBotaoAmarelo = true;
    contadorAmarelo++;
    delay(1000);
  } else if (!botaoPressionadoAmarelo && controleBotaoAmarelo) {
    controleBotaoAmarelo = false;
    delay(1000);
  }

  if (botaoPressionadoVerde && !controleBotaoVerde) {
    controleBotaoVerde = true;
    contadorVerde++;
    delay(1000);
    digitalWrite(ledVerde, HIGH);
  } else if (!botaoPressionadoVerde && controleBotaoVerde) {
    controleBotaoVerde = false;
    delay(1000);
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
  }

  if (controleBotaoVerde && contadorVerde == 1 && !mensagens[1] && contadorAmarelo == 1) {
    digitalWrite(ledVerde, HIGH);
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

    Serial.print("\nO dado foi rolado !!!\n\n"
                 "Dado do Vilao: ");
    Serial.print(valorDadoVilao);
    Serial.print("\nDado do Heroi: ");
    Serial.print(valorDadoHeroi);
    Serial.print("\n");
    Serial.print("\nValor do Ataque do Vilao: ");
    Serial.print(valorAtaqueVilao);
    Serial.print("\nValor do Ataque do Heroi: ");
    Serial.print(valorAtaqueHeroi);
    Serial.print("\n");
    Serial.print("\nVida do Vilao: ");
    Serial.print(vidaVilao);
    Serial.print("\nVida do Heroi: ");
    Serial.print(vidaHeroi);
    Serial.print("\n");

    if (vidaVilao <= 0) {
      godfather();
    }
    if (vidaHeroi <= 0) {
      pacman();
    }
  }
}
