#include <PWMChannel.h>
#include <Servo.h>

/**
 * Project Name: Arduino Controlled Halloween RC Eyes
 * Project Type: Halloween
 *
 * Script for controlling the eyes of the Halloween
 * decoration using an RC Remote control. 
 *
 * Author: Frank Hernandez
 * Date: October, 2013
 *
 * Note: Make sure to place the PWMReceiver folder 
 * inside the Libraries folder of your Arduino 
 * installation.
 **/

const int EYE_HORIZONTAL_MIN = 0;
const int EYE_HORIZONTAL_MAX = 170;

const int EYE_VERTICAL_MIN = 70;
const int EYE_VERTICAL_MAX = 120;
int ch1, ch2;

// Read from Channel 2 with a threshold of 30
PWMChannel ch1Read(2, 30);
// Read from Channel 3 with a threshold of 30
PWMChannel ch2Read(3, 30);

// Pin where the servo for the horizontal controls
// is attached. 
int eyeHorizontalServoPin = 7;

// Pin where the servo for the vertical controls 
// is attached. 

int eyeVerticalServoPin = 8;
Servo m_eyeHorizontalServo, m_eyeVerticalServo;

void setup()
{
  
  m_eyeHorizontalServo.attach(eyeHorizontalServoPin);
  // Center the servo so the eyes are looking forward 
  // horizontally.
  m_eyeHorizontalServo.write(90);
  
  m_eyeVerticalServo.attach(eyeVerticalServoPin);
  // Center the servo so the eyes are looking forward
  // vertically.
  m_eyeVerticalServo.write(90);
  
  Serial.begin(9600);
}

void loop()
{
  // Read Horizontal Joytick Move
  ch1 = ch1Read.readPulse();
  // Read Vertical Joystick Move
  ch2 = ch2Read.readPulse();
  
  if(ch1 > 0)
  {
	// Map the pulse received to an angle between
	// 0 and 180 degrees. 
	int angle = map(ch1, 1110, 1866, 0, 180);

	// If the angle is between range then move the eyes horizontally.
    if(angle >=EYE_HORIZONTAL_MIN && angle <= EYE_HORIZONTAL_MAX)
    {
      m_eyeHorizontalServo.write(angle);
    }
  }
  
  if(ch2 > 0)
  {
	// Map the readings to an angle between 0 and 180 degrees.
    int angle2 = map(-1 * ch2, -1866, -1200, 0, 180);
	
    // Cap the motion to the eyes limit for this rig.
    if(angle2 >= EYE_VERTICAL_MIN && angle2 <= EYE_VERTICAL_MAX)
    {
      m_eyeVerticalServo.write(angle2);
    }
  }
    
}


