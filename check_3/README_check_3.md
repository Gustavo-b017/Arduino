# CHECKPOINT 3 -- monitor de estoque

## Contexto:

* <h4>Criar um monitor para estoque, usando sensores como: </h4> 1. sensor de distancia. <br><br> 2. sensor de luz, usando o LDR. <br><br> 3. LCD, como um visor que ira mostrar os dados, bem como a situacao do estoque. <br><br>4. LEDs, sendo de qualquer cor, desde que sejam 3. No caso, foram usados: Vermelho, Amarelo e Verde. <br><br> 5. DHT11, como sensor de temperatura e umidade. <br><br> 6. Buzzer, como um alerta sonoro de status do estoque. <br><br> 7. Potenciometro, para poder regular o contraste do LCD. <br><br> 8. Resistores, tendo de diferentes valores, no totas foramusados 5. <br><br> 9. Arduino uno, sendo usado para controlar dos componentes, bem como para fazer as ligacoes e realizar os comandos. <br><br> 10. Junpers, para realizar as ligacoes entre os sensores e componentes com o arduino.

* <h4> Objetivos: </h4> Criar um sistema que consiga verificar a situacao do estoque usando os componentes estudados na aula. Alem disso, deve aparecer as informacoes da temperantura, umidade, luz, e situacao do estoque.

* <h4> Participantes: </h4> 1. GUSTAVO BEZERRA ASSUMÇÃO : Montagem do código, montagem do arduino, gravacao do video e criacao do README. <br><br> 2. LUCAS MASAKI : Montagem do arduino e gravacao do video. <br><br> 3. JEFERSON GABRIEL : Montagem do arduino. <br><br> 4. VICTOR VILARES: ...

## Codigo: 
// Autor: GUSTAVO BEZERRA ASUMCAO  
// chama a biblioteca do LCD e do DHT11  <br>
#include <LiquidCrystal.h>  <br>
#include <DHT.h>  <br>
  <br>
  <br>
// INICIANDO DHT11   <br>
  <br>
  #define DHTPIN A4    // Define o pino ao qual o sensor DHT11 está conectado  <br>
  #define DHTTYPE DHT11   // Define o tipo de sensor DHT (DHT11 neste caso)  <br>
  DHT dht(DHTPIN, DHTTYPE);  <br>
  <br>
  <br>
// INICIANDO LCD  <br>
  <br>
  // define os pinos do LCD, sendo os dois primeiro de controle e os 4 ultimos de recebimento de dados  <br>
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  <br>
  <br>
  <br>
// INICIANDO DISTANCIA:  <br>
  <br>
  // definindo porta de entradas:  <br>

  const int trig = 3;  <br>
  const int echo = 2;  <br>
  const int ledR = 6;  <br>
  const int ledL = 5;  <br>
  const int ledV = 7;  <br>
  float dist = 0;  <br>
    <br>
  <br>
// INICIANDO LDR E BUZZER  <br>
  <br>
  int ldr = A2; // entrada do sensor luminoso  <br>
  int buzzer = 4; //saida do buzzer  <br>
  <br>
  <br>
void setup()  <br>
{  <br>
// INICIANDO SERIAL:  <br>
  Serial.begin(9600);  <br>
      <br>
    <br>
// INICIANDO O LCD:  <br>
  lcd.begin(16, 2); // define qual e o tamanho do LCD, no caso com 16 caracteres e 2 colunas  <br>
  <br>
    <br>
// INICAINADO SENSOR DE DISTANCIA E BUZZER:  <br>
  // definindo o todos os tipo de entrada, exeto das entradas analogicas <br>
  pinMode (ledR, OUTPUT);  <br>
  pinMode (ledL, OUTPUT);  <br>
  pinMode (ledV, OUTPUT);  <br>
  pinMode (trig, OUTPUT);  <br>
  pinMode (echo, INPUT);  <br>
  pinMode (buzzer, OUTPUT);  <br>
    <br>
    <br>
// INICIANDO DHT11  <br>
   <br>
 dht.begin();  <br>
    <br>
    <br>
}  <br>
  <br>
