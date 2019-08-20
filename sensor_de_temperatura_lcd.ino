#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
float centi(){
  int dato;
  float c;
  dato=analogRead(A0);
  c=(500.0 * dato)/1023;
  return (c); 
}
float kelvin(float cent){
  float k;
  k=cent+273.15;
  return (k);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  lcd.begin(16,2);
  lcd.print("C=      K=");
  lcd.setCursor(0,1);
  lcd.print("Temperatura");
}

void loop() {
  // put your main code here, to run repeatedly:
  float Centigrados = centi();
  float Kelvin = kelvin(Centigrados);
  if(Centigrados < 23){
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  } else if ( Centigrados > 22 && Centigrados < 25 ){
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
  } else{
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }

  lcd.setCursor(2,0);
  lcd.print(Centigrados);

  lcd.setCursor(10,0);
  lcd.print(Kelvin);

  delay(500);
}
