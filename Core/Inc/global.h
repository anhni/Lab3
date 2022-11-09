/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: anhni
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define MODE_INIT 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4

#define INIT 0
#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

#define INIT_1 0
#define AUTO_RED_1 1
#define AUTO_GREEN_1 2
#define AUTO_YELLOW_1 3

#define MAN_RED 1
#define MAN_GREEN 2
#define MAN_YELLOW 3

extern int status;
extern int status_1;
extern int red_time;
extern int green_time;
extern int yellow_time;

extern int TIMER_CYCLE;
extern int mode;
extern int led01, led23;
extern int index_led;

#endif /* INC_GLOBAL_H_ */
