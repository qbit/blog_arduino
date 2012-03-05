#include <Ethernet.h>

void setup() {
	Serial.begin( 9600 );
	return;
}

void loop() {
	delay( 3000 );
	Serial.println( "Hola\n" );
}
