
extern "C"{
#include "stm32f4xx_hal.h"
}
#include <stdint.h>
class Sensor
{
    public:
        	virtual void Start(void) = 0;
					virtual uint8_t Check_Response (void) = 0;
					virtual uint8_t Read (void)= 0;
					virtual bool GetMeasurement() = 0;
										
					virtual ~Sensor(){};
};

namespace test{
	

					 void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
					 void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
	};