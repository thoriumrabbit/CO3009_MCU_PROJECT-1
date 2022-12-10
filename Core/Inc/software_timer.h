/*
 * software_timer.h
 *
 *  Created on: Nov 16, 2022
 *      Author: pmt12
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_CYCLE 10

extern int trafficTimer1_flag;
extern int trafficTimer2_flag;
extern int waitTimer_flag;
extern int modifyTimer_flag;
extern int timerLed_flag;
extern int countDownTimer1_flag;
extern int countDownTimer2_flag;
extern int scanFreqTimer_flag;

extern int timerLed_counter;
extern int trafficTimer1_counter;
extern int trafficTimer2_counter;
extern int waitTimer_counter;
extern int modifyTimer_counter;
extern int countDownTimer1_counter;
extern int countDownTimer2_counter;
extern int scanFreqTimer_counter;

void setTimerTraffic1(int duration);
void setTimerTraffic2(int duration);
void setTimerWait(int duration);
void setTimerModify(int duration);
void setTimerTriggerLed(int duration);

void setTimerCounter1(int duration);
void setTimerCounter2(int duration);
void setTimerScanFreq(int duration);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
