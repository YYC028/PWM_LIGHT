#include "bsp_led.h"
#include"main.h"
extern TIM_HandleTypeDef htim5;

void aRGB_led_show(unsigned int aRGB)
{
    static uint8_t alpha;
    static uint16_t red,green,blue;

    alpha =(aRGB & 0xFF000000) >> 16;
    red = ((aRGB & 0x00FF0000) >> 24) * alpha;
    green = ((aRGB & 0x0000FF00)>>16) * alpha;
    blue = ((aRGB & 0x000000FF)>> 0)  *  alpha;

  __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_1, blue);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, green);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_3, red);
    
}



