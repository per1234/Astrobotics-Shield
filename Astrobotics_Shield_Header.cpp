//Virginia Tech Astrobotics 2015 Galileo Shield Cpp File
//Written by Michael Lai
//Do not steal
#include "Astrobotics_Shield_Header.h"

Astrobotics_Shield_Header::Astrobotics_Shield_Header()
{
	talon_max_forward = 450; //max forward frequency for reference
	talon_max_reverse = 120;//max reverse frequency for reference
	talon_neutral = 285;//neutral frequency for reference
	Adafruit_PWMServoDriver Talon = Adafruit_PWMServoDriver();
}

void Astrobotics_Shield_Header::talon_init()
{
	Talon.begin();
	Talon.setPWMFreq(50);
}

void Astrobotics_Shield_Header::set_talon_speed(int speed,int port)
{
	Talon.setPWM(port,0,speed);
}
