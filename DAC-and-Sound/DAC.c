// DAC.c
// Runs on  TM4C123, 
// Implementation of the 4-bit digital to analog converter
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"

// **************DAC_Init*********************
// Initialize 4-bit DAC 
// Input: none
// Output: none
void DAC_Init(void){
	unsigned long volatile delay ;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; //activate port B
	delay = SYSCTL_RCGC2_R; // delay for initialization
	GPIO_PORTB_AMSEL_R &= ~0x0F; // no analog
	GPIO_PORTB_PCTL_R &= ~0x00000FFF; // regular GPIO function
	GPIO_PORTB_DR8R_R |= 0x0F;
  GPIO_PORTB_DIR_R |= 0x0F; // PortB 3-0 are outputs
  GPIO_PORTB_DEN_R	|= 0x0F; // Enable digital on portB 3-0
	GPIO_PORTB_AFSEL_R  &= ~0x0F; // disable alternative function
}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(unsigned long data){
  GPIO_PORTB_DATA_R = data;
}
