#include "stdint.h"
#include "ISensor.h"

#define DS18B20_PORT GPIOB
#define DS18B20_PIN GPIO_PIN_4

uint8_t DS18B20_Start (void);

void DS18B20_Write (uint8_t data);

uint8_t DS18B20_Read (void);

uint8_t DS18B20_GetMeasurement(float& Temperature);

