// Speaker pin is set to pin 8 

#if defined(__SAM3X8E__)
    //Used for Due boards (SAMD)
    #include "ToneDue.h"
    playDue playTune(true); // Instaniate version of tone for Due boards
#else
    //Used for Nano, Uno, Mega, Lenardo and possibily others
    #include "ToneUno.h"
    playUno playTune(true);// Instaniate version of tone for other boards
  
#endif

void setup() {
  playTune.playMelody();

}

void loop() {
  // put your main code here, to run repeatedly:

}
