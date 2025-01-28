// #include <Arduino.h> // For printing
// #include "i2c.h"

// #include <util/delay.h> // For delays

// #define AHT10_ADDRESS 0x23 // Change to 0x5C if ADDR pin is high


// // BH1750 Functions
// void bh1750_init()
// {
//   i2c_start();
//   i2c_send_address(AHT10_ADDRESS, true);  // Write mode
//   i2c_write(0x01);                        // Power ON command
//   i2c_stop();
//   _delay_ms(10); // Wait for sensor to power up
// }

// void bh1750_set_mode(uint8_t mode)
// {
//   i2c_start();
//   i2c_send_address(AHT10_ADDRESS, true);  // Write mode
//   i2c_write(mode);                        // Set measurement mode
//   i2c_stop();
//   _delay_ms(10); // Allow the sensor to start the measurement
// }

// uint16_t bh1750_read_lux()
// {
//   uint16_t lux = 0;

//   // Request 2 bytes of data from the sensor
//   i2c_start();
//   i2c_send_address(AHT10_ADDRESS, false);  // Read mode
//   uint8_t msb = i2c_read(true);            // Read high byte, send ACK
//   uint8_t lsb = i2c_read(false);           // Read low byte, send NACK
//   i2c_stop();

//   // Combine MSB and LSB
//   lux = (msb << 8) | lsb;
//   return lux; // Return raw lux value
// }

// int main()
// {
//   i2c_init();            // Initialize I²C bus
//   bh1750_init();         // Initialize BH1750
//   bh1750_set_mode(0x11); // Set continuous high-resolution mode

//   init(); // Initialize Arduino libraries
//   Serial.begin(9600);
//   while (!Serial);
//   Serial.println("Hello from void main!");

//   while (1)
//   {
//     uint16_t lux = bh1750_read_lux(); // Read lux value
    
//     Serial.println("Lux: " + String(lux));
//     _delay_ms(1000); // Wait 1 second between readings
//   }
// }
