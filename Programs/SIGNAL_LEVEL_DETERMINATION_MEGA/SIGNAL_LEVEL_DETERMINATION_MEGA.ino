
// Code to acquire the values of analog inputs from the ldrs
// Used for determining the signal level 

int LDR1 = 0;
int LDR2 = 2;
int value1 = 0;
int value2 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  value1 = analogRead(LDR1);
  value2 = analogRead(LDR2);
  Serial.println("LDR1");
  Serial.println(value1);
  Serial.println("LDR2");
  Serial.println(value2);
  delay(60000); 
}

