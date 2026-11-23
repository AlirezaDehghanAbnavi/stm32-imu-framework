/*
 * sensor_data.h
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */

#ifndef INC_SENSOR_DATA_H_
#define INC_SENSOR_DATA_H_

#include <stdint.h>

typedef struct
{
    // Accelerometer (g)
    float accel_x;
    float accel_y;
    float accel_z;

    // Gyroscope (degrees per second)
    float gyro_x;
    float gyro_y;
    float gyro_z;

} IMU_Data_t;

#endif /* INC_SENSOR_DATA_H_ */
