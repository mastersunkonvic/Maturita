int rh=2;
int oh=3;
int gh=4;

int rv=6;
int ov=7;
int gv=8;

int x=3,z=2,f,y=0,a=0;
const int tlacitko =5; 

float d=1000;


void setup() {
  pinMode(rh, OUTPUT);
  pinMode(oh, OUTPUT);
  pinMode(gh, OUTPUT);
  pinMode(rv, OUTPUT);
  pinMode(ov, OUTPUT);
  pinMode(gv, OUTPUT);
  
  pinMode(x,INPUT);
  pinMode(tlacitko,INPUT);
}

void loop() {
  f=digitalRead(x);
  a=digitalRead(tlacitko);
 
  
  
  if(a == HIGH)
  {
  y++;

  if(y==0)
  {
  d=2000;  
  }
  
  if(y==1)
  {
  d=1000;  
  }

  if(y==2)
  {
  d=500;  
  }

  if(y==3)
  {
  y=0;  
  }
  }


  
  if (f == HIGH)
  {
    


    
    if(z==0){   
  digitalWrite(rh, HIGH);
  digitalWrite(rv, HIGH);
  delay (2000);
  digitalWrite(rh, LOW);
  digitalWrite(rv, LOW);
  delay (100);
  z=1;
  }

  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(d); 
  //1s
  
  digitalWrite(rh, HIGH);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //2s

  digitalWrite(rh, LOW);
  digitalWrite(oh, LOW);
  digitalWrite(gh, HIGH);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //3s

  digitalWrite(rh, LOW);
  digitalWrite(oh, LOW);
  digitalWrite(gh, HIGH);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //4s

  digitalWrite(rh, LOW);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //5s

  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(d);
  //6s

  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, LOW);
  digitalWrite(gv, HIGH);
  delay(d);
  //7s
  }

  else {
  z=0;
  digitalWrite(rh, LOW);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(500);

  digitalWrite(oh, LOW);
  digitalWrite(ov, LOW);
  delay(500);
    }
}
