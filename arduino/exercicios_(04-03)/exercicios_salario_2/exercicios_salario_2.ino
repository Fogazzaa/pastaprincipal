
float sal_atual, novo_sal, perc, aumento;

void setup() {

  Serial.begin(9600);

  delay(1000);

}

void loop() {
  
  Serial.print("Digite o salario : ");
  sal_atual = aguardaEntrada();
  Serial.println(sal_atual);
  delay(1000);

  Serial.print("Digite o valor percentual do aumento : ");
  perc = aguardaEntrada();
  Serial.println(perc);

  aumento = sal_atual * perc/100 ;

  Serial.print("O aumento e de : ");
  Serial.println(aumento);

  novo_sal = sal_atual + aumento;

  Serial.print("O novo salario e de : ");
  Serial.println(novo_sal);

}

float aguardaEntrada()
  {
    while(!Serial.available())
    {
      
    }
    
    return Serial.parseFloat(); 
  }