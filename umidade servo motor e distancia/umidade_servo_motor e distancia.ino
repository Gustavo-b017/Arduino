#include <Servo.h>
 // umidade
#include <DHT.h>

#define DHTPIN 8     // Define o pino ao qual o sensor DHT11 está conectado
#define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)

DHT dht(DHTPIN, DHTTYPE);


int servoPin = 9;

// distancia
const int trig = 5; 
const int echo = 4;
const int ledR = 13;
const int ledL = 12;
const int ledV = 11;
float dist = 0;

// objeto do tipo Servo
Servo servoMotor;


void setup() {
// servo motor
  
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);

  // Anexa o objeto do tipo Servo ao pino do servo motor
  servoMotor.attach(servoPin);

// umidade
   Serial.begin(9600);
  dht.begin();

// distancia

 Serial.begin(9600);
  pinMode (ledR, OUTPUT);
  pinMode (ledL, OUTPUT);
  pinMode (ledV, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  
}

void loop() {
  
  // motor
  
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

  // umidade

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

  // distancia
    digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite (trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  
  dist = pulseIn (echo, HIGH);
  dist = dist / 58;  //converte para cm
  Serial.print("distancia = ");
  Serial.print (dist);
  Serial.print (" cm");
  Serial.write (10);
  delay (200);

  if (dist <= 20 )
  {
    digitalWrite (ledR, HIGH);
    digitalWrite (ledL, LOW);
    digitalWrite (ledV, LOW); 
    
  }
  
  else if ( dist >20 && dist <= 110) 
  {
    digitalWrite (ledR, LOW);
    digitalWrite (ledL, HIGH);
    digitalWrite (ledV, LOW); 
  }
  else 
  {
    digitalWrite (ledR, LOW);
    digitalWrite (ledL, LOW);
    digitalWrite (ledV, HIGH); 
  }
  
}
