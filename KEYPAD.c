/*
 * KEYPAD.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG:RAGAB
 */
#define FCY 4000000UL
#include "KEYPAD.h"
#include <p24FJ256GA705.h>

unsigned char KEYPAD_pressed(){
	unsigned char col , row;
	unsigned char keypad_matrix[ROW][COL]=
		   {{'1','2','3' , 'A'},
			{'4','5','6' , 'B' },
			{'7','8','9' , 'C'},
			{'*','0','#' , 'D'}};
//    PORTA &=0XFF00;
    TRISA &= 0XFFF0;
while(1){
	for(col =0 ; col<COL ; col++)
		{
			//KEYPAD_DDR = (KEYPAD_DDR & 0XFF00) | (~(0b1111111100010000<<col)) ;
            TRISB =~(1<<COL);
			PORTB =0X000 ;
			__delay_us(30);
			for(row=0 ;row <ROW ; row++){
				if(!(PORTA &(1<<row))){
					while(!(PORTA &(1<<row)));//polling to print one key
					return keypad_matrix[row][col];
				}

			}
		}

}



}


