#include <DHT.h>

#define DHTPIN 8     // Define o pino ao qual o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(200);  // Aguarda 2 segundos entre as leituras

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
}
