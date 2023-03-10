/*
 * global.c
 *
 *  Created on: Nov 24, 2022
 *      Author: pmt12
 */


#include "global.h"
enum TRAFFIC_STATE state;

int counter_red = DEFAULT_RED_DURATION;
int counter_yellow = DEFAULT_YELLOW_DURATION;
int counter_green = DEFAULT_GREEN_DURATION;
int counter_pedestrian;

int buzzer_warning = 0;

int isRedMode;
int isYellowMode;
int isGreenMode;
int isInManual;
int isInChange;
int isInAuto;
int isPedestrian;
int isPedestrianPressed;

int wasInModify;
int timeCounter;
int tempCounter;
int segment1Counter;
int segment2Counter;

int segmentIndexAuto;
int segmentIndexManual;

char message[MAX_MESSAGE_LENGTH];
