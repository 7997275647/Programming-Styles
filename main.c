/*
 * main.c
 *
 *  Created on: Jan 5, 2025
 *      Author: modugu Sandeep Reddy
 */
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<mpu6050.h>



#define MAX_LOOP_COUNTER  (10)

/*
 * Rules To follow
 *
 * 1. Follow camelCase when naming a variable
 * 2. Use Clear and Descriptive names
 * 3. Put each variable in a new line
 * 4. Align values and names of variables
 * 5. pointer prefix p use pp for double pointer
 * 6. boolean prefix b
 * 7. Handle:  prefix h
 * 8. Global Variables: prefix g
 *
 * 9. Priority Naming Prefixes: multiple variable types
 *    a. Global (strongest)
 *    b. pointer
 *    c. Normal (boolean: b, handle: h)
 *
 *
 * Variable Keywords: const, static, volatile
 *
 */

/* typedef struct{
	uint8_t  slaveAddr;
	bool     bIsActive;
	uint32_t msTimeout;
}I2cHandle; */

// static uint16_t gTotalGreenApples = 4;

/*int incrementCounter(){
	static int counter = 0;
	return counter++;
}*/

int main(void)
{

	Mpu6050_Config_t *pAccelConfig;
	pAccelConfig = mpu6050_init(0x14, Mpu6050_AccelFullScale_8g);

	mpu6050_updateAccelData(pAccelConfig);
	int16_t accelX = mpu6050_getAccelX(pAccelConfig);
	int16_t accelY = mpu6050_getAccelY(pAccelConfig);
	int16_t accelZ = mpu6050_getAccelZ(pAccelConfig);

	printf("AccelX Value = %d \n", accelX);
	printf("AccelY Value = %d \n", accelY);
	printf("AccelZ Value = %d \n", accelZ);

	Mpu6050_RegDef_t hAccelConfigReg;
	hAccelConfigReg.resrved =0;
	hAccelConfigReg.AFS_SEL = 2;
	hAccelConfigReg.XA_ST =1;
	hAccelConfigReg.YA_ST = 0;
	hAccelConfigReg.ZA_ST =1;

	uint8_t accelConfigReg=0;
	accelConfigReg |= (hAccelConfigReg.resrved& 0x07)<<0;
	accelConfigReg |= (hAccelConfigReg.AFS_SEL& 0x03)<<3;
	accelConfigReg |= (hAccelConfigReg.ZA_ST& 0x01)<<5;
	accelConfigReg |= (hAccelConfigReg.YA_ST& 0x01)<<6;
	accelConfigReg |= (hAccelConfigReg.XA_ST& 0x01)<<7;

	printf("Value Reg = 0x%X\n", accelConfigReg );

	bool isLightOn = true;

	if (isLightOn){
		printf(" How are you\n");
	}
	else{
		printf("Do Nothing\n");
	}

	/*
	 * Use switch case with an enum variables(whenever possible)
	 * no default case for enum switch case(compiler throws error when we miss any label case if dont use default case)
	 * If you have same handling for multiple cases, utilize fallthrough.
	 * When not using enum cases, we must add default case
	 */
	Mpu6050_AccelFullScale_e accelFullScale= Mpu6050_AccelFullScale_4g;
	switch(accelFullScale){
	case Mpu6050_AccelFullScale_2g:
		printf("Full Scale 2g\n");
		break;
	case Mpu6050_AccelFullScale_4g:
		printf("Full Scale 4g\n");
		break;
	case Mpu6050_AccelFullScale_8g:
		printf("Full Scale 8g\n");
		break;
	case Mpu6050_AccelFullScale_16g:
		printf("Full Scale 16g\n");
		break;
	}

	/*
	 * do not use magic numbers in loop counter use #define
	 */
	for (uint8_t i = 0; i <= MAX_LOOP_COUNTER; i++){
		printf("Counter Value: %d \n", i);
	}

	getchar();
	return 0;
}

