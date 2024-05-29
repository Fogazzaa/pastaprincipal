
#define pinotrig 2
#define pinoecho 3
#define buzina 4
#define botaoalarme 5
#define botaoldr 6
#define ldr A0

const int leds[] = {7,8,9,10,11};
const int led1 = leds[0];
const int led2 = leds[1];
const int led3 = leds[2];
const int led4 = leds[3];
const int led5 = leds[4];

bool controleBotao[] = {false, false};

float velocidadeSomms = 0.000340;
float velocidadeSoms = 340;

int calculodistanciam;
int calculodistanciacm;

float tempoecho = 0.0;

void setup() {

  for (int i = 0; i < 3; i++) pinMode(leds[i], OUTPUT);
  pinMode(botaoldr, INPUT);
  pinMode(botaoalarme, INPUT);
  pinMode(ldr, INPUT);
  pinMode(pinotrig, INPUT);
  pinMode(pinoecho, INPUT);

  Serial.begin(9600);
  delay(1000);

}

void disparotrig() {

 digitalWrite(pinotrig, HIGH);
 delayMicroseconds(10);
 digitalWrite(pinotrig, LOW);
}

void loop() {

  disparotrig();

  calculodistanciacm = calculodistanciam * 100;

  Serial.print("Pull Down: ");
  Serial.println(analogRead(ldr));

  Serial.print("Distancia em metros: ");
  Serial.println(calculodistanciam);

  Serial.print("Distancia em centimetros: ");
  Serial.println(calculodistanciam* 100);

  float calculodistanciam = tempoecho * velocidadeSomms / 2;

  // Botão Alarme

  if (digitalRead(botaoalarme) == 1 && controleBotao[1] == false) {

    controleBotao[1] = true;
  }

  else if (digitalRead(botaoalarme) == 1 && controleBotao[1] == true) {

    controleBotao[1] = false;
  }

  // Botão LDR

  if (digitalRead(botaoldr) == 1 && controleBotao[0] == false) {

    controleBotao[0] = true;
  }

  else if (digitalRead(botaoldr) == 1 && controleBotao[0] == true) {

    controleBotao[0] = false;
  }

  if (controleBotao[0] == true) {

    if (analogRead(ldr) < 500) { // Acionar LED, caso Luminosidade Baixa

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    tone(buzina, 523);
    delay(250);

    }  // Fim do "if analogRead"

    if (analogRead(ldr) > 500) { // Desativar LED, caso Luminosidade Alta

     noTone(buzina);
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     delay(250);

    }
  }

  if (controleBotao[0] == false) {
    noTone(buzina);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(250);

  }

 tempoecho = pulseIn(pinoecho, HIGH);
  
  delay(500);

  if(calculodistanciacm <= 200 ){

    digitalWrite(buzina, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);

  }


  if(calculodistanciacm > 200){

    digitalWrite(buzina, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);

  }
}

