
#pragma INTERRUPT A2DInterrupt
#pragma INTERRUPT UART0TransmitInterrupt
#pragma INTERRUPT UART0ReceiveInterrupt

#pragma INTERRUPT TimerA0Interrupt
#pragma INTERRUPT TimerA1Interrupt
#pragma INTERRUPT TimerA2Interrupt
#pragma INTERRUPT TimerB0Interrupt

#pragma INTERRUPT KeyBoardInterrupt
#pragma INTERRUPT DMA0Interrupt
#pragma INTERRUPT WakeUpInterrupt
#pragma INTERRUPT RTCInterrupt
#pragma INTERRUPT TimerB0Interrupt
#pragma INTERRUPT WatchDogInterrupt

#pragma INTERRUPT Switch_S1Interrupt
#pragma INTERRUPT Switch_S2Interrupt
#pragma INTERRUPT Switch_S3Interrupt



#define SW1 (0x01) // Switch 1
#define SW2 (0x02) // Switch 2
#define SW3 (0x04) // Switch 3
#define SW1H (0x10) // Switch 1
#define SW2H (0x20) // Switch 2
#define SW3H (0x40) // Switch 3
#define SW_HOLD (250) // Hold Off Debounce Time
#define FALLING_EDGE    (0x0)
#define RISING_EDGE     (0x1)
#define Restart_count     (0)
#define TimeCountCompare 12000
#define ClockAlarm 30

#define IncrementCount 5
#define EnableSwitch 0x04
#define DisableSwitch 0x00
#define PinHigh 1
#define Reset 0

int Count;
int TimeCount_Switch1;
int TimeCount_Switch2;
int TimeCount_Switch3;
int TimeCount;

volatile unsigned char switch_set; // Switch State variable
volatile unsigned char switch_hold [3]; // Switch holdoff time 



