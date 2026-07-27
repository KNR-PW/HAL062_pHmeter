/*
 * pHmeter.c
 *
 *  Created on: Jul 27, 2025
 *      Author: morswin
 */


#include "pHmeter.h"

uint32_t averageArray(uint16_t* arr, uint8_t len)
{
	uint32_t sum = 0;

	for(int i =0; i<len; i++)
	{
		sum+= arr[i];
	}
	uint32_t avg = (sum + len/2U)/len;
	return avg;
}

uint8_t calculatepH(uint32_t avg)
{
	uint8_t pHValue = (uint8_t)((((avg * 693U) + 8192U) >> 14) + OFFSET); //fixed-point arithmetic
	return pHValue;
}

uint8_t prepareFrame(uint16_t* arr, uint8_t len)
{
	uint32_t avg =  averageArray(arr, len);
	uint8_t prepared = calculatepH(avg);
	return prepared;
}
