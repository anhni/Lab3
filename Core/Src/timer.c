/*
 * timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: anhni
 */
#include "main.h"
#include "software_timer.h"
#include "input_reading.h"
#include "input_processing.h"
#include  "button.h"
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if( htim -> Instance == TIM2 ) {
		timerRun();
		//getKeyInput();
		button_reading () ;
		//fsm_for_input_processing();
	}
}

