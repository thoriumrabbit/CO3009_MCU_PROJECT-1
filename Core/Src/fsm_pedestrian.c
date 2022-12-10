/*
 * fsm_pedestrian.c
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


void trafficLight_pedestrian(){
	switch(state){
	case PEDESTRIAN_GO:
		break;
	case PEDESTRIAN_STOP:
		break;
	default:
		break;
	}
}
