/**
 * @file    AD5252_ReadWrite.ino
 * @brief   Example code for interfacing Arduino with AD5252 digital potentiometer.
 * @author  mvader2 | Engr. M. Farhan
 * @date    17-Feb-2025
 * @details This example initializes the AD5252 via I2C, sets Channel 0 and Channel 1 to a 
 *          mid-scale value (128), and reads back the values for verification.
 */

#include <Wire.h>
#include <AD5252.h>

// Select the correct I2C address based on AD0 and AD1 pin connections
#define DIGIPOT_ADDR 0x2C  ///< AD0 = GND, AD1 = GND
// #define DIGIPOT_ADDR 0x2D ///< AD0 = VDD, AD1 = GND
// #define DIGIPOT_ADDR 0x2E ///< AD0 = GND, AD1 = VDD
// #define DIGIPOT_ADDR 0x2F ///< AD0 = VDD, AD1 = VDD

AD5252 digipot(DIGIPOT_ADDR);

void setup() {
  Serial.begin(115200);
#if defined(ESP32)
  // ESP32 Default I2C pins: SDA = GPIO21, SCL = GPIO22
  Wire.begin(21, 22);
#elif defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_ARCH_MBED_RP2040) || defined(ARDUINO_ARCH_RP2350)
  // RP2040: Set custom SDA/ SCL pins (GP16, GP17)
  Wire.setSDA(16);
  Wire.setSCL(17);
  Wire.begin();
  // Set the I2C clock speed to 400kHz
  Wire.setClock(400000);
#else
  Wire.begin();
#endif

  // Check if AD5252 is connected
  if (digipot.begin()) {
    Serial.println("AD5252 Connected!");
  } else {
    Serial.println("AD5252 NOT found!");
    while (true) {
      delay(100);
    }
  }

  // Set Channel 0 (RDAC1) and Channel 1 (RDAC3) to mid-scale (128)
  digipot.write(0, 128);
  Serial.print("Channel 0 (RDAC1) Value: ");
  Serial.println(digipot.read(0));

  digipot.write(1, 128);
  Serial.print("Channel 1 (RDAC3) Value: ");
  Serial.println(digipot.read(1));
}

void loop() {
}
