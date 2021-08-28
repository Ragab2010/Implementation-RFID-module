/* 
 * File:   rfid.h
 * Author: ragab
 *
 * Created on April 6, 2018, 11:08 PM
 */

#ifndef RFID_H
#define	RFID_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spi.h"
#include "lcdlib.h"
#include "libpic30.h"
#define PORT_DDR_EN TRISB
#define PORT_PORT_EN PORTB
#define EN 5

/**************IRQ********************/
#define TRIS_HAS_INT_PIN  TRISC
#define PORT_HAS_INT_PIN  PORTC
#define INTERRUPT_PIN  0

void rfid_init();
void rfid_initTransmiter();
void rfid_initReciever();
void rfid_writeByte(unsigned char addr, unsigned char data);
unsigned rfid_readByte(unsigned char addr);
void rfid_sendString(unsigned char number_of_byte , char *str);
void rfid_recieveString(char *str);
void rfid_sendByte(unsigned char data );
unsigned char rfid_readBytee();



#endif	/* RFID_H */

