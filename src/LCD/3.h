#include <util/delay.h>
#include "I2C/i2c.h"

#define I2C_ADDR 0x27 // PCF8574 address

// LCD pin assignments
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2
#define LCD_BACKLIGHT 3

//--------------------------------------------------
// I2C expander write function using i2c.h
//--------------------------------------------------
static inline void expanderWrite(unsigned char data)
{
    i2c_start();
    i2c_send_address(I2C_ADDR, true); // 7-bit address + write
    i2c_write(data);
    i2c_stop();
}

//--------------------------------------------------
// LCD functions (modified for 16x2)
//--------------------------------------------------
static inline void pulseEnable(unsigned char data)
{
    expanderWrite(data | (1 << LCD_EN));
    _delay_us(1);
    expanderWrite(data & ~(1 << LCD_EN));
    _delay_us(50);
}

void write4bits(unsigned char nibble, unsigned char mode)
{
    unsigned char data = (nibble << 4) | (mode ? (1 << LCD_RS) : 0) | (1 << LCD_BACKLIGHT);
    expanderWrite(data);
    pulseEnable(data);
}

void lcd_command(unsigned char cmd)
{
    write4bits(cmd >> 4, 0);
    write4bits(cmd & 0x0F, 0);
}

void lcd_write(unsigned char data)
{
    write4bits(data >> 4, 1);
    write4bits(data & 0x0F, 1);
}

void lcd_init()
{

    expanderWrite(0);
    _delay_ms(100);

    // 4-bit initialization
    write4bits(0x03, 0);
    _delay_ms(5);
    write4bits(0x03, 0);
    _delay_us(150);
    write4bits(0x03, 0);
    _delay_us(150);
    write4bits(0x02, 0); // 4-bit mode
    _delay_us(150);

    lcd_command(0x28); // 4-bit, 2 lines, 5x8
    lcd_command(0x0C); // Display on
    lcd_command(0x06); // Increment cursor
    lcd_command(0x01); // Clear display
    _delay_ms(2);
}

void lcd_set_cursor(unsigned char col, unsigned char row)
{
    unsigned char row_offsets[] = {0x00, 0x40}; // 16x2 offsets
    lcd_command(0x80 | (col + row_offsets[row]));
}

void lcd_print(const char *str)
{
    while (*str)
        lcd_write(*str++);
}

//--------------------------------------------------
// Main program
//--------------------------------------------------
// int main()
// {
//     _delay_ms(50);
//     i2c_init()
//     lcd_init();
//     lcd_set_cursor(0, 0);
//     lcd_print("Deepseek 16x2");
//     lcd_set_cursor(0, 1);
//     lcd_print("LCD Test OK!");

//     while (1)
//         ;
//     return 0;
// }