/* site:https://github.com/daishitong/51demo */

#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <reg52.h>

sbit LCD1602_RS_Pin = P2^7;
sbit LCD1602_RW_Pin = P2^6;
sbit LCD1602_EN_Pin = P2^5;

#define LCD1602_DATAPORT P0

#define uint8 unsigned char
#define bool  bit

void Lcd1602_Init();

void Lcd1602_Clear();

// 8row * 5bit,total 8 char
void Lcd1602_SetCustomGraghicRAM(char c,const uint8 dots[8]);

void Lcd1602_SetPosition_2R_16C(char row,char column);
void Lcd1602_ShowChar(char c);
void Lcd1602_ShowText(char str[]);

#endif