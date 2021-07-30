 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_PWM, 2, 3);  // PWM 1A = Pin 2, PWM 1B = Pin 3.
CytronMD motor2(PWM_PWM, 4, 5);  // PWM 2A = Pin 4, PWM 2B = Pin 5.
CytronMD motor3(PWM_PWM, 6, 7);  // PWM 3A = Pin 6, PWM 3B = Pin 7.
CytronMD motor4(PWM_PWM, 8, 9);  // PWM 4A = Pin 8, PWM 4B = Pin 9.

//const int s4 = 28 ;
//const int s3 = 26 ;
//const int s2 = 24 ;
//const int s1 = 22 ;

int inp;

// The setup routine runs once when you press reset.
void setup() 
{
  Serial.begin(9600);
 motor1.setSpeed(0); 
 motor2.setSpeed(0);
 motor3.setSpeed(0);
 motor4.setSpeed(0);
 //pinMode(s4, INPUT);  
 //pinMode(s3, INPUT);  
 //pinMode(s2, INPUT);
 //pinMode(s1, INPUT);   
}


void backward()
{
  Serial.println("Backward\n");
  motor1.setSpeed(-255);
  motor2.setSpeed(-255);
  motor3.setSpeed(-255);
  motor4.setSpeed(-255);
}
void right()
{
  Serial.println("Right \n");
  motor1.setSpeed(255);
  motor2.setSpeed(-255);
  motor3.setSpeed(255);
  motor4.setSpeed(-255);
}
void left()
{
  Serial.println("Left\n");
  motor1.setSpeed(-255);
  motor2.setSpeed(255);
  motor3.setSpeed(-255);
  motor4.setSpeed(255); 
}
void forward()
{
  Serial.println("Forward\n");
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}
void forwardleft()
{
  Serial.println("Forward Left\n");
  motor1.setSpeed(100);
  motor2.setSpeed(200);
  motor3.setSpeed(125);
  motor4.setSpeed(255);
}
void forwardright()
{
  Serial.print("Forward Right\n");
  motor1.setSpeed(200);
  motor2.setSpeed(100);
  motor3.setSpeed(255);
  motor4.setSpeed(125);
}
void backwardleft()
{
  Serial.println("Backward Left\n");
  motor4.setSpeed(-100);
  motor3.setSpeed(-200);
  motor2.setSpeed(-125);
  motor1.setSpeed(-255);
}
void backwardright()
{
  Serial.print("Backward Right\n");
  motor4.setSpeed(-200);
  motor3.setSpeed(-100);
  motor2.setSpeed(-255);
  motor1.setSpeed(-125);
}
void Breaks()
{
  Serial.print("Breaks\n");
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}
/*void loop() 
{
  if(digitalRead(s4)==LOW)
  {
    Breaks();
  }
  else
  {
    if(digitalRead(s3)==HIGH)
    {
      if(digitalRead(s2)==HIGH)
      {
       if(digitalRead(s1)==HIGH)
        forward();
       else
        backward();
      }
      else
      {
        if(digitalRead(s1)==HIGH)
          right();
        else
          left();  
      }
    }
    else
    {
      if((digitalRead(s2)==HIGH)&&(digitalRead(s1)==HIGH))
        forwardright();
      else if((digitalRead(s2)==HIGH)&&(digitalRead(s1)==LOW))
        forwardleft();
      else if((digitalRead(s2)==LOW)&&(digitalRead(s1)==HIGH))
        backwardright();
      else
        backwardleft();
    }
  }
}
*/
void loop()
{
  if(Serial.available() > 0)
  {
    inp = Serial.read();
    
    switch(inp)
    {
      case 'w' : 
                  forward();
                  delay(200);
                  Breaks();
                  break;
      case 's' : 
                  backward();
                  delay(200);
                  Breaks();
                  break;
      case 'd' : 
                  backwardright();
                  delay(40);
                  Breaks();
                  break;
      case 'a' : 
                  backwardleft();
                  delay(40);
                  Breaks();
                  break;
      case 'p' : 
                  forwardright();
                  delay(40);
                  Breaks();
                  break;
      case 'i' : 
                  forwardleft();
                  delay(40);
                  Breaks();
                  break;
      case 'l' : 
                  backwardright();
                  delay(40);
                  Breaks();
                  break;
      case 'k' : 
                  backwardleft();
                  delay(40);
                  Breaks();
                  break;
      case 'b' :
      default : 
                  Breaks();
    }
  }
}
