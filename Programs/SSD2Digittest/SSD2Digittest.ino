int pin1 = 2;
int pin2 = 3;                                    //                            --6--
int pin3 = 4;                                    //                         5 |     | 7
int pin4 = 5;                                    //                           |--4--|
int pin5 = 6;                                    //                         1 |     | 3
int pin6 = 7;                                    //                            --2--
int pin7 = 8;
int gnd1 = 11;                                 //                          gnd1 is display 1's gnd
int gnd2 = 9;                                   //                          gnd2 is display 2's gnd
int timer = 50;                               //   A timer, to run the for loop 10 times, which turns out as 1 second.
int value;                                        //   The value, part of the FADING display

void setup(){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);           //The following sets up all of the pins for use.
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
  
  
  for (int i=0; i<timer; i++){                     //   The for loop, for running the program 10 times.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);                         
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 20 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  
for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 19 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 18 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 17 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 16 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 15 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 14 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 13 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 12 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 11 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 10 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 09 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 08 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 07 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 06 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 05 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 04 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 03 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 02 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 01 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 00 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  
  
}

void loop() {
  
  
  digitalWrite(13, HIGH);   //  Turns the TIMER ENDED LED on.
  
   for(value = 0 ; value <= 255; value+=5) // fade in (from min to max) 
  { 
    analogWrite(gnd1, value);           // sets the value (range from 0 to 255) 
    analogWrite(gnd2, value);           // sets the value (range from 0 to 255) 
    delay(10);                            // waits for 30 milli seconds to see the dimming effect 
  } 
  for(value = 255; value >=0; value-=5)   // fade out (from max to min) 
  { 
    analogWrite(gnd1, value);           // sets the value (range from 0 to 255) 
    analogWrite(gnd2, value);           // sets the value (range from 0 to 255) 
    delay(10); 
  }  
  
}


