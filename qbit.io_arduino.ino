#include <Arduino.h>
#include <IPAddress.h>
#include <Ethernet.h>
#include <SPI.h>

byte mac[] = {  0x90, 0xA2, 0xDA, 0x00, 0xC9, 0xA5 };
IPAddress server( 206,125,173,186 );

EthernetClient client;

void setup() {
  Serial.begin(9600);

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    for(;;)
      ;
  }
  
  delay(1000);
  Serial.println("connecting...");

  if (client.connect(server, 3232)) {
    Serial.println("connected");
    char x = client.read();
    char y = client.read();
    
    Serial.println( x );
    Serial.println( y );
  } 
  else {
    Serial.println("connection failed");
  }
}

void loop() {
  if (client.available()) {
    client.println( "status\r\n" );
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    
    for(;;)
      ;
  }
}
