#include <Arduino.h>
#include <Ethernet.h>
#include <SPI.h>
#include <aJSON.h>

byte mac[] = {  0x90, 0xA2, 0xDA, 0x00, 0xC9, 0xA5 };
IPAddress server( 206,125,173,186 );

EthernetClient client;

aJsonObject* root = aJson.createObject();


void setup() {
	randomSeed(analogRead(0));

	aJson.addItemToObject( root, "width",  aJson.createItem( random( 800)));
	aJson.addItemToObject( root, "height", aJson.createItem( random( 400)));

	Serial.begin(9600);

	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		for(;;)
		;
	}

	delay(2000);
	Serial.println("connecting...");

	if (client.connect(server, 3232)) {
		Serial.println("connected");
		client.print( aJson.print(root) );
		Serial.println("sent position");
	} else {
		Serial.println("connection failed");
	}
}

int count = 0;

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print( "received: " );
	Serial.println( c );
	client.write( count );
	count++;
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    
    for(;;)
      ;
  }
}
#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USB.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

