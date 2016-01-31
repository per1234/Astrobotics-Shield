// Virginia Tech Astrobotics 2015 Galileo Shield Cpp File
// Written by Michael Lai
// Do not steal

#include "Astrobotics_Shield_Header.h"

const int talon_max_forward = 455; // max forward talon pulse frequency for reference
const int talon_max_reverse = 115; // max reverse talon pulse frequency for reference
const int talon_neutral = 285;     // neutral talon pulse frequency for reference
const float epsilon = 0.001;

Adafruit_PWMServoDriver* PWMTalon::TalonDriver = NULL;

void PWMTalon::talon_init()
{
    if(TalonDriver == NULL)
    {
        TalonDriver = new Adafruit_PWMServoDriver();
        TalonDriver->begin();
        TalonDriver->setPWMFreq(50);
    }
}

void PWMTalon::set_talon_speed(int speed, int port)
{
    TalonDriver->setPWM(port, 0, speed);
}

PWMTalon::PWMTalon() : port(-1), reversed(false)
{
}

PWMTalon::~PWMTalon()
{
}

void PWMTalon::attach(int _port, bool _reversed)
{
    port = _port;
    reversed = _reversed;
}

void PWMTalon::set_speed(float value)
{
    if(port < 0)
    {
        return;
    }

    value *= (reversed ? -1.0f : 1.0f);
    // Convert [-1.0, 1.0] range to PWM frequency range
    int speed;
    if(value > -epsilon && value < epsilon) {
        speed = talon_neutral;
    }
    else
    {
        speed = (int)(((value + 1.0f) / 2.0f * (talon_max_forward - talon_max_reverse)) + talon_max_reverse);
    }
    set_talon_speed(speed, port);
}
