// Lab13.c
// Runs on TM4C123
// SysTick interrupts are used to implement a 4-key digital piano
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys

#include "..//tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
#include "DAC.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delayms(unsigned long msec);
unsigned long input, previous ;

 int main(void){ 
	
  TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); 
// PortE used for piano keys, PortB used for DAC        
  Sound_Init(); // initialize SysTick timer and DAC
  Piano_Init();
  EnableInterrupts();  // enable after all initialization are done
	previous = 0;
  while(1){                
// input from keys to select tone
input = Piano_In();
   if (input == 0x01)// && (previous == 0))
   {
		 EnableInterrupts();
		 Sound_Tone(4778);
   }	
	 else if (input == 0x02) //&& (previous == 0))
   {
		 EnableInterrupts();
		 Sound_Tone(4257);
   }
	 else if (input == 0x04) //&& (previous == 0))
   {
		 EnableInterrupts();
		 Sound_Tone(3792);
   }
	 else if (input == 0x08) //&& (previous == 0))
   {
		 EnableInterrupts();
		 Sound_Tone(3189);
   }
	 //else if (previous && input == 0x0)
	 //{
	//	 DisableInterrupts();
   //}
	 else{
	   Sound_Off(); 
	 }
	 previous = input;
	 delayms(10);
            
 }}

// Inputs: Number of msec to delay
// Outputs: None
void delayms(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}
