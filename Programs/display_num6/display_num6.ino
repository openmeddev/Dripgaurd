
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

int num2disp,d0,d1,d2,t0,t1,t2,z,w,x,y;
volatile int a = 0; 
unsigned long oldtime = 0, newtime = 0, b = 0;

void setup() {
// put your setup code here, to run once:

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
  //Serial.begin(9600);

  digitalWrite(pinG1, B1);
  digitalWrite(pinG2, B1);
  digitalWrite(pinG3, B1);
}

void loop() 

{
// put your main code here, to run repeatedly:
//Serial.println(a);  
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
  for(int i = 0; i<=255; i=i+2)
  {
    delay(1);
  }
  for(int j = 255; j>=0; j=j-2)
  {
    delay(1);
  }
}

newtime = b;
oldtime = newtime;
x = newtime - oldtime;
y = 1/x;
w = num2disp/10;
t0 = num2disp%10; 
t1 = z%10;
t2 = z/10; 


   displaySetup(t2);
   digitalWrite(pinG1, B0);
   delay(2);
   digitalWrite(pinG1, B1);

   displaySetup(t1);
   digitalWrite(pinG2, B0);
   delay(2);
   digitalWrite(pinG2, B1);

   displaySetup(t0);
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
  b = millis();
}// end of pqr interrupt

