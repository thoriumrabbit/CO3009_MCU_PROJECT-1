/*
 * fsm_change.c
 *
 *  Created on: Dec 10, 2022
 *      Author: pmt12
 */

#include "fsm_manual.h"
#include "fsm_automatic.h"
#include "fsm_change.h"
#include "fsm_pedestrian.h"
#include "global.h"
#include "button.h"
#include "software_timer.h"
#include "led_segment_control.h"
#include <stdio.h>


void trafficLight_change(){
	switch(state){
	case CHANGE_MODE:
		isRedMode = 1;
		isYellowMode = 0;
		isGreenMode = 0;
		isInChange = 1;
		//------
		state = CHANGE_MODE_RED;
		tempCounter = counter_red / DIVISION_NUMBER;
		HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!CHANGE#\r\n"), 1000);
		clearTrafficDisplay();
		setTimerTriggerLed(DURATION_FOR_4HZ);
		//------
		break;
	case CHANGE_MODE_RED:
		isRedMode = 1;
		isYellowMode = 0;
		isGreenMode = 0;
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			tempCounter = counter_yellow/DIVISION_NUMBER;
			clearTrafficDisplay();
			state = CHANGE_MODE_YELLOW;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter += 10;
				int buffer1 = tempCounter/10;
				int buffer2 = tempCounter%10;
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#RED\r\n", buffer1, buffer2), 1000);
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
				setTimerModify(DURATION_1S);
			}
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SET#RED\r\n"), 1000);
			setTimerWait(DURATION_3S);
		}
		break;
	case CHANGE_MODE_YELLOW:
		isRedMode = 0;
		isYellowMode = 1;
		isGreenMode = 0;

		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			tempCounter = counter_green/DIVISION_NUMBER;
			clearTrafficDisplay();
			state = CHANGE_MODE_GREEN;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter += 10;
				int buffer1 = tempCounter/10;
				int buffer2 = tempCounter%10;
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#YEL\r\n", buffer1, buffer2), 1000);
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
				if((tempCounter + counter_green/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
					HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
					tempCounter = 0;
				}
				setTimerModify(DURATION_1S);
			}
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SET#YEL\r\n"), 1000);
			setTimerWait(DURATION_3S);
		}
		break;
	case CHANGE_MODE_GREEN:
		isRedMode = 0;
		isYellowMode = 0;
		isGreenMode = 1;

		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			tempCounter = counter_red/DIVISION_NUMBER;
			state = CHANGE_MODE_RED;
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MODIFY_PRESSED;
		}
		if(is_button_pressed(BTN_MODIFY_INDEX)){
			if(is_button_pressed_3s(BTN_MODIFY_INDEX)){
				state = MODIFY_LONGPRESSED;
				tempCounter += 10;
				int buffer1 = tempCounter/10;
				int buffer2 = tempCounter%10;
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#GRE\r\n", buffer1, buffer2), 1000);
				if(tempCounter > MAX_SEGMENT_VALUE) {
					tempCounter = 0;
				}
				if((tempCounter + counter_yellow/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
					HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
					tempCounter = 0;
				}
				setTimerModify(DURATION_1S);
			}
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			state = SET_PRESSED;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SET#GRE\r\n"), 1000);
			setTimerWait(DURATION_3S);
		}
		break;
	case MODIFY_PRESSED:
		if(isRedMode == 1){
			tempCounter += 1;
			int buffer1 = tempCounter/10;
			int buffer2 = tempCounter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#RED\r\n", buffer1, buffer2), 1000);
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter = 0;
			}
			state = CHANGE_MODE_RED;
		}
		else if(isYellowMode == 1){
			tempCounter += 1;
			int buffer1 = tempCounter/10;
			int buffer2 = tempCounter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#YEL\r\n", buffer1, buffer2), 1000);
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter =0;
			}
			if((tempCounter + counter_green/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
				tempCounter = 0;
			}
			state = CHANGE_MODE_YELLOW;
		}
		else if(isGreenMode == 1){
			tempCounter += 1;
			int buffer1 = tempCounter/10;
			int buffer2 = tempCounter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#GRE\r\n", buffer1, buffer2), 1000);
			if(tempCounter > MAX_SEGMENT_VALUE){
				tempCounter = 0;
			}
			if((tempCounter + counter_yellow/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
				tempCounter = 0;
			}
			state = CHANGE_MODE_GREEN;
		}
		break;
	case MODIFY_LONGPRESSED:
		if(scanFreqTimer_flag == 1){
			segmentIndexManual++;
			if(segmentIndexManual >= SEGMENT_IN_A_ROW) segmentIndexManual = 0;
			setTimerScanFreq(DURATION_FOR_5HZ);
		}
		if(modifyTimer_flag == 1){
			tempCounter += 10;
			if (isYellowMode == 1){
				if((tempCounter + counter_green/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
					HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
					tempCounter = 0;
				}
			}

			else if (isGreenMode == 1){
				if((tempCounter + counter_yellow/DIVISION_NUMBER) > MAX_SEGMENT_VALUE){
					HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:RED_SYNC_OVERFLOW\r\n"), 1000);
					tempCounter = 0;
				}
			}

			int buffer1 = tempCounter/10;
			int buffer2 = tempCounter%10;
			if(isRedMode == 1)
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#RED\r\n", buffer1, buffer2), 1000);
			else if(isYellowMode == 1)
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#YEL\r\n", buffer1, buffer2), 1000);
			else if(isGreenMode == 1)
				HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#GRE\r\n", buffer1, buffer2), 1000);

			if(tempCounter > MAX_SEGMENT_VALUE) {
				tempCounter = 0;
			}
			setTimerModify(DURATION_1S);
		}
		if(!is_button_pressed(BTN_MODIFY_INDEX)){
			if(isRedMode == 1) state = CHANGE_MODE_RED;
			else if(isYellowMode == 1) state = CHANGE_MODE_YELLOW;
			else if(isGreenMode == 1) state = CHANGE_MODE_GREEN;
		}

		break;
	case SET_PRESSED:
		if(isRedMode == 1){
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SYNC\r\n"), 1000);
			counter_red = tempCounter * DIVISION_NUMBER;
			counter_green = counter_red - counter_yellow;

			int bufferRed_1 = (counter_red/DIVISION_NUMBER) / 10;
			int bufferRed_2 = (counter_red/DIVISION_NUMBER) % 10;
			int bufferYel_1 = (counter_yellow/DIVISION_NUMBER) / 10;
			int bufferYel_2 = (counter_yellow/DIVISION_NUMBER) % 10;
			int bufferGre_1 = (counter_green/DIVISION_NUMBER) / 10;
			int bufferGre_2 = (counter_green/DIVISION_NUMBER) % 10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWRED\r\n", bufferRed_1, bufferRed_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferYel_1, bufferYel_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferGre_1, bufferGre_2), 1000);
		}
		else if (isYellowMode == 1) {
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SYNC\r\n"), 1000);
			counter_yellow = tempCounter * DIVISION_NUMBER;
			counter_red = counter_yellow + counter_green;

			int bufferRed_1 = (counter_red/DIVISION_NUMBER) / 10;
			int bufferRed_2 = (counter_red/DIVISION_NUMBER) % 10;
			int bufferYel_1 = (counter_yellow/DIVISION_NUMBER) / 10;
			int bufferYel_2 = (counter_yellow/DIVISION_NUMBER) % 10;
			int bufferGre_1 = (counter_green/DIVISION_NUMBER) / 10;
			int bufferGre_2 = (counter_green/DIVISION_NUMBER) % 10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWRED\r\n", bufferRed_1, bufferRed_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferYel_1, bufferYel_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferGre_1, bufferGre_2), 1000);
		}
		else if (isGreenMode == 1) {
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:SYNC\r\n"), 1000);
			counter_green = tempCounter * DIVISION_NUMBER;
			counter_red = counter_yellow + counter_green;

			int bufferRed_1 = (counter_red/DIVISION_NUMBER) / 10;
			int bufferRed_2 = (counter_red/DIVISION_NUMBER) % 10;
			int bufferYel_1 = (counter_yellow/DIVISION_NUMBER) / 10;
			int bufferYel_2 = (counter_yellow/DIVISION_NUMBER) % 10;
			int bufferGre_1 = (counter_green/DIVISION_NUMBER) / 10;
			int bufferGre_2 = (counter_green/DIVISION_NUMBER) % 10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWRED\r\n", bufferRed_1, bufferRed_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferYel_1, bufferYel_2), 1000);
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#NEWYEL\r\n", bufferGre_1, bufferGre_2), 1000);
		}
		isRedMode = 0;
		isYellowMode = 0;
		isGreenMode = 0;
		isInChange = 0;
		isInManual = 0;
		scanFreqTimer_flag = 0;
		tempCounter = 0;
		clearTrafficDisplay();
		if(isPressedAndReleased(BTN_SELECT_INDEX)){
			isInChange = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
			setTimerScanFreq(DURATION_FOR_5HZ);
			tempCounter = counter_red/DIVISION_NUMBER;

			state = CHANGE_MODE_RED;
		}
		if(waitTimer_flag == 1){
			state = IDLE;
		}
		break;
	default:
		break;
	}
}

