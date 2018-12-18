/******************************************************************************************
* freeRTOS I2C AL implementation for microROS.
* This AL module, include the functions necessary to work with i2c
* TODO:
* -Configuration of the I2C
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/

/***************************Libraries & includes******************************************/
#include "microros_al/I2C/microros_i2c_freertos.h"

/**********************************Variables**********************************************/
I2C_HandleTypeDef hi2c1;

/**********************************Private Functions*************************************/


/**********************************Public Functions**************************************/

#ifdef freertos

/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/

/*void freertos_i2c_write(uint8_t device_addr,int8_t data, uint8_t addr, uint8_t len){
  //TODO
}*/

/**************************************************************************
 * Description: Read the value of a given I2C register.
 * Arguments: device_addr -> Address of the device to work with, regaddr ->
 * 	Value to read, len -> size of the data that we're going to receive in
 * 	bytes.
 * Return: Value of the register.
 * Notes:
 **************************************************************************/

uint32_t freertos_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len ){

  uint32_t regval;
  int ret;

   ret=HAL_I2C_Master_Transmit (&hi2c1, device_addr<<1,(uint8_t)regaddr, 1, 100);
   if(ret>0){
      //error
  	 // printf("Error getreg32 transmit: %i \r\n",ret);
    }
   ret=HAL_I2C_Master_Receive (&hi2c1,device_addr<<1,&regval,len,100);
    if(ret>0){
     //printf("Error getreg32 receive: %i \r\n",ret);
    }
    //Theses operations are to set in the correct place each byte.
   if(len==2){

  	uint16_t msb, lsb;
  	msb = (regval & 0xFF);
  	lsb = (regval & 0xFF00) >> 8;

  	regval = (msb << 8) | lsb;
   }
   else if(len==3){
  	uint16_t byte1, byte2, byte3, byte4;//byte1 is the msb and byte4 is the lsb
  	byte1=(regval & 0xFF);
  	byte2=(regval & 0xFF00) >>8;
  	byte3=(regval & 0xFFFF00) >> 16;
  	byte4=(regval & 0xFFFFFF00) >> 24;

  	regval=(byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
  }
    	return regval;
}

/**************************************************************************
 * Description: This function setup the I2C port
 * Arguments: Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/
void freertos_i2c_init(){

  __HAL_RCC_GPIOB_CLK_ENABLE();
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
}

#endif
