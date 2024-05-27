
#define buzina 2
int led = 3;

void setup() {

  Serial.begin(9600);
  pinMode(buzina, OUTPUT);
  pinMode(led, OUTPUT);
  delay(1000);

}

void loop() {

  tone(buzina, 523); // Liga a Buzina, Tom (Dó)
  digitalWrite(led, HIGH);
  delay(1000);
  noTone(buzina); // Desliga a Buzina
  digitalWrite(led, LOW);
  delay(1000);

}
