#include "ComponentsManager.h"


#define DHT22_PORT GPIOB
#define DHT22_PIN GPIO_PIN_5



ComponentsManager::ComponentsManager() : m_dht22(DHT22_PIN,DHT22_PORT){
}

bool ComponentsManager::getDHT22Measure(float* a_ptemperature,float* a_phumidiy)
{		
		return m_dht22.GetMeasurement(a_ptemperature,a_phumidiy);
		
}

		


