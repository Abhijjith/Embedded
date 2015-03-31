// Piano.c
// Runs on TM4C123
// There are four keys in the piano

// Port E bits 3-0 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"


// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void){ 
  unsigned long volatile delay ;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; //activate port E
	delay = SYSCTL_RCGC2_R; // delay for initialization
	GPIO_PORTE_AMSEL_R &= ~0x0F; // no analog
	GPIO_PORTE_PCTL_R &= ~0x00000FFF; // regular GPIO function
  GPIO_PORTE_DIR_R |= 0x00; // PortE 3-0 are inputs
  GPIO_PORTE_DEN_R	|= 0x0F; // Enable digital on portE 3-0
	GPIO_PORTE_AFSEL_R  &= ~0x0F; // disable alternative function
}
// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void){
  
  return GPIO_PORTE_DATA_R &= ~0xFFFFFFF0; // 
}
