/*

 * blink.c:

 *      Simple "blink" test for the PiFace interface board.

  ***********************************************************************

 */



#include <stdio.h>



#include <wiringPi.h>

#include <piFace.h>



// Use 200 as the pin-base for the PiFace board, and pick a pin

//      for the LED that's not connected to a relay



#define PIFACE  200

#define LED     (PIFACE+1)



int main (int argc, char *argv [])

{

  printf ("Raspberry Pi PiFace Blink\n") ;

  printf ("=========================\n") ;



// Always initialise wiringPi. Use wiringPiSys() if you don't need

//      (or want) to run as root



  wiringPiSetupSys () ;



// Setup the PiFace board



  piFaceSetup (PIFACE) ;



  for (;;)

  {

    digitalWrite (LED, HIGH) ;  // On
    digitalWrite (LED+1, HIGH) ;  // On
    delay (500) ;               // mS

    digitalWrite (LED, LOW) ;   // Off
    digitalWrite (LED, LOW) ;   // Off
    delay (500) ;

  }



  return 0 ;

}

