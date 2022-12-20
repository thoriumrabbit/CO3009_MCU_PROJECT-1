/*
 * fsm_manual.c
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

void trafficLight_manual(){
	switch(state){
	case MANUAL_RED1_GREEN2:
		displayTrafficLight(RED_LIGHT, GREEN_LIGHT);
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MANUAL_RED1_YELLOW2;
			setTimerTraffic1(counter_yellow);
		}
		if(isPressedAndReleased(BTN_SET_INDEX)){
			isInAuto = 1;
			state = MANUAL_RED1_YELLOW2;
			setTimerTraffic1(counter_yellow);
		}
		break;
	case MANUAL_RED1_YELLOW2:
		displayTrafficLight(RED_LIGHT, YELLOW_LIGHT);
		if(isPressedAndReleased(BTN_SET_INDEX)){
			isInAuto = 1;
		}
		if(trafficTimer1_flag == 1 && isInAuto == 0){
			state = MANUAL_GREEN1_RED2;
		}
		else if (trafficTimer1_flag == 1 && isInAuto == 1){
			isInManual = 0;
			segment1Counter = counter_green / DIVISION_NUMBER;
			segment2Counter = counter_red / DIVISION_NUMBER;
			state = AUTO_GREEN1_RED2;
			setTimerCounter1(DURATION_1S);
		}
		break;
	case MANUAL_GREEN1_RED2:
		displayTrafficLight(GREEN_LIGHT, RED_LIGHT);
		if(isPressedAndReleased(BTN_SET_INDEX)){
			isInAuto = 1;
			state = MANUAL_YELLOW1_RED2;
			setTimerTraffic1(counter_yellow);
		}
		if(isPressedAndReleased(BTN_MODIFY_INDEX)){
			state = MANUAL_YELLOW1_RED2;
			setTimerTraffic1(counter_yellow);
		}
		break;
	case MANUAL_YELLOW1_RED2:
		if(isPressedAndReleased(BTN_SET_INDEX)){
			isInAuto = 1;
		}
		displayTrafficLight(YELLOW_LIGHT, RED_LIGHT);
		if(trafficTimer1_flag == 1 && isInAuto == 0){
			state = MANUAL_RED1_GREEN2;
		}
		else if (trafficTimer1_flag == 1 && isInAuto == 1){
			isInManual = 0;
			segment1Counter = counter_red / DIVISION_NUMBER;
			segment2Counter = counter_green / DIVISION_NUMBER;
			state = AUTO_RED1_GREEN2;
			setTimerCounter1(DURATION_1S);
		}
		break;
	default:
		break;
	}
}


