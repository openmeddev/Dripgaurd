
int pinA=0;
int pinB=1;
int pinC=4;
int pinD=5;
int pinE=6;
int pinF=7;
int pinG=8;
int pinH=12;
int pinG1=9;
int pinG2=10;
int pinG3=11;

int num2disp,d0,d1,d2,z;
volatile int a = 0;

void setup() 
{
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinH,OUTPUT);

  pinMode(pinG1,OUTPUT);
  pinMode(pinG2,OUTPUT);
  pinMode(pinG3,OUTPUT);
  
  attachInterrupt(0,pqr,FALLING);
  
  digitalWrite(pinG1, B1);
  digitalWrite(pinG2, B1);
  digitalWrite(pinG3, B1);
}

void loop() 

{ 
  num2disp = a;
  if (num2disp<1000)
  {
    z = num2disp/10;
    d0 = num2disp%10; 
    d1 = z%10;
    d2 = z/10; 
  }
  else
  {
    for(int i = 0; i<=255; i++)
    {
      analogWrite(pinG1, i);           // sets the value (range from 0 to 255) 
      analogWrite(pinG2, i); 
      analogWrite(pinG3, i);           // sets the value (range from 0 to 255) 
      delay(5);
    }
    for(int j = 255; j>=0; j--)
    {
      analogWrite(pinG1, j);           // sets the value (range from 0 to 255) 
      analogWrite(pinG2, j); 
      analogWrite(pinG3, j);
      delay(5);
    }
  }
   
   displaySetup(d2);
   digitalWrite(pinG1, B0);
   delay(2);
   digitalWrite(pinG1, B1);

   displaySetup(d1);
   digitalWrite(pinG2, B0);
   delay(2);
   digitalWrite(pinG2, B1);

   displaySetup(d0);
   digitalWrite(pinG3, B0);
   delay(2);
   digitalWrite(pinG3, B1);
}

void displaySetup(int q)//q is the digit to be displayed
{
  switch(q)
  {
    case 1:
    digitalWrite(pinA, B0);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B0);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B0);
    digitalWrite(pinG, B0);
    digitalWrite(pinH, B0);
    break;

    case 2:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B0);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B1);
    digitalWrite(pinF, B0);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 3:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B0);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 4:
    digitalWrite(pinA, B0);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B0);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 5:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B0);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 6:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B0);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B1);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 7:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B0);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B0);
    digitalWrite(pinG, B0);
    digitalWrite(pinH, B0);
    break;

    case 8:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B1);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 9:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B0);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B1);
    digitalWrite(pinH, B0);
    break;

    case 0:
    digitalWrite(pinA, B1);
    digitalWrite(pinB, B1);
    digitalWrite(pinC, B1);
    digitalWrite(pinD, B1);
    digitalWrite(pinE, B1);
    digitalWrite(pinF, B1);
    digitalWrite(pinG, B0);
    digitalWrite(pinH, B0);
    break;

    default :
    digitalWrite(pinA, B0);
    digitalWrite(pinB, B0);
    digitalWrite(pinC, B0);
    digitalWrite(pinD, B0);
    digitalWrite(pinE, B0);
    digitalWrite(pinF, B0);
    digitalWrite(pinG, B0);
    digitalWrite(pinH, B0);
    break;
  }
}//end of displaySetup

void pqr()//interrupt program
{
  a++;
}// end of pqr interrupt

