/* 
 * File:   spi.h
 * Author: ragab
 *
 * Created on April 6, 2018, 3:46 PM
 */

#ifndef SPI_H
#define	SPI_H


#include <p24FJ256GA705.h>
unsigned char SPI_initMaster();
void SPI_initSlave();
unsigned char SPI_sendrecieveByte(unsigned char byte);
unsigned char SPI_recieveByte();


#endif	/* SPI_H */

