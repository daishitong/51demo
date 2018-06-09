/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "mutex.h"

#include <stdio.h> 
#include <stdarg.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

void Serial_Init()
{
    SerialBase_Init();
    Interrupt_Init(Interrupt_ID_ES);
    Interrupt_Enable();
}

#define GET_SERIAL_DATA()       (SBUF)
#define SET_SERIAL_DATA(ch)     {SBUF = ch;}

#ifdef ENABLE_SERIAL_INTERRUPT_READ

SerialEventHandler _parseHandler = NULL;
char receive_buffer[SERIAL_BUFFER_SIZE];

void Serial_SetParseHandler(SerialEventHandler parseHandler)
{
    _parseHandler = parseHandler;
}

void Serial_ReceiveBufferHandler()
{
    static char receive_index = 0;

    if(((receive_buffer[receive_index++] = GET_SERIAL_DATA()) == END_OF_RECEIVE_CHAR) || receive_index == SERIAL_BUFFER_SIZE)
    {
        receive_index = 0;
        if(_parseHandler != NULL)
        {
            _parseHandler(receive_buffer);
        }
    }
}
#endif

void Serial_WriteMessage(char *str)
{
    if (str == NULL)
        return;

    while(*str != '\0')
    {
        SerialBase_Write(*str);

        if (*str == END_OF_RECEIVE_CHAR)
        {
            break;
        }
        str++;
    }   
}

#ifdef ENABLE_SERIAL_INTERRUPT_WRITE

Mutex_Create(mutex_serial_send);
char send_buffer[SERIAL_BUFFER_SIZE];

void Serial_SendBufferHandler()
{
    static char send_index = 0;
   
    if (send_index == SERIAL_BUFFER_SIZE || send_buffer[send_index] == '\0')
    {
        send_index = 0;
        Mutex_Exit(mutex_serial_send);
        return;
    }
    
    SET_SERIAL_DATA(send_buffer[send_index++]);
}

void Serial_Printf(const char *fmt, ...)
{
    va_list ap;

    Mutex_Enter(mutex_serial_send);

    va_start(ap, fmt);
    vsprintf(send_buffer, fmt, ap);
    Serial_SendBufferHandler();
    va_end(ap);
}
#endif

#if (defined ENABLE_SERIAL_INTERRUPT_READ) || (defined ENABLE_SERIAL_INTERRUPT_WRITE)
void Interrupt_Handler_SIO_VECTOR() interrupt SIO_VECTOR
{
    #ifdef ENABLE_SERIAL_INTERRUPT_READ
    if(RI == 1)
    {
        RI = 0;
        Serial_ReceiveBufferHandler();
    }
    #endif

    #ifdef ENABLE_SERIAL_INTERRUPT_WRITE
    if(TI == 1)
    {
        TI = 0;
        Serial_SendBufferHandler();
    }
    #endif
}
#endif
