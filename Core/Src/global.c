/*
 * global.c
 *
 *  Created on: Nov 24, 2022
 *      Author: pmt12
 */


#include "global.h"
enum TRAFFIC_STATE state;

int counter_red;
int counter_yellow;
int counter_green;
int counter_pedestrian;


int isRedMode;
int isYellowMode;
int isGreenMode;
int isInManual;
int isInChange;
int isInAuto;
int isPedestrian;

int wasInModify;
int timeCounter;
int tempCounter;
int segment1Counter;
int segment2Counter;

int segmentIndexAuto;
int segmentIndexManual;
