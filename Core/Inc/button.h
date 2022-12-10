/*
 * button.h
 *
 *  Created on: Nov 20, 2022
 *      Author: pmt12
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define WAIT_TIME				3000

#define NUM_OF_BUTTONS 			4
#define PRESSED_DURATION_3S 	3000
#define BTN_PRESSED 			GPIO_PIN_RESET
#define BTN_RELEASED 			GPIO_PIN_SET
#define BTN_SELECT_INDEX 		0
#define BTN_MODIFY_INDEX 		1
#define BTN_SET_INDEX 			2
#define BTN_PED_INDEX			3
int isPressedAndReleased(int buttonIndex);
void readKeyInput();
unsigned char is_button_pressed(uint8_t index);
unsigned char is_button_pressed_3s(unsigned char index);
#endif /* INC_BUTTON_H_ */
