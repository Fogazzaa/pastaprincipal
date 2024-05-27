#define pinobuzina 2
#define pinodo 3
#define pinore 4
#define pinomi 5
#define pinofa 6
#define pinoso 7
#define pinola 8
#define pinosi 9
#define pinodo2 10

byte doh, re, mi, fa, so ,la , si, doh2 = 0;

void setup() {

  Serial.begin(9600);
  delay(1000);
  
  pinMode(pinobuzina, OUTPUT);
  pinMode(pinodo, INPUT);
  pinMode(pinore, INPUT);
  pinMode(pinomi, INPUT);
  pinMode(pinofa, INPUT);
  pinMode(pinoso, INPUT);
  pinMode(pinola, INPUT);
  pinMode(pinosi, INPUT);
  pinMode(pinodo2, INPUT);

}

void loop() {
  
doh = digitalRead(pinodo);
re = digitalRead(pinore);
mi = digitalRead(pinomi);
fa = digitalRead(pinofa);
so = digitalRead(pinoso);
la = digitalRead(pinola);
si = digitalRead(pinosi);
doh2 = digitalRead(pinodo2);

delay(2000);
  tone(pinobuzina, 392, 300); //SOL
  delay(350);
  tone(pinobuzina, 392, 300); //SOL
  delay(350);
  tone(pinobuzina, 349, 400); //FA
  delay(300);
  tone(pinobuzina, 330, 400); //MI
  delay(300);
  tone(pinobuzina, 392, 300); //SOL
  delay(350);
  tone(pinobuzina, 392, 300); //SOL
  delay(300);
  tone(pinobuzina, 349, 400); //FA
  delay(300);
  tone(pinobuzina, 330, 400); //MI
  delay(300);
  tone(pinobuzina, 392, 300); //SOL
  delay(300);
  tone(pinobuzina, 440, 300); //LA
  delay(350);
  tone(pinobuzina, 392, 300); //SOL
  delay(300);
  tone(pinobuzina, 349, 300); //FA
  delay(300);
  tone(pinobuzina, 330, 300); //MI
  delay(300);
  tone(pinobuzina, 294, 400); //RE
  delay(350);
  tone(pinobuzina, 294, 300); //RE
  delay(300);
  tone(pinobuzina, 330, 300); //MI
  delay(300);
  tone(pinobuzina, 349, 300); //FA
  delay(300);
  tone(pinobuzina, 294, 300); //RE
  delay(300);
  tone(pinobuzina, 330, 300); //MI
  delay(300);
  tone(pinobuzina, 349, 300); //FA
  delay(300);
  tone(pinobuzina, 294, 300); //RE
  delay(300);
  tone(pinobuzina, 330, 300); //MI
  delay(300);
  tone(pinobuzina, 349, 300); //FA
  delay(300);
  tone(pinobuzina, 392, 300); //SOL
  delay(300);
  tone(pinobuzina, 440, 300); //LA
  delay(300);
  tone(pinobuzina, 392, 300); //SOL
  delay(300);
  tone(pinobuzina, 349, 300); //FA
  delay(350);
  tone(pinobuzina, 330, 300); //MI
  delay(350);
  tone(pinobuzina, 294, 400); //RE
  delay(350);
  tone(pinobuzina,262,600); //DO
  delay(300);
}