/*
 * input_processing.c
 *
 *  Created on: Nov 3, 2022
 *      Author: anhni
 */
# include "main.h"
# include "input_reading.h"

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,
					BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState_0 = BUTTON_RELEASED ;
enum ButtonState buttonState_1 = BUTTON_RELEASED ;
enum ButtonState buttonState_2 = BUTTON_RELEASED ;
void fsm_for_input_processing ( void ) {
	////////////BUTTON_0/////////////
		switch ( buttonState_0 ){
			case BUTTON_RELEASED :
				if( is_button_pressed (0) ) {
					buttonState_0 = BUTTON_PRESSED ;
				}
				break ;
			case BUTTON_PRESSED :
				if (! is_button_pressed (0) ) {
					buttonState_0 = BUTTON_RELEASED ;
				} else {
					if( is_button_pressed_1s (0) ) {
						buttonState_0 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
						}
				}
				break ;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND :
				if (! is_button_pressed (0) ) {
					buttonState_0 = BUTTON_RELEASED ;
				}
				// todo
				break ;
			}
		////////////BUTTON_1/////////////
		switch ( buttonState_1 ){
			case BUTTON_RELEASED :
				if( is_button_pressed (1) ) {
					buttonState_1 = BUTTON_PRESSED ;
				}
				break ;
			case BUTTON_PRESSED :
				if (! is_button_pressed (1) ) {
					buttonState_1 = BUTTON_RELEASED ;
				} else {
					if( is_button_pressed_1s (1) ) {
						buttonState_1 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
						}
				}
				break ;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND :
				if (! is_button_pressed (1) ) {
					buttonState_1 = BUTTON_RELEASED ;
				}
				// todo
				break ;
			}
		////////////BUTTON_2/////////////
		switch ( buttonState_2 ){
			case BUTTON_RELEASED :
				if( is_button_pressed (2) ) {
					buttonState_2 = BUTTON_PRESSED ;
				}
				break ;
			case BUTTON_PRESSED :
				if (! is_button_pressed (2) ) {
					buttonState_2 = BUTTON_RELEASED ;
				} else {
					if( is_button_pressed_1s (2) ) {
						buttonState_2 = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
						}
				}
				break ;
			case BUTTON_PRESSED_MORE_THAN_1_SECOND :
				if (! is_button_pressed (2) ) {
					buttonState_2 = BUTTON_RELEASED ;
				}
				// todo
				break ;
			}


}

