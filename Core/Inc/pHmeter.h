/*
 * pHmeter.h
 *
 *  Created on: Jul 27, 2025
 *      Author: morswin
 */

#ifndef INC_PHMETER_H_
#define INC_PHMETER_H_

#include<stdint.h>

#define ARRAY_LEN 40

#define OFFSET 0

float averageArray(uint16_t* arr, uint8_t len);
float convertpH(float avg);

#endif /* INC_PHMETER_H_ */
