#include <Servo.h>

#include <Servo.h>


int servoPin = 9;


// objeto do tipo Servo
Servo servoMotor;


void setup() {
  
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);

  // Anexa o objeto do tipo Servo ao pino do servo motor
  servoMotor.attach(servoPin);
}

void loop() {
  
  
  
  servoMotor.write(0);
  delay(2000);
  Serial.println("o angulo e:" + String(servoMotor.read()));

  
  
  servoMotor.write(90);
  delay(2000);
  Serial.println("o angulo e:" + String(servoMotor.read()));

 
  
  servoMotor.write(180);
  delay(2000);
  Serial.println("o angulo e:" + String(servoMotor.read()));
  
}
