# STM32 IMU Sensor Acquisition Framework

A modular embedded C framework for acquiring accelerometer and gyroscope data from an LSM6DSV16X 6-axis IMU using an STM32 microcontroller.

## Overview

This project implements a sensor acquisition framework on the STM32F401RE (ARM Cortex-M4), using the STM32 HAL.

It supports both polling-based and interrupt-driven data acquisition, with configurable output data rates.

## Hardware

- STM32 NUCLEO-F401RE
- X-NUCLEO-IKS4A1 sensor expansion board
- LSM6DSV16X 6-axis IMU

## Features

- Custom LSM6DSV16X sensor driver in C
- I2C communication for sensor configuration and data acquisition
- Accelerometer and gyroscope measurements
- Conversion of raw sensor values into g and degrees per second (dps)
- Polling and interrupt-driven acquisition modes
- Configurable output data rates: 15, 30, 60 and 120 Hz
- UART communication for sensor data output

## Software and Tools

- C
- STM32CubeIDE
- STM32 HAL
- I2C
- UART
- GPIO External Interrupts (EXTI)

## Project Structure

```text
Core
├── Inc
│   ├── imu.h
│   ├── lsm6dsv16x.h
│   ├── main.h
│   ├── sensor_config.h
│   ├── sensor_data.h
│   ├── stm32f4xx_hal_conf.h
│   └── stm32f4xx_it.h
├── Src
│   ├── imu.c
│   ├── lsm6dsv16x.c
│   ├── main.c
│   ├── stm32f4xx_hal_msp.c
│   ├── stm32f4xx_it.c
│   ├── syscalls.c
│   ├── sysmem.c
│   └── system_stm32f4xx.c
└── Startup
    └── startup_stm32f401retx.s
```

## Getting Started

1. Clone this repository.
2. Open STM32CubeIDE.
3. Import the project into your workspace.
4. Connect the NUCLEO-F401RE and X-NUCLEO-IKS4A1 boards.
5. Build and flash the firmware.
6. Connect to the board's serial interface at 115200 baud.

## Output

Sensor measurements are transmitted over UART, including:

- Accelerometer: X, Y, Z (g)
- Gyroscope: X, Y, Z (dps)

## Future Improvements

- Real-time Python visualization
- Additional sensor drivers
- FreeRTOS integration
- Improved power management

## Author

Alireza

## License

MIT License (to be added).
