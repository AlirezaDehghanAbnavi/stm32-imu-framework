/*
 * imu.h
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */

#ifndef INC_IMU_H_
#define INC_IMU_H_

#include "sensor_data.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef IMU_Init(void);
HAL_StatusTypeDef IMU_Read(IMU_Data_t *data);
void IMU_ReadAndPrint(void);

typedef enum
{
    IMU_ODR_15HZ,
    IMU_ODR_30HZ,
    IMU_ODR_60HZ,
    IMU_ODR_120HZ
} IMU_ODR_t;

HAL_StatusTypeDef IMU_SetODR(IMU_ODR_t odr);

#endif /* INC_IMU_H_ */
