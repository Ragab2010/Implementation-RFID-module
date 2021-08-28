/* 
 * File:   spi.c
 * Author: ragab
 *
 * Created on April 6, 2018, 3:48 PM
 */



#include "spi.h"
#include <p24FJ256GA705.h>

inline void spi1_close(void)
{
    SPI1CON1Lbits.SPIEN = 0;
}


unsigned char SPI_initMaster(){
    TRISB |=(1<<9);//SDI INPUT MISO
    TRISC &=~(1<<2);//SDO OUTPUT  MOSI
    TRISC &=~(1<<6);//CLK OUTPUT  
    TRISA &=~(1<<10);//SS OUTPUT
    
    /***********************/
   if(!SPI1CON1Lbits.SPIEN)
    {
        TRISB |=(1<<3);//SDI INPUT
        TRISB &=~(1<<4);//SDO OUTPUT
        TRISB &=~(1<<2);//CLK OUTPUT
        TRISB &=~(1<<5);//SS OUTPUT
    
//        SPI1CON1 = spi1_configuration[spiUniqueConfiguration].con1 | 0x0020;
//        SPI1CON2 = spi1_configuration[spiUniqueConfiguration].con2;
//        SPI1STAT = spi1_configuration[spiUniqueConfiguration].stat | 0x8000;
       // SPI1CON1 =0x00;
        //SPI1CON2 =0X00;
       // SPI1STAT =0x00;
        
        
        SPI1CON1H =0;
        SPI1CON2L =0;
        SPI1STATL =0;
        SPI1STATH =0;
        SPI1BRGL =0x0013;
        SPI1IMSKL =0;
        SPI1IMSKH=0;
        SPI1URDTL=0;
        SPI1URDTH=0;
        
        
        SPI1CON1Lbits.MSTEN =1;//MASTER
       // SPI1CON1Lbits.CKE=1 ; //FOR TEST CKE: SPIx Clock Edge Select bit*******************
        SPI1CON1Lbits.SPIEN =1;//ENABLE SPI
                
                
                

   //     SCK1OUT_SetDigitalOutput();
        return 1;
    }
    return 0;
//	

}

void SPI_initSlave(){

}

unsigned char SPI_sendrecieveByte(unsigned char byte){
    SPI1BUFL = byte;
    while(!SPI1STATLbits.SPIRBF);
    return SPI1BUFL;
	
}
unsigned char SPI_recieveByte(){
   
    while(!SPI1STATLbits.SPIRBF);
    return SPI1BUFL;
	
}

