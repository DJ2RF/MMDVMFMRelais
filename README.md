# MMDVM FM Relais

First check if your RX TX are ready for FM. Here i have  ft7800 TX and FT857d as RX.

You must have a Piface card from JoyIt a USB Soundcard and Alsa utilitys are running.
The WiringPi must be installed also the WiringPiDev librarys

One of the relais switch off the PTT from MMDVM to TX, digitalWrite (RELAIS1, HIGH) ;. The second switch off the sound from MMDVM to TX. digitalWrite (RELAIS2, HIGH)

digitalWrite (PTT, HIGH)  set PTT from Mic input at the TX.

The audio path for FM is from RX out to USB Card Mic and from USB Card sound out to mic in from the TX unit.
In this constelation it is possible to mix other sounds to the audio path as shown at the software.
At the FT7800 this audio Path only works with Mic in PTT !!!!!!!!!!!!!!!!!!!!!!!!
So there is no problem to switch back to digital sound from MMDVM

Compiler command

gcc -Wall relais.c -o relais -lwiringPi -lwiringPiDev

More details are following

schematics.jpg gives a overview how to connect raspi, mmdvm, piface and usb soundcard

at https://github.com/DJ2RF/MMDVMFMRelais/blob/master/schematics.jpg you can find a description piface

relais  without a extension is the binary

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

