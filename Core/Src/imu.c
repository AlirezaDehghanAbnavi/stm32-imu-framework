/*
 * imu.c
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */
#include "imu.h"
#include "lsm6dsv16x.h"
#include <stdio.h>

HAL_StatusTypeDef IMU_Init(void)
{
    if (LSM6DSV16X_Init() != HAL_OK)
        return HAL_ERROR;

    if (LSM6DSV16X_InitGyroscope() != HAL_OK)
        return HAL_ERROR;

    return HAL_OK;
}

HAL_StatusTypeDef IMU_Read(IMU_Data_t *data)
{
    int16_t x, y, z;

    if (data == NULL)
        return HAL_ERROR;

    if (LSM6DSV16X_ReadAcceleration(&x, &y, &z) != HAL_OK)
        return HAL_ERROR;

    LSM6DSV16X_ConvertToG(x, y, z,
                          &data->accel_x, &data->accel_y, &data->accel_z);

    if (LSM6DSV16X_ReadGyroscope(&x, &y, &z) != HAL_OK)
        return HAL_ERROR;

    LSM6DSV16X_ConvertToDPS(x, y, z,
                            &data->gyro_x, &data->gyro_y, &data->gyro_z);

    return HAL_OK;
}

void IMU_ReadAndPrint(void)
{
    IMU_Data_t data;

    if (IMU_Read(&data) != HAL_OK)
    {
        printf("IMU read failed!\r\n");
        return;
    }

    printf("Accel: X=%.3f Y=%.3f Z=%.3f g | "
           "Gyro: X=%.2f Y=%.2f Z=%.2f dps\r\n",
           data.accel_x, data.accel_y, data.accel_z,
           data.gyro_x, data.gyro_y, data.gyro_z);
}

HAL_StatusTypeDef IMU_SetODR(IMU_ODR_t odr)
{
    uint8_t register_value;

    switch (odr)
    {
        case IMU_ODR_15HZ:  register_value = 0x03; break;
        case IMU_ODR_30HZ:  register_value = 0x04; break;
        case IMU_ODR_60HZ:  register_value = 0x05; break;
        case IMU_ODR_120HZ: register_value = 0x06; break;
        default: return HAL_ERROR;
    }

    return LSM6DSV16X_SetODR(register_value);
}
