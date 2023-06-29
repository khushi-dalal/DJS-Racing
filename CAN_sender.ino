#include <CAN.h>
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("CAN Sender");
  // Start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  // Send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");
  
  CAN.beginPacket(0x12);  // Start building a packet with ID 0x12
  CAN.write('h');         // Write character 'h' to the packet
  CAN.write('e');         // Write character 'e' to the packet
  CAN.write('l');         // Write character 'l' to the packet
  CAN.write('l');         // Write character 'l' to the packet
  CAN.write('o');         // Write character 'o' to the packet
  CAN.endPacket();        // Send the packet
  Serial.println("done");
  
  delay(1000);
  
  // Send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending extended packet ... ");
  
  CAN.beginExtendedPacket(0xabcdef);  // Start building an extended packet with ID 0xabcdef
  CAN.write('w');                     // Write character 'w' to the packet
  CAN.write('o');                     // Write character 'o' to the packet
  CAN.write('r');                     // Write character 'r' to the packet
  CAN.write('l');                     // Write character 'l' to the packet
  CAN.write('d');                     // Write character 'd' to the packet
  CAN.endPacket();                    // Send the packet
  Serial.println("done");
  
  delay(1000);
}
