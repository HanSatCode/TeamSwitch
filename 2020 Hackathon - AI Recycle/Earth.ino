#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h> // 서보 모터에 필요한 라이브러리 불러오기
Servo servoClassification1;
Servo servoClassification2;

void basics() {
  servoClassification1.write(90);                   // 프로그램 실행 시 서보 모터 기본 각도 90도 설정
  servoClassification2.write(90);                   // (위와 동일)
}
void plastic() {
  servoClassification1.write(0);                    // '플라스틱'이라고 인식되면 특정 방향으로 회전
  servoClassification2.write(180);                   // (위와 동일)
}
void can() {
  servoClassification1.write(180);                   // '캔'이라고 인식되면 특정 방향으로 회전
  servoClassification2.write(0);                    // (위와 동일)
}
void test(){
  servoClassification1.write(180);
  servoClassification2.write(180);
}

void canPrint(){
  lcd.init();
  lcd.setCursor(14,0);
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.setCursor(14,1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,0);
  lcd.write(byte(7));
  lcd.print(" CAN");
  lcd.init();
}

void plasticPrint(){
  lcd.init();
  lcd.setCursor(14,0);
  lcd.write(byte(5));
  lcd.write(byte(6));
  lcd.setCursor(14,1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,0);
  lcd.write(byte(7));
  lcd.print(" PLASTIC");
}

void nullPrint() {
  lcd.init();
  lcd.setCursor(0,0);
  lcd.write(byte(7));
  lcd.print(" NULL");
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  byte CAN1[8] = {
  B00111,
  B01000,
  B10100,
  B10011,
  B10000,
  B10000,
  B10000,
  B10000
  };

  byte CAN2[8] = {
  B11100,
  B00010,
  B00101,
  B11001,
  B00001,
  B00001,
  B00001,
  B00001
  };

  byte CAN3[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B01000,
  B00111
  };

  byte CAN4[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00010,
  B11100
  };

  byte PLASTIC1[8] = {
  B00011,
  B00100,
  B00110,
  B00101,
  B01000,
  B10000,
  B10000,
  B10000
  };

  byte PLASTIC2[8] = {
  B11000,
  B00100,
  B01100,
  B10100,
  B00010,
  B00001,
  B00001,
  B00001
  };

  byte Question[8] = {
  B11111,
  B10001,
  B10001,
  B00001,
  B00111,
  B00100,
  B00000,
  B00100
  };
  

  lcd.createChar(1, CAN1);
  lcd.createChar(2, CAN2);
  lcd.createChar(3, CAN3);
  lcd.createChar(4, CAN4);
  lcd.createChar(5, PLASTIC1);
  lcd.createChar(6, PLASTIC2);
  lcd.createChar(7, Question);
  
  servoClassification1.attach(7);
  servoClassification2.attach(4);
  
  basics();
  lcd.setCursor(0,0);
  lcd.print(" 2020 Hackathon ");
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();
    delay(2000);
    
    if (input == 'c') {
      lcd.init();
      canPrint();
      can();
      delay(1000);
      basics();
    } 
    else if (input == 'p') {
      lcd.init();
      plasticPrint();
      plastic();
      delay(1000);
      basics();
    }
    else if (input == 'n') {
      lcd.init();
      nullPrint();
      basics();
    }
  }
}
