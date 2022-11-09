/*
 * input_reading.c
 *
 *  Created on: Nov 3, 2022
 *      Author: anhni
 */
#include "main.h"
// we aim to work with more than one buttons
#define N0_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING 10
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

int TIME_OUT_FOR_KEY_PRESS = 10;
// the buffer that the final result is stored after
// debouncing
static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer0 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s [ N0_OF_BUTTONS ];
static uint8_t flagForButtonPress [ N0_OF_BUTTONS ];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s [ N0_OF_BUTTONS ];
void button_reading ( void ) {
	for(int i = 0; i < N0_OF_BUTTONS ; i++) {
		debounceButtonBuffer2 [i] = debounceButtonBuffer1 [i];
		debounceButtonBuffer1 [i] = debounceButtonBuffer0 [i];
		if(i == 0) debounceButtonBuffer0 [i] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port , BUTTON_0_Pin) ;
		if(i == 1) debounceButtonBuffer0 [i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port , BUTTON_1_Pin) ;
		if(i == 2) debounceButtonBuffer0 [i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port , BUTTON_2_Pin) ;
		if(debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i]
			&& debounceButtonBuffer1 [i] == debounceButtonBuffer0 [i]){
			if(buttonBuffer [i] != debounceButtonBuffer2 [i]){
				buttonBuffer [i] = debounceButtonBuffer2 [i];
				if(buttonBuffer[i] == BUTTON_IS_PRESSED ) {
				TIME_OUT_FOR_KEY_PRESS = 100;
				flagForButtonPress [i] = 1;
				}
			}
			else {
				TIME_OUT_FOR_KEY_PRESS--;
				if(TIME_OUT_FOR_KEY_PRESS == 0){
					if(buttonBuffer[i] == BUTTON_IS_PRESSED) flagForButtonPress1s[i] = 1;
					TIME_OUT_FOR_KEY_PRESS = 100;
				}
			}
		}
	}
}

unsigned char is_button_pressed ( unsigned int index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if(flagForButtonPress [index] == 1){
		flagForButtonPress [index] = 0;
		return 1;
	}
	return 0 ;
}

unsigned char is_button_pressed_1s ( unsigned int index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if( flagForButtonPress1s [ index ] == 1) {
		flagForButtonPress1s [ index ] = 0;
	}
	return 0;
}

