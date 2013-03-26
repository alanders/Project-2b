
#include "ports.h"
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"



//******************************************************************************
//  Purpose:  This function calls each of 10 ports to initalize the board.
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//*******************************************************************************/



void Port_Init(void) {
    
	/* Switches */
	Port01_Init();
	Port02_Init();
	Port03_Init();
	Port04_Init();
	Port05_Init();
	Port06_Init();
	Port07_Init();
	Port08_Init();
	Port09_Init();
	Port10_Init();
//    return;    

}

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 0
//  System registers associated with Port 1 configured
//    Pin 0 - D8     		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 0 - I/O      		General Purpose I/O
//    Pin 1 - D9     		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 1 - I/O      		General Purpose I/O
//    Pin 2 - D10   		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 2 - I/O      		General Purpose I/O
//    Pin 3 - D11    		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 3 - I/O      		General Purpose I/O
//    Pin 4 - D12    		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 4 - I/O      		General Purpose I/O
//    Pin 5 - D13	    	Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 5 - INT3   	 	Input pins for the INT interrupt
//    Pin 5 - I/O  			General Purpose I/O
//    Pin 6 - D14			Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.			
//    Pin 6 - I/O           General Purpose I/O
//    Pin 7 - D15			Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 7 - I/O		 	General Purpose I/O
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------

void Port00_Init(void){
    pd0 = OUTPUT;
    p0_0 = PIN_LOW;
    p0_1 = PIN_LOW;
    p0_2 = PIN_LOW;
    p0_3 = PIN_LOW;
    p0_4 = PIN_LOW;
    p0_5 = PIN_LOW;
    p0_6 = PIN_LOW;
    p0_7 = PIN_LOW;
    return;
}


//----------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 1
//  System registers associated with Port 1 configured
//    Pin 0 - D8     		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 0 - I/O      		General Purpose I/O
//    Pin 1 - D9     		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 1 - I/O      		General Purpose I/O
//    Pin 2 - D10   		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 2 - I/O      		General Purpose I/O
//    Pin 3 - D11    		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 3 - I/O      		General Purpose I/O
//    Pin 4 - D12    		Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 4 - I/O      		General Purpose I/O
//    Pin 5 - D13	    	Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//   *Pin 5 - INT3   	 	Input pins for the interrupt 3
//    Pin 5 - I/O  			General Purpose I/O
//    Pin 6 - D14			Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.	
//    Pin 6 - I/O           General Purpose I/O
//    Pin 7 - D15			Inputs and outputs data (D8 to D15) when external 16-bit data bus is set as the separate bus.
//    Pin 7 - I/O		 	General Purpose I/O
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------

void Port01_Init(void){
    pd1 = OUTPUT;
    p1_0 = PIN_LOW;
    p1_1 = PIN_LOW;
    p1_2 = PIN_LOW;
    p1_3 = PIN_LOW;
    p1_4 = PIN_LOW;
    p1_5 = PIN_LOW; //INTERRUPT PIN
	//pd1_5 = INPUT;
    p1_6 = PIN_LOW;
    p1_7 = PIN_LOW;
 
}

//----------------------------------------------------------------------------------







//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 2
//  System registers associated with Port 2 configured
//    Pin 0 - A0     		Output address bits (A0 to A19).
//    Pin 0 - AN2_0   		Analog input pins for the A/D converter.
//    Pin 1 - A1     		Output address bits (A0 to A19).
//    Pin 1 - AN2_1    		Analog input pins for the A/D converter.
//    Pin 2 - A2	   		Output address bits (A0 to A19).
//    Pin 2 - AN2_2      	Analog input pins for the A/D converter.
//    Pin 3 - A3	   		Output address bits (A0 to A19).
//    Pin 3 - AN2_3    		Analog input pins for the A/D converter.
//    Pin 4 - A4    		Output address bits (A0 to A19)..
//    Pin 4 - AN2_4    		Analog input pins for the A/D converter.
//    Pin 5 - A5	        Output address bits (A0 to A19).
//    Pin 5 - AN2_5   	 	Analog input pins for the A/D converter.		
//    Pin 6 - A6			Output address bits (A0 to A19).
//    Pin 6 - AN2_6			Analog input pins for the A/D converter.
//    Pin 7 - A7			Output address bits (A0 to A19).
//    Pin 7 - AN2_7			Analog input pins for the A/D converter.
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------

