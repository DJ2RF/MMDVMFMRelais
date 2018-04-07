/*
 * relais.c:
 *      Relais Steuerung MMDVM auto Analog FM.
 *      gcc -Wall relais.c -o relais -lwiringPi -lwiringPiDev     Compiler command
 *  ***********************************************************************
 */
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <piFace.h>
#include "/usr/include/alsa/asoundlib.h"

// Use 200 as the pin-base for the PiFace board, and pick a pin

// Output
#define PIFACE  200
#define RELAIS1     (PIFACE)
#define RELAIS2     (PIFACE+1)
#define RELAIS3     (PIFACE+2)
#define PTT		  (PIFACE+3)
#define RELAISHOLDTIME  10000  // 10 Sekunden Abfallzeit

// Input
#define SQL 200
#define MMDVMPTT 201 // Negiert HIGH = Sendet nicht, PIFACE PullUp 

int main (int argc, char *argv [])
{
int iRelaiHoldTime = 0;
int iSql = 0;
int iReady = 0;

char command1[150];
char command2[150];
char command3[150];
strcpy( command1, "aplay -D sysdefault:CARD=Device  /home/pi/work/piface/welc.wav > /dev/null " );
strcpy( command2, "aplay -D sysdefault:CARD=Device  /home/pi/work/piface/beep-08b.wav > /dev/null " );
strcpy( command3, "aplay -D sysdefault:CARD=Device  /home/pi/work/piface/bye.wav > /dev/null " );

  wiringPiSetupSys () ;

// Setup the PiFace board

  piFaceSetup (PIFACE) ;
  
  for (;;)
  {
    if (digitalRead(SQL)  == HIGH)
    {
	delay(800);
	if (digitalRead(MMDVMPTT) == HIGH)  // Sendet nicht
	 {
		digitalWrite (RELAIS1, HIGH) ;  // On
		digitalWrite (RELAIS2, HIGH) ;  // On		
		digitalWrite (PTT, HIGH) ;          // On
		system(command1);
		iReady=1;                                    // for short open squelch
	
	    do
	    {
                if ((digitalRead(SQL) == HIGH) || (iReady == 1))
		{
			iReady=0;
			iSql=1;
			iRelaiHoldTime = 0;
		}
		if ((digitalRead(SQL) == LOW) && (iSql == 1))
		{
			iSql=0;
			system(command2);		// Hier roger beep
		}
		
		delay (1) ;      // mS
		iRelaiHoldTime++;
	    }
	    while (iRelaiHoldTime < RELAISHOLDTIME); 
	
	    system(command3);   // Bye Bye 
	
	    digitalWrite (PTT, LOW) ; 		
	    digitalWrite (RELAIS1, LOW) ;  // Off
	    digitalWrite (RELAIS2, LOW) ;  // Off
        } 
     } // End of if (digitalRead(MMDVMPTT) == HIGH)  
   delay(200);
   }
  return 0 ;
}


