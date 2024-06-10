// Declaração de estatísticas do herói e vilão
int vidaHeroi = 1000; // Vida inicial do herói
int vidaVilao = 1000; // Vida inicial do vilão
int ataqueHeroi = 50; // Poder de ataque do herói
int ataqueVilao = 50; // Poder de ataque do vilão
int piscadas = 10; // Número de piscadas para efeito visual
int intervalo = 250; // Intervalo de tempo entre as piscadas

// Controle da condição do botão
bool controleBotaoVermelho = false; // Controle do botão vermelho
bool controleBotaoAmarelo = false; // Controle do botão amarelo
bool controleBotaoVerde = false; // Controle do botão verde

// Definição dos pinos do tinkercad
const int pinos[] = {4, 3, 2, 5, 6, 7, 11}; // Array de pinos
const int ledVermelho = pinos[0]; // Pino do LED vermelho
const int ledAmarelo = pinos[1]; // Pino do LED amarelo
const int ledVerde = pinos[2]; // Pino do LED verde
const int botaoVermelho = pinos[3]; // Pino do botão vermelho
const int botaoAmarelo = pinos[4]; // Pino do botão amarelo
const int botaoVerde = pinos[5]; // Pino do botão verde
const int buzzer = pinos[6]; // Pino do buzzer

// Declaração dos contadores
int contadorVermelho = 0; // Contador para o botão vermelho
int contadorAmarelo = 0; // Contador para o botão amarelo
int contadorVerde = 0; // Contador para o botão verde

// Declaração das mensagens do jogo
bool mensagens[] = {false, false, false, false, false, false, false}; // Array de mensagens

// Array de frequências musicais para o tema do Pac-Man
const int notaspacman[] = {
  494, 16, 988, 16, 740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 523, 16,
  1047, 16, 1568, 16, 1319, 16, 1047, 32, 1568, -16, 1319, 8, 494, 16, 988, 16,
  740, 16, 622, 16, 988, 32, 740, -16, 622, 8, 622, 32, 659, 32, 698, 32,
  698, 32, 740, 32, 784, 32, 784, 32, 831, 32, 880, 16, 988, 8
};

// Array de frequências musicais para o tema do Doom
const int notasdoom[] = {
  82, 8, 82, 8, 165, 8, 82, 8, 82, 8, 147, 8, 82, 8, 82, 8,
  131, 8, 82, 8, 82, 8, 117, 8, 82, 8, 82, 8, 123, 8, 131, 8,
  82, 8, 82, 8, 165, 8, 82, 8, 82, 8, 147, 8, 82, 8, 82, 8,
  131, 8, 82, 8, 82, 8, 117, 8, 82, 8, 82, 8, 117, -2,

  82, 8, 82, 8, 165, 8, 82, 8, 82, 8, 147, 8, 82, 8, 82, 8,
  131, 8, 82, 8, 82, 8, 117, 8, 82, 8, 82, 8, 123, 8, 131, 8
};

// Array de frequências musicais para o tema do O Poderoso Chefão (The Godfather)
const int notasgodfather[] = {
  0, 4, 0, 8, 0, 8, 0, 8, 330, 8, 440, 8, 523, 8, // 1
  494, 8, 440, 8, 523, 8, 440, 8, 494, 8, 440, 8, 349, 8, 392, 8,
  330, 2, 330, 8, 440, 8, 523, 8,
  494, 8, 440, 8, 523, 8, 440, 8, 523, 8, 440, 8, 330, 8, 311, 8
};

// Calcula o número de notas para cada tema musical
int notasPacman = sizeof(notaspacman) / sizeof(notaspacman[0]) / 2; // Número de notas do tema do Pac-Man
int semibrevePacman = (60000 * 4) / 105; // Duração da semibreve em milissegundos para o tema do Pac-Man

int notasDoom = sizeof(notasdoom) / sizeof(notasdoom[0]) / 2; // Número de notas do tema do Doom
int semibreveDoom = (60000 * 4) / 200; // Duração da semibreve em milissegundos para o tema do Doom

int notasGodfather = sizeof(notasgodfather) / sizeof(notasgodfather[0]) / 2; // Número de notas do tema do O Poderoso Chefão
int semibreveGodfather = (60000 * 4) / 80; // Duração da semibreve em milissegundos para o tema do O Poderoso Chefão

