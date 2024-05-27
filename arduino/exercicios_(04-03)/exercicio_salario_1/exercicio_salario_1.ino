float sal_atual, novo_sal;

void setup() {
  
  Serial.begin(9600);

  delay(1000);

}

void loop() {
 
  Serial.print("Digite o salario : ");
  sal_atual = aguardaEntrada();
  Serial.println(sal_atual);
  delay(1000);
  novo_sal = sal_atual + sal_atual * 1/4 ;

  Serial.print (" O novo salario e :  ");
  Serial.println (novo_sal);
  delay(1000);

}

float aguardaEntrada()
  {
    while(!Serial.available())
    {
      
    }
    
    return Serial.parseFloat(); 
  }
