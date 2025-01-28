// #include <Arduino.h> // For printing
// #include "i2c.h"

// #include <util/delay.h> // For delays

// #define AHT10_ADDRESS 0x38 



// // AHT10 Functions
// void aht10_init()
// {
//     i2c_start();
//     i2c_send_address(AHT10_ADDRESS, true); // Write mode
//     i2c_write(0xE1);                       // Initialization command
//     i2c_write(0x08);                       // Calibration command
//     i2c_write(0x00);                       // Calibration command
//     i2c_stop();
//     _delay_ms(10); // Wait for sensor to initialize
// }

// void aht10_set_mode(uint8_t mode)
// {
//     i2c_start();
//     i2c_send_address(AHT10_ADDRESS, true); // Write mode
//     i2c_write(mode);                       // Set measurement mode
//     i2c_stop();
//     _delay_ms(10); // Allow the sensor to start the measurement
// }

// void aht10_read_data(float &temperature, float &humidity)
// {
//     uint8_t data[6];

//     // Request 6 bytes of data from the sensor
//     i2c_start();
//     i2c_send_address(AHT10_ADDRESS, true); // Write mode
//     i2c_write(0xAC);                       // Trigger measurement command
//     i2c_write(0x33);                       // Data byte 1
//     i2c_write(0x00);                       // Data byte 2
//     i2c_stop();
//     _delay_ms(80); // Wait for measurement to complete

//     i2c_start();
//     i2c_send_address(AHT10_ADDRESS, false); // Read mode
//     for (int i = 0; i < 6; i++)
//     {
//         data[i] = i2c_read(i < 5); // Read data bytes, send ACK for all but the last byte
//     }
//     i2c_stop();

//     // Convert the data
//     uint32_t raw_humidity = ((uint32_t)data[1] << 12) | ((uint32_t)data[2] << 4) | (data[3] >> 4);
//     uint32_t raw_temperature = ((uint32_t)data[3] & 0x0F) << 16 | ((uint32_t)data[4] << 8) | data[5];

//     humidity = ((float)raw_humidity / 1048576.0) * 100.0;
//     temperature = ((float)raw_temperature / 1048576.0) * 200.0 - 50.0;
// }

// int main()
// {
//     i2c_init();           // Initialize I²C bus
//     aht10_init();         // Initialize AHT10
//     aht10_set_mode(0xAC); // Set measurement mode

//     init(); // Initialize Arduino libraries
//     Serial.begin(9600);
//     while (!Serial)
//         ;
//     Serial.println("Hello from void main!");

//     while (1)
//     {
//         float temperature, humidity;
//         aht10_read_data(temperature, humidity); // Read temperature and humidity values

//         Serial.print("Temperature: ");
//         Serial.print(temperature);
//         Serial.print(" C, Humidity: ");
//         Serial.print(humidity);
//         Serial.println(" %");
//         _delay_ms(1000); // Wait 1 second between readings
//     }
// }