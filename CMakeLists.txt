cmake_minimum_required(VERSION 3.7)
project(NRF24_On_Pi C)

set(CMAKE_C_STANDARD 99)

add_executable(NRF24_On_Pi main.c nrf24_hal.c nrf24.h nrf24.c nRF24L01.h)
target_link_libraries(NRF24_On_Pi wiringPi)