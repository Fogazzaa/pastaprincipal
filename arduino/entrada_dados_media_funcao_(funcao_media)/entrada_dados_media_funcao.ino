
// Declaração das Variáveis - Números Reais

float nota1, nota2, nota3, peso1, peso2, peso3, media;

void setup() 

{

  // Inicia a Comunicação com o Serial Monitor

  Serial.begin(9600);

  delay(1000);  // Espera Estratégica
  
}

void loop()

{
  // Atribuição das notas:

  // NOTA 1

  Serial.print("Digite a nota 1 : ");
  nota1 = aguardaEntrada();
  Serial.println(nota1);
  
  // NOTA 2

  Serial.print("Digite a nota 2 : ");
  nota2 = aguardaEntrada();
  Serial.println(nota2);

  // NOTA 3 

  Serial.print("Digite a nota 3 : ");
  nota3 = aguardaEntrada();
  Serial.println(nota3);

  // Atribuição dos pesos:

  // PESO 1 

  Serial.print("Digite o peso 1 : ");
  peso1 = aguardaEntrada();
  Serial.println(peso1);  

  // PESO 2

  Serial.print("Digite o peso 2 : ");-
  peso2 = aguardaEntrada();
  Serial.println(peso2);

  // PESO 3

  Serial.print("Digite o peso 3 : ");
  peso3 = aguardaEntrada();
  Serial.println(peso3);

  // Cálculo da Média Ponderada

  media = ( nota1*peso1 + nota2*peso2 + nota3*peso3 ) / ( peso1 + peso2 + peso3 );

  Serial.print (" A Media Ponderada e : ");
  Serial.println (media);
  delay(10000);

}

  // Criando uma função chamada "aguardaEntrada"

  float aguardaEntrada()
  {
    while(!Serial.available())
    {
      // Aguarda até que uma nota seja digitada
    }
    
    return Serial.parseFloat(); // Rertornar o valor digital em tipo "float"
  }