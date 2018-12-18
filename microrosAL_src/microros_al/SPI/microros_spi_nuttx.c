/******************************************************************************************
* NuttX SPI AL implementation for microROS.
* This AL module, include the functions necessary to work with SPI
* TODO:
* -SPI DMA
* -Add the option to receive 4 bytes.
*
*Developed by Acutronics Robotics, for microROS project.
* ****************************************************************************************/

/***************************Libraries & includes******************************************/
#include "microros_al/SPI/microros_spi_nuttx.h"

/**********************************Variables**********************************************/
	struct spi_dev_s *spi_aux;

/**********************************Private Functions*************************************/
static void nuttx_spi_lock(bool state){
	//This functions blocks the bus like a mutex
	if(state){
		(void)SPI_LOCK(spi_aux, true);

		SPI_SETMODE(spi_aux, SPIDEV_MODE0);
		SPI_SETBITS(spi_aux, 8);
		(void)SPI_HWFEATURES(spi_aux, 0);
		//TODO: Implement to modify the configuration of the SPI
		(void)SPI_SETFREQUENCY(spi_aux, 5000000);
	}
	else{
		(void)SPI_LOCK(spi_aux, false);
	}
}

/**********************************Public Functions**************************************/

/**************************************************************************
 * Description: This function writes a define value to a register address.
 * Arguments: regaddr ->  Register address where we want to write a value,
 * regval -> Value to write, len -> Length of the data that we want to write
 * Return: Nothing
 * Notes:
 **************************************************************************/
void nuttx_spi_write(uint8_t regaddr, int8_t regval,uint8_t len ){
	nuttx_spi_lock(true);
	if(len ==1){
		//Send
		SPI_SEND(spi_aux, regaddr);
		SPI_SEND(spi_aux, regval);
	}
	else if (len > 1){
		SPI_SEND(spi_aux, regaddr );
		SPI_SNDBLOCK(spi_aux, regval, len);
	}
	nuttx_spi_lock(false);

}

/**************************************************************************
 * Description: Read the value of a register.
 * Arguments: regaddr -> address to be read,
 * len -> Number of bytes that will be returned
 * Return:
 * Notes:
 **************************************************************************/
uint32_t nuttx_spi_read(uint8_t regaddr,uint8_t len ){
	uint32_t regval;
	uint8_t address = (0x80 | (regaddr )); //?? es solo de este driver

	nuttx_spi_lock(true); //Aqui no se si sera correcto hace el bloqueo del bus o antes del CS
	if(len==1){
		SPI_SEND(spi_aux, address);
		regval = SPI_SEND(spi_aux, 0);
	}
	else{
		  SPI_SEND(spi_aux, address);
			SPI_RECVBLOCK(spi_aux, &regval, len);

			if(len==2){
				uint16_t msb, lsb;

				msb = (regval & 0xFF);
				lsb = (regval & 0xFF00) >> 8;

				regval = (msb << 8) | lsb;
			}
			else if(len==3){
				uint16_t v1, v2,v3;

				v1=(regval & 0xFF);
				v2=(regval & 0xFF00) >>8;
				v3=(regval & 0xFFFF00) >> 16;


				regval = (v1 << 16) | (v2 << 8) | v3;
			}
	}
	nuttx_spi_lock(false);

	return regval;

}

/**************************************************************************
 * Description: Function to set the SPI configuration.
 * Arguments:Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/

void nuttx_spi_config(){
	spi_aux = stm32_spibus_initialize(1);

	if (!spi_aux){
	 printf("ERROR: Error with SPI configuration\n");
	}
}

/**************************************************************************
 * Description: This function is to obtain the pointer of the peripheral in NuttX
 * Arguments:Nothing
 * Return:Nothing
 * Notes:
 **************************************************************************/

uint32_t nuttx_spi_hal_aux(struct spi_dev_s *spi){
  //This funciton is to obtain the data of the connection form the driver an can use local in this file
  memcpy(&spi_aux,&spi,sizeof(spi));
}
