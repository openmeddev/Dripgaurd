//int digits


void setup() {
  // put your setup code here, to run once:

  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  //pinMode(13,OUTPUT);


  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  //digitalWrite(13,HIGH);

  
  PORTD= B11110110;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  
  PORTD = B00000110; //display 1
  digitalWrite(9,LOW);
  delay(1);
  digitalWrite(9,HIGH);
  
  PORTD= B01011011; //display 2
  digitalWrite(10,LOW);
  delay(1);
  digitalWrite(10,HIGH);

  PORTD =B01001111;
  digitalWrite(11,LOW);
  delay(1);
  digitalWrite(11,HIGH);
}




