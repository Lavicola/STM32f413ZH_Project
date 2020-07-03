
extern "C"{
#include "stm32f4xx_hal.h"
}
namespace gpio{

void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
	
}
