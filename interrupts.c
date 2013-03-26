#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "Interrupts.h"


/***********************************************************************/
/*                                                                     */
/*  DATE        :  Mon, Mar 23, 2009                                  */
/*																	   */
/*  DESCRIPTION :  	This file contains all the interrupt routines for  */
/* 	  				the peripherals.  								   */
/*																	   */
/*  CPU GROUP   :	62P                                                */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/


/////////////////////////////////
//switches
/////////////////////////////////


void Init_Switches(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This initalizes the switches.
//  
//  
//  Date Created: March 2, 2015
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: No global values used.
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
TimerInit();
int0ic = FALLING_EDGE; //Set Switch 1 Falling Edge
int1ic = FALLING_EDGE;// Set Switch 2 Falling Edge
ta4ic =  FALLING_EDGE;// Set Switch 3 Falling Edge
DISABLE_IRQ //disableirqsbefore setting irq registers
int1ic = EnableSwitch;//Enable Switch 1
int0ic = EnableSwitch;//Enable Switch 2
ta4ic  = EnableSwitch;//Enable Switch 3
ENABLE_IRQ // Enable all interrupts

}


void Process_Switchs(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Process each switch and reset
//				switches when the end count is reached.
//  
//  
//  Date Created: March 2, 2015
//
//  Passed: 	No variables passed
//  Locals: 	No local values used
//  Global: 	No global values used.
//  Returned: 	No values returned.
//  Author: 	Amy Anderson   
//  Rev:    	1.0     Initial Release
//  
//  Notes:      None    
//-----------------------------------------------------------------------------------------------------

{
	Process_Switch_1();
	Process_Switch_2();
	Process_Switch_3();
	Process_Display();
}



void Process_Switch_1(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Process to run if switch one is triggered.
//
//  
//  Date Created: March 2, 2015
//
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_set, TimeCount_Switch1.
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev: 1.0 Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------

{
	if(switch_set& SW1)
	{
	switch_set &= ~SW1;
	BNSPrintf(LCD,"\tLeft  \n ");
	BNSPrintf(SERIAL,"\n\rButton1");
	TimeCount_Switch1 = Reset;
	LED0 ^= LED_OFF;
 	LED1 = LED_OFF;
	LEFT_FORWARD ^= ON; //Left motor off
	}
	

	/////////////////////////////////////////////////////////////////////////	
	//These are counters for switch re-enables. If a switch is disabled and 
	//a predetermined clock count has been reached, the switch is re-enabled
	/////////////////////////////////////////////////////////////////////////
	
	if ((TimeCount_Switch1 >= ClockAlarm))
	{
	    int1ic = EnableSwitch;//Re-Enable Switch 1
		TimeCount_Switch1 = Reset;
		A2D_4Channel_Sweep();
	}
}

void Process_Switch_2(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Process to run if switch two is triggered.
//  
//  
//  Date Created: March 2, 2015 
//
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_set, TimeCount_Switch2.
//  Returned: No values returned.
//  Author: Amy Anderson  
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------

{
	if(switch_set & SW2){
	switch_set&= ~SW2;
	BNSPrintf(LCD,"\tRight   \n ");
	BNSPrintf(SERIAL,"\n\rButton2");
	TimeCount_Switch2 = Reset;
	LED2 ^= LED_OFF;
	LED1 = LED_OFF;
	RIGHT_FORWARD ^= ON;
	}
 	
	
	/////////////////////////////////////////////////////////////////////////	
	//These are counters for switch re-enables. If a switch is disabled and 
	//a predetermined clock count has been reached, the switch is re-enabled
	/////////////////////////////////////////////////////////////////////////
	
	if ((TimeCount_Switch2 >= ClockAlarm))
	{
	    int0ic = EnableSwitch;//Re-Enable Switch 2
		TimeCount_Switch2 = Reset;	
	}
}



void Process_Switch_3(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Process to run if switch three is triggered.
//  
//  
//  Date Created: March 2, 2015
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_set, TimeCount_Switch3
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	if(switch_set & SW3){
	switch_set&= ~SW3;
	BNSPrintf(LCD,"\tOff    \n ");
	BNSPrintf(SERIAL,"\n\rButton3");
	TimeCount_Switch3 = Reset;
	LED0 = LED_OFF;
	LED2 = LED_OFF;
	LED1 = LED_ON;
	LEFT_FORWARD = OFF; //right motor off
 	RIGHT_FORWARD = OFF;
	IR_LED ^= ON; //IR-LED TOGGLE
}
 
 
	/////////////////////////////////////////////////////////////////////////	
	//These are counters for switch re-enables. If a switch is disabled and 
	//a predetermined clock count has been reached, the switch is re-enabled
	/////////////////////////////////////////////////////////////////////////
 
	if ((TimeCount_Switch3 >= ClockAlarm))
	{
		ta4ic  = EnableSwitch;//Enable Switch 3
		TimeCount_Switch3 = Reset; 	
	}
}


//-----------------------------------------------------------------------------------------------------
//  Purpose:	Processed A2D update Display.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------


void Process_Display(void){
	if (A2DProcessed == TRUE) {// only update the display when a new value is available
	A2DProcessed = FALSE;
	BNSPrintf(LCD,"\tRT1:%04u\nAD0:%04u",A2DValueTherm,A2DValuePot);
}
}



void TimerA0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This handles the interrupt for Timer A0.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          Unused at this time.    
//-----------------------------------------------------------------------------------------------------
{
  
}

void TimerA1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This handles the interrupt for Timer A1. 
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          Unused at this time.   
//-----------------------------------------------------------------------------------------------------
{
}


void TimerA2Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This increments a 5 ms timer
//  
//  
//  Date Created: March 2, 2015
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: Count, TimeCount_Switch1, TimeCount_Switch2, TimeCount_Switch3, TimeCount, IncrementCount.
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//  
//  Notes:          This process is just displaying an LED toggle on the QSK to show the 5ms timer is working.
//-----------------------------------------------------------------------------------------------------
{
    	if ((TimeCount += IncrementCount) > (TimeCountCompare))
		{ 
  		LED1 ^= LED_OFF;               // toggle LED ON-OFF-ON
		Count++;			    		// CLOCK COUNTER 
		IR_LED ^= LED_OFF;
		TimeCount_Switch1++;
		TimeCount_Switch2++;
		TimeCount_Switch3++;
    	TimeCount = Restart_count;
}
}

//---------------------------------------------------------------------------
//  Purpose:  Set Timer B0 5 ms.
//  
//  Rev:    1.0     Initial Release
//  
//  Notes:          Unused at this time.    
//---------------------------------------------------------------------------

void TimerB0Interrupt(void)
	{
	}

void Switch_S1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
// Purpose: Switch 1 Interrupt
//
//  
//  Date Created: March 2, 2015
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_hold[S1].
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev: 1.0 Initial Release
//
// Notes: None
//-----------------------------------------------------------------------------------------------------
{
int1ic = DisableSwitch; // Disable Switch 1
switch_set |= SW1;
switch_set |= SW1H;
switch_hold[S1] = Reset;
}

void Switch_S2Interrupt(void)
//-----------------------------------------------------------------------------------------------------
// Purpose: Switch 2 Interrupt
//
//  
//  Date Created: March 2, 2015
//
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_hold[S2].
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev: 1.0 Initial Release
//
// Notes: None
//-----------------------------------------------------------------------------------------------------
{
int0ic = DisableSwitch; // Disable Switch 2
switch_set |= SW2;
switch_set |= SW2H;
switch_hold[S2] = Reset;
}

void Switch_S3Interrupt(void)

//-----------------------------------------------------------------------------------------------------
// Purpose: Switch 3 Interrupt
//
//  
//  Date Created: March 2, 2015
//
//  Passed:	 	No variables passed
//  Locals: 	No local values used
//  Global: 	switch_set, switch_hold[S3]
//  Returned: 	No values returned.
//  Author: 	Amy Anderson   
// 	Rev: 		1.0 Initial Release
//
// Notes: None
//-----------------------------------------------------------------------------------------------------
{
ta4ic = DisableSwitch; // Disable Switch 3
switch_set |= SW3;
switch_set |= SW3H;
switch_hold[S3] = Reset;
}
		



/////////////////////////////////
//
//
//
//
//
// OTHER FUNCTIONS
//
//
//
//
//
//
/////////////////////////////////


void UART0ReceiveInterrupt(void)

//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	while(ri_u0c1 == 0);	  // make sure receive is complete
	
    while(ti_u0c1 == 0); 			//  puts it in the UART 0 transmit buffer 

	u0tb = (char) u0rb;      // read in received data
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////
//NECESSARY CODE STOPS HERE, YOU SHOULD TOO!! 
//CURRENTLY UNUSED FUNCTIONS
///////////////////////////////////////////////////////////////////
//
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////




void WatchDogInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}



void A2DInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void UART0TransmitInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void DMA0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}
void KeyBoardInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void WakeUpInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

void RTCInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}
