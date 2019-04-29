//
// Created by mengguang on 2019/4/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define SPI_CHANNEL     0
#define SPI_SPEED       8000000
//NOTE: In order to manual control CS Pin,
//We use SPI Channel 0, but connect Channel 1 CS Pin to NRF24.
#define NRF24_CE_PIN    26
#define NRF24_CS_PIN    11
#define NRF24_IRQ_PIN   25

uint8_t spi_transfer(uint8_t tx) {
    uint8_t data = tx;
    wiringPiSPIDataRW(SPI_CHANNEL, &data, 1);
    return data;
}

/* -------------------------------------------------------------------------- */
/* In this function you should do the following things:
 *    - Set MISO pin input
 *    - Set MOSI pin output
 *    - Set SCK pin output
 *    - Set CSN pin output
 *    - Set CE pin output     */
/* -------------------------------------------------------------------------- */
void nrf24_setupPins() {
    int result = wiringPiSPISetup(SPI_CHANNEL, SPI_SPEED);
    if (result == -1) {
        perror("wiringPiSPISetup:");
        exit(-1);
    }
    pinMode(NRF24_CE_PIN, OUTPUT);
    pinMode(NRF24_CS_PIN, OUTPUT);
    pinMode(NRF24_IRQ_PIN,INPUT);
}

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_ce_digitalWrite(uint8_t state) {
    digitalWrite(NRF24_CE_PIN, state);
}

/* -------------------------------------------------------------------------- */
/* nrf24 CE pin control function
 *    - state:1 => Pin HIGH
 *    - state:0 => Pin LOW     */
/* -------------------------------------------------------------------------- */
void nrf24_csn_digitalWrite(uint8_t state) {
    //(void) state;
    digitalWrite(NRF24_CS_PIN, state);
}
