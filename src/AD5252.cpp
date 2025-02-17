/**
 * @file AD5252.cpp
 * @brief Implementation of the AD5252 Arduino library.
 * @author mvader2 | Engr. M. Farhan
 * @date 28-Jan-2025
 * @version 1.0
 */

#include "AD5252.h"

AD5252::AD5252(uint8_t i2c_address) : _i2c_address(i2c_address) {}

bool AD5252::begin() {
    return isConnected();
}

bool AD5252::isConnected() {
    Wire.beginTransmission(_i2c_address);
    return (Wire.endTransmission() == 0);
}

void AD5252::write(uint8_t value) {
    write(0, value);  
}

void AD5252::write(bool channel, uint8_t value) {
    if (!isConnected()) return;

    uint8_t reg = (channel == 1) ? RDAC3 : RDAC1;

    Wire.beginTransmission(_i2c_address);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t AD5252::read() {
    return read(0); 
}

uint8_t AD5252::read(bool channel) {
    if (!isConnected()) return 0;

    uint8_t reg = (channel == 1) ? RDAC3 : RDAC1;

    Wire.beginTransmission(_i2c_address);
    Wire.write(reg);
    Wire.endTransmission();

    Wire.requestFrom(_i2c_address, (uint8_t)1);
    
    while (!Wire.available());  

    return Wire.read();
}
