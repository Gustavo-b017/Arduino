// C++ code
// Autor: GUSTAVO BEZERRA Assumcao
// chama a biblioteca do LCD
# include <LiquidCrystal.h>
#include <DHT.h>


// INICIANDO DHT11 

  #define DHTPIN A4    // Define o pino ao qual o sensor DHT11 está conectado
  #define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)
  DHT dht(DHTPIN, DHTTYPE);


// INICIANDO LCD

  // define os pinos do LCD, sendo os dois primeiro de controle e os 4 ultimos de recebimento de dados
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


// INICIANDO DISTANCIA:

  const int trig = 3;
  const int echo = 2;
  const int ledR = 6;
  const int ledL = 5;
  const int ledV = 7;
  float dist = 0;
  

// INICIANDO LDR E BUZZER

  int ldr = A2; // entrada do sensor luminoso
  int buzzer = 4; //saida do buzzer


void setup()
{
// INICIANDO SERIAL:
  Serial.begin(9600);
    
  
// INICIANDO O LCD:
  lcd.begin(16, 2); // define qual e o tamanho do LCD, no caso com 16 caracteres e 2 colunas

  
// INICAINADO SENSOR DE DISTANCIA E BUZZER:
  pinMode (ledR, OUTPUT);
  pinMode (ledL, OUTPUT);
  pinMode (ledV, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode (buzzer, OUTPUT);
  
  
// INICIANDO DHT11
 
 dht.begin();
  
  
}

void loop()
{  
// FIANLIZANDO SENSOR DE DISTANCIA:
 
  digitalWrite(trig, LOW); // deslida o emissor ultrasonico
  delayMicroseconds(5); // espera 5 micro segundo para execultar outra acao
  digitalWrite (trig, HIGH); // liga o emissor ultrasonico
  delayMicroseconds (10); // espera 10 micro segundo para realizar outra acao
  digitalWrite (trig, LOW); // desliga o emissor ultrassonico
  
  dist = pulseIn (echo, HIGH); // liga o receptor ultrassonico 
  dist = dist / 58;  //converte para cm ao dividir por 58
  Serial.print("distancia = "); // adiciona "distancia = " antes do valor do dado recebido
  Serial.print (dist); // mostra o valor do dado recebido
  Serial.print (" cm"); // adiciona "cm" ao fianl do dado recebido
  Serial.write (10);
  delay (200); // espera 2 milisegundos
  
  
// FINALIZANDO LDR
  
  int valLDR = analogRead(ldr); // le o ldr e armazena o valor dentro de uma variavel
  Serial.println(valLDR); // exibe a variavel
  Serial.print(valLDR); // define a ordem que deve aparecer, no caso o valor depois a palavra
  Serial.println(" luz"); // adiciona "luz" ao final do valor da variavel

// FIANLIZANDO DHT11  
  
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();  
  
// Verifica se a leitura do sensor foi bem-sucedida
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler o sensor DHT!");
  } else {
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C"); 
  }  
  
  
// INICIO DA ESTRUTURA DE CONDICAO
  if (dist <= 20)
  {
    digitalWrite (ledR, LOW); // desliga o led
    digitalWrite (ledL, LOW); // desliga o led
    digitalWrite (ledV, HIGH); // liga o led definido
    digitalWrite(buzzer, LOW); // deixa desliagado o buzzer
    lcd.print("estoque cheio");
    delay(1500);
    lcd.clear();
    lcd.print(valLDR);
    lcd.print(" luz");
    delay(1500);
    lcd.clear();
    lcd.print(temperatura);
    lcd.print(" Celsius");
    delay(1500);
    lcd.clear();
    lcd.print(umidade);
    lcd.print(" umidade");
    delay(1500);
    lcd.clear();
  }
  
  else if ( dist >20 && dist <= 80) 
  {
    digitalWrite (ledR, LOW); // desliga o led
    digitalWrite (ledL, HIGH); // liga o led definido
    digitalWrite (ledV, LOW); // desliga o led
    digitalWrite (buzzer, LOW); 
    lcd.print("estoque metade");
    delay(1500);
    digitalWrite (buzzer, HIGH);
    lcd.clear();
    lcd.print(valLDR);
    lcd.print(" luz");
    delay(1500);
    lcd.clear();
    lcd.print(temperatura);
    lcd.print(" Celsius");
    delay(1500);
    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.print(umidade);
    lcd.print(" umidade");
    delay(1500);
    lcd.clear();
  }
  else 
  {
    digitalWrite (ledR, HIGH); // liga o led definido
    digitalWrite (ledL, LOW); // desliga o led
    digitalWrite (ledV, LOW); // desliga o led
    digitalWrite (buzzer, HIGH); // liga o buzzer
    lcd.print("estoque vazio");
    delay(1500);
    lcd.clear();
    lcd.print(valLDR);
    lcd.print(" luz");
    delay(1500);
    lcd.clear();
    lcd.print(temperatura);
    lcd.print(" Celsius");
    delay(1500);
    lcd.clear();
    lcd.print(umidade);
    lcd.print(" umidade");
    delay(1500);
    lcd.clear();
  }
  
}
