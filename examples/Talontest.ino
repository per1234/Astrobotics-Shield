#include <Astrobotics_Shield_Header.h>

int TALON_PORT = 0;
PWMTalon talon;

void setup() 
{
  talon.attach(TALON_PORT);
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
