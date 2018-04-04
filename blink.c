/*
 * relais.c:
 *      Relais Steuerung MMDVM auto Analog FM.
 *  ***********************************************************************
 */
#include <stdio.h>
#include <wiringPi.h>
#include <piFace.h>

// Use 200 as the pin-base for the PiFace board, and pick a pin

#define PIFACE  200
#define RELAIS1     (PIFACE)
#define RELAIS2     (PIFACE+1)
#define RELAIS3     (PIFACE+2)
#define RELAISHOLDTIME  15000  // 15 Sekunden Abfallzeit

int main (int argc, char *argv [])
{
  //printf ("Raspberry Pi PiFace Blink\n") ;
  //printf ("=========================\n") ;

// Always initialise wiringPi. Use wiringPiSys() if you don't need
//      (or want) to run as root

  wiringPiSetupSys () ;

// Setup the PiFace board

  piFaceSetup (PIFACE) ;

  for (;;)
  {
    if (digitalRead(200)  == HIGH)
	 {
		digitalWrite (RELAIS1, HIGH) ;  // On
		digitalWrite (RELAIS2, HIGH) ;  // On		
		digitalWrite (RELAIS3, HIGH) ;  // On
		delay (RELAISHOLDTIME) ;      // mS
    		
	}
	else
	{
		digitalWrite (RELAIS1, LOW) ;  // Off
		digitalWrite (RELAIS2, LOW) ;  // Off
		digitalWrite (RELAIS3, LOW) ;  // Off		
		delay (500) ;               		    // mS
	}
  }
  return 0 ;
}

