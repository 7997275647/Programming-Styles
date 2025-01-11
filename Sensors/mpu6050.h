/*
 * mpu6050.h
 *
 *  Created on: Jan 7, 2025
 *      Author: modug
 */

#ifndef SENSORS_MPU6050_H_
#define SENSORS_MPU6050_H_

#include <stdint.h>
#include <stdbool.h>

/*
 * Always typedef structures
 *
 * Use PascalCase for typedef name(Variable name still use camelCase)
 *
 * add suffix _t to typedef name
 *
 * Good to use <filename>_ as a prefix if that struct is specific to mpu6050
 */
/*typedef struct{
	int16_t accelX;
	int16_t accelY;
	int16_t accelZ;
	bool    isValid;
}Mpu6050_AccelData_t;*/

typedef struct{
	uint8_t  resrved : 3;
	uint8_t  AFS_SEL : 2;
	uint8_t  ZA_ST   : 1;
	uint8_t  YA_ST   : 1;
	uint8_t  XA_ST   : 1;


}Mpu6050_RegDef_t;

typedef enum{
	Mpu6050_AccelFullScale_2g =0,
	Mpu6050_AccelFullScale_4g,
	Mpu6050_AccelFullScale_8g,
	Mpu6050_AccelFullScale_16g,
}Mpu6050_AccelFullScale_e;

typedef struct Mpu6050_Config_Tag Mpu6050_Config_t;

Mpu6050_Config_t* mpu6050_init    (uint8_t addr, Mpu6050_AccelFullScale_e fullScale);
void     mpu6050_updateAccelData   (Mpu6050_Config_t *pConfig);
int16_t  mpu6050_getAccelX         (Mpu6050_Config_t *pConfig);
int16_t  mpu6050_getAccelY         (Mpu6050_Config_t *pConfig);
int16_t  mpu6050_getAccelZ         (Mpu6050_Config_t *pConfig);
void     mpu6050_deInit            (Mpu6050_Config_t *pConfig);

#endif /* SENSORS_MPU6050_H_ */
