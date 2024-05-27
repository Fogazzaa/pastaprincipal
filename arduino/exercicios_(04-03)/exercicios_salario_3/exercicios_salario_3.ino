
float sal_atual, sal_receber, grat, imp ;

void setup() {

  Serial.begin(9600);

  delay(1000);

}

void loop() {
  
  Serial.print("Digite o salario base : ");
  sal_atual = aguardaEntrada();
  Serial.println(sal_atual);
  delay(1000);

  grat = sal_atual * 5/100 ;
  imp = sal_atual * 7/100 ;
  sal_receber = sal_atual + grat - imp ;

  Serial.print("O salario a receber e de : ");
  Serial.println(sal_receber);

}

float aguardaEntrada()
  {
    while(!Serial.available())
    {
      
    }
    
    return Serial.parseFloat(); 
  }