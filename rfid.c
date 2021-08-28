/* 
 * File:   rfid.c
 * Author: ragab
 *
 * Created on April 6, 2018, 11:08 PM
 */
#define FCY 4000000UL
#include "rfid.h"
#include "lcdlib.h"
#include "libpic30.h"

void rfid_init(){
    
    SPI_initMaster();
    PORT_DDR_EN   &=~(1<<EN);
    PORT_PORT_EN  |=(1<<EN);
    /*********THIS FOR IRQ (TEST NOW)*********/
    //TRIS_HAS_INT_PIN |=(1<<INTERRUPT_PIN);
    TRIS_HAS_INT_PIN &=~(1<<INTERRUPT_PIN);
    /*****************************************/
    
}

void rfid_initTransmiter(){
    unsigned char check; 
    rfid_init();
    rfid_writeByte(0x00 ,0x01);//enable Normal mode ,Enable Tx RF field and receiver
    __delay_ms(1500);//THIS NEEDED
    check=rfid_readByte(0x2A);
    if(check &(1<<2)){
        LCD_clearScreen();
        LCD_displayString("RF operated Tx");
    }else{
        LCD_clearScreen();
        LCD_displayString("RF nonoperated Tx");
    }
    __delay_ms(1500);
}

void rfid_initReciever(){
    unsigned char check;
    rfid_init();
    rfid_writeByte(0x00 ,0x03);//enable Normal mode ,Enable Tx RF field and receiver
    __delay_ms(80);//THIS NEEDED
    check=rfid_readByte(0x2A);
    if(check &(1<<2)){
        LCD_clearScreen();
        LCD_displayString("RF operated Rx");
    }else{
        LCD_clearScreen();
        LCD_displayString("RF nonoperated RX");
    }
    
}


void rfid_writeByte(unsigned char addr, unsigned char data){
    SPI_sendrecieveByte(addr);
   SPI_sendrecieveByte(data);
    
}
unsigned rfid_readByte(unsigned char addr){
    SPI_sendrecieveByte(((1<<7) | addr));
    return SPI_recieveByte();
}
//"RA"
void rfid_sendByte(unsigned char data ){
    rfid_writeByte(0x3F,data);//buffer address  
}
unsigned char rfid_readBytee(){
    rfid_writeByte(0x3B ,(1<<1));
    while(!(PORT_HAS_INT_PIN &(1<<INTERRUPT_PIN)));
   
    return rfid_readByte(0x3F);
}
void rfid_sendString(unsigned char number_of_byte , char *str){
    unsigned char check=strlen(str);
    if(check >11){
        LCD_clearScreen();
        LCD_displayString("str >11 char");
        
    }else{
        
        if(check <= 3){
           rfid_writeByte(0x3E ,(16<<check));
        }
        else if(check >= 4){
             rfid_writeByte(0x3D ,(1<<(check-4)));
        }
        
        if(check==1){
            rfid_writeByte(0x3F ,str);
        }else{
            SPI_sendrecieveByte(0x3F);
         do{
            SPI_sendrecieveByte(str); //"RA"
         }while(str++ =='#');
        }
       check=rfid_readByte(0x39);
       while(check &(1<<7));//wait during data transimit
        LCD_clearScreen();
        LCD_displayString("Tx ok");
        __delay_ms(500);
       
    }
 
}

void rfid_recieveString(char *str){
    char *tmp=str;
    while(!(PORT_HAS_INT_PIN &(1<<INTERRUPT_PIN)));
    rfid_readByte(0x3F);
    do{
        *tmp=rfid_readByte(0x3F);
    }while(*tmp++ =='#');
        *tmp='\0';
        LCD_clearScreen();
        LCD_displayString("Rx ok");
        __delay_ms(500);
 
}