void triggerLed(){
	if(timerLed_flag == 1){
		if (isRedMode == 1 && isInChange == 1){
			//HAL_GPIO_WritePin(D2_RED_LED1_GPIO_Port, D2_RED_LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D3_GREEN_LED1_GPIO_Port, D3_GREEN_LED1_Pin, GPIO_PIN_RESET);
			//HAL_GPIO_WritePin(D4_RED_LED_2_GPIO_Port, D4_RED_LED_2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D5_GREEN_LED2_GPIO_Port, D5_GREEN_LED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_TogglePin(D2_RED_LED1_GPIO_Port, D2_RED_LED1_Pin);
			HAL_GPIO_TogglePin(D4_RED_LED_2_GPIO_Port, D4_RED_LED_2_Pin);

			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (isYellowMode == 1 && isInChange == 1){
//			HAL_GPIO_WritePin(D2_RED_LED1_GPIO_Port, D2_RED_LED1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(D3_GREEN_LED1_GPIO_Port, D3_GREEN_LED1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(D4_RED_LED_2_GPIO_Port, D4_RED_LED_2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(D5_GREEN_LED2_GPIO_Port, D5_GREEN_LED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_TogglePin(D2_RED_LED1_GPIO_Port, D2_RED_LED1_Pin);
			HAL_GPIO_TogglePin(D3_GREEN_LED1_GPIO_Port, D3_GREEN_LED1_Pin);
			HAL_GPIO_TogglePin(D4_RED_LED_2_GPIO_Port, D4_RED_LED_2_Pin);
			HAL_GPIO_TogglePin(D5_GREEN_LED2_GPIO_Port, D5_GREEN_LED2_Pin);

			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (isGreenMode == 1 && isInChange == 1){
			HAL_GPIO_WritePin(D2_RED_LED1_GPIO_Port, D2_RED_LED1_Pin, GPIO_PIN_RESET);
			//HAL_GPIO_WritePin(D3_GREEN_LED1_GPIO_Port, D3_GREEN_LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D4_RED_LED_2_GPIO_Port, D4_RED_LED_2_Pin, GPIO_PIN_RESET);
			//HAL_GPIO_WritePin(D5_GREEN_LED2_GPIO_Port, D5_GREEN_LED2_Pin, GPIO_PIN_RESET);

			HAL_GPIO_TogglePin(D3_GREEN_LED1_GPIO_Port, D3_GREEN_LED1_Pin);
			HAL_GPIO_TogglePin(D5_GREEN_LED2_GPIO_Port, D5_GREEN_LED2_Pin);

			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
	}
}
