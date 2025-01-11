/**
 * @file mpu6050.c
 * @brief Mpu6050 Accelerometer file
 * @date Created on: Jan 7, 2025
 * @author modug
 *
 */


#include "mpu6050.h"
#include <stdlib.h>

struct Mpu6050_Config_Tag{
	uint8_t i2cAddr;
	Mpu6050_AccelFullScale_e accelFullScale;
	int16_t accelX;
	int16_t accelY;
	int16_t accelZ;
};

/**
 * @brief Initializes the MPU6050 accelerometer with the given values.
 *
 * This function sets up the MPU6050 configuration structure with the specified
 * I2C address and accelerometer full-scale range. The configuration is allocated
 * dynamically.
 *
 * @param addr The I2C address of the MPU6050 device.
 * @param fullScale The accelerometer full-scale value (e.g., 2g, 4g, 8g, 16g).
 * @return A pointer to the initialized Mpu6050_Config_t structure.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 * returned configuration structure.
 */
Mpu6050_Config_t* mpu6050_init(uint8_t addr, Mpu6050_AccelFullScale_e fullScale){

	Mpu6050_Config_t *pConfig = malloc(sizeof(Mpu6050_Config_t));
	pConfig->i2cAddr         = addr;
	pConfig->accelFullScale  = fullScale;
	return pConfig;
}
/**
 * @brief Updtes accelerometer with default values
 *
 * @param *pConfig pointer to the initialized Mpu6050_Config_t structure
 * @return none
 *
 * @note
 **********************************************************************************************************/
void mpu6050_updateAccelData(Mpu6050_Config_t *pConfig){
	//Read from MPU6050 or Emulate data
	pConfig->accelX = 20;
	pConfig->accelY = 30;
	pConfig->accelZ = 40;


}
/**********************************************************************************************************
 * @fn : mpu6050_init
 *
 * @brief : This function initializes the accelorometer with the given values
 *
 * @param[1]: I2c address
 * @param[2]: Accelerometer Full Scale value
 * @param[3]:
 *
 * @return : none
 *
 * @Note:
 **********************************************************************************************************/
int16_t  mpu6050_getAccelX(Mpu6050_Config_t *pConfig){

	return pConfig->accelX;

}
/**********************************************************************************************************
 * @fn : mpu6050_init
 *
 * @brief : This function initializes the accelorometer with the given values
 *
 * @param[1]: I2c address
 * @param[2]: Accelerometer Full Scale value
 * @param[3]:
 *
 * @return : none
 *
 * @Note:
 **********************************************************************************************************/
int16_t  mpu6050_getAccelY(Mpu6050_Config_t *pConfig){

	return pConfig->accelY;
}
/**********************************************************************************************************
 * @fn : mpu6050_init
 *
 * @brief : This function initializes the accelorometer with the given values
 *
 * @param[1]: I2c address
 * @param[2]: Accelerometer Full Scale value
 * @param[3]:
 *
 * @return : none
 *
 * @Note:
 **********************************************************************************************************/
int16_t  mpu6050_getAccelZ(Mpu6050_Config_t *pConfig){

	return pConfig->accelZ;
}
/**********************************************************************************************************
 * @fn : mpu6050_init
 *
 * @brief : This function initializes the accelorometer with the given values
 *
 * @param[1]: I2c address
 * @param[2]: Accelerometer Full Scale value
 * @param[3]:
 *
 * @return : none
 *
 * @Note:
 **********************************************************************************************************/
void  mpu6050_deInit(Mpu6050_Config_t *pConfig){

	free(pConfig);
}
/** @} */
