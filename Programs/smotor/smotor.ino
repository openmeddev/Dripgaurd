
#include <Servo.h>
Servo myservo;
int degree1 = 0;
int degree2 = 180;
void setup() 
{
  myservo.attach(9);
}

void loop() 
{
    myservo.write(degree1);
    delay(1000);
    myservo.write(degree2);
    delay(1000);
}


