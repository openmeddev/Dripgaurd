#include <Key.h>
#include <Keypad.h>


const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char key;
byte rowPins[ROWS] = {38, 39, 40, 41}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {42, 43, 44, 45}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int DF = 0; //Drip Factor
int IRV = 0; // Input Reservoir Volume
int IT = 0; // Input Time
int IDR = 0; //Input Drip Rate
int PRV = 0; //Preset Reservoir Volume
int TH = 5; // limit for variation in dpm around desired value (IDR)


int pinA=22;
int pinB=23;
int pinC=24;
int pinD=25;
int pinE=26;
int pinF=27;
int pinG=28;
int pinH=29;

int pinG1=9;
int pinG2=10;
int pinG3=11;
int pinG4=12;

int num2disp,d0,d1,d2,d3,z;
int dpm;
volatile int a = 0;
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0;
int dt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int avg = 0;
int i = 0;
boolean drop = false;
float temp;


void setup() {
  Serial.begin(9600);
  pinMode(alarm_pin,OUTPUT); 

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
}

void loop() 
{
  int num;
  key = keypad.getKey();

  if (key != NO_KEY) 
  {
    Serial.println(key);
  }
  if ((key == 'A') || (key == 'B') || (key == 'C') || (key == 'D') || (key == '#')) 
  {
    num = numinput();
    Serial.println("here");
    Serial.println(key);
    Serial.println(num);

    if (num != -1) {
      Serial.println("here2");
      switch (key) 
      {
          case 'A':
          if ((num <= 60) && (num >= 5)) 
          {
            DF = num;
            Serial.print("Drip Factor:");
            Serial.println(DF);
          }
          else 
          {
            beep();
            Serial.println("Incorrect Drip Factor");
          };
          break;

          case 'B';
          if ((num <= 1000) && (num >= 50)) 
          {
            IRV = num;
            Serial.print("Input Reservoir Volume:");
            Serial.println(IRV);
          }
          else 
          {
            beep();
            Serial.println("Incorrect Intial Reservoir Volume");
          };
          break;

          case 'C':
          if ((num <= 1440) && (num >= 30)) 
          {
            IT = num;
            Serial.print("Infusion Time:");
            Serial.println(IT);
            IDR = ((IRV*DF)/IT);  // drip rate calculatio
            Serial.print("Drip Rate:");
            Serial.println(IDR);
          }
          else 
          {
            beep();
            Serial.println("Incorrect Infussion Time");
          };
          break;
          
          case 'D':
          if ((num <= 200) && (num >= 2)) 
          {
            IDR = num;
            Serial.print("Input Drip Rate:");
            Serial.println(IDR);
            IT = ((IRV*DF)/IDR); // time calculation
            Serial.print("Infusion Time:");
            Serial.println(IT);
          }
          else 
          {
            beep();
            Serial.println("Incorrect Input Drip Rate");
          };
          break;
          case '#':
          if ((num <= 1000) && (num >= 50)) 
          {
            PRV = num;
            Serial.print("Preset Reservior Volume:");
            Serial.println(PRV);
          }
          else 
          {
            beep();
            Serial.println("Incorrect Preset Reservior Volume");
          };
          break;
          default:
          break;
      }//end of switch
    }//end of if num!=-1


  }// end of number input

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
  //num2disp=7465;
  display_num(dpm);

  if ((dpm> IDR+TH) || (dpm<IDR-TH))
  beep(); 
}//end of loop

int numinput()
{
  Serial.println(" Please input number  on key pad  and press star:");

  char key2;
  int num1 = 0;
  int digit = 0;
  while (true) 
  {
    key2 = keypad.getKey();
    while (key2 == NO_KEY) 
    {
      key2 = keypad.getKey();
      display_num(num1);
    }//end of inner while loop
    
    if ((key2 == 'A') || (key2 == 'B') || (key2 == 'C') || (key2 == 'D') || (key2 == '#'))
    {
      Serial.print("wrong key pressed:");
      Serial.println(key2);
      beep();
      return (-1);
      break;
    }
    else if (key2 == '*')
    {
      Serial.print("Exiting key input");
      Serial.println(key2);
      return (num1);
      break;
    }
    else 
    {
      digit = int(key2) - int('0');
      num1 = num1 * 10 + digit;
      display_num(num1);
      if (num1 > 9999) 
      {
        beep();
        return (-1);
        break;
      }
    }

  }// end of top while loop

  Serial.println(" end of keyinput");
}

void beep()
{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(BUZZER, HIGH);  
    delay(250);  
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(BUZZER, LOW);
    delay(250);
}//end of beep

void display_num(int num2disp){
  if (num2disp<10000)
  {
    z = num2disp/10;
    d0 = num2disp%10; 
    d1 = z%10;
    z=z/10;
    d2=z%10;
    d3=z/10;
     
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
}//end of displaySetup

void pqr()//interrupt program
{
  newtime = millis();
  deltat = newtime - oldtime;
  oldtime = newtime;
  drop = true;
}// end of pqr interrupt