void Port02_Init(void)
{
    pd2 = OUTPUT;
    //p2_0 = PIN_LOW;
    //p2_1 = PIN_LOW;
    p2_2 = PIN_LOW;
    p2_3 = PIN_LOW;
    p2_4 = PIN_LOW;
    p2_5 = PIN_LOW;
    p2_6 = PIN_LOW;
    p2_7 = PIN_LOW;

}

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 3
//  System registers associated with Port 3 configured
//    Pin 0 - A8     		Output address bits (A0 to A19).
//  * Pin 0 - I00      		Right Motor Forward
//    Pin 1 - A9    		Output address bits (A0 to A19).
//  * Pin 1 - I01      		Right Motor Reverse
//    Pin 2 - A10   		Output address bits (A0 to A19).
//  * Pin 2 - I02      		Left Motor Forward
//    Pin 3 - A11    		Output address bits (A0 to A19).
//  * Pin 3 - I03      		Left Motor Reverse
//    Pin 4 - A12    		Output address bits (A0 to A19).
//  * Pin 4 - I04      		GPS Power Control
//    Pin 5 - A13	    	Output address bits (A0 to A19).
//  * Pin 5 - I05   	 	GPS Reset In
//    Pin 6 - A14			Output address bits (A0 to A19).
//  * Pin 6 - I06			GPS Power
//    Pin 7 - A15			Output address bits (A0 to A19).
//  * Pin 7 - I07			IR LED
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------

void Port03_Init(void)
  {  
    pd3 = OUTPUT;
	pd3_0=OUTPUT;
    RIGHT_FORWARD = PIN_LOW; // LEFT MOTOR FORWARD
	pd3_1=OUTPUT;    
    RIGHT_FORWARD = PIN_LOW; // LEFT MOTOR REVERSE 
	pd3_2=OUTPUT; 
    LEFT_FORWARD = PIN_LOW;	// RIGHT MOTOR FORWARD
   
	pd3_3 = OUTPUT; 
	LEFT_REVERSE = PIN_LOW; // RIGHT MOTOR REVERSE
    pd3_4 = OUTPUT; 
	p3_4 = PIN_LOW; // GPS POWER CONTROL
    pd3_5 = OUTPUT; 
	p3_5 = PIN_LOW; // GPS RESET
    pd3_6 = OUTPUT; 
	p3_6 = PIN_LOW; // GPS POWER
    pd3_7 = OUTPUT; 
	IR_LED = PIN_LOW; // INFRARED LED
    return;
}

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 4
//  System registers associated with Port 4 configured
//    Pin 0 - A16     		Output address bits (A0 to A19).
//   *Pin 0 - LED0     		LED0
//    Pin 1 - A17   		Output address bits (A0 to A19).
//   *Pin 1 - LED1     		LED1
//    Pin 2 - A18 	 		Output address bits (A0 to A19).
//   *Pin 2 - LED2     		LED2
//    Pin 3 - A19   		Output address bits (A0 to A19).
//   *Pin 3 - LED3     		LED3	
//   *Pin 4 - CS3N     		Output CS0 to CS3 signals. CS0 to CS3 are chip-select signals to specify an external space.	
//   *Pin 5 - CS2N  		Output CS0 to CS3 signals. CS0 to CS3 are chip-select signals to specify an external space.	 	 	
//   *Pin 6 - CS1N			Output CS0 to CS3 signals. CS0 to CS3 are chip-select signals to specify an external space.	
//   *Pin 7 - CS0N			Output CS0 to CS3 signals. CS0 to CS3 are chip-select signals to specify an external space.	
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------

void Port04_Init(void)
{
    pd4 = OUTPUT;
    p4_0 = PIN_LOW;//LED0 
    p4_1 = PIN_LOW;//LED1
    p4_2 = PIN_LOW;//LED2
    p4_3 = PIN_LOW;//LED3
    p4_4 = PIN_LOW;
    p4_5 = PIN_LOW;
    p4_6 = PIN_LOW;
    p4_7 = PIN_LOW;
    return;
}
//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 5
//  System registers associated with Port 5 configured
//    Pin 0 - E8 		Output     		
//    Pin 0 - CE      	Output 	
//    Pin 1 - WRHN      Output 		
//    Pin 2 - RDN   	Output 		
//    Pin 3 - TRSTN  	BCLK output  		
//    Pin 4 - UD    	Bus control pins. In a hold state, HLDA outputs a "L" signal.		
//    Pin 5 - E8	  	Bus control pins. While the HOLD pin is held "L", the microcomputer is placed in a hold state.   		 	
//    Pin 6 - ALE		Bus control pins. ALE is a signal to latch the address.		
//    Pin 7 - RDY		Bus control pins. Clock out. 		
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port05_Init(void)
	{
    pd5 = OUTPUT;
    p5_0 = PIN_LOW;
    p5_1 = PIN_LOW;
    p5_2 = PIN_LOW;
    p5_3 = PIN_LOW;
    p5_4 = PIN_LOW;
    p5_5 = PIN_LOW;
    p5_6 = PIN_LOW;
    p5_7 = PIN_LOW;
	    return;
	}





