/* site:https://github.com/daishitong/51demo */

#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "SerialBase.h"
#include "Interrupt.h"

#define ENABLE_SERIAL_INTERRUPT_READ
//#define ENABLE_SERIAL_INTERRUPT_WRITE

#define SERIAL_BUFFER_SIZE 15
#define END_OF_RECEIVE_CHAR ';'

typedef void (*SerialEventHandler)(unsigned char* buffer);

void Serial_Init();
void Serial_SetParseHandler(SerialEventHandler parseHandler);
void Serial_WriteMessage(char *str);

#ifdef ENABLE_SERIAL_INTERRUPT_WRITE
#undef mcu_printf
#define mcu_printf Serial_Printf
void Serial_Printf(const char* fmt,...);
#endif

#endif