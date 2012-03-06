#include "WProgram.h"
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0xC9, 0xA5 };
IPAddress server( 206,125,173,186 );

EthernetClient client;

void setup() {
	Serial.begin( 9600 );

	if ( Ethernet.begin( mac ) == 0 ) {
		Serial.println( "Failed to configure via DHCP" );
		for( ;; )
			;
	}

	delay( 1000 );
	Serial.println( "Connecting..." );

	if ( client.connect( server, 3232 ) ) {
		Serial.println( "Connected.." );
	} else {
		Serial.println( "Connection failed!" );
	}
}

void loop() {
	if ( client.available() ) {
		//client.println( "whut" );
		char c = client.read();
		Serial.print( c );
	}

	if ( ! client.connected() ) {
		Serial.println();
		Serial.println( "disconnected." );
		client.stop();

		for( ;; ) 
			;
	}
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
