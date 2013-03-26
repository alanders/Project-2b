#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "timers.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*  																   */
/*  DESCRIPTION :	This code will set up timers A1 through B0         */
/*																	   */
/*  DATE        :Sat, Jan 23, 2013                                     */
/*																	   */
/*  MODIFIED BY :      Amy Anderson                                    */
/*																	   */
/*                                                                     */
/*  Version1                                                           */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

//---------------------------------------------------------------------------
//  Purpose:  Initalizes all timers.
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
//---------------------------------------------------------------------------
void TimerInit(void) {
    TimerA2_Init(); 
	TimerA4_Init(); 
    return;
}

//---------------------------------------------------------------------------
//  Purpose:  Initalizes Timer A0 For future use
//  
//  Rev:    1.0     Initial Release
//  
//  Notes:          Not used in this revision
//---------------------------------------------------------------------------

void TimerA0_Init(void) 
{
}


//---------------------------------------------------------------------------
//  Purpose:  Initalizes Timer A1 For future use
//  
//  Rev:    1.0     Initial Release
//  
//  Notes:          Not used in this revision
//---------------------------------------------------------------------------

void TimerA1_Init(void) 
{
}



//---------------------------------------------------------------------------
//  Purpose:  Initalizes Timer A2 into timer mode 5ms
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
//---------------------------------------------------------------------------
void TimerA2_Init(void) {
               
	ta2mr = TIMER_MODE;
	ta2 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS*NUM_OF_SECS) - 1);  // 5 ms timer 	

/* The recommended procedure for writing an Interrupt Priority Level is shown
   below (see M16C datasheets under 'Interrupts' for details). */
   
   	DISABLE_IRQ				
   	ta2ic = CNTR_IPL;		
    ENABLE_IRQ				

	ta2s = StartTimer;				// start timer
}

void TimerA4_Init(void)

//------------------------------------------------------------------------------
// Purpose: This will set up A4 timer for event counter
// Configure Timer A4 as Event counter
// TMOD0 : 0 Event counter mode
// TMOD1 : 1
// MR0 : 0 Pulse is not output (TAiOUT pin functions as I/O port)
// MR1 : 0 Counts falling edge of external signal
// MR2 : 1 Input signal to TAiOUT pin
// Count down when input on TAiOUT pin is low or count up when input on that pin is high.
// The port direction bit for TAiOUT pin is set to “0” (= input mode).
// MR3 : 0 in event counter mode
// TCK0 : 0 Reload type
// TCK1 : 0 when not using two- phase pulse signal processing
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
//  Notes:
//------------------------------------------------------------------------------
{
ta4mr = CLEAR_REGISTER;//Clear Timer A4 Mode Register
ta4mr |= EVENT_MODE;// Select Event / Count Mode
ta4mr |= NO_PULSE_OUT; //Pulse is not output (TAiOUT pin functions as I/O port)
ta4mr |= FALLLING_EDGE; //Counts falling edge of external signal
ta4 = InitalValue;//initial value-0 one count down and interrupt
trgsr|= EventTrigger;//Timer A4 as event trigger
ta4s = StartTimer;				// start timer
}




//---------------------------------------------------------------------------
//  Purpose:  Initalizes Timer B0 for future use
//  
//  Rev:    1.0     Initial Release
//  
//  Notes:          Not used in this revision
//---------------------------------------------------------------------------

void TimerB0_Init(void) 
{
}