// Função da música do Pac-Man
void pacman() {
  // Verifica se a mensagem de vitória do herói já foi exibida
  if (mensagens[4] == false) {
    Serial.println("\nParabens! O Heroi venceu a batalha!\n");
    mensagens[4] = true; // Marca que a mensagem já foi exibida
  }
  // Toca a música do Pac-Man
  for (int estaNota = 0; estaNota < notasPacman * 2; estaNota += 2) {
    // Calcula a duração da nota com base na semibreve e na sua duração relativa
    int duracaoNota = (notaspacman[estaNota + 1] > 0) ? (semibrevePacman / notaspacman[estaNota + 1]) : (semibrevePacman / abs(notaspacman[estaNota + 1]) * 1.5);
    // Toca a nota no buzzer com a frequência e a duração calculadas
    tone(buzzer, notaspacman[estaNota], duracaoNota * 0.9); // Toca a nota
    // Aguarda a duração da nota
    delay(duracaoNota);
    // Desliga o buzzer
    noTone(buzzer);
  }
}

void doom() {
  // Toca a música do Doom
  for (int estaNota = 0; estaNota < notasDoom * 2; estaNota += 2) {
    // Obtém a frequência da nota atual
    int frequenciaNota = notasdoom[estaNota];
    // Calcula a duração da nota com base na semibreve e na sua duração relativa
    int duracaoNota = (notasdoom[estaNota + 1] > 0) ? (semibreveDoom / notasdoom[estaNota + 1]) : (semibreveDoom / abs(notasdoom[estaNota + 1]) * 1.5);
    // Verifica se é uma pausa
    if (frequenciaNota == 0) {
      // Aguarda a duração da pausa
      delay(duracaoNota); // Pausa
    } else {
      // Toca a nota no buzzer com a frequência e a duração calculadas
      tone(buzzer, frequenciaNota, duracaoNota * 0.9); // Toca a nota
      // Aguarda a duração da nota
      delay(duracaoNota);
      // Desliga o buzzer
      noTone(buzzer);
    }
  }
}

void godfather() {
  // Verifica se a mensagem de vitória do vilão já foi exibida
  if (mensagens[7] == false) {
    Serial.println("\nParabens! O Vilao venceu a batalha!\n");
    mensagens[7] = true; // Marca que a mensagem já foi exibida
  }
  // Toca a música do O Poderoso Chefão
  for (int estaNota = 0; estaNota < notasGodfather * 2; estaNota += 2) {
    // Calcula a duração da nota com base na semibreve e na sua duração relativa
    int duracaoNota = (notasgodfather[estaNota + 1] > 0) ? (semibreveGodfather / notasgodfather[estaNota + 1]) : (semibreveGodfather / abs(notasgodfather[estaNota + 1]) * 1.5);
    // Verifica se é uma pausa
    if (notasgodfather[estaNota] == 0) {
      // Aguarda a duração da pausa
      delay(duracaoNota); // Pausa
    } else {
      // Toca a nota no buzzer com a frequência e a duração calculadas
      tone(buzzer, notasgodfather[estaNota], duracaoNota * 0.9); // Toca a nota
      // Aguarda a duração da nota
      delay(duracaoNota);
      // Desliga o buzzer
      noTone(buzzer);
    }
  }
}