//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 6
//  System registers associated with Port 6 configured
//    Pin 0 - CTSRTS ctso/rts0  		
//    Pin 1 - CLK0	     	Serial interface
//    Pin 2 - RXD0   		Serial interface
//    Pin 3 - TXD0    		Serial interface
//    Pin 4 - E8    		Serial interface
//    Pin 4 - BUSY    		Serial interface
//    Pin 5 - E8	    	Serial interface
//    Pin 6 - E8			Serial interface
//    Pin 7 - E8			Serial interface
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port06_Init(void)
{
    pd6_0 = OUTPUT; // send - receive ctrl bits
    pd6_1 = OUTPUT; // transfer clock I/O
    pd6_2 = INPUT; // serial data input
    pd6_3 = OUTPUT; // serial output
    //pd6_4 = OUTPUT;
    //pd6_5 = OUTPUT;
    //pd6_6 = INPUT;
    //pd6_7 = OUTPUT;
	
    p6_0 = PIN_LOW;
    p6_1 = PIN_LOW;
    p6_2 = PIN_LOW;
    p6_3 = PIN_LOW;
    //p6_4 = PIN_LOW;
    //p6_5 = PIN_LOW;
    //p6_6 = PIN_LOW;
    //p6_7 = PIN_LOW;
    return;


}





//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 7
//  System registers associated with Port 7 configured
//    Pin 0 - IICSDA   		
//    Pin 0 - TXD2     	UARTTX	
//    Pin 1 - IICSCL   		
//    Pin 1 - RXD2     	UARTRX	
//    Pin 2 - CLK2   	RIGHT LED	
//    Pin 2 - VP      		
//    Pin 3 - VN    		
//    Pin 4 - TA2OUT   	MIDDLE LED	
//    Pin 4 - WP      		
//    Pin 5 - TA2IN	    	
//    Pin 5 - WN	   	 	
//    Pin 6 - CAN0OUT		
//    Pin 7 - CAN0IN		
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port07_Init(void)
{
   // pd7 	 = OUTPUT;
    pd7_0 	 = OUTPUT; // UART2 TX
    pd7_1 	 = INPUT;  // UART2 RX
    LED2_DDR = OUTPUT; // LED2 - right LED
    pd7_3 	 = OUTPUT; 
    LED1_DDR = OUTPUT; // LED1 - middle LED
    pd7_5 	 = OUTPUT;
    pd7_6 	 = OUTPUT;
    pd7_7 	 = OUTPUT;

    p7_0 	= PIN_LOW;
    p7_1 	= PIN_LOW;
    LED2 	= LED_OFF; // LED2 Off
    p7_3 	= PIN_LOW;
    LED1 	= LED_OFF; // LED1 Off 
    p7_5 	= PIN_LOW;
    p7_6 	= PIN_LOW;
    p7_7 	= PIN_LOW;
    return;

}

