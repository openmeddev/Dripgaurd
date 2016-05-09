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
byte rowPins[ROWS] = {38, 39, 40, 41}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {42, 43, 44, 45}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int DF = 0; //Drip Factor
int IRV = 0; // Input Reservoir Volume
int IT = 0; // Input Time
int IDR = 0; //Input Drip Rate
int PRV = 0; //Preset Reservoir Volume
int const alarm_pin =46;

void setup() {
  Serial.begin(9600);
  pinMode(alarm_pin,OUTPUT); 
}

void loop() {
  int num;
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);
  }
  if ((key == 'A') || (key == 'B') || (key == 'C') || (key == 'D') || (key == '#')) {
    num = numinput();
    Serial.println("here");
    Serial.println(key);
    Serial.println(num);

    if (num != -1) {
      Serial.println("here2");
      switch (key) 
      {
          case 'A':
          //Serial.println("here3");
          if ((num <= 60) && (num >= 5)) {
            DF = num;
            Serial.print("Drip Factor:");
            Serial.println(DF);
          }
          else {
            beep();
            Serial.println("Incorrect Drip Factor");
          };
          break;

        case 'B':
          Serial.println("here4");
          if ((num <= 1000) && (num >= 50)) {
            IRV = num;
            Serial.print("Intial Reservoir Volume:");
            Serial.println(IRV);
          }
          else {
            beep();
            Serial.println("Incorrect Intial Reservoir Volume");
          };
          break;

        case 'C':
          if ((num <= 1440) && (num >= 30)) {
            IT = num;
            Serial.print("Infussion Time:");
            Serial.println(IT);
          }
          else {
            beep();
            Serial.println("Incorrect Infussion Time");
          };
          break;
        case 'D':
          if ((num <= 200) && (num >= 2)) {
            IDR = num;
            Serial.print("Input Drip Rate:");
            Serial.println(IDR);
          }
          else {
            beep();
            Serial.println("Incorrect Input Drip Rate");
          };
          break;
        case '#':
          if ((num <= 1000) && (num >= 50)) {
            PRV = num;
            Serial.print("Preset Reservior Volume:");
            Serial.println(PRV);
          }
          else {
            beep();
            Serial.println("Incorrect Preset Reservior Volume");
          };
          break;
          default:
          break;
      }//end of switch
    }//end of if num!=-1


  }// end of number input
}//end of loop

int numinput()
{
  Serial.println(" Please input number  on key pad  and press star:");

  char key2;
  int num1 = 0;
  int digit = 0;
  while (true) {
    key2 = keypad.getKey();
    while (key2 == NO_KEY) {
      key2 = keypad.getKey();
    }//end of inner while loop
    //delay(10);

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
    else {
      digit = int(key2) - int('0');
      num1 = num1 * 10 + digit;
      if (num1 > 9999) {
        beep();
        return (-1);
        break;
      }
    }

  }// end of top while loop

  Serial.println(" end of keyinput");
}

void beep(){
  digitalWrite(alarm_pin,HIGH);
  delay(250);
  digitalWrite(alarm_pin,LOW);
}//end of beep

