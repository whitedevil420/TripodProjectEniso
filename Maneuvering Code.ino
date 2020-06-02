#include <Servo.h>
  
Servo servo1;
Servo servo2;
int joyX = 0;
int joyY = 1;
int SW = 2;

int count;
int XVal,YVal;
int reset = 0;        //center the camera mount upon starting
float Xangle = 0, Xangular_speed, Yangle = 0, Yangular_speed;
int Timer = 0;

  
void setup() 
{
  servo1.attach(3);
  servo2.attach(5);
  pinMode(SW,INPUT);
}
  
void loop()
{
  if (digitalRead(SW) || reset == 0) {
    servo1.write(90);
    servo2.write(90);
    reset = 1;
  }
  
  XVal = analogRead(joyX);
  Xangular_speed = map(XVal, 0, 1023, -100, 100);
  Xangle = constrain ( (Xangle += Xangular_speed * (Timer+5) / 1000), 0, 180); 
  servo1.write(Xangle);

  YVal = analogRead(joyY);
  Yangular_speed = map(YVal, 0, 1023, -100, 100);
  Yangle = constrain ( (Yangle += Yangular_speed * (Timer+5) / 1000), 0, 180); 
  servo2.write(Yangle);

  Timer++;
  if( abs(XVal-512) < 50 && abs(YVal-512) < 50 ) Timer = 0;
  delay(15);  
}
