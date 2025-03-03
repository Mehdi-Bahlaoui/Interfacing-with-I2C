#include <stdio.h>          // For snprintf
#include "I2C/i2c.h"        // Include your I2C library
#include "LCD/3.h"          // Include LCD functions
#include "SENSORS/BH1750.h" // Include BH1750 functions
#include "SENSORS/AHT10.h"  // Include AHT10 functions
#include <util/delay.h>     // For _delay_ms (if using AVR)


int main()
{
    // Initialize I2C, LCD, BH1750, and AHT10
    i2c_init();            // Initialize I2C bus
    lcd_init();            // Initialize LCD
    bh1750_init();         // Initialize BH1750
    aht10_init();          // Initialize AHT10
    bh1750_set_mode(0x10); // Set BH1750 to continuous high-resolution mode
    aht10_set_mode(0xAC);  // Set measurement mode

    char buffer[60]; // Buffer to hold formatted strings
    float temperature = 0.0f;
    float humidity = 0.0f;

    while (1)
    {
        // Read lux value from BH1750
        unsigned int lux = bh1750_read_lux();
        // Read temperature and humidity from AHT10
        aht10_read_data(&temperature, &humidity);

        // Display Lux value
        lcd_set_cursor(0, 0); // Move cursor to start of first line
        snprintf(buffer, sizeof(buffer), "Lux: %-5d", lux);
        lcd_print(buffer); // Print lux value

        // Display Temperature and Humidity on second line
        lcd_set_cursor(0, 1); // Move cursor to start of second line
        int t10 = (int)(temperature * 10);
        int h10 = (int)(humidity * 10);
        snprintf(buffer, sizeof(buffer), "T:%d.%dC H:%d.%d%%",t10 / 10, t10 % 10, h10 / 10, h10 % 10);

        lcd_print(buffer); // Print temperature and humidity values

        _delay_ms(500); // Wait 500 ms between readings
    }

    return 0;
}
