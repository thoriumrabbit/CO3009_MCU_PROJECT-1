/*
 * fsm_automatic.c
 *
 *  Created on: Nov 23, 2022
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
#include "melody.h"
#include "main.h"
#include <stdio.h>

char message[MAX_MESSAGE_LENGTH];

void trafficLight_automatic() {
	switch (state) {
	case IDLE:
		state = AUTO_RED1_GREEN2;
		clearTrafficDisplay();
		segment1Counter = counter_red / DIVISION_NUMBER;
		segment2Counter = counter_green / DIVISION_NUMBER;
		setTimerCounter1(DURATION_1S);
		counter_pedestrian = 0;
		HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!AUTOMATIC#\r"), 1000);
		break;
	case AUTO_RED1_GREEN2:
		displayTrafficLight(RED_LIGHT, GREEN_LIGHT);
		if (isPedestrian == 1)
			displayPedestrianLight(PEDESTRIAN_LIGHT_GO);
		if (isPedestrian == 0)
			displayPedestrianLight(PEDESTRIAN_LIGHT_OFF);
		if (isInManual == 1) {
			state = MANUAL_RED1_GREEN2;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!MANUAL#\r"), 1000);
		}
		if (isPressedAndReleased(BTN_SELECT_INDEX)) {
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!MANUAL#\r"), 1000);
			state = MANUAL_RED1_GREEN2;
			isInManual = 1;
			isInAuto = 0;
		}
		if (is_button_pressed_3s(BTN_SELECT_INDEX)){
			clearTrafficDisplay();
			state = CHANGE_MODE;
			isInChange = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (isPressedAndReleased(BTN_PED_INDEX)) {
			isPedestrian = 1;
		}


		if (countDownTimer1_counter == 1) {
			int buffer1 = segment1Counter/10;
			int buffer2 = segment1Counter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#\r", buffer1, buffer2), 1000);
			segment1Counter--;
			segment2Counter--;
			if (segment2Counter == 0) {
				segment2Counter = counter_yellow / DIVISION_NUMBER;
				state = AUTO_RED1_YELLOW2;
				//buzzer_warning = 0;

				if (isPedestrian == 1) {
					counter_pedestrian++;
					if (counter_pedestrian == PEDESTRIAN_LIGHT_CYCLE) {
						counter_pedestrian = 0;
						isPedestrian = 0;
					}
				}
			}

			setTimerCounter1(DURATION_1S);
		}
		break;
	case AUTO_RED1_YELLOW2:
		displayTrafficLight(RED_LIGHT, YELLOW_LIGHT);
		if (isPedestrian == 1)
			displayPedestrianLight(PEDESTRIAN_LIGHT_GO);
		if (isPedestrian == 0)
			displayPedestrianLight(PEDESTRIAN_LIGHT_OFF);
		if (isPressedAndReleased(BTN_SELECT_INDEX)) {
			isInManual = 1;
			isInAuto = 0;
		}
		if (isPressedAndReleased(BTN_PED_INDEX)) {
			isPedestrian = 1;
		}

		if (is_button_pressed_3s(BTN_SELECT_INDEX)){
			clearTrafficDisplay();
			state = CHANGE_MODE;
			isInChange = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}
		if (countDownTimer1_counter == 1) {
			int buffer1 = segment1Counter/10;
			int buffer2 = segment1Counter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#\r", buffer1, buffer2), 1000);
			segment1Counter--;
			segment2Counter--;
			if (segment2Counter <= 0) {
				segment1Counter = counter_green / DIVISION_NUMBER;
				segment2Counter = counter_red / DIVISION_NUMBER;
				state = AUTO_GREEN1_RED2;

				if (isPedestrian == 1) {
					counter_pedestrian++;
					if (counter_pedestrian == PEDESTRIAN_LIGHT_CYCLE) {
						counter_pedestrian = 0;
						isPedestrian = 0;
					}
				}
			}

			setTimerCounter1(DURATION_1S);
		}
		break;
	case AUTO_GREEN1_RED2:
		displayTrafficLight(GREEN_LIGHT, RED_LIGHT);
		if (isPedestrian == 1)
			displayPedestrianLight(PEDESTRIAN_LIGHT_STOP);
		if (isPedestrian == 0)
			displayPedestrianLight(PEDESTRIAN_LIGHT_OFF);
		if (isInManual == 1) {
			state = MANUAL_GREEN1_RED2;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!MANUAL#\r"), 1000);
		}
		if (isPressedAndReleased(BTN_SELECT_INDEX)) {
			state = MANUAL_GREEN1_RED2;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!MANUAL#\r"), 1000);
			isInManual = 1;
			isInAuto = 0;
		}
		if (is_button_pressed_3s(BTN_SELECT_INDEX)){
			clearTrafficDisplay();
			state = CHANGE_MODE;
			isInChange = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}

		if (isPressedAndReleased(BTN_PED_INDEX)) {
			isPedestrian = 1;
		}
		if (countDownTimer1_counter == 1) {
			int buffer1 = segment1Counter/10;
			int buffer2 = segment1Counter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#\r", buffer1, buffer2), 1000);
			segment1Counter--;
			segment2Counter--;
			if (segment1Counter <= 0) {
				segment1Counter = counter_yellow / DIVISION_NUMBER;
				state = AUTO_YELLOW1_RED2;

				if (isPedestrian == 1) {
					counter_pedestrian++;
					if (counter_pedestrian == PEDESTRIAN_LIGHT_CYCLE) {
						counter_pedestrian = 0;
						isPedestrian = 0;
					}
				}
			}

			setTimerCounter1(DURATION_1S);
		}
		break;
	case AUTO_YELLOW1_RED2:
		displayTrafficLight(YELLOW_LIGHT, RED_LIGHT);
		if (isPedestrian == 1)
			displayPedestrianLight(PEDESTRIAN_LIGHT_STOP);
		if (isPedestrian == 0)
			displayPedestrianLight(PEDESTRIAN_LIGHT_OFF);
		if (isPressedAndReleased(BTN_SELECT_INDEX)) {
			isInManual = 1;
			isInAuto = 0;
		}
		if (is_button_pressed_3s(BTN_SELECT_INDEX)){
			clearTrafficDisplay();
			state = CHANGE_MODE;
			isInChange = 1;
			setTimerTriggerLed(DURATION_FOR_4HZ);
		}

		if (isPressedAndReleased(BTN_PED_INDEX)) {
			isPedestrian = 1;
		}

		if (isPedestrian == 1) {
			buzzer_warning = 1;
		}

		if (countDownTimer1_counter == 1) {
			int buffer1 = segment1Counter/10;
			int buffer2 = segment1Counter%10;
			HAL_UART_Transmit(&huart2, (void *)message, sprintf(message, "!7SEG:%d%d#\r", buffer1, buffer2), 1000);
			segment1Counter--;
			segment2Counter--;
			if (segment1Counter <= 0) {
				segment1Counter = counter_red / DIVISION_NUMBER;
				segment2Counter = counter_green / DIVISION_NUMBER;
				state = AUTO_RED1_GREEN2;
				buzzer_warning = 0;

				if (isPedestrian == 1) {
					counter_pedestrian++;
					if (counter_pedestrian == PEDESTRIAN_LIGHT_CYCLE) {
						counter_pedestrian = 0;
						isPedestrian = 0;
					}
				}
			}
			setTimerCounter1(DURATION_1S);
		}

		break;
	default:
		break;
	}
}
