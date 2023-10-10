// C++ code
//
const int trig = 5; 
const int echo = 4;
const int ledR = 13;
const int ledL = 12;
const int ledV = 11;
float dist = 0;

void setup()
{
  Serial.begin(9600);
  pinMode (ledR, OUTPUT);
  pinMode (ledL, OUTPUT);
  pinMode (ledV, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  
}

void loop()
{
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
