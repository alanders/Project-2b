#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*  																   */
/*  DESCRIPTION :      TSet up the A2D for one shot mode.              */
/*																	   */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/
int TempStore0 = 0x0000;		// Location where ADC ch0 result is stored
int TempStore1 = 0x0000;		// Location where ADC ch1 result is stored
int TempStore2 = 0x0000;		// Location where ADC ch2 result is stored
int TempStore3 = 0x0000;		// Location where ADC ch3 result is stored



void ADInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	TSet up the A2D for one shot mode.  
//  
//  Passed: No variables passed
//  Locals: No local values used
//  Global: adcon0, adcon1, adcon2
//			TempStore0 to TempStore3 
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	
	/*Configure ADC - AN0 (Analog Adjust Pot)*/ 
   adcon0 = 0x80;	// AN0, One-shot, software trigger, fAD/2
   adcon1 = 0x28;	// 10-bit mode, Vref connected.
   adcon2 = 0x01;	// Sample and hold enabled
}   


void A2D_4Channel_Sweep(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:  This will set up the A2D to sweep through the 4 channels.  We will then grab the 
//				results and put them in the TempStore values.
//				UART is set to 9600,N,8,1
//  Passed: No variables passed
//  Locals: No local values used
//  Global: TempStore0 to TempStore3 , ad0 to ad3
//  Returned: No values returned.
//  Author: Amy Anderson   
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
		TempStore0= ad0 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore1= ad1 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore2= ad2 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		TempStore3= ad3 & 0x03ff;	// Mask off the upper 6 bits of the 
									// variable leaving only the result
									// in the variable itself

		// print the results on the display
		// Since the display is only 8 characters we need to display in hex, 3 characters wide
		// with a space in between each.  Channel 0 is upper left, Channel 1 is upper right
		// Channel 2 is lower left and Channel 3 is lower right
		BNSPrintf(LCD,"\t%03x %03x \n%03x %03x ",TempStore0,TempStore1,TempStore2,TempStore3);
		
		// now put the results to the serial port.
		BNSPrintf(SERIAL,"\n\r%03x %03x %03x %03x",TempStore0,TempStore1,TempStore2,TempStore3);
		
		DisplayDelay(1000);
	
}


void A2DInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:  This will init the A2D and put it in Sweep mode.  It will then start a converstion.
//  
//  Passed: No variables passed
//  Locals: No local values used
//  Global: adcon0, adcon1, adcon2, adst
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{	
	adcon0 = 0x98;
		      /*
  		      10011000;  	** Repeat sweep mode 0, soft trigger, fAD/2
		   	  ||||||||______Analog input select bit 0
		   	  |||||||_______Analog input select bit 1
		   	  ||||||________Analog input select bit 2
		  	  |||||_________A/D operation mode select bit 0
		   	  ||||__________A/D operation mode select bit 1
		   	  |||___________Trigger select bit
		   	  ||____________A/D conversion start flag
		  	  |_____________Frequency select bit 0 */

	adcon1 = 0x39;
		      /*
		      00111001;		** Scan AN0-AN3, 10-bit mode, fAD/2, Vref connected
		   	  ||||||||______A/D sweep pin select bit 0
		   	  |||||||_______A/D sweep pin select bit 1
		  	  ||||||________A/D operation mode select bit 1
		   	  |||||_________8/10 bit mode select bit
		   	  ||||__________Frequency select bit 1
		   	  |||___________Vref connect bit
		   	  ||____________External op-amp connection mode bit 0
		  	  |_____________External op-amp connection mode bit 1 */   

	adcon2 = 0x01;
		      /*
		      00000001;		** Sample and hold enabled, fAD/2
		  	  ||||||||______AD conversion method select bit
 	          |||||||_______AD input group select bit 0
		      ||||||________AD input group select bit 1
		      |||||_________Reserved
		      ||||__________Frequency select bit 2
		      |||___________Reserved
		      ||____________Reserved
		      |_____________Reserved */

    adst = 1;				// Start a conversion here
}
