//[ 프로젝트 : 나랏말싸미 ]
//코드 개발 : 한석희(V2), 허준혁(버그 리포트), 윤태영(V1) / 하드웨어 : 한석희(V1, V2)

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 4, 5);


int One = 11; // 포트 별 네이밍 선언
int Two = 12;
int Three = 13;
int Four = 8;
int Five = 9;
int Six = 10;
int Piezo = 7;

void setup() {
Serial.begin(9600);
pinMode(One, INPUT_PULLUP); 
pinMode(Two, INPUT_PULLUP); 
pinMode(Three, INPUT_PULLUP); 
pinMode(Four, INPUT_PULLUP); 
pinMode(Five, INPUT_PULLUP); 
pinMode(Six, INPUT_PULLUP);
pinMode(Piezo, OUTPUT);

lcd.init();
lcd.backlight();
lcd.home();
lcd.blink();

byte Switch1[8] = { //스
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B00000,
  B11111
};

byte Switch2[8] = { //위
  B01001,
  B10101,
  B10101,
  B01001,
  B00001,
  B11111,
  B01001,
  B01001
};

byte Switch3[8] = { //치
  B01001,
  B11101,
  B00101,
  B01001,
  B01001,
  B01001,
  B10101,
  B10101
};

byte JeomJaKeyBoard1[8] = { //점
  B11101,
  B01001,
  B01011,
  B10101,
  B10101,
  B00000,
  B11111,
  B11111
};

byte JeomJaKeyBoard2[8] = { //자
  B11110,
  B01010,
  B01010,
  B01011,
  B01010,
  B10110,
  B10110,
  B10110
};

byte JeomJaKeyBoard3[8] = { //키
  B11101,
  B00101,
  B00101,
  B11101,
  B00101,
  B00101,
  B00101,
  B00101
};

byte JeomJaKeyBoard4[8] = { //보
  B10001,
  B11111,
  B10001,
  B11111,
  B00000,
  B00100,
  B00100,
  B11111
};

byte JeomJaKeyBoard5[8] = { //드
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111,
  B00000,
  B11111
};

lcd.createChar(1, Switch1); // 스
lcd.createChar(2, Switch2); // 위
lcd.createChar(3, Switch3); // 치
lcd.createChar(4, JeomJaKeyBoard1); // 점
lcd.createChar(5, JeomJaKeyBoard2); // 자
lcd.createChar(6, JeomJaKeyBoard3); // 키
lcd.createChar(7, JeomJaKeyBoard4); // 보
lcd.createChar(8, JeomJaKeyBoard5); // 보드

lcd.setCursor(0,1);
lcd.print("[");
lcd.write(byte(4));
lcd.write(byte(5));
lcd.print(" ");
lcd.write(byte(6));
lcd.write(byte(7));
lcd.write(byte(8));
lcd.print(" V2] ");
lcd.write(byte(1));
lcd.write(byte(2));
lcd.write(byte(3));
lcd.setCursor(0,0);

tone(Piezo, 2673, 100);
delay(100);
tone(Piezo, 2673, 100);
delay(200);
tone(Piezo, 2673, 100);
delay(200);
tone(Piezo, 2093, 100);
delay(100);
tone(Piezo, 2673, 100);
delay(200);
tone(Piezo, 3136, 100);
delay(400);
tone(Piezo, 1568, 100);
delay(400);
}

void loop() {
  
  if(digitalRead(One) == LOW and digitalRead(Two)==HIGH and digitalRead(Four)==HIGH)
    {
      tone(7, 523, 100);
      delay(100);
      tone(7, 659, 100);
      Serial.println("1");
      lcd.print("1");
      delay(1500);
    }

  else if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Four)==HIGH and digitalRead(Five)==HIGH)
    {
      tone(7, 587, 100);
      delay(100);
      tone(7, 698, 100);
      Serial.println("2");
      lcd.print("2");
      delay(1500);
      if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Four)==LOW and digitalRead(Five)==HIGH)
    {
      tone(7, 880, 100);
      delay(100);
      tone(7, 1046, 100);
      Serial.println("6");
      lcd.print("6");
      delay(1500);
    }
    }

  else if(digitalRead(One) == LOW and digitalRead(Four) == LOW and digitalRead(Two)==HIGH and digitalRead(Five)==HIGH)
    {
      if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Four)== LOW and digitalRead(Five)==HIGH)
    {
      tone(7, 880, 100);
      delay(100);
      tone(7, 1046, 100);
      Serial.println("6");
      lcd.print("6");
      delay(1500);
    }
    else {
      tone(7, 659, 100);
      delay(100);
      tone(7, 783, 100);
      Serial.println("3");
      lcd.print("3");
      delay(1500);
    }
    }
    
  else if(digitalRead(One) == LOW and digitalRead(Four) == LOW and digitalRead(Five)==LOW)
    {
      tone(7, 698, 100);
      delay(100);
      tone(7, 880, 100);
      Serial.println("4");
      lcd.print("4");
      delay(1500);
    }

  else if(digitalRead(One) == LOW and digitalRead(Five) == LOW and digitalRead(Two)==HIGH)
    {
      tone(7, 783, 100);
      delay(100);
      tone(7, 987, 100);
      Serial.println("5");
      lcd.print("5");
      delay(1500);
    }
    
  

  else if(digitalRead(Two) == LOW and digitalRead(Four) == LOW and digitalRead(Five)==HIGH)
    {
      tone(7, 1174, 100);
      delay(100);
      tone(7, 1396, 100);
      Serial.println("9");
      lcd.print("9");
      delay(1500);
      if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Four)==LOW and digitalRead(Five)==HIGH)
    {
      tone(7, 880, 100);
      delay(100);
      tone(7, 1046, 100);
      Serial.println("6");
      lcd.print("6");
      delay(1500);
    }
    }
  
  else if(digitalRead(Two) == LOW and digitalRead(Four) == LOW and digitalRead(Five)==LOW and digitalRead(One)==HIGH)
    {
      tone(7, 1318, 100);
      delay(100);
      tone(7, 1567, 100);
      Serial.println("0");
      lcd.print("0");
      delay(1500);
      if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Four)==LOW and digitalRead(Five)==LOW)
    {
      tone(7, 987, 100);
      delay(100);
      tone(7, 1174, 100);
      Serial.println("7");
      lcd.print("7");
      delay(1500);
      
    }
    }

  

  else if(digitalRead(One) == LOW and digitalRead(Two) == LOW and digitalRead(Five)==LOW and digitalRead(Four)==HIGH)
    {
      tone(7, 1046, 100);
      delay(100);
      tone(7, 1318, 100);
      Serial.println("8");
      lcd.print("8");
      delay(1500);
    }
    
  else if(digitalRead(Six) == LOW)
    {
      tone(Piezo, 830, 150);
      delay(150);
      tone(Piezo, 554, 150);
      delay(150);

      Serial.println("Delete");
      
      lcd.init();
      lcd.home();
      lcd.blink();
      
      lcd.setCursor(0,1);
      lcd.print("[");
      lcd.write(byte(4));
      lcd.write(byte(5));
      lcd.print(" ");
      lcd.write(byte(6));
      lcd.write(byte(7));
      lcd.write(byte(8));
      lcd.print(" V2] ");
      lcd.write(byte(1));
      lcd.write(byte(2));
      lcd.write(byte(3));
      lcd.setCursor(0,0);
    }
}
