// Declaração das variáveis que representam os leds

int ledAmarelo = 8;
int ledVermelho = 9;
int ledVerde = 10;

void setup() {

  // Definindo os tipos de pinos

  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {

  digitalWrite(ledAmarelo, HIGH);
  delay(1000);
  digitalWrite(ledAmarelo, LOW);
  delay(1000);
  
}
