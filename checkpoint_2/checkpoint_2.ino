// participantes:
// Gustavo Bezerra
// Carolina Machado
// Jeferson Gabriel
// Edson Leonardo

#include <DHT.h>
#define DHTPIN 8     // Define o pino ao qual o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)
DHT dht(DHTPIN, DHTTYPE);

int ldr = A2; 
int ledR = 4; 
int ledA = 3; 
int ledV = 2; 
int buzzer = 12;

void setup()
{
 
Serial.begin(9600);

// UMIDADE E TEMPERAURA

dht.begin();


  Serial.begin(9600);
  pinMode (ledR, OUTPUT);
  pinMode (ledA, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (ledV, OUTPUT);
  dht.begin();
}

void loop()
{
// SENSOR DE UMIDADE E TEMPERATURA
  delay(200);  // Aguarda 2 segundos entre as leituras

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

// SENSOR DE LUZ
  int valLDR = analogRead(ldr);
  Serial.println(valLDR);
  Serial.print(valLDR); Serial.println(" luz"); 

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

delay(300);
 // LUZ

if (valLDR <100 ) {
    digitalWrite (ledR, LOW);
    digitalWrite (ledA, LOW);
    digitalWrite (ledV, HIGH); 
    delay(300);
    Serial.print("perigo");
    digitalWrite(buzzer, HIGH); 
  
  }

else if(valLDR >= 100 and valLDR <=220 ){
    digitalWrite (ledR, LOW);
    digitalWrite (ledA, HIGH);
    digitalWrite (ledV, LOW);
    
    delay(300);
    Serial.print("atencao");

   
    digitalWrite (buzzer, HIGH);
    delay(3000); //espera 3 segundos para desligar
    digitalWrite (buzzer, LOW);
    delay (1000); // espera 1 segundo para recomecar o ciclo
  }
  
else {
  digitalWrite (ledR, HIGH);
    digitalWrite (ledA, LOW);
    digitalWrite (ledV, LOW);
    delay(300);
    Serial.print("okay");
    digitalWrite(buzzer, LOW);
 }
}
