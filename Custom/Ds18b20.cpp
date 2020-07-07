#include "Ds18b20.h"
#include "ISensor.h"
#include "TIM_Delay.h"

uint8_t DS18B20_Start (void)
{
	uint8_t Response = 0;
	ISensor::Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);   // set the pin as output
	HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, GPIO_PIN_RESET);  // pull the pin low
	delay (480);   // delay according to datasheet

	ISensor::Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);    // set the pin as input
	delay (80);    // delay according to datasheet

	if (!(HAL_GPIO_ReadPin (DS18B20_PORT, DS18B20_PIN))) Response = 1;    // if the pin is low i.e the presence pulse is detected
	else Response = -1;

	delay (400); // 480 us delay totally.

	return Response;
}

void DS18B20_Write (uint8_t data)
{
	ISensor::Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);  // set as output

	for (int i=0; i<8; i++)
	{

		if ((data & (1<<i))!=0)  // if the bit is high
		{
			// write 1

			ISensor::Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);  // set as output
			HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, GPIO_PIN_RESET);  // pull the pin LOW
			delay (1);  // wait for 1 us

			ISensor::Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);  // set as input
			delay (50);  // wait for 60 us
		}

		else  // if the bit is low
		{
			// write 0

			ISensor::Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);
			HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, GPIO_PIN_RESET);  // pull the pin LOW
			delay (50);  // wait for 60 us

			ISensor::Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);
		}
	}
}

uint8_t DS18B20_Read (void)
{
	uint8_t value=0;

	ISensor::Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);

	for (int i=0;i<8;i++)
	{
		ISensor::Set_Pin_Output(DS18B20_PORT, DS18B20_PIN);   // set as output

		HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, GPIO_PIN_RESET);  // pull the data pin LOW
		delay (1);  // wait for > 1us

		ISensor::Set_Pin_Input(DS18B20_PORT, DS18B20_PIN);  // set as input
		if (HAL_GPIO_ReadPin (DS18B20_PORT, DS18B20_PIN))  // if the pin is HIGH
		{
			value |= 1<<i;  // read = 1
		}
		delay (50);  // wait for 60 us
	}
	return value;
}




uint8_t DS18B20_GetMeasurement(float& Temperature){
	
	
	
	
uint8_t Temp_byte1, Temp_byte2;
uint16_t SUM, TEMP;

uint8_t Presence = 0;
	
	 Presence = DS18B20_Start ();
	  HAL_Delay (1);
	  DS18B20_Write (0xCC);  // skip ROM
	  DS18B20_Write (0x44);  // convert t
	  HAL_Delay (800);

	  Presence = DS18B20_Start ();
      HAL_Delay(1);
      DS18B20_Write (0xCC);  // skip ROM
      DS18B20_Write (0xBE);  // Read Scratch-pad

      Temp_byte1 = DS18B20_Read();
	  Temp_byte2 = DS18B20_Read();
	  TEMP = (Temp_byte2<<8)|Temp_byte1;
	  Temperature = (float)TEMP/16;
	
	
	
	
	
}



