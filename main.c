#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "nrf24.h"
#include <unistd.h>
#include <string.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main() {
    wiringPiSetup();
    /* initializes hardware pins */
    nrf24_init();

    /* RF channel: #2 , payload length: 4 */
    nrf24_config(2,16);

    uint8_t tx_mac[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
    uint8_t rx_mac[5] = {0xD7,0xD7,0xD7,0xD7,0xD7};

    /* Set the module's own address */
    nrf24_rx_address(rx_mac);

    /* Set the transmit address */
    nrf24_tx_address(tx_mac);

    uint8_t data_array[16] = {0};

    //nrf24_powerUpRx();

    while(1) {
        if(nrf24_dataReady())
        {
            memset(data_array, 0, sizeof(data_array));
            nrf24_getData(data_array);
            printf("Receive: %s\n",(char *)data_array);
        }
        usleep(5000);
    }

}
#pragma clang diagnostic pop