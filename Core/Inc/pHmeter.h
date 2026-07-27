/*
 * pHmeter.h
 *
 *  Created on: Jul 27, 2025
 *      Author: morswin
 */

#ifndef INC_PHMETER_H_
#define INC_PHMETER_H_

#include<stdint.h>

#define SAMPLES_PER_FRAME 40
#define ADC_BUFFER_LEN (SAMPLES_PER_FRAME * 2)
#define PH_METER_TX_ID 192
#define PH_METER_RX_ID 193

#define OFFSET 1.1

float averageArray(uint16_t* arr, uint8_t len);
float convertpH(float avg);
uint8_t pHRound(float pH);
uint8_t prepareFrame(uint16_t* arr, uint8_t len);

#endif /* INC_PHMETER_H_ */
