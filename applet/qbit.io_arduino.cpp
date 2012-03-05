#include "WProgram.h"
#include <Ethernet.h>

void setup() {
	Serial.begin( 9600 );
	return;
}

void loop() {
	delay( 3000 );
	Serial.println( "Hola\n" );
}
#include <WProgram.h>

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

// http://www.arduino.cc/playground/OpenBSD/CLI
extern "C" void __cxa_pure_virtual(void) {
	while(1);
}
