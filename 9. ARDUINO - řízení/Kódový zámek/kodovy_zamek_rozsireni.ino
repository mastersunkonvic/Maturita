#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
const byte radky = 4;
const byte sloupce = 4;

char prvniover;
char druheover;
char tretiover;
char ctvrteover;
int nigga=0;
int prvni=0;
int druha=0;
int treti=0;
int ctvrta=0;
int stav=0;
char prvniheslo='2';
char druheheslo='5';
char tretiheslo='8';
char ctvrteheslo='0';

char prvniblok='9';
char druheblok='6';
char tretiblok='3';
char ctvrteblok='2';

int pocetpok=3;

char keys[radky][sloupce] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte pinyRadku[radky] = {8, 7, 6, 5};
byte pinySloupcu[sloupce] = {9, 10, 11, 12};
Keypad keypad = Keypad( makeKeymap(keys), pinyRadku, pinySloupcu, radky, sloupce );
void setup() {
  lcd.init(); 
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
 lcd.print("Zadej heslo:");
  
}

void loop() {
 
  
  
char key = keypad.getKey();
 switch(stav){
  case 0:
 if (key) {
        if(nigga==0){
          
        
        lcd.print("*");
        prvni=key;
        }
      if(nigga==1){
          
        
        lcd.print("*");
        druha=key;
        }
         if(nigga==2){
          
        
        lcd.print("*");
        treti=key;
        }
         if(nigga==3){
          
        
        lcd.print("*");
        ctvrta=key;
        }
        nigga++;

        
    }

    if(key == '#')
    {
      if((prvniheslo==prvni) && (druheheslo==druha) && (tretiheslo==treti) && (ctvrteheslo==ctvrta)) { 
      lcd.clear();
        lcd.print("cest zmrde");
  delay(2000);
  lcd.clear();
      stav=2;
    }
    else{
  
  lcd.clear();
  lcd.print("Pocet pokusu: ");
  pocetpok=pocetpok-1;
  lcd.print(pocetpok);
  nigga=0;
  delay(2000);
  if(pocetpok>0){
  lcd.clear();
   lcd.print("Zadej heslo:");
  }
  if(pocetpok==0){
    lcd.clear();
    lcd.print("Zablokovano");
    delay(2000);
     lcd.clear();
  lcd.print("Tovarni heslo:");
   lcd.setCursor(0,1);
    stav=1;
  }
    }
   
}
 
break;

  case 1:
 
   if (key) {
        if(nigga==0){
          
        
        lcd.print("*");
        prvni=key;
        }
      if(nigga==1){
          
        
        lcd.print("*");
        druha=key;
        }
         if(nigga==2){
          
        
        lcd.print("*");
        treti=key;
        }
         if(nigga==3){
          
        
        lcd.print("*");
        ctvrta=key;
        }
        nigga++;

        
    }
     if(key == '#')
    {
      if((prvniblok==prvni) && (druheblok==druha) && (tretiblok==treti) && (ctvrteblok==ctvrta)) { 
      lcd.clear();
  lcd.print("Odblokovano");
  delay(2000);
    lcd.clear();
  lcd.print("Zadej heslo:");
  pocetpok=3;
  nigga=0;
  stav=0;
  
    }
    else{
      lcd.clear();
  lcd.print("Zkus to znovu!");
  delay(2000);
  lcd.clear();
  lcd.print("Tovarni heslo:");
  nigga=0;
  lcd.setCursor(0,1);
  

    }
}
  break;
  
  case 2:

  lcd.print("zmen heslo: A");
  lcd.setCursor(0,1);
  lcd.print("Odhlaseni: B     ");
  pocetpok=3;
   if(key == 'B'){
      nigga=0;
      lcd.clear();
   lcd.print("Zadej heslo:");
   stav=0;
    }
    if(key == 'A'){
      nigga=0;
       lcd.clear();
   lcd.print("Zadej puvodni");
   lcd.setCursor(0,1);
   lcd.print("heslo: ");
      stav=3;
    }
  break;

  case 3:
   if (key) {
        if(nigga==0){
          
        
        lcd.print("*");
        prvni=key;
        }
      if(nigga==1){
          
        
        lcd.print("*");
        druha=key;
        }
         if(nigga==2){
          
        
        lcd.print("*");
        treti=key;
        }
         if(nigga==3){
          
        
        lcd.print("*");
        ctvrta=key;
        }
        nigga++;

        
    }
    
  
   if(key == '#')
    {
      if((prvniheslo==prvni) && (druheheslo==druha) && (tretiheslo==treti) && (ctvrteheslo==ctvrta)) { 
      lcd.clear();
  lcd.print("Spravne!");
  delay(2000);
    lcd.clear();
    lcd.print("Zadejte nove: ");
    lcd.setCursor(0,1);
    nigga=0;
  stav=4;
  
    }
    else{
      lcd.clear();
  lcd.print("Zmena selhala!");
  delay(2000);
  lcd.clear();
 
  nigga=0;
stav=2;
  

    }
}
  break;
  case 4:
 if (key) {
        if(nigga==0){
          
        
        lcd.print(key);
        prvni=key;
        }
      if(nigga==1){
          
        
        lcd.print(key);
        druha=key;
        }
         if(nigga==2){
          
        
        lcd.print(key);
        treti=key;
        }
         if(nigga==3){
          
        
        lcd.print(key);
        ctvrta=key;
        }
        nigga++;

        
    }
    
  
   if(key == '#')
    {
      prvniover=prvni;
      druheover=druha;
      tretiover=treti;
      ctvrteover=ctvrta;
nigga=0;
lcd.clear();
lcd.print("Zadej znovu:");
lcd.setCursor(0,1);
  stav=5;
  
    }
    

  
  break;
  case 5:
   if (key) {
        if(nigga==0){
          
        
        lcd.print(key);
        prvni=key;
        }
      if(nigga==1){
          
        
        lcd.print(key);
        druha=key;
        }
         if(nigga==2){
          
        
        lcd.print(key);
        treti=key;
        }
         if(nigga==3){
          
        
        lcd.print(key);
        ctvrta=key;
        }
        nigga++;

        
    }
    
  
   if(key == '#')
    {
      if((prvniover==prvni) && (druheover==druha) && (tretiover==treti) && (ctvrteover==ctvrta)) { 
        prvniheslo=prvni;
        druheheslo=druha;
        tretiheslo=treti;
        ctvrteheslo=ctvrta;
      lcd.clear();
  lcd.print("Zmena uspesna!");
  delay(2000);
    lcd.clear();
  stav=2;
  
    }
    else{
      lcd.clear();
  lcd.print("Hesla neshodne!");
  delay(2000);
  lcd.clear();
 
  nigga=0;
stav=2;
  

    }
}
  
  break;
 }
  
}
