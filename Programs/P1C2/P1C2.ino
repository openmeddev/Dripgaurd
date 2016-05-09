
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
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0;
int dt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int avg = 0;
int i = 0;
boolean drop = false;
float temp;

void setup() 
{
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
    Serial.println(deltat);
    Serial.println("dt[]");
    Serial.println(dt[0]);
    Serial.println(dt[1]);
    Serial.println(dt[2]);
    Serial.println(dt[3]);
    Serial.println(dt[4]);
    Serial.println(dt[5]);
    Serial.println(dt[6]);
    Serial.println(dt[7]);
    Serial.println(dt[8]);
    Serial.println(dt[9]);

    Serial.println(avg);
    Serial.println(dpm);
    Serial.println("abcd");
    drop=false;
  }
}

void pqr()//interrupt program
{
  newtime = millis();
  deltat = newtime - oldtime;
  oldtime = newtime;
  drop = true;
}// end of pqr interrupt