void loop()  <br>
{    <br>
// FIANLIZANDO SENSOR DE DISTANCIA:  <br>
   <br>
  digitalWrite(trig, LOW); // deslida o emissor ultrasonico  <br>
  delayMicroseconds(5); // espera 5 micro segundo para execultar outra acao  <br>
  digitalWrite (trig, HIGH); // liga o emissor ultrasonico  <br>
  delayMicroseconds (10); // espera 10 micro segundo para realizar outra acao  <br>
  digitalWrite (trig, LOW); // desliga o emissor ultrassonico  <br>
    <br>
  dist = pulseIn (echo, HIGH); // liga o receptor ultrassonico   <br>
  dist = dist / 58;  //converte para cm ao dividir por 58  <br>
  Serial.print("distancia = "); // adiciona "distancia = " antes do valor do dado recebido  <br>
  Serial.print (dist); // mostra o valor do dado recebido  <br>
  Serial.print (" cm"); // adiciona "cm" ao fianl do dado recebido  <br>
  Serial.write (10);  <br>
  delay (200); // espera 2 milisegundos  <br>
    <br>
    <br>
// FINALIZANDO LDR  <br>
    <br>
  int valLDR = analogRead(ldr); // cria uma variavel, le o ldr e armazena o valor dentro da variavel criada <br>
  Serial.println(valLDR); // exibe a variavel  <br>
  Serial.print(valLDR); // define a ordem que deve aparecer, no caso o valor depois a palavra  <br>
  Serial.println(" luz"); // adiciona "luz" ao final do valor da variavel  <br>
  <br>
// FIANLIZANDO DHT11    <br>
    <br>
  float umidade = dht.readHumidity();  <br> // cria uma variavel e adiciona a ela os valores da umidade de acordo com o DHT11 <br>
  float temperatura = dht.readTemperature();  // cria uma variavel e adiciona a ela os valores da temperatura de acordo com o DHT11  <br>
    <br>
// Verifica se a leitura do sensor foi bem-sucedida  <br>
  if (isnan(umidade) || isnan(temperatura)) {  <br>
    Serial.println("Erro ao ler o sensor DHT!");  <br>
  } else {  <br>
    Serial.print("Umidade: ");  // define que a "umidade: " deve vir primeiro <br>
    Serial.print(umidade);  // logo em seguida o valor da umidade <br> 
    Serial.print(" %\t");  // e por fim a porcentagem <br>
    Serial.print("Temperatura: ");  // o mesmo que ocorre com as 3 linhas de codigo acima<br>
    Serial.print(temperatura);  <br>
    Serial.println(" °C");   <br>
  }    <br>
    <br>
    <br>
// INICIO DA ESTRUTURA DE CONDICAO  <br>
  if (dist <= 20)  // define que a distancia deve ser menor ou igual  a 20 centimentros <br>  
  {  <br>
    digitalWrite (ledR, LOW); // desliga o led  <br>
    digitalWrite (ledL, LOW); // desliga o led  <br>
    digitalWrite (ledV, HIGH); // liga o led definido  <br>
    digitalWrite(buzzer, LOW); // deixa desliagado o buzzer  <br>
    lcd.print("estoque cheio");  // exibe uma mensagem no visor LCD <br>
    delay(1500);  // espera 1500 milisegundos, ou seja 1 segundo e meio<br>
    lcd.clear();  // limpa a mensagem exibida no LCD<br>
    lcd.print(valLDR); // exibe o valor do LDR <br>
    lcd.print(" luz"); // coloca "luz" depois do valor do LDR <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(temperatura); // exibe o valor da temperatura  <br>
    lcd.print(" Celsius"); // coloca "celsius" depois do valor da temperatura  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(umidade);  // exibe o valor da umidade <br>
    lcd.print(" umidade"); // coloca "umidade" depois do valor da umidade  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
  }  <br>
    <br>
  else if ( dist >20 && dist <= 80)  // define que a distancia deve ser maior que 20 centimentros e menor ou igual a 80 centimetros <br>
  {  <br>
    digitalWrite (ledR, LOW); // desliga o led  <br>
    digitalWrite (ledL, HIGH); // liga o led definido  <br>
    digitalWrite (ledV, LOW); // desliga o led  <br>
    digitalWrite (buzzer, LOW);   <br>
    lcd.print("estoque metade");  <br>
    delay(1500);  <br>
    digitalWrite (buzzer, HIGH); // liga o buzzer <br>
    lcd.clear();  <br>
    lcd.print(valLDR);  <br>
    lcd.print(" luz");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(temperatura);  <br>
    lcd.print(" Celsius");  <br>
    delay(1500);  <br>
    digitalWrite(buzzer, LOW); // desliga o buzzer <br>
    lcd.clear();  <br>
    lcd.print(umidade);  <br>
    lcd.print(" umidade");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
  }  <br>
  else  // caso nenuma condicao anterior seja atendida, ira rodar esse comando <br>
  {  <br>
    digitalWrite (ledR, HIGH); // liga o led definido  <br>
    digitalWrite (ledL, LOW); // desliga o led  <br>
    digitalWrite (ledV, LOW); // desliga o led  <br>
    digitalWrite (buzzer, HIGH); // liga o buzzer  <br>
    lcd.print("estoque vazio");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(valLDR);  <br>
    lcd.print(" luz");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(temperatura);  <br>
    lcd.print(" Celsius");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
    lcd.print(umidade);  <br>
    lcd.print(" umidade");  <br>
    delay(1500);  <br>
    lcd.clear();  <br>
  }  <br>
    <br>
}  <br>

## # Autor
1. Gustavo Bezerra Assumção
        
  * estudande da FIAP
       
  * <a href="https://www.linkedin.com/in/gustavo-bezerra-829202289/"> linkedin </a>
        
  * <a href="https://www.instagram.com/gustavo_b017/"> Instagram </a>
    
  * <a href="https://github.com/Gustavo-b017"> Github </a>
