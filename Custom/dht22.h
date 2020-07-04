
#ifndef DHT22_H
#define DHT22_H


#include "GPIO_Functions.h"
#include "ISensor.h"

class DHT22 : ISensor{
	
	private:
		GPIO_TypeDef* m_GPIO_PORT;
		uint16_t m_GPIO_PIN;

		
	public:
		DHT22(uint16_t a_pin,GPIO_TypeDef* a_port);

	
		void Start(void);
		uint8_t Check_Response (void);
		uint8_t Read (void);
		bool parse(uint8_t data[40], float* a_ptemperature, float* a_phumidity);
		bool GetMeasurement(float* a_ptemperature, float* a_phumidity);

	
	
	
	
	
	
};

#endif
