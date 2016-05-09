
volatile int a = 0;  //a is a global variable for counting no of interrupts
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,pqr,FALLING);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(a);
delay(100);
}

void pqr(){
  a++;
}


