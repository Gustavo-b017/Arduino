#include <Servo.h>

#include <DHT.h>

#define DHTPIN 8     // Define o pino ao qual o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)

DHT dht(DHTPIN, DHTTYPE);


int servoPin = 9;


// objeto do tipo Servo
Servo servoMotor;


void setup() {
  
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);

  // Anexa o objeto do tipo Servo ao pino do servo motor
  servoMotor.attach(servoPin);

   Serial.begin(9600);
  dht.begin();
}

void loop() {
  
  
  
  servoMotor.write(0);
  delay(1000);
  Serial.println("o angulo e:" + String(servoMotor.read()));

  
  
  servoMotor.write(90);
  delay(1000);
  Serial.println("o angulo e:" + String(servoMotor.read()));

 
  
  servoMotor.write(180);
  delay(1000);
  Serial.println("o angulo e:" + String(servoMotor.read()));

  delay(200);  // Aguarda 2 segundos entre as leituras

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Verifica se a leitura do sensor foi bem-sucedida
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler o sensor DHT!");
  } 
  
  else {
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C"); 
  }
  
}
