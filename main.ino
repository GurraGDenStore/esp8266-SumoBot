// Input definition
#define L_sensor /*Insert pin*/
#define R_sensor /*Insert pin*/

// Output definition
#define L_MotorF /*Insert pin*/
#define L_MotorR /*Insert pin*/
#define R_MotorF /*Insert pin*/
#define R_MotorR /*Insert pin*/

void setup(){
// Sensors
    pinMode(L_Sensor, INPUT); // Left Sensor Input
    pinMode(R_Sensor, INPUT); // Right Sensor Input

// Motors
    pinMode(L_MotorF, OUTPUT); // Left Motor Forward
    pinMode(L_MotorR, OUTPUT); // Left Motor Reverse
    pinMode(R_MotorF, OUTPUT); // Right Motor Forward
    pinMode(R_MotorR, OUTPUT); // Right Motor Reverse
}

void loop(){

     if((analogRead(L_Sensor)>250) && (analogRead(R_Sensor)>250))  
    {    
      MoveForward();
    }
    
    if((analogRead(L_Sensor)<250) && (analogRead(R_Sensor)<250))  
    {
        Stop();
    }
    if((analogRead(L_Sensor)<250) && (analogRead(R_Sensor)>250))  
    {
      TurnLeft();
    }
    
    if((analogRead(L_Sensor)>250) && (analogRead(R_Sensor)<250))
    {
      TurnRight();
    }
  } else {
    Stop();
  }

}

void MoveForward()
{
    digitalWrite(L_MotorR, LOW);
    digitalWrite(L_MotorF, HIGH);
    
    digitalWrite(R_MotorR, HIGH);
    digitalWrite(R_MotorF, LOW);
    delay(20);
}

void TurnRight()
{
    digitalWrite(L_MotorR, LOW);
    digitalWrite(L_MotorF, HIGH);
    
    digitalWrite(R_MotorR, LOW);
    digitalWrite(R_MotorF, HIGH);
    delay(30); 
}

void TurnLeft() 
{
    digitalWrite(L_MotorR, HIGH);
    digitalWrite(L_MotorF, LOW);
    
    digitalWrite(R_MotorR, HIGH);  
    digitalWrite(R_MotorF, LOW);
    delay(30);
}

void Stop()
{
    digitalWrite(L_MotorR, LOW);
    digitalWrite(L_MotorF, LOW);

    digitalWrite(R_MotorR, LOW);
    digitalWrite(R_MotorF, LOW);
    delay(20);
}