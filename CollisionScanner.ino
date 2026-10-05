//10/04/26
//Collision Scanner - Arjun Amarakone

#include <LiquidCrystal.h>
#include <limits.h>

const int Trig = 4; //Trig Sensor
const int Echo = 2; //Echo Sensor
const int LEDG = 3; //RGB Green 
const int LEDB = A1; //RGB Blue 
const int LEDR = A2; //RGB Red
const int Enable = 6; //Enable Pin LCD
const int DB4 = 12; //Pin 4 LCD
const int DB5 = 11; //Pin 5 LCD
const int DB6 = 10; //Pin 6 LCD
const int DB7 = 9; //Pin 7 LCD
const int RS = 7; //Register Select LCD
const int Buzzer = 5; //Buzzer pin

LiquidCrystal lcd(RS, Enable, DB4, DB5, DB6, DB7); //create LCD object

void setup() { //State LCD dimensions to library (16x2) & ultrasonic sensor pins & buzzer
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDR, OUTPUT);
}

long distance; //variable to hold distance value

void loop(){

  //set title on LCD
  lcd.setCursor(0,0);
  lcd.print("Distance(cm):"); 

  lcd.setCursor(0,1);

  //send trigger pulse
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);


  long duration = pulseIn(Echo, HIGH);
  distance = duration * 0.034 / 2;
  lcd.print(distance);
  lcd.print("cm.    ");//extra spaces to clear LCD 

  if(distance <= 10){ //LED turns red on if distance < 10cm
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDR,HIGH);
    tone(Buzzer, 2000);//high pitched buzzer
  }else if(distance > 10 && distance <= 20) { //LED turns Yellow within 20-10cm
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDR,HIGH); 
    tone(Buzzer, 800);//lower pitched buzzer  
  }else{ //turn buzzer and RGB to green
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDR,LOW);
    noTone(Buzzer);
  }
}//end of loop