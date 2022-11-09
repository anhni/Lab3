/*
 * button.c
 *
 *  Created on: Sep 24, 2022
 *      Author: anhni
 */
#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int downtime = 100;

int TimeOutForKeyPress =  10;
int button0_flag = 1;
void subKeyProcess(){
//	if(KeyReg3 == PRESSED_STATE){
//
//	}
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button0_flag = 1;
}
int is_Button0_Pressed(){
	if(button0_flag == 1)
	{
		button0_flag =0;
		return 1;
	}
	return 0;
}
void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;

      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 100;
        subKeyProcess();
      }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
          KeyReg3 = NORMAL_STATE;
        }
    }
  }
}
