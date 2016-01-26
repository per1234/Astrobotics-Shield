#include <Astrobotics_Shield_Header.h>

Astrobotics_Shield_Header Talons = Astrobotics_Shield_Header();

void setup() 
{
  Talons.talon_init();//YOU MUST INITIALIZE THIS. THIS INITIALIZES THE INTERFACE
}
void loop() 
{
  //This loop sets the talons to full forward, neutral, full reverse, then neutral, then loops
  Talons.set_talon_speed(450,1);
  delay(500);
  Talons.set_talon_speed(285,1);
  delay(500);
  Talons.set_talon_speed(120,1);
  delay(500);
  Talons.set_talon_speed(285,1);
  delay(500);
}
