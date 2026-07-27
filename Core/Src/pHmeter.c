/*
 * pHmeter.c
 *
 *  Created on: Jul 27, 2025
 *      Author: morswin
 */


#include "pHmeter.h"

static inline uint32_t averageArray(uint16_t* arr, uint8_t len)
{
	for(int32_t i = 1; i < len; i++)
	{
		uint16_t key = arr[i];
		int32_t j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}//insertion sort

	uint8_t trim = len>>2;
	uint8_t newLen = len - (trim<<1);
	uint32_t sum = 0;

	for(int32_t i =trim; i<(len-trim); i++)
	{
		sum+= arr[i];
	}
	uint32_t avg = (sum + (newLen>>1))/newLen;
	return avg;
}

static inline uint8_t calculatepH(uint32_t avg)// returns pH value as an integer (0-140) using fixed-point arithmetic
{
	int16_t pHValue = (int16_t)((((avg * 693U) + 8192U) >> 14) + OFFSET); //fixed-point arithmetic
	if(pHValue < 0)
	{
		return 0;
	}
	else if(pHValue > 140)
	{
		return 140;
	}
	return (uint8_t) pHValue;
}

uint8_t prepareFrame(uint16_t* arr, uint8_t len)
{
	uint32_t avg =  averageArray(arr, len);
	uint8_t prepared = calculatepH(avg);
	return prepared;
}
