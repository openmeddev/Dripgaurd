

// Pins declaration for SSD
// Segment pins
int pinA = 22;
int pinB = 23;
int pinC = 24;
int pinD = 25;
int pinE = 26;
int pinF = 27;
int pinG = 28;
int pinH = 29;

int BUZZER = 46;
int CALIBERATE_BUTTON = 47;
int ALARM_SILENCE_BUTTON = 48;

int LED1 = 30;
int LED2 = 31; 
int LED3 = 32;
int LED4 = 33;
int LED5 = 34;
int LED6 = 35;
int LED7 = 36;
int LED8 = 37;

// Ground(Cathode)
int pinG1 = 9;
int pinG2 = 10;
int pinG3 = 11;
int pinG4 = 12;

int num2disp,d0,d1,d2,d3,A,B;
int dpm;
volatile int a = 0;
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0; deltat2 = 0; currenttime =0;
int dt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int avg = 0;
int i = 0;
boolean drop = false;
float temp;
int val1, val2;


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
  pinMode(pinG4, OUTPUT);

  digitalWrite(pinG1, B1);
  digitalWrite(pinG2, B1);
  digitalWrite(pinG3, B1);
  digitalWrite(pinG4, B1);

  pinMode(LED1, OUTPUT);   //  leds 
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  
  pinMode(BUZZER, OUTPUT);  // buzzer
  pinMode(CALIBERATE_BUTTON, INPUT);   // refresh button #2
  pinMode(ALARM_SILENCE_BUTTON, INPUT);   // alarm silence button  #3
  
  Serial.begin(9600);
  
}

void loop()
{

  val1 = digitalRead(47);
  if (val1 == HIGH)
  {
    CALIBERATE();
  }
  
  currenttime=millis();
  deltat2 = currenttime - oldtime;
  if (deltat2 > 30000)
  {
    ALERT();
  }

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
    Serial.println("Delta t");
    Serial.println(deltat);
    Serial.println("Drip count");
    Serial.println(a);
    Serial.println("Drop rate");
    Serial.println(dpm);
    drop = false;
  }

  if (num2disp<10000)
  {
    A = num2disp/10;
    d0 = num2disp%10; 
    B = A/10;
    d1 = A%10; 
    d2 = B%10;
    d3 = B/10;
  }

   displaySetup(d3);
   digitalWrite(pinG1, B0);
   delay(2);
   digitalWrite(pinG1, B1);

   displaySetup(d2);
   digitalWrite(pinG2, B0);
   delay(2);
   digitalWrite(pinG2, B1);

   displaySetup(d1);
   digitalWrite(pinG3, B0);
   delay(2);
   digitalWrite(pinG3, B1);

   displaySetup(d0);
   digitalWrite(pinG4, B0);
   delay(2);
   digitalWrite(pinG4, B1);
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
}  //end of displaySetup


void pqr()//interrupt program
{
  a++;
  newtime = millis();
  deltat = newtime - oldtime;
  oldtime = newtime;
  drop = true;
}// end of pqr interrupt

void ALERT ()
{
  x = analogRead(LDR_top);
  y = analogRead(LDR_bottom);
  
  if ((x-y)<10)&((x-y)>-10)
  {
    if ((x == truevalue1) && (y == truevalue2))   // drip stopped - case3 in book
    {
       ALARM(LED1);
    }
  }
  else
  {
    if ((x > truevalue1) && (y == truevalue
      ALARM(32);
    }
  }
}
/*
if ((x == truevalue1) && (y == truevalue2))
{
  ALARM(30);
}
else if  ((x > truevalue1) && (y == truevalue2))
{
  ALARM(31);
}
else if ((x == truevalue1) && (y < truevalue2))
{
  ALARM(32);
}
*/
void REFRESH ()
{
  truevalue1 = analogRead(A0);
  truevalue2 = analogRead(A1);
  DC = 0;
  MDR = 0;
}

void ALARM (int p)
{
  
  digitalWrite(p, HIGH);
  //val2 = digitalRead(48);
  //val2 = digitalRead(alarm_stop_pin);
    digitalWrite(BUZZER, HIGH);
    //delay(500);
    //digitalWrite(46, LOW);
    //delay(500);
    //alarmtime = millis()-starttime;
  
}


