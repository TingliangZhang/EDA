/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_pwm.h"

void MotorInit()
{
	TM_PWM_TIM_t TIM4_Data;
	
	/* Initialize system */
	SystemInit();

/* STM32F4-Discovery LEDS start */
/* Leds on PD12, PD13, PD14, PD15 */
	
	/* Set PWM to 1kHz frequency on timer TIM4 */
	/* 1 kHz = 1ms = 1000us */
	TM_PWM_InitTimer(TIM4, &TIM4_Data, 1000);
	
	/* Initialize PWM on TIM4, Channel 1 and PinsPack 2 = PD12 */
	TM_PWM_InitChannel(&TIM4_Data, TM_PWM_Channel_1, TM_PWM_PinsPack_2);
	/* Initialize PWM on TIM4, Channel 2 and PinsPack 2 = PD13 */
	TM_PWM_InitChannel(&TIM4_Data, TM_PWM_Channel_2, TM_PWM_PinsPack_2);
	/* Initialize PWM on TIM4, Channel 3 and PinsPack 2 = PD14 */
	TM_PWM_InitChannel(&TIM4_Data, TM_PWM_Channel_3, TM_PWM_PinsPack_2);
}

// 
void MotorSpeed1(float n)
{
		TM_PWM_TIM_t TIM4_Data;
/*PD12 Set channel 1 value, 1/N duty cycle */
	TM_PWM_SetChannel(&TIM4_Data, TM_PWM_Channel_1, TIM4_Data.Period / n);
}

void MotorSpeed2(float n)
{
		TM_PWM_TIM_t TIM4_Data;
/*PD13 Set channel 2 value, 1/N duty cycle */
	TM_PWM_SetChannel(&TIM4_Data, TM_PWM_Channel_2, TIM4_Data.Period / n);
}

void MotorSpeed3(float n)
{
		TM_PWM_TIM_t TIM4_Data;
/*PD14 Set channel 3 value, 1/N duty cycle */
	TM_PWM_SetChannel(&TIM4_Data, TM_PWM_Channel_3, TIM4_Data.Period / n);
}
