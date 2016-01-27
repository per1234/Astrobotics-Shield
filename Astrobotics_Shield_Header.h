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

// Notes:
// - To initialize PWM Talon control, you must call PWMTalon::talon_init()
//   during setup
//
// - Afterwards just use the sest_speed method in the range [-1.0, 1.0] to set the talon speeds. 
//   Specify port numbers to control different talons in the constructor
//
// - An example Arduino file has been included for reference in the library.

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
