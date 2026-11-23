/*
 * lsm6dsv16x.h
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */

#ifndef INC_LSM6DSV16X_H_
#define INC_LSM6DSV16X_H_

#include "stm32f4xx_hal.h"

/* I2C device address */
#define LSM6DSV16X_I2C_ADDR       (0x6B << 1)

/* Register addresses */
#define LSM6DSV16X_WHO_AM_I_REG  0x0F

/* Expected device identification */
#define LSM6DSV16X_WHO_AM_I_VAL  0x70

/* Register Mapping */
#define LSM6DSV16X_CTRL1_REG       0x10
#define LSM6DSV16X_CTRL8_REG       0x17

#define LSM6DSV16X_XL_ODR_120HZ    0x06
#define LSM6DSV16X_XL_FS_2G        0x00

#define LSM6DSV16X_OUTX_L_A_REG    0x28

/* Gyroscope configuration registers */
#define LSM6DSV16X_CTRL2_G_REG       0x11
#define LSM6DSV16X_CTRL6_G_REG       0x15

/* Gyroscope output registers */
#define LSM6DSV16X_OUTX_L_G_REG     0x22

/* Gyroscope configuration */
#define LSM6DSV16X_GYRO_ODR_120HZ   0x06
#define LSM6DSV16X_GYRO_FS_250DPS   0x01

/* Interrupt Registers */
#define LSM6DSV16X_INT1_CTRL_REG  0x0D
#define LSM6DSV16X_INT1_DRDY_XL   0x01


/* Conversion Constant */
#define LSM6DSV16X_ACC_SENSITIVITY 0.000061f

/* Gyroscope sensitivity: dps/LSB */
#define LSM6DSV16X_GYRO_SENSITIVITY 0.00875f

/* runtime ODR configuration */
#define LSM6DSV16X_ODR_15HZ   0x03
#define LSM6DSV16X_ODR_30HZ   0x04
#define LSM6DSV16X_ODR_60HZ   0x05
#define LSM6DSV16X_ODR_120HZ  0x06

extern I2C_HandleTypeDef hi2c1;
/* Function declarations */
HAL_StatusTypeDef LSM6DSV16X_ReadID(uint8_t *);

HAL_StatusTypeDef LSM6DSV16X_Init(void);

HAL_StatusTypeDef LSM6DSV16X_ReadAcceleration(int16_t *, int16_t *, int16_t *);

void LSM6DSV16X_ConvertToG(int16_t, int16_t, int16_t, float*, float*, float*);

HAL_StatusTypeDef LSM6DSV16X_EnableDataReadyInterrupt(void);

HAL_StatusTypeDef LSM6DSV16X_InitGyroscope(void);

HAL_StatusTypeDef LSM6DSV16X_ReadGyroscope(int16_t *, int16_t *, int16_t *);

void LSM6DSV16X_ConvertToDPS(int16_t, int16_t, int16_t,	float *, float *, float *);

HAL_StatusTypeDef LSM6DSV16X_SetODR(uint8_t);

#endif /* INC_LSM6DSV16X_H_ */
