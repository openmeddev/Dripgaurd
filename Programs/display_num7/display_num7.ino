
int pinA = 0;
int pinB = 1;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinH = 12;
int pinG1 = 9;
int pinG2 = 10;
int pinG3 = 11;

int num2disp, d0, d1, d2, dpm;
volatile int a = 0;
//volatile unsigned long newtime = 0;
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0;
float temp; //
char message[500];
void setup() {
  // put your setup code here, to run once:

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

  attachInterrupt(0, pqr, FALLING); //INT0 on pin2
  Serial.begin(9600);

  digitalWrite(pinG1, B1);
  digitalWrite(pinG2, B1);
  digitalWrite(pinG3, B1);
}

void loop()

{
  // put your main code here, to run repeatedly:
  //
  temp = (1.0 / deltat);
  dpm = (temp * 1000 * 60);
  num2disp = dpm;
  Serial.println(deltat);
  //sprintf(message,"%2.5" ,temp);
  //Serial.println(message);
  Serial.println(dpm);
  Serial.println("abcd");
//  if (num2disp < 1000)
//  {
//    z = num2disp / 10;
//    d0 = num2disp % 10;
//    d1 = z % 10;
//    d2 = z / 10;
//  }
//
//  else
//  {
//    for (int i = 0; i <= 255; i = i + 2)
//    {
//      delay(1);
//    }
//    for (int j = 255; j >= 0; j = j - 2)
//    {
//      delay(1);
//    }
//  }
//
//  newtimee = newtime * 60000;
//  if (newtimee < 1000)
//  {
//    x = newtimee - oldtime;
//    oldtime = newtimee;
//    y = 1 / x;
//    w = y / 10;
//    t0 = y % 10;
//    t1 = w % 10;
//    t2 = w / 10;
//  }
//
//  displaySetup(t2);
//  digitalWrite(pinG1, B0);
//  delay(2);
//  digitalWrite(pinG1, B1);
//
//  displaySetup(t1);
//  digitalWrite(pinG2, B0);
//  delay(2);
//  digitalWrite(pinG2, B1);
//
//  displaySetup(t0);
//  digitalWrite(pinG3, B0);
//  delay(2);
//  digitalWrite(pinG3, B1);
}//end of loop

void displaySetup(int q)//q is the digit to be displayed
{
  switch (q)
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
}// end of pqr interrupt

