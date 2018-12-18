/******************************************************************************************
* NuttX I2C AL implementation for microROS.
* This AL module, include the functions necessary to work with i2c
* TODO:
* -Configuration of the I2C
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/

/***************************Libraries & includes******************************************/
#include "microros_al/I2C/microros_i2c_nuttx.h"
struct i2c_master_s *i2c_aux;
/**********************************Variables**********************************************/

/**************************************************************************
 * Description:
 * Arguments:
 * Return:
 * Notes:
 **************************************************************************/

void nuttx_i2c_write(uint8_t device_addr,uint8_t regaddr, int8_t regval,uint8_t len ){

  struct i2c_msg_s msg;
  int ret;

  /* Setup for the transfer */

  msg.frequency = 100000, //TODO: Look if everytime is the same speed or we could get from other side
  msg.addr      = regaddr;
  msg.flags     = 0;
  msg.buffer    = regval;  /* Override const */
  msg.length    = len;

  /* Then perform the transfer. */

  ret = I2C_TRANSFER(i2c_aux, &msg, 1);
  if(ret<0){
	printf("Error sending data\r\n");
	return -1;
  }

}

/**************************************************************************
 * Description: Read the value of a given I2C register.
 * Arguments: device_addr -> Address of the device to work with, regaddr ->
 * 	Value to read, len -> size of the data that we're going to receive in
 * 	bytes.
 * Return: Value of the register.
 * Notes:
 **************************************************************************/

uint32_t nuttx_i2c_read(uint8_t device_addr,uint8_t regaddr,uint8_t len ){

	//TODO Modificar para añadir i2c_transfer en vez de i2c_write/read
	  struct i2c_config_s config;
	  uint16_t msb, lsb;
	  uint32_t regval = 0;
	  int ret;

	  /* Set up the I2C configuration */

	  config.frequency = 100000;
	  config.address   = device_addr;
	  config.addrlen   = 7;

	  /* Register to read */

	  ret = i2c_write(i2c_aux, &config, &regaddr, 1);
	  if (ret < 0)
		{
		  return ret;
		}

	  /* Read register */

	  ret = i2c_read(i2c_aux, &config, (uint8_t *)&regval, len);
	  if (ret < 0)
		{
		  return ret;
		}



	  if(len==2){

		uint16_t msb, lsb;
		msb = (regval & 0xFF);
		lsb = (regval & 0xFF00) >> 8;

		regval = (msb << 8) | lsb;
	  }
	  //añadir para 3 bytes
	  else if(len==4){

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

uint8_t nuttx_i2c_hal_aux(struct i2c_master_s *i2c){
  //This funciton is to obtain the data of the connection form the driver an can use local in this file
  memcpy(&i2c_aux,&i2c,sizeof(i2c));
}

void nuttx_i2c_init(){
  i2c_aux = stm32_i2cbus_initialize(1);

  if (!i2c_aux){
   printf("Error init I2C\r\n");
  }
}
