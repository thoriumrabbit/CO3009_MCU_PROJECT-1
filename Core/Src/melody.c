/*
 * melody.c
 *
 *  Created on: Dec 11, 2022
 *      Author: binch
 */

#include "main.h"
#include "melody.h"
#include "global.h"
#include "software_timer.h"

int signal = 1;
uint8_t idx = 0;
uint16_t beep[3] = {1,1,1};
uint32_t scale = 0;

void buzzer_init(TIM_TypeDef *tim){
	scale = tim->PSC;
	setTimerBuzzer(10);
}
int butterfly[72] = {
		NOTE_C6, NOTE_C6, NOTE_D6,NOTE_D6, NOTE_E6 ,NOTE_E6, NOTE_C6, NOTE_C6,
		NOTE_C6,NOTE_C6, NOTE_D6,NOTE_D6, NOTE_E6 ,NOTE_E6, NOTE_C6, 0,
		NOTE_E6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_G6,  NOTE_G6, NOTE_G6, NOTE_G6,
		NOTE_E6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_G6,  NOTE_G6, NOTE_G6, NOTE_G6,
		NOTE_G6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6,NOTE_E6, NOTE_C6,NOTE_C6,
		NOTE_G6, NOTE_A6, NOTE_G6, NOTE_F6, NOTE_E6,NOTE_E6, NOTE_C6,0,
		NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_C6,NOTE_C6,NOTE_C6,0,
		NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,NOTE_C6,NOTE_C6,NOTE_C6,0,
};
int dio[72] = {
		NOTE_FS5,NOTE_FS5,0,NOTE_D5,NOTE_D5,0, //6
		NOTE_D5,NOTE_E5,NOTE_F5,0,	//4
		NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_D5,//4
		NOTE_E5,NOTE_FS5,NOTE_FS5,0, //4
		NOTE_B5,NOTE_B5,0,NOTE_B4, //4
		NOTE_CS5,NOTE_D5,0, NOTE_E5, //4
		NOTE_D5, NOTE_CS5, 0, NOTE_A5, NOTE_G5,//6
		//----------------------
		NOTE_FS5,NOTE_FS5,0,NOTE_D5,NOTE_D5,0, //6
		NOTE_D5,NOTE_E5,NOTE_F5,0,	//4
		NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_D5,//4
		NOTE_E5,NOTE_FS5,NOTE_FS5,0, //4
		NOTE_B5,NOTE_B5,0,NOTE_B5, //4
		NOTE_CS6,NOTE_D6,0, NOTE_G5, //4
		NOTE_FS5, NOTE_F5, NOTE_D6 , NOTE_AS5, NOTE_B5, NOTE_B5//6
};

void buzzer_sound(TIM_HandleTypeDef htim ,int volume){
		TIM_CCxChannelCmd(TIM3, TIM_CHANNEL_1, TIM_CCx_ENABLE);
		__HAL_TIM_SET_COMPARE(&htim,TIM_CHANNEL_1,volume);
		// TIM3->PSC = 64000/dio[i%72];// melody[i%3];
		TIM3->PSC = (TIM3->PSC + 1)%63 + 20;// melody[i%3];
	idx++;
}

void buzzer_run(){
	if(buzzerTimer_flag == 1){
		if (buzzer_warning == 1) buzzer_sound(htim3, 40);
		if (buzzer_warning == 0)
			TIM_CCxChannelCmd(TIM3, TIM_CHANNEL_1, TIM_CCx_DISABLE);
		setTimerBuzzer(120);
	}
}
