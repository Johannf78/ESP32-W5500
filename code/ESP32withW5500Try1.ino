#include <Ethernet.h>

#define ETH_SPI_SCS   5   // CS (Chip Select), Green

// Define MAC and IP
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);


void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Starting Ethernet connection...");

  //Set the CS pin, required for ESP32 as the arduino default is different
  Ethernet.init(ETH_SPI_SCS); 

  //Start the Ethernet connection
  Ethernet.begin(mac, ip);

    //Hardware check
  Serial.println("Checking Ethernet hardware...");
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("ERROR: No Ethernet hardware detected!");
    return;
  }
  else {
    Serial.println("Ethernet hardware detected!");
  }

  //Check if cable is connected
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Link is OFF. Check cable connection.");
  }
  else {
    Serial.println("Link is ON. Cable is connected. Ready to go!");
    Serial.print("To test connection, please ping: ");
    Serial.println(ip);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
