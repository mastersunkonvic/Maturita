#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#define x 2
LiquidCrystal_I2C lcd(0x27,16,2);
byte customChar[8] = {
  0b00110,
  0b01001,
  0b01001,
  0b00110
  ,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

float tep;
float maxtep=-100;
float mintep=1000;
int red=10;
int green=9;
int blue=8;

OneWire oneWire(x);                        
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("Teplomer s teplotnim snimacem DS18B20");
  Serial.println("Nacitani nejvyssich a nejnizsich hodnot z teplotniho snimace...");  
  lcd.init();
  lcd.backlight();
  pinMode(x,INPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  sensors.begin();
  lcd.createChar(0, customChar);
}

void loop(){
  sensors.requestTemperatures();
  tep=sensors.getTempCByIndex(0);
  if(tep>maxtep)
  {
    maxtep=tep;
  }
  
  if(tep<mintep)
  {
    mintep=tep;
  }  
    
  if(tep>28.5)
  {
    klimatizace();
  }
 
   if(tep<26.5)
   { 
     topeni();    
   }

  if(tep>26.5 && tep<28.5)
  {
    klid();
  }
  vypis();
  
}

void topeni() 
  {
    digitalWrite(green,0);
    digitalWrite(red,255);
    digitalWrite(blue,0);
    lcd.setCursor(0,0);
    lcd.print("TOPENI=ON");
    lcd.setCursor(0,1);
    lcd.print("KLIMATIZACE=OFF");
    delay(2500);
    lcd.setCursor(0,0);
    lcd.print("TEPLOTA:        ");
    lcd.setCursor(0,1);
    lcd.print(tep,4);
    lcd.write(0);    
    lcd.print("C               ");
    delay(2500);
  }

void klimatizace() 
  {
    digitalWrite(green,0);
    digitalWrite(red,0);
    digitalWrite(blue,255);
    lcd.setCursor(0,0);
    lcd.print("KLIMATIZACE=ON");
    lcd.setCursor(0,1);
    lcd.print("TOPENI=OFF");
    delay(2500);
    lcd.setCursor(0,0);
    lcd.print("TEPLOTA:        ");
    lcd.setCursor(0,1);
    lcd.print(tep,4);
    lcd.write(0);  
    lcd.print("C               ");
    delay(2500);
  }

void klid()
  {
    digitalWrite(green,255);
    digitalWrite(red,0);
    digitalWrite(blue,0);
    lcd.setCursor(0,0);
    lcd.print("TOPENI=OFF");
    lcd.setCursor(0,1);
    lcd.print("KLIMATIZACE=OFF");
    delay(2500);
    lcd.setCursor(0,0);
    lcd.print("TEPLOTA:        ");
    lcd.setCursor(0,1);
    lcd.print(tep,4);
    lcd.write(0);  
    lcd.print("C               ");
    delay(2500);
  }

void vypis()
  {
  Serial.println("Maximalni teplota je: ");
  Serial.println(maxtep,4);
  Serial.println("Minimalni teplota je: ");
  Serial.println(mintep,4);
  Serial.println("\n");
  }
