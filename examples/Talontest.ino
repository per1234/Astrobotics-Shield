#include <Astrobotics_Shield_Header.h>

PWMTalon talon(0);

void setup() 
{
  PWMTalon::talon_init(); // YOU MUST INITIALIZE THIS. THIS INITIALIZES THE INTERFACE
}

void loop() 
{
  //This loop sets the talons to full forward, neutral, full reverse, then neutral, then loops
  talon.set_speed(1.0);
  delay(500);
  talon.set_speed(0.0);
  delay(500);
  talon.set_speed(-1.0);
  delay(500);
  talon.set_speed(0.0);
  delay(500);
}