// Função para configurar o setup inicial
void setup() {

  randomSeed(analogRead(0)); // Inicializa o gerador de números aleatórios

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

// Função para verificar se os botões foram pressionados
void botoes() {

  bool botaoPressionadoVermelho = digitalRead(botaoVermelho) == HIGH;
  bool botaoPressionadoAmarelo = digitalRead(botaoAmarelo) == HIGH;
  bool botaoPressionadoVerde = digitalRead(botaoVerde) == HIGH;

  // Verifica se o botão vermelho foi pressionado
  if (botaoPressionadoVermelho && !controleBotaoVermelho) {
    controleBotaoVermelho = true;
    contadorVermelho++;
    digitalWrite(ledVermelho, HIGH);
    delay(1000);
  } else if (!botaoPressionadoVermelho && controleBotaoVermelho) {
    controleBotaoVermelho = false;
    delay(1000);
  }

  // Verifica se o botão amarelo foi pressionado
  if (botaoPressionadoAmarelo && !controleBotaoAmarelo) {
    controleBotaoAmarelo = true;
    contadorAmarelo++;
    delay(1000);
  } else if (!botaoPressionadoAmarelo && controleBotaoAmarelo) {
    controleBotaoAmarelo = false;
    delay(1000);
  }

  // Verifica se o botão verde foi pressionado
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

// Função principal que é executada repetidamente
void loop() {

  botoes(); // Verifica se os botões foram pressionados

  // Verifica se o botão amarelo foi pressionado pela primeira vez
  if (controleBotaoAmarelo && contadorAmarelo == 1 && !mensagens[0]) {
    Serial.println("\nO jogo comecou, o botao esquerdo\n"
                   "escolhe o vilao (led vermelho), e o\n"
                   "direito escolhe o heroi (led verde).\n"
                   "Faca uma boa escolha !!!\n");

    mensagens[0] = true;
  }

  // Verifica se o botão verde foi pressionado pela primeira vez
  if (controleBotaoVerde && contadorVerde == 1 && !mensagens[1] && contadorAmarelo == 1) {
    digitalWrite(ledVerde, HIGH);
    Serial.print("\nVoce escolheu o heroi !!!");
    // Exibe as estatísticas do herói
    Serial.print("\nVida: ");
    Serial.print(vidaHeroi);
    Serial.print("\nAtaque: ");
    Serial.print(ataqueHeroi);
    Serial.print("\n" "Clique no botao central para\n"
                               "rolar o dado !!!\n");

    mensagens[1] = true;
  }

  // Verifica se o botão vermelho foi pressionado pela primeira vez
  if (controleBotaoVermelho && contadorVermelho == 1 && !mensagens[2] && contadorAmarelo == 1) {
    Serial.println("\nVoce escolheu o vilao !!!");
    // Exibe as estatísticas do vilão
    Serial.print("\nVida: ");
    Serial.print(vidaVilao);
    Serial.print("\nAtaque: ");
    Serial.print(ataqueVilao);
    Serial.print("\nClique no botao central para\n"
                   "rolar o dado !!!\n");

    mensagens[2] = true;
  }

  // Verifica se o botão amarelo foi pressionado mais de uma vez e se as mensagens foram exibidas
  if (controleBotaoAmarelo && (contadorAmarelo > 1) && (mensagens[1] || mensagens[2])) {
    int valorDadoHeroi = random(1, 7);
    int valorDadoVilao = random(1, 7);

    int valorAtaqueHeroi = valorDadoHeroi * ataqueHeroi;
    int valorAtaqueVilao = valorDadoVilao * ataqueVilao;

    // Calcula os ataques e reduz as vidas
    vidaVilao -= valorAtaqueHeroi;
    vidaHeroi -= valorAtaqueVilao;

    // Exibe os resultados dos dados e dos ataques
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

  }

  // Verifica se a vida do vilão chegou a zero
  if (vidaVilao <= 0 && vidaHeroi >= 50) {
    pacman(); // Toca a música do O Poderoso Chefão
  }
  // Verifica se a vida do herói chegou a zero
  if (vidaHeroi <= 0 && vidaVilao >= 50) {
    godfather(); // Toca a música do Pac-Man
  }
  // Verifica se ambas as vidas chegaram a zero
  if (vidaVilao <= 0 && vidaHeroi <=0 && mensagens[8] == false){
    Serial.println("\n O jogo terminou, os dois morreram.\n"
                   " Reinicie o jogo e jogue novamente \n");
    // Efeito visual de pisca o LED verde e vermelho piscando
    for (int i = 0; i < piscadas; i++) {
      digitalWrite(ledVerde, HIGH); // Liga o LED verde
      digitalWrite(ledVermelho, HIGH); // Liga o LED vermelho
      delay(intervalo); // Espera o intervalo de tempo
      digitalWrite(ledVerde, LOW); // Desliga o LED verde
      digitalWrite(ledVermelho, LOW); // Desliga o LED vermelho
      delay(intervalo); // Espera o intervalo de tempo
    }
    mensagens[8] = true; // Marca que a mensagem de fim foi exibida
  }
}