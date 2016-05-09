
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
int dpm;
volatile int a = 0;
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0;
int dt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int avg = 0;
int i = 0;
boolean drop = false;
float temp;

void setup() 
{
  attachInterrupt(0, pqr, FALLING); //INT0 on pin2
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinH, OUTPUT);

  pinMode(pinG1, OUTPUT);
  pinMode(pinG2, OUTPUT);
  pinMode(pinG3, OUTPUT);

  digitalWrite(pinG1, B1);
  digitalWrite(pinG2, B1);
  digitalWrite(pinG3, B1);
}

void loop()
{
  if (drop == true)
  {
    dt[9] = dt[8];
    dt[8] = dt[7];
    dt[7] = dt[6];
    dt[6] = dt[5];
    dt[5] = dt[4];
    dt[4] = dt[3];
    dt[3] = dt[2];
    dt[2] = dt[1];
    dt[1] = dt[0];    
    dt[0] = deltat;
    avg = ((dt[0] + dt[1] + dt[2] + dt[3] + dt[4] + dt[5] + dt[6] + dt[7] + dt[8] + dt[9]) / 10);
    temp = (1.00 / avg);
    dpm = (temp * 1000 * 60);
    num2disp = dpm;
    drop = false;
  }
  if (num2disp<1000)
  {
    z = num2disp/10;
    d0 = num2disp%10; 
    d1 = z%10;
    d2 = z/10; 
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
  newtime = millis();
  deltat = newtime - oldtime;
  oldtime = newtime;
  drop = true;
}// end of pqr interrupt

