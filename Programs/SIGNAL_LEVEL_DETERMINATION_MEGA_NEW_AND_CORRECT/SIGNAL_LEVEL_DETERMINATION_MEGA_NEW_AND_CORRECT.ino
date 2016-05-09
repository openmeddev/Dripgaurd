
// Code to acquire the values of analog inputs from the ldrs
// Used for determining the signal level 

int LDR1 = 0;
int LDR2 = 1;
int FILTERED_LDR1 = 2;
int FILTERED_LDR2 = 3;
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  value1 = analogRead(LDR1);
  value2 = analogRead(LDR2);
  value3 = analogRead(FILTERED_LDR1);
  value4 = analogRead(FILTERED_LDR2);
  Serial.println("LDR1");
  Serial.println(value1);
  Serial.println("LDR2");
  Serial.println(value2);
  Serial.println("FILTERED LDR1");
  Serial.println(value3);
  Serial.println("FILTERED LDR2");
  Serial.println(value4);
  delay(6000); 
}



