/*
 * sensor_config.h
 *
 *  Created on: Nov 23, 2026
 *      Author: alirezadehghanabnavi
 */

#ifndef INC_SENSOR_CONFIG_H_
#define INC_SENSOR_CONFIG_H_

typedef enum
{
    SENSOR_MODE_POLLING = 0,
    SENSOR_MODE_INTERRUPT

} SensorMode_t;

/* Select acquisition mode here */
#define SENSOR_MODE SENSOR_MODE_INTERRUPT

#endif /* INC_SENSOR_CONFIG_H_ */
