/* site:https://github.com/daishitong/51lib */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <reg52.h>

typedef enum
{
    Interrupt_ID_EX0 = 1,
    Interrupt_ID_ET0 = 2,
    Interrupt_ID_EX1 = 4,
    Interrupt_ID_ET1 = 8,
    Interrupt_ID_ES  = 0x10,
    Interrupt_ID_ET2 = 0x20
}Enum_Interrupt_ID;

/*------------------------------------------------
Interrupt Vectors:
Interrupt Address = (Number * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR    0  /* 0x03 External Interrupt 0 */
#define TF0_VECTOR    1  /* 0x0B Timer 0 */
#define IE1_VECTOR    2  /* 0x13 External Interrupt 1 */
#define TF1_VECTOR    3  /* 0x1B Timer 1 */
#define SIO_VECTOR    4  /* 0x23 Serial port */
#define TF2_VECTOR    5  /* 0x2B Timer 2 */

#define Interrupt_Handler(vector) Interrupt_Handler_##vector() interrupt vector

#define Interrupt_Enable()  {EA = 1;}
#define Interrupt_Disable() {EA = 0;}

void Interrupt_Init(Enum_Interrupt_ID interrupt_id);

typedef void (*EventHandler)();

#endif