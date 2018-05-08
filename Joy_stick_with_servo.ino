///my own code

#include <Servo.h>
//defining my joystick analog pins
const int X =  A0;
const int Y = A1;
#define SW_pin 2 // the joystick switch pin

Servo s;
Servo s2;

void setup(){
  pinMode (SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  s.attach(9); //servo pin
  s.write(90);
  s2.attach(8);
  s2.write(90);
  Serial.begin(9600);
}

void loop(){
  /* The joystick x is a value in the range of [0,1023], the servo angle is in the
   *  range of [0, 180] so the map function will convert a value on the joy stick range to a 
   *  number in the servo range.
   *  https://www.arduino.cc/reference/en/language/functions/math/map/
   *  about the map function:
   *  Syntax
  map(value, fromLow, fromHigh, toLow, toHigh)

    Parameters
    value: the number to map
    
    fromLow: the lower bound of the value’s current range
    
    fromHigh: the upper bound of the value’s current range
    
    toLow: the lower bound of the value’s target range
    
    toHigh: the upper bound of the value’s target range
    
    Returns
    The mapped value.
   */
   int fromJoy = analogRead(X);
   int fromJoy2 = analogRead(Y);
   
  int joy2servoY = map(fromJoy2, 0, 1023, 3, 175);
  int joy2servoX = map(fromJoy, 0, 1023, 3, 175);//didnt go all range of servo to not push the servo too hard
  s.write(90);
  s2.write(90);
  //Serial.print(fromJoy);
  //Serial.print("\n");
  s.write(joy2servoX);
  s2.write(joy2servoY);
  delay(10);
  
}



