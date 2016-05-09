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
  
}

void loop() 

{
  // put your main code here, to run repeatedly:
  

   digitalWrite(pinG1, B1);
   digitalWrite(pinG2, B1);
   digitalWrite(pinG3, B1);
   
   displaySetup(9);
   digitalWrite(pinG1, B0);
   delay(2);
   digitalWrite(pinG1, B1);

   displaySetup(9);
   digitalWrite(pinG2, B0);
   delay(2);
   digitalWrite(pinG2, B1);

   displaySetup(9);
   digitalWrite(pinG3, B0);
   delay(2);
   digitalWrite(pinG3, B1);
}

void displaySetup(int q)   //q is the digit to be displayed
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
}

