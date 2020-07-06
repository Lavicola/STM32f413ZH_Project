
#ifndef DHT22_H
#define DHT22_H

#include "ISensor.h"



#define DHT22_PORT GPIOB
#define DHT22_PIN GPIO_PIN_5



typedef struct dht22MeasureObject{
	float tmp;
	float rh;
}dht22MeasureObject;


static	GPIO_TypeDef* m_GPIO_PORT= GPIOB;
static	uint16_t m_GPIO_PIN = GPIO_PIN_5;

		

		

	
		void Start(void);
		uint8_t Check_Response (void);
		uint8_t Read (void);
		bool parse(uint8_t data[40], float* a_ptemperature, float* a_phumidity);
		bool GetMeasurement(dht22MeasureObject &MeasureObject);

	
	
	
	
	

#endif
