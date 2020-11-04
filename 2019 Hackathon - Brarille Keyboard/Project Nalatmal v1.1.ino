#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 4, 5);


int buttonApin = 11;
int buttonBpin = 12;
int buttonCpin = 13;
int buttonDpin = 8;
int buttonEpin = 9;
int buttonFpin = 10;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buttonApin, INPUT_PULLUP); 
pinMode(buttonBpin, INPUT_PULLUP); 
pinMode(buttonCpin, INPUT_PULLUP); 
pinMode(buttonDpin, INPUT_PULLUP); 
pinMode(buttonEpin, INPUT_PULLUP); 
pinMode(buttonFpin, INPUT_PULLUP); 


lcd.init();
lcd.backlight();
lcd.home();
lcd.blink();

byte SpecialChar1[8] = { //강
  B11010,
  B01010,
  B01011,
  B01010,
  B00000,
  B01110,
  B10001,
  B01110
};

byte SpecialChar2[8] = { //북
  B10001,
  B11111,
  B11111,
  B00000,
  B11111,
  B00100,
  B11111,
  B00001
};

byte SpecialChar3[8] = { //고
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
  B00100,
  B00100,
  B11111
};

byte SpecialChar4[8] = { //스
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B00000,
  B00000,
  B11111
};

byte SpecialChar5[8] = { //위
  B01001,
  B10101,
  B10101,
  B01001,
  B00001,
  B11111,
  B01001,
  B01001
};

byte SpecialChar6[8] = { //치
  B01001,
  B11101,
  B00101,
  B01001,
  B01001,
  B01001,
  B10101,
  B10101
};

byte SpecialChar7[8] = { //치
  B11101,
  B10001,
  B11101,
  B10001,
  B11101,
  B00000,
  B11111,
  B11111
};

lcd.createChar(1, SpecialChar1); // 저장
lcd.createChar(2, SpecialChar2);
lcd.createChar(3, SpecialChar3);
lcd.createChar(4, SpecialChar4); 
lcd.createChar(5, SpecialChar5);
lcd.createChar(6, SpecialChar6);
lcd.createChar(7, SpecialChar7);


lcd.setCursor(0,1);
lcd.write(byte(1));
lcd.write(byte(2));
lcd.write(byte(3));

lcd.setCursor(4,1);
lcd.write(byte(4));
lcd.write(byte(5));
lcd.write(byte(6));

lcd.setCursor(8,1);
lcd.write(byte(7));
lcd.print(" | V1.1");

lcd.setCursor(0,0);
}

void loop() {
  
  
  
  if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin)==HIGH and digitalRead(buttonDpin)==HIGH)
    {
      Serial.println("1");
      lcd.print("1");
      delay(2000);

     
    }

  else if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin)==HIGH and digitalRead(buttonEpin)==HIGH)
    {
      Serial.println("2");
      lcd.print("2");
      delay(2000);
      if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin)==LOW and digitalRead(buttonEpin)==HIGH)
    {
      Serial.println("6");
      lcd.print("6");
      delay(2000);
    }
    }

  else if(digitalRead(buttonApin) == LOW and digitalRead(buttonDpin) == LOW and digitalRead(buttonBpin)==HIGH and digitalRead(buttonEpin)==HIGH)
    {
      if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin)==LOW and digitalRead(buttonEpin)==HIGH)
    {
      Serial.println("6");
      lcd.print("6");
      delay(2000);
    }
    else {
      Serial.println("3");
      lcd.print("3");
      delay(2000);
    }
    }
    
  else if(digitalRead(buttonApin) == LOW and digitalRead(buttonDpin) == LOW and digitalRead(buttonEpin)==LOW)
    {
      Serial.println("4");
      lcd.print("4");
      delay(2000);
    }

  else if(digitalRead(buttonApin) == LOW and digitalRead(buttonEpin) == LOW and digitalRead(buttonBpin)==HIGH)
    {
      Serial.println("5");
      lcd.print("5");
      delay(2000);
    }
    
  

  else if(digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin) == LOW and digitalRead(buttonEpin)==HIGH)
    {
      Serial.println("9");
      lcd.print("9");
      delay(2000);
      if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin)==LOW and digitalRead(buttonEpin)==HIGH)
    {
      Serial.println("6");
      lcd.print("6");
      delay(2000);
    }
    }
  
  else if(digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin) == LOW and digitalRead(buttonEpin)==LOW and digitalRead(buttonApin)==HIGH)
    {
      Serial.println("0");
      lcd.print("0");
      delay(2000);
      if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonDpin)==LOW and digitalRead(buttonEpin)==LOW)
    {
      Serial.println("7");
      lcd.print("7");
      delay(2000);
      
    }
    }

  

  else if(digitalRead(buttonApin) == LOW and digitalRead(buttonBpin) == LOW and digitalRead(buttonEpin)==LOW and digitalRead(buttonDpin)==HIGH)
    {
      Serial.println("8");
      lcd.print("8");
      delay(2000);
    }
    
  else if(digitalRead(buttonFpin) == LOW)
    {
      lcd.init();
      lcd.backlight();
      lcd.home();
      lcd.blink();
      lcd.setCursor(0,1);
      
      Serial.println("Delete");
      
      lcd.setCursor(0,1);
      lcd.write(byte(1));
      lcd.write(byte(2));
      lcd.write(byte(3));

      lcd.setCursor(4,1);
      lcd.write(byte(4));
      lcd.write(byte(5));
      lcd.write(byte(6));

      lcd.setCursor(8,1);
      lcd.write(byte(7));
      lcd.print(" | V1.1");

      lcd.setCursor(0,0);
    }
}
