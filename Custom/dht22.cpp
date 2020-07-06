
#include "dht22.h"
#include "TIM_Delay.h"



void Start(void)
{
	ISensor::Set_Pin_Output(m_GPIO_PORT, m_GPIO_PIN); // set the pin as output
	HAL_GPIO_WritePin (m_GPIO_PORT, m_GPIO_PIN, GPIO_PIN_RESET);   // pull the pin low
	delay(500);   // wait for > 1ms

	HAL_GPIO_WritePin (m_GPIO_PORT, m_GPIO_PIN, GPIO_PIN_SET);   // pull the pin high
	delay (30);   // wait for 30us

	ISensor::Set_Pin_Input(m_GPIO_PORT, m_GPIO_PIN);   // set as input
}



uint8_t Check_Response(void)
{
	uint8_t Response = 0;
	delay (40);  // wait for 40us
	if (!(HAL_GPIO_ReadPin (m_GPIO_PORT, m_GPIO_PIN))) // if the pin is low
	{
		delay (80);   // wait for 80us
	
		if ( HAL_GPIO_ReadPin (m_GPIO_PORT, m_GPIO_PIN) == 1 ){
			Response = 1;
		}else{
			Response = -1;
		}
	}
	while ((HAL_GPIO_ReadPin(m_GPIO_PORT, m_GPIO_PIN)));   // wait for the pin to go low
	return Response;
}

uint8_t Read(void)
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (m_GPIO_PORT, m_GPIO_PIN)));   // wait for the pin to go high
		delay (40);   // wait for 40 us

		if (!(HAL_GPIO_ReadPin (m_GPIO_PORT, m_GPIO_PIN)))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (m_GPIO_PORT, m_GPIO_PIN)));  // wait for the pin to go low
	}

	return i;
}


bool parse(uint8_t a_data[5], float* a_ptemperature, float* a_phumidity) {
		uint16_t l_humidity = 0;
	  uint16_t l_temperature = 0;
		uint8_t l_crc = 0;
		uint8_t l_crc_calculated = 0;
	
	
		l_humidity = ((a_data[0]<<8)|a_data[1]);
		l_temperature = ((a_data[2]<<8)|a_data[3]);
		l_crc = a_data[4];
		//TODO check how to calculate crc
		for(uint8_t i=0;i<4;i++){ 
			l_crc_calculated += a_data[i];
		}
		if(l_crc != l_crc_calculated){
			return false;
		}
		*a_ptemperature = (float) (l_temperature/10.0);
		*a_phumidity = (float) (l_humidity/10.0);

	
		return true;
	}


	bool GetMeasurement(dht22MeasureObject &MeasureObject){
	
	uint8_t l_Presence = -1;
	uint8_t l_data[5] ={0};
	bool isValid = false;
			
		Start();
		l_Presence = Check_Response();
		if(l_Presence != 1){return false;}
		for(uint8_t i =0;i<5;i++)
		{
			l_data[i] = Read();
		}
		
		
		isValid = parse(l_data,&MeasureObject.tmp,&MeasureObject.rh);
		if(!isValid){MeasureObject.tmp = -100;MeasureObject.rh= -100; return false;}
		return true;	
			
	}


	
	

