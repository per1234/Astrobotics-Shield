// Virginia Tech Astrobotics 2015 Galileo Shield Cpp File
// Written by Michael Lai
// Do not steal

#include "Astrobotics_Shield_Header.h"
#include <Adafruit_LiquidCrystal.h>

// ==== Control Box Menu ====

Adafruit_LiquidCrystal* lcd;

byte star1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00000
};

byte star2[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B11111,
  B01111
};

byte star3[8] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111
};


byte star4[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B11111,
  B11110
};

byte star5[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000
};

byte star6[8] = {
  B00001,
  B00011,
  B00011,
  B00111,
  B01110,
  B01100,
  B11000,
  B10000
};

byte star7[8] = {
  B11111,
  B11111,
  B10001,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte star8[8] = {
  B10000,
  B11000,
  B11000,
  B11100,
  B01110,
  B00110,
  B00011,
  B00001
};

void setupControlBoxMenu() {
    lcd = new Adafruit_LiquidCrystal(0);
    lcd->begin(20,4);
    lcd->clear();
    lcd->createChar(0, star1);
    lcd->createChar(1, star2);
    lcd->createChar(2, star3);
    lcd->createChar(3, star4);
    lcd->createChar(4, star5);
    lcd->createChar(5, star6);
    lcd->createChar(6, star7);
    lcd->createChar(7, star8);
    lcd->setCursor(2,1);
    lcd->print(char(0));
    lcd->print(char(1));
    lcd->print(char(2));
    lcd->print(char(3));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->print(char(4));
    lcd->setCursor(3,2);
    lcd->print(char(5));
    lcd->print(char(6));
    lcd->print(char(7));
    lcd->print("STROBOTICS");
    lcd->setBacklight(0);
}

// ==== Talon PWM ====

const int talon_max_forward = 455; // max forward talon pulse frequency for reference
const int talon_max_reverse = 135; // max reverse talon pulse frequency for reference
const int talon_neutral = 295;     // neutral talon pulse frequency for reference
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
    set_speed(0.0f);
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
