
//turn off buzzer

void setup()
{
  pinMode(46, OUTPUT);
}
void loop()
{
  digitalWrite(46, HIGH);
  delay(500);
  digitalWrite(46, LOW);
  delay(500);
}


