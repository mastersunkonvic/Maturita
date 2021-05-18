#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', 'E', '0', '#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad klavesnice = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char klavesa;
int pokus=0;
int i=0;
int n=0;
int x=0;
int o=0;
char heslomain[]="1234";
char servisheslo[]="1111";
char heslo[4];


void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
  
void loop()
{
  if(o==0) // o je všeobecný stav 
  {
  lcd.print("                          ");
  lcd.setCursor(0, 0);
  lcd.print("Zadejte Heslo:");
  klavesa = klavesnice.getKey();
  if(klavesa && n<4) // pokud se klikne klávesa a zároveň se klikne 4x (0x,1x,2x,3x)
  {
    lcd.setCursor(n,1); //vždycky se ten "*" znak posune
    lcd.print("*");
    heslo[n]=klavesa;    //pokus se to z té klávesy rovná tomu stálému heslu
    n++;
  }

if(klavesa == '#') //potvrzení musí být jako první podmínka
  {
    for(i=0; i<4; i++) //teď použiju ičko pro porovnání všech hodnot v poli
    {
      if(heslomain[i]==heslo[i])
      {
        x++; //každá stejná hodnota v poli se přičte jako x++
      }
    }
      
  if(x==4) //přijetí hesla
    {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Heslo prijato");
    delay(2000);
    lcd.clear();
    lcd.print("Vitejte");
    delay(1500);
    lcd.clear();
    o=1;
    }
  else if(x!=4) //špatně heslo
    {
    pokus++;
    n=0;
    i=0;   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Spatne - pokus:");
    lcd.print(pokus);
    delay(2000); 
    if(pokus==3) //3 špatné pokusy, takže blokace
    {
    o=2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Blokace");
    delay(1500);
    lcd.clear();  
    }
    }
  }
 }

  if(o==1) //přihlášení menu
  {
    lcd.print("                               ");
    lcd.setCursor(0, 0);
    lcd.print("Zmena hesla- D"); 
    lcd.setCursor(0, 1);
    lcd.print("Odhlasit- 0");
    klavesa=klavesnice.getKey();

    if(klavesa == '0')
    {
    o=0;
    n=0;
    x=0;
    lcd.clear();
    }

    if(klavesa == 'D')
    {
      
    }
  }
  
  
  if(o==2) //po blokaci zadej servnisní pin
  {
    lcd.setCursor(0, 0);
    lcd.print("Zadejte pin:");
    klavesa=klavesnice.getKey();
    if(klavesa && n < 4)
    {
      lcd.setCursor(n, 1);
      lcd.print("*");
      heslo[n]=klavesa;
      n++;
    }

    if (klavesa == '#')
    {
      for(i=0;i<4;i++)
      {
        if(servisheslo[i]==heslo[i]) //teď se porovnává se servisním pinem
        {
          x++;   
        }
      }
    if(x < 4) //špatně pin, takže se opakuje toto větev
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Spatne");
      delay(2000);
      lcd.clear();
      n=0;
      o=2;
    }

    if(x == 4) //správně pin, takže probíhá operace 0 pro zadání normálního hesla
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Vitejte");
      delay(2000);
      lcd.clear();
      n=0;
      o=0;
      x=0;
      pokus=0;
    }
    
    }
  }
  if (klavesa){ 
    Serial.println(klavesa); //vypsání klávesy na servisní monitor
  }
 
}
