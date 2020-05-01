        float vetCorrente[300];
 
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
 }
void loop()
{
 // char liga_relay(float potencia);
  double maior_Valor = 0;
  double valor_Corrente = 0;  
  float tensao = 127;
  float potencia;
  for(int i = 0; i < 300; i++)
  {
    vetCorrente[i] = analogRead(A0);
    delayMicroseconds(600);
  }  
  for(int i = 0; i < 300; i++)
  {
  if(maior_Valor < vetCorrente[i])
    {
      maior_Valor = vetCorrente[i];
    }
  }  
  maior_Valor = maior_Valor * 0.004882812;
  valor_Corrente = maior_Valor - 2.5;
  valor_Corrente = valor_Corrente * 1000;
  valor_Corrente = valor_Corrente / 33;
  valor_Corrente = valor_Corrente / 1.41421356;
 // Serial.print("Corrente = ");
 // Serial.print(valor_Corrente);
 // Serial.println(" A");
  potencia = valor_Corrente * tensao;
//  Serial.print("Potencia = ");
//  Serial.print(potencia);
//  Serial.println(" W");
  
 // Serial.print(".");
//  delay(500);
//  Serial.print(".");
//  delay(500);
//  Serial.print(".");
//  delay(500);
 
 // Serial.println("");

if (valor_Corrente > 1)  // identificada uma corrente pelo ACS712
 {    
   Serial.print("Ligou a máquina de lavar ");
   Serial.print(valor_Corrente);
   Serial.println(" A");
   digitalWrite(7,LOW); //desliga o aquecedor
   digitalWrite(8,LOW);    
}
if (valor_Corrente < 1)  
{    
   Serial.print("**** Máquina de lavar desligada ");
   Serial.print(valor_Corrente);
   Serial.println(" A");
   digitalWrite(7,HIGH); //liga o aquecedor
   digitalWrite(8,HIGH);    
 }
}





  
