#include "emotion.h"

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

String syncT = "";
String syncH = "";
int syncW = 2;
String rea = "";

int red = 9;
int green = 11;
int blue = 10;

void setup() { 
  Serial.begin(9600);
  pinMode(8, OUTPUT); // Piezo
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  lcd.init(); // LCD ON
  lcd.backlight(); // LCD Backlight
  lcd.home();
  
  lcd.createChar(1, temperature);
  lcd.createChar(2, humid);
  
  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.setCursor(5,0);
  lcd.print("C");
  
  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(15,0);
  lcd.print("%");
  
  lcd.setCursor(0,1);
  lcd.print("GangBuk");

  lcd.setCursor(9,1);
  lcd.print("Switch");
  
}

void loop(){
  //char receive = Serial.read();
  //rea.concat(receive);
  String receive = String(3054);
  
  syncT = receive.substring(0, 2);
  syncH = receive.substring(2, 4);
  
  lcd.setCursor(2,0);
  lcd.print(syncT);
  lcd.setCursor(12,0);
  lcd.print(syncH);

  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);

  if (syncW == 0) { // 맑음 예정
    lcd.createChar(3, sun1);
    lcd.createChar(4, sun2);
    lcd.createChar(5, sun3);
    
    lcd.setCursor(7,0);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.setCursor(7,1);
    lcd.write(byte(5));
    lcd.print("S");

    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 10);
    
    tone(8, 2637, 200);
    delay(230);
    tone(8, 2794, 200);
    delay(240);
    tone(8, 3135, 90);
    delay(100);
    tone(8, 3520, 110);
    delay(120);
    tone(8, 3135, 110);
    delay(120);
    
  }
  
  else if (syncW == 1) { // 구름 예정
    lcd.createChar(3, cloud1);
    lcd.createChar(4, cloud2);
    lcd.createChar(5, cloud3);
    
    lcd.setCursor(7,0);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.setCursor(7,1);
    lcd.write(byte(5));
    lcd.print("C");
    
    analogWrite(red, 0);
    analogWrite(green, 225);
    analogWrite(blue, 229);

    tone(8, 523, 1030);
    delay(1030);
    tone(8, 783, 360);
    delay(360);
    tone(8, 622, 520);
    delay(520);
    tone(8, 830, 410);
    delay(410);
    tone(8, 783, 350);
    delay(350);
    tone(8, 622, 230);
    delay(230);
    tone(8, 587, 100);
    delay(100);
    tone(8, 523, 1630);
    delay(1630);
  }
  

  else if (syncW == 2) { // 흐림(비) 예정
    lcd.createChar(3, cloud1);
    lcd.createChar(4, cloud2);
    lcd.createChar(5, cloud3);
    
    lcd.setCursor(7,0);
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.setCursor(7,1);
    lcd.write(byte(5));
    lcd.print("R");

    analogWrite(red, 0);
    analogWrite(green, 10);
    analogWrite(blue, 255);

    tone(8, 1046, 590);
    delay(640);
    tone(8, 784, 530);
    delay(580);
    tone(8, 1046, 350);
    delay(400);
    tone(8, 932, 540);
    delay(590);
    tone(8, 880, 360);
    delay(410);
    tone(8, 1046, 640);
    delay(690);
  
    tone(8, 523, 790);
    delay(790);
    tone(8, 1046, 740);
    delay(740);
    tone(8, 523, 620);
    delay(620);
    tone(8, 1046, 920);
    delay(920);
  }
  delay(3600000);
}
