/* 
 * File:   i2c.h
 * Author: ENG.RAGAB
 *
 * Created on 04 ?????, 2018, 11:27 ?
 */

#ifndef I2C_H
#define	I2C_H
#include "PLATFORM_CONFIGRATION.h"

#include <p24FJ256GA705.h>
//#include "stdutils.h"


/***************************************************************************************************
                               SCL and SDA pin configuration
***************************************************************************************************/							   
#define SCL RG3		//SCL Connected to PORTC.3
#define SDA RG4 	//SDA Connected to PORTC.4

#define SCL_Direction TRISG
#define SDA_Direction TRISG
/**************************************************************************************************/







/***************************************************************************************************
                             Function Prototypes
***************************************************************************************************/
void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(unsigned char var_i2cData_u8);
uint8_t I2C_Read(uint8_t var_ackOption_u8);
void i2c_WaitForIdle();
void I2C_Restart();
void i2c_Ack();
void i2c_NoAck();

#endif	/* I2C_H */

