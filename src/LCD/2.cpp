// #include <Arduino.h>
// #include <Wire.h>

// #define I2C_ADDR 0x27
// #define EN 2
// #define RW 1
// #define RS 0
// #define D4 4
// #define D5 5
// #define D6 6
// #define D7 7
// #define BACKLIGHT 3



// void lcd_send_nibble(uint8_t data, uint8_t mode)
// {
//     uint8_t nibble = (data & 0x0F) << D4;
//     nibble |= mode << RS;
//     nibble |= (1 << BACKLIGHT); // Backlight on
//     nibble |= (1 << EN);

//     Wire.beginTransmission(I2C_ADDR);
//     Wire.write(nibble);
//     Wire.endTransmission();

//     delayMicroseconds(1);
//     nibble &= ~(1 << EN);
//     Wire.beginTransmission(I2C_ADDR);
//     Wire.write(nibble);
//     Wire.endTransmission();
//     delayMicroseconds(50);
// }

// void lcd_send_byte(uint8_t data, uint8_t mode)
// {
//     lcd_send_nibble(data >> 4, mode);
//     lcd_send_nibble(data, mode);
// }

// void lcd_command(uint8_t cmd)
// {
//     lcd_send_byte(cmd, 0);
// }

// void lcd_write(char data)
// {
//     lcd_send_byte(data, 1);
// }

// void lcd_init()
// {
//     delay(50);

//     // Initialize in 4-bit mode
//     lcd_send_nibble(0x03, 0);
//     delayMicroseconds(4500);
//     lcd_send_nibble(0x03, 0);
//     delayMicroseconds(150);
//     lcd_send_nibble(0x03, 0);
//     lcd_send_nibble(0x02, 0);

//     // Function set: 4-bit, 2 lines, 5x8 dots
//     lcd_command(0x28);
//     delayMicroseconds(60);

//     // Display control: Display on, cursor off
//     lcd_command(0x0C);
//     delayMicroseconds(60);

//     // Entry mode set: Increment, no shift
//     lcd_command(0x06);
//     delay(2);
// }

// void lcd_set_cursor(uint8_t col, uint8_t row)
// {
//     const uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
//     lcd_command(0x80 | (col + row_offsets[row]));
// }

// void lcd_print(const char *str)
// {
//     while (*str)
//     {
//         lcd_write(*str++);
//     }
// }

// int main()
// {
//     init();
    
//     Wire.begin();

//     lcd_init();
//     lcd_command(0x01); // Clear display
//     delay(2);

//     lcd_set_cursor(0, 0);
//     lcd_print("Deepseek will be Alive");

//     while (1)
//     {
//     } // Required for AVR
//     return 0;
// }