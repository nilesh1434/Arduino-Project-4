// Nilesh Jain - 653929943
// Lab 4 - More complicated input and output
// 1. This code is supposed to turn the lights on and off dependeing on the amount of light
// that is being given to the photoresistor. If it's dark, then all lights will glow,
// else one LED light will turn off depending on the brightness increased.
// 2. It also consists of a potentiometer to controll the loudness of the buzzer attached
// to it.
// Youtube link (Part 1) - https://youtu.be/fceGR6EKHE0
// Youtube link (Part 2) - https://youtu.be/Zn17M_yklGY

// LEDs
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

// Photoresistor
int photoresistor = A0;
int photoresistorValue = 0;

// Buzzer
int buzzer = 9;

// Potentiometer
int potentiometer = A1;
int potentiometerValue = 0;

void setup() {
  // output devices
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // input devices
  pinMode(photoresistor, INPUT);
  pinMode(potentiometer, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Photoresistor values in the range from 500-800
  
  photoresistorValue = analogRead(photoresistor);
  potentiometerValue = analogRead(potentiometer);
  Serial.println(potentiometerValue);

  // if brightness level is 100%
  if (photoresistorValue > 800) {

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } 

  // if brightness level is 75%
  else if(photoresistorValue < 800 && photoresistorValue > 700){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } 

  // if brightness level is 50%
  else if (photoresistorValue < 700 && photoresistorValue > 600) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } 

  // if brightness level is 25%
  else if(photoresistorValue < 600 && photoresistorValue > 500) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  } 

  // if brightness level is 0%
  else if (photoresistorValue < 500) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }

  byte pwm = map(potentiometerValue, 0, 1024, 0, 255);
  analogWrite(buzzer, pwm);

  // dleay for 0.1 second
  delay(100);
}
