#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*  																   */
/*  DESCRIPTION :      This is the main file for the project           */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

	/*DEFINE VARIABLES*/
	#define LOOP_IS_RUNNING 1
	#define DEFAULTS 0x0000


void main(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	The MCU will come here after reset. 
//  Passed: No variables passed
//  Locals: No local values used
//  Global: switch_set initalized
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//			2.0		Updated to include interrupts
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	/*INITALIZE SWITCHES*/ 
     Port_Init(); 
	
	/*INITALIZE SWITCHES*/
	Init_Switches();
	
	/*INITALIZE SYSTEM CLOCK*/
	Init_Clocks();
	
	/*INITALIZE THE DESPLAY*/	
	InitDisplay("ALANDERS");
		
	InitUART();
	
	BNSPrintf(LCD,"\tALANDERS \n  HW#5  ");
  	TimerInit();
	ADInit();//one shot mode
	A2DInit(); //sweep
	ENABLE_SWITCHES;
	
	/*set switch set to empty*/
	switch_set = DEFAULTS;
	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS;
	
	/*IR LED*/

	
	while(LOOP_IS_RUNNING) 
			{
			Process_Switchs(); //HW #5
			A2D_4Channel_Sweep(); //Project 2b
			}	
            
} 
