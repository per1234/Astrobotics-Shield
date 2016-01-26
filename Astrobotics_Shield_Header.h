// Virginia Tech Astrobotics 2015 Galileo Shield Header FIle
// Written by Michael Lai
// Do not steal

#include "mcp_can_dfs.h"
#include "mcp_can.h"
#include "SPI.h"
#include "Adafruit_ADS1015.h"
#include "Wire.h"
#include "Adafruit_MCP23008.h"
#include "LiquidCrystal.h"
#include "Adafruit_PWMServoDriver.h"

//Notes:
//-To initialize PWM Talon control, you must initialize the talon_init class
//in void setup
//
//-Afterwards just use the set_talon_speed class to set the talon speeds. 
//You don't have to initialize multiple classes of talon_init or set_talon_speed 
//to control multiple talons. set_talon_speed takes speed and port number. Just specify
//different port numbers to control difference talons.
//
//-The talon classes accept pulsewidth values from 120 to 450. Full forward, full reverse, and neutral have been initialized
//as private variables for reference. Check the default constructor to see which values correspond to which speeds.
//
//-An example Arduino file has been included for reference in the library.

class PWMTalon
{
public:
    static void talon_init();                         // Initialize Talon driver

    PWMTalon(int port);
    ~PWMTalon();
    void set_speed(float value);                      // Set speed in range [-1.0, 1.0]

private:
    static Adafruit_PWMServoDriver* TalonDriver;      // Declares Talon control PWM interfacing
    static void set_talon_speed(int speed, int port); // Set Talon Speeds

    int port;
};