//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 8
//  System registers associated with Port 8 configured
//    Pin 0 - I/O    General Purpose I/O
//  * Pin 0 - TA4OUT Timer A4 Out
//    Pin 0 - U      Three-Phase Positive Waveform Output Pin
//    Pin 1 - I/O    General Purpose I/O
//  * Pin 1 - TA4IN  Timer A4 In
//    Pin 1 - U      Three-Phase Negative Waveform Output Pin
//  * Pin 2 - I/O    General Purpose I/O
//    Pin 2 - INT0   Interrupt 0 Input
//  * Pin 3 - I/O    General Purpose I/O
//    Pin 3 - INT1   Interrupt 1 Input
//  * Pin 4 - I/O    General Purpose I/O
//    Pin 4 - INT2   Interrupt 2 Input
//    Pin 5 - I/O    General Purpose I/O
//  * Pin 5 - NMI    Non-Maskable Interrupt Input
//    Pin 6 - I/O    General Purpose I/O
//  * Pin 6 - XCIN ==> Connected to X2 back side
//    Pin 7 - I/O    General Purpose I/O
//  * Pin 7 - XCOUT ==> Connected to X2 back side
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Jim Carlson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port08_Init(void){
// P8_0 is used as and LED port with specific #defines
//  pd8_0 = PORT_DIRECTION_OUT;
//  p8_0 = PORT_IN_LOW;
// LED 0
// LED0 Direction Initialization
  LED0_DDR = PORT_DIRECTION_OUT; 
  LED0 = LED_OFF; 
// Switches 1,2,3
// Switch 1,2,3 Direction Initialization
  pd8_1 = PORT_DIRECTION_IN;  // Switch 2
  pd8_2 = PORT_DIRECTION_IN;  // Switch 3
  pd8_3 = PORT_DIRECTION_IN;  // Switch 1
 
// Switch 1,2,3 Inputs set low
  S2 = PORT_IN_LOW;
  S3 = PORT_IN_LOW;
  S1 = PORT_IN_LOW;
// Unused Port Pins
// Unused Port Pin Direction Initialization
  pd8_4 = PORT_DIRECTION_IN;
// Unused Port Pin Inputs set low
  p8_4 = PORT_IN_LOW;
// Port * Pin 5 is NMI / sfr62p.h does not support GP I/O
//  pd8_5 = PORT_DIRECTION_IN;
//  p8_5 = PORT_IN_LOW;
// XC input is used thus these cannot be used  
//  pd8_6 = PORT_DIRECTION_IN;
//  p8_6 = PORT_IN_LOW;
//  pd8_7 = PORT_DIRECTION_IN;
//  p8_7 = PORT_IN_LOW;


}
//----------------------------------------------------------------------------------




//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 9
//  System registers associated with Port 9 configured
//    Pin 0 - P90     		
//    Pin 0 - CLK3     		
//    Pin 1 - P91     		
//    Pin 1 - RXD3     		
//    Pin 2 - P92   		
//    Pin 2 - TXD3     		
//    Pin 3 - P93    		
//    Pin 3 - DA0      		
//    Pin 4 - P94    	ADC	
//    Pin 4 - DA1      		
//    Pin 5 - P95	    ADC	
//    Pin 5 - CAN1IN   	 	
//    Pin 6 - P96		ADC	
//    Pin 6 - CAN1OUT		
//    Pin 7 - P97		GPS PWR CHK	
//    Pin 7 - ADTRG
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port09_Init(void)
{
    pd9 = OUTPUT;
    //pd9_0 = OUTPUT;
    //pd9_1 = OUTPUT;
    //pd9_2 = OUTPUT;
    //pd9_3 = OUTPUT; //GOES TO PIN JA1_13
    pd9_4 = OUTPUT; //GOES TO PIN JA1_13
    pd9_5 = OUTPUT; // ADC
    pd9_6 = OUTPUT; // ADC
    pd9_7 = OUTPUT; // GPS PWRCHK

    //p9_0 = PIN_LOW;
    //p9_1 = PIN_LOW;
    //p9_2 = PIN_LOW;
    //p9_3 = PIN_LOW;
    p9_4 = PIN_LOW;
    p9_5 = PIN_LOW;
    p9_6 = PIN_LOW;
    p9_7 = PIN_LOW;
    return;

}





//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 10
//  System registers associated with Port 10 configured
//    Pin 0 - ADPOT    		
//    Pin 0 - AN0      		
//    Pin 1 - AN1     		
//    Pin 2 - AN2   		
//    Pin 3 - AN3    		
//    Pin 4 - AN4    		
//    Pin 4 - CAN0     		
//    Pin 4 - EN    		
//    Pin 5 - AN5	    	
//    Pin 5 - CAN0   	 	
//    Pin 5 - EN 			
//    Pin 6 - AN6			
//    Pin 6 - CAN1			
//    Pin 6 - EN			
//    Pin 7 - AN7			
//    Pin 7 - CAN1
//    Pin 7 - STBN
// * as configured below
//  Passed: No variables passed
//  Locals: No local values used
//  Returned: No values returned.
//  Author: Amy Anderson   
//  Rev:    1.0     Initial Release
//   
//----------------------------------------------------------------------------------
void Port10_Init(void){
	pd10_0 = INPUT;
    pd10_1 = INPUT;
    pd10_2 = INPUT;
    pd10_3 = INPUT; //GOES TO PIN JA1_13
	
    p10_0 = PIN_LOW; //GOES TO JA1-09
    p10_1 = PIN_LOW; //GOES TO JA1-10
    p10_2 = PIN_LOW; //GOES TO JA1-11
    p10_3 = PIN_LOW; //GOES TO JA1-12
    p10_4 = PIN_LOW;
    p10_5 = PIN_LOW;
    p10_6 = PIN_LOW;
    p10_7 = PIN_LOW;
    return;

}
