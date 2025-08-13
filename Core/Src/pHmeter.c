/*
 * pHmeter.c
 *
 *  Created on: Jul 27, 2025
 *      Author: morswin
 */


#include "pHmeter.h"

float averageArray(uint16_t* arr, uint8_t len)
{
	float avg;
	uint32_t sum;
	for(int i =0; i<len; i++)
	{
		sum+= arr[i];
	}
	avg = (float)sum / len;
	return avg;
}

uint8_t convertpH(float avg)
{
	float voltage = 3.3f * avg / 4096.0f;
	//printf("(%.3f V)\n", voltage);
	uint8_t pHValue = 52.5f * voltage + OFFSET;
	return pHValue;
}
