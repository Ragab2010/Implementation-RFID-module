/*
 * File:   main.c
 * Author: ENG:RAGAB
 *
 * Created on 05 ?????, 2018, 05:11 ?
 */
#include "PLATFORM_CONFIGRATION.h"
//PLEASE SEE THE PLATFORM_CONFIGRATION.H FRIST 
#define FCY 4000000UL
#include "pc.h"

int main(void) {

    char RX ,check;
    LCD_init();
    LCD_clearScreen();
    
    rfid_init();
    rfid_writeByte(0x00 ,0x01);//enable Normal mode ,Enable Tx RF field and receiver
    __delay_ms(1500);//THIS NEEDED
    check=rfid_readByte(0x00);
    if(check ==1){
        LCD_clearScreen();
        LCD_displayString("byte 1");
    }else{
        LCD_clearScreen();
        LCD_displayString("none 1");
        
   }
    
    
    /*
    rfid_initTransmiter();
    //LCD_clearScreen();
    LCD_clearScreen();
    LCD_displayString("WELCOME");
    __delay_ms(1500);
    LCD_clearScreen();
    LCD_displayString("Sending Data");
    rfid_sendByte('A');//65
    LCD_clearScreen();
    LCD_displayString("Data Sent.");
    __delay_ms(1500);
    LCD_clearScreen();
    LCD_displayString("Receive Data");
    RX=rfid_readBytee();
    LCD_clearScreen();
    LCD_displayCharacter(RX);
    LCD_displayStringRowCol(2 ,1 ,"Data Recieved");*/
   
    while(1);
    
    
    return 0;
}
