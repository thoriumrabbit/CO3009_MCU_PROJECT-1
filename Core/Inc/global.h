/*
 * global.h
 *
 *  Created on: Nov 23, 2022
 *      Author: pmt12
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define DEFAULT_RED_DURATION			5000
#define DEFAULT_YELLOW_DURATION			2000
#define DEFAULT_GREEN_DURATION			3000

#define DIVISION_NUMBER					1000

#define DURATION_1S						1000
#define DURATION_3S						3000

#define RED_LIGHT						1
#define YELLOW_LIGHT					2
#define GREEN_LIGHT						3
#define PEDESTRIAN_LIGHT_GO				4
#define PEDESTRIAN_LIGHT_STOP			5

#define MAX_SEGMENT_VALUE				99
#define DURATION_FOR_4HZ				250
#define DURATION_FOR_5HZ				200

#define SEGMENT_IN_A_ROW				2
#define MAX_LED_SEGMENT					4

#define TIME_FOR_PEDESTRIAN				5000

#define PEDESTRIAN_LIGHT_CYCLE			8

enum TRAFFIC_STATE	{IDLE,
					AUTO_RED1_GREEN2, AUTO_RED1_YELLOW2, AUTO_GREEN1_RED2, AUTO_YELLOW1_RED2,
					CHANGE_MODE_RED, CHANGE_MODE_YELLOW, CHANGE_MODE_GREEN,
					MODIFY_PRESSED, MODIFY_LONGPRESSED, SET_PRESSED,
					MANUAL_RED1_GREEN2, MANUAL_RED1_YELLOW2, MANUAL_GREEN1_RED2, MANUAL_YELLOW1_RED2,
					PEDESTRIAN_STOP, PEDESTRIAN_GO};
extern enum TRAFFIC_STATE state;

extern int counter_red;
extern int counter_yellow;
extern int counter_green;
extern int counter_pedestrian;


extern int isRedMode;
extern int isYellowMode;
extern int isGreenMode;
extern int isInManual;
extern int isInChange;
extern int isInAuto;
extern int isPedestrian;
extern int isPedestrianPressed;

extern int wasInModify;
extern int timeCounter;
extern int tempCounter;
extern int segment1Counter;
extern int segment2Counter;

extern int segmentIndexAuto;
extern int segmentIndexManual;

extern int led_buffer_auto[MAX_LED_SEGMENT];
extern int led_buffer_manual[MAX_LED_SEGMENT];
#endif /* INC_GLOBAL_H_ */
