
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

if(doh == 1){
  tone(pinobuzina, 523);
}

else if(re == 1){
  tone(pinobuzina, 587);
}

else if(mi == 1){
  tone(pinobuzina, 659);
}

else if(fa == 1){
  tone(pinobuzina, 698);
}

else if(so == 1){
  tone(pinobuzina, 392);
}

else if(la == 1){
  tone(pinobuzina, 440);
}

else if(si == 1){
  tone(pinobuzina, 494);
}

else if(doh2 == 1){
  tone(pinobuzina, 554);
}

else {
  noTone(pinobuzina);
}

delay(50);
}
