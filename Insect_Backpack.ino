#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(CE_PIN, CSN_PIN);

const uint64_t pipe = 0xE8E8F0F0E1LL; //pipeline address 

void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  // Send the signal to move the left antenna
  radio.write("L", sizeof("L"));
  delay(1000);
  
  // Send the signal to move the right antenna
  radio.write("R", sizeof("R"));
  delay(1000);
  
  // Send the signal to move the left leg
  radio.write("l", sizeof("l"));
  delay(1000);
  
  // Send the signal to move the right leg
  radio.write("r", sizeof("r"));
  delay(1000);
}
