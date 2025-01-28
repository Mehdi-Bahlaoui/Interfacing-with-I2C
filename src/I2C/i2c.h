#include <avr/io.h>


// I²C functions
void i2c_init()
{
    TWBR = 16; // Set bit rate register for ~100 kHz
    TWSR = 0;  // No prescaler
}

void i2c_start()
{
    TWCR = (1 << TWSTA) | (1 << TWINT) | (1 << TWEN); // Start condition
    while (!(TWCR & (1 << TWINT)))
        ; // cad bghina interrupt ikoun 1
}

void i2c_stop()
{
    TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN); // Stop condition
    while (TWCR & (1 << TWSTO))
        ; // cad bghina stop flag ikoun 0
}

void i2c_send_address(uint8_t address, bool write = true)
{
    uint8_t address_with_rw = (address << 1) | (write ? 0 : 1);
    TWDR = address_with_rw;            // Load address into data register
    TWCR = (1 << TWINT) | (1 << TWEN); // Start transmission
    while (!(TWCR & (1 << TWINT)))
        ; // Wait for transmission to complete
}

void i2c_write(uint8_t data)
{
    TWDR = data;                       // Load data into data register
    TWCR = (1 << TWINT) | (1 << TWEN); // Start transmission
    while (!(TWCR & (1 << TWINT)))
        ; // Wait for transmission to complete
}

uint8_t i2c_read(bool ack = true)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (ack ? (1 << TWEA) : 0); // Read with or without ACK
    while (!(TWCR & (1 << TWINT)))
        ;        // Wait for reception to complete
    return TWDR; // Return received
}