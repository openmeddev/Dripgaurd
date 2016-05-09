#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
char key;
byte rowPins[ROWS] = {38, 39, 40, 41}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {42, 43, 44, 45}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int DF = 15; //Drip Factor
int IRV = 500; // Input Reservoir Volume
int IT = 250; // Input Time
int IDR = 30; //Desired Drip Rate
int PRV = IRV; //Preset Reservoir Volume - addtional alarm when reached 
int TH = 5; // Threshold for alarms variation in drip rate

// Pins declaration for Seven segment display
// Segment pins
int pinA = 22;
int pinB = 23;
int pinC = 24;
int pinD = 25;
int pinE = 26;
int pinF = 27;
int pinG = 28;
int pinH = 29;

int BUZZER = 46; //for alarm

int CALIBERATE_BUTTON = 47;
int ALARM_SILENCE_BUTTON = 48;
int START_OR_STOP_BUTTON = 49;

int ALARM_LED1 = 30;
int ALARM_LED2 = 31; 
int ALARM_LED3 = 32;
int ALARM_LED4 = 33;
int ALARM_LED5 = 34;
int ALARM_LED6 = 35;
int ALARM_LED7 = 36;
int ALARM_LED8 = 37;

int LDR1 = 0; //reading of LDR1 (top)
int LDR2 = 0; //reading of LDR2 (bottom)

// Ground(Cathode) For SSD
int pinG1 = 9;
int pinG2 = 10;
int pinG3 = 11;
int pinG4 = 12;

int num2disp,d0,d1,d2,d3,A,B;
volatile int DC = 0; // drop count
volatile unsigned long oldtime = 0, newtime = 0, deltat = 0, deltat2 = 0, currenttime =0;
int dt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int avg = 0;
int i = 0;
boolean drop = false;
float temp; 
int val1, val2;
int MDR = 0; //measured drip rate
int CRV = 0; // current reservior volume 
int X = 0;// used for alarms 
int Y = 0;// used for alarms 
int Z = 0;// used for alarms 
int truevalue1 = 0, truevalue2 = 0; // for analog read of LDR during refresh
boolean alarm_on = false;
boolean start = false;

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

  pinMode(ALARM_LED1, OUTPUT);   //  leds 
  pinMode(ALARM_LED2, OUTPUT);
  pinMode(ALARM_LED3, OUTPUT);
  pinMode(ALARM_LED4, OUTPUT);
  pinMode(ALARM_LED5, OUTPUT);
  pinMode(ALARM_LED6, OUTPUT);
  pinMode(ALARM_LED7, OUTPUT);
  pinMode(ALARM_LED8, OUTPUT);

  pinMode(BUZZER, OUTPUT);  // buzzer

  pinMode(CALIBERATE_BUTTON, INPUT);   // refresh button #2
  pinMode(ALARM_SILENCE_BUTTON, INPUT);   // alarm silence button  #3
  pinMode(START_OR_STOP_BUTTON, INPUT); // start or stop button #4

  Serial.begin(9600);
}

void loop()
{
  CRV = (DC/DF) ; // Current reservoir volume
  
  X = ((1/10)*IRV); // MOVE to
  Y = ((1/20)*IRV);
  Z = ((1/20)*PRV); 
     
  int num;
  key = keypad.getKey();
  if (key != NO_KEY) 
  {
    Serial.println(key);
  }
  if ((key == 'A') || (key == 'B') || (key == 'C') || (key == 'D') || (key == '#')) 
  {
    num = numinput();
    Serial.println(key);
    Serial.println(num);
  }

  if (num != -1) 
  {
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
        BEEP();
        Serial.println("Incorrect Drip Factor");
      };
      break;
      
      case 'B':
      if ((num <= 1000) && (num >= 50)) 
      {
        IRV = num;
        Serial.print("Input Reservoir Volume:");
        Serial.println(IRV);
       }
       else 
       {
        BEEP();
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
        Serial.print("Input Drip Rate:");
        Serial.println(IDR);
       }
       else 
       {
        BEEP();
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
        BEEP();
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
        BEEP();
        Serial.println("Incorrect Preset Reservior Volume");
       };
       break;
       default:
       break;
      }//end of switch
     }//end of if num!=-1
     
     val1 = digitalRead(CALIBERATE_BUTTON); // code for caliberate button
     if (val1 == HIGH)
     {
      CALIBERATE();
     }
     
     currenttime = millis();
     deltat2 = currenttime - oldtime;
     if (deltat2 > 10000) //name 10000 as something 
     {
      ALARM(ALARM_LED1);
     }else{
      
     }
     
     if (alarm_on)
     {
      digitalWrite(BUZZER, HIGH);
      Serial.println("alarm is on ");
     }
     else
     {
      digitalWrite(BUZZER, LOW);
      Serial.println("alarm is off ");
     }
     
     val2 = digitalRead(ALARM_SILENCE_BUTTON);
     if (val2 == HIGH)
     {
      alarm_on= false;
      Serial.print("Truning alarm off");
     }
     
     if (CRV == X)// change to range
     {
      ALARM(ALARM_LED2);
     }
     
     if(CRV == Y)// change to range 
     {
      ALARM(ALARM_LED3);
     }
     
     if ((MDR > (IDR+TH)) | (MDR < (IDR-TH)))
     {
      ALARM(ALARM_LED4);
     }else{
      check if alarm4 is on then 
      
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
      MDR = (temp * 1000 * 60);
      Serial.println("Drip count");
      Serial.println(DC);
      Serial.println("Drop rate");
      Serial.println(MDR);
      drop = false;
     }

     display_num(MDR); //display measured drip rate
     
}// End of voidloop

int numinput() // function
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
      BEEP();
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
        BEEP();
        return (-1);
        break;
      }
    }
  }  // end of above while loop
  
  Serial.println(" end of keyinput");

}

void BEEP()  // function
{
    digitalWrite(ALARM_LED1, HIGH);
    digitalWrite(ALARM_LED2, HIGH);
    digitalWrite(ALARM_LED3, HIGH);
    digitalWrite(ALARM_LED4, HIGH);
    digitalWrite(ALARM_LED5, HIGH);
    digitalWrite(ALARM_LED6, HIGH);
    digitalWrite(ALARM_LED7, HIGH);
    digitalWrite(ALARM_LED8, HIGH);
    digitalWrite(BUZZER, HIGH);  
    delay(250);  
    digitalWrite(ALARM_LED1, LOW);
    digitalWrite(ALARM_LED2, LOW);
    digitalWrite(ALARM_LED3, LOW);
    digitalWrite(ALARM_LED4, LOW);
    digitalWrite(ALARM_LED5, LOW);
    digitalWrite(ALARM_LED6, LOW);
    digitalWrite(ALARM_LED7, LOW);
    digitalWrite(ALARM_LED8, LOW);
    digitalWrite(BUZZER, LOW);
    delay(250);
}//end of beeP

void display_num(int num2disp) // function
{
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

void displaySetup(int q)//q is the digit to be displayed  //  function
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

void CALIBERATE ()     //  function
{
  truevalue1 = analogRead(LDR1);
  truevalue2 = analogRead(LDR2);
  DC = 0;
  MDR = 0;
  //TBC: open the valve
}

void ALARM (int p)  // function
{
    digitalWrite(p, HIGH);
    alarm_on =true;
}

void pqr()  //interrupt program
{
  DC++;
  newtime = millis();
  deltat = newtime - oldtime;
  oldtime = newtime;
  drop = true;
}// end of pqr interrupt

