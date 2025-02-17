#pragma once

/**
 * @file AD5252.h
 * @brief Library for interfacing Arduino with the AD5252 digital potentiometer.
 * @author mvader2 | Engr. M. Farhan
 * @date 28-Jan-2025
 * @version 1.0
 * @details Provides functions to read and write to RDAC registers over I²C.
 */

#ifndef AD5252_H
#define AD5252_H

#include <Arduino.h>
#include <Wire.h>

/**
 * @class AD5252
 * @brief A class to interface with the AD5252 digital potentiometer using I²C.
 */
class AD5252 {
public:
    /**
     * @brief Constructor to initialize the AD5252.
     * @param i2c_address The I2C address of the AD5252 (default: 0x2C).
     */
    explicit AD5252(uint8_t i2c_address = 0x2C);

    /**
     * @brief Initializes the AD5252 by checking if the device is connected.
     * @return True if the device is detected, false otherwise.
     */
    bool begin();

    /**
     * @brief Checks if the AD5252 is connected over I2C.
     * @return True if the device is responding, false otherwise.
     */
    bool isConnected();

    /**
     * @brief Writes a value to the default RDAC1 channel.
     * @param value The 8-bit value to write (0-255).
     */
    void write(uint8_t value);

    /**
     * @brief Writes a value to a specific RDAC channel.
     * @param channel The RDAC channel to write to (0 for RDAC1, 1 for RDAC2).
     * @param value The 8-bit value to write (0-255).
     */
    void write(bool channel, uint8_t value);

    /**
     * @brief Reads the value from the default RDAC1 channel.
     * @return The 8-bit value read from RDAC1 (0-255).
     */
    uint8_t read();

    /**
     * @brief Reads the value from a specific RDAC channel.
     * @param channel The RDAC channel to read from (0 for RDAC1, 1 for RDAC2).
     * @return The 8-bit value read from the specified channel (0-255).
     */
    uint8_t read(bool channel);

private:
    uint8_t _i2c_address;  ///< I2C address of the AD5252 device.

    static constexpr uint8_t RDAC1 = 0x01; ///< Register address for RDAC1.
    static constexpr uint8_t RDAC3 = 0x03; ///< Register address for RDAC2.
};

#endif // AD5252_H
