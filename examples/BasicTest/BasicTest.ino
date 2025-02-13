#include <Wire.h>
#include <AD5252.h>

AD5252 digipot(0x2C);  

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (digipot.begin()) {
        Serial.println("AD5252 Connected!");
    } else {
        Serial.println("AD5252 NOT found!");
    }
}

void loop() {
    digipot.write(0, 128); 
    Serial.print("RDAC1 Value: ");
    Serial.println(digipot.read(0));
    digipot.write(1, 128); 
    Serial.print("RDAC2 Value: ");
    Serial.println(digipot.read(1));

    delay(1000);
}
