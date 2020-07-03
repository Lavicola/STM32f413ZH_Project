
#ifndef COMPONENTSMANAGER_H
#define COMPONENTSMANAGER_H

#include "dht22.h"


#define DHT22_PORT GPIOA
#define DHT22_PIN GPIO_PIN_5





class ComponentsManager
{
	
	public:
		ComponentsManager();
		~ComponentsManager();
	
		bool getDHT22Measure(float* a_ptemperature,float* a_phumidiy);
		
	
	
	
	
	
	
	
	DHT22 m_dht22;
	
	
	
	
	
};





#endif





