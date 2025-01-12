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

/*
 * Use uppercase letters for macro namings and use _to seperate words
 * can use __ between prefix and name
 *
 *
 */


#define MAIN_TASK_SIG__SUSPEND 1
#define MAIN_TASK_SIG__RESUME  2
#define MAIN_TASK_SIG__STAT    3
/*
 * Defining constants
 * when there is arithmetic in the definition use paranthesis
 *
 */
#define MAX_LOOP_COUNTER  (5*2)

/*
 * Function like macros
 *
 * Macros work better in generalization(as they are not type specific)
 * For each use of macro parameter you have to surround it with parentheses
 * if the return variable type is necessary, use normal C function.
 *
 */
#define DEGREES_TO_FAHRENHEIT(X)  ((((X) * 18) / 10) + 32)
#define FAHRENHEIT_TO_DEGREES(X)  ((((X) - 32) * 10) / 18)

/*
 * X MACROS
 *
 *
 */
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
	hAccelConfigReg.AFS_SEL = 1;
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
	Mpu6050_AccelFullScale_e accelFullScale= hAccelConfigReg.AFS_SEL;
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

	float tempInD = 46.3f;
	printf("temp in fahrenheit is %.2f \n", DEGREES_TO_FAHRENHEIT(tempInD));


	getchar();
	return 0;
}

