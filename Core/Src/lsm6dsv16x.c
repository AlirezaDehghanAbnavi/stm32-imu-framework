/*
 * lsm6dsv16x.c
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */

#include "lsm6dsv16x.h"

/* Read the sensor identification register */
HAL_StatusTypeDef LSM6DSV16X_ReadID(uint8_t *id)
{
    return HAL_I2C_Mem_Read(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_WHO_AM_I_REG,
        I2C_MEMADD_SIZE_8BIT,
        id,
        1,
        100
    );
}

HAL_StatusTypeDef LSM6DSV16X_Init(void)
{
    uint8_t ctrl1 = LSM6DSV16X_XL_ODR_120HZ;
    uint8_t ctrl8 = LSM6DSV16X_XL_FS_2G;

    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Write(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL1_REG,
        I2C_MEMADD_SIZE_8BIT,
        &ctrl1,
        1,
        100
    );

    if (status != HAL_OK)
        return status;

    return HAL_I2C_Mem_Write(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL8_REG,
        I2C_MEMADD_SIZE_8BIT,
        &ctrl8,
        1,
        100
    );
}


HAL_StatusTypeDef LSM6DSV16X_ReadAcceleration(
    int16_t *x,
    int16_t *y,
    int16_t *z)
{
    uint8_t data[6];

    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_OUTX_L_A_REG,
        I2C_MEMADD_SIZE_8BIT,
        data,
        6,
        100
    );

    if (status != HAL_OK)
        return status;

    *x = (int16_t)((data[1] << 8) | data[0]);
    *y = (int16_t)((data[3] << 8) | data[2]);
    *z = (int16_t)((data[5] << 8) | data[4]);

    return HAL_OK;
}

void LSM6DSV16X_ConvertToG(int16_t raw_x, int16_t raw_y, int16_t raw_z,
		float *x, float *y, float *z)
{
    *x = raw_x * LSM6DSV16X_ACC_SENSITIVITY;
    *y = raw_y * LSM6DSV16X_ACC_SENSITIVITY;
    *z = raw_z * LSM6DSV16X_ACC_SENSITIVITY;
}


HAL_StatusTypeDef LSM6DSV16X_EnableDataReadyInterrupt(void)
{
    uint8_t config = LSM6DSV16X_INT1_DRDY_XL;

    return HAL_I2C_Mem_Write(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_INT1_CTRL_REG,
        I2C_MEMADD_SIZE_8BIT,
        &config,
        1,
        100
    );

    uint8_t value = 0;

    HAL_I2C_Mem_Read(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_INT1_CTRL_REG,
        I2C_MEMADD_SIZE_8BIT,
        &value,
        1,
        100
    );

    printf("INT1_CTRL = 0x%02X\r\n", value);
}

HAL_StatusTypeDef LSM6DSV16X_InitGyroscope(void)
{
    uint8_t ctrl2 = LSM6DSV16X_GYRO_ODR_120HZ;
    uint8_t ctrl6 = LSM6DSV16X_GYRO_FS_250DPS;

    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Write(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL2_G_REG,
        I2C_MEMADD_SIZE_8BIT,
        &ctrl2,
        1,
        100
    );

    if (status != HAL_OK)
        return status;

    return HAL_I2C_Mem_Write(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL6_G_REG,
        I2C_MEMADD_SIZE_8BIT,
        &ctrl6,
        1,
        100
    );
}

HAL_StatusTypeDef LSM6DSV16X_ReadGyroscope(
    int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t data[6];

    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(
        &hi2c1,
        LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_OUTX_L_G_REG,
        I2C_MEMADD_SIZE_8BIT,
        data,
        6,
        100
    );

    if (status != HAL_OK)
        return status;

    *x = (int16_t)((data[1] << 8) | data[0]);
    *y = (int16_t)((data[3] << 8) | data[2]);
    *z = (int16_t)((data[5] << 8) | data[4]);

    return HAL_OK;
}

void LSM6DSV16X_ConvertToDPS(
    int16_t raw_x, int16_t raw_y, int16_t raw_z,
    float *x, float *y, float *z)
{
    *x = raw_x * LSM6DSV16X_GYRO_SENSITIVITY;
    *y = raw_y * LSM6DSV16X_GYRO_SENSITIVITY;
    *z = raw_z * LSM6DSV16X_GYRO_SENSITIVITY;
}

HAL_StatusTypeDef LSM6DSV16X_SetODR(uint8_t odr)
{
    HAL_StatusTypeDef status;

    // Accelerometer ODR
    status = HAL_I2C_Mem_Write(
        &hi2c1, LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL1_REG,
        I2C_MEMADD_SIZE_8BIT, &odr, 1, 100);

    if (status != HAL_OK)
        return status;

    // Gyroscope ODR
    status = HAL_I2C_Mem_Write(
        &hi2c1, LSM6DSV16X_I2C_ADDR,
        LSM6DSV16X_CTRL2_G_REG,
        I2C_MEMADD_SIZE_8BIT, &odr, 1, 100);

    return status;
}
