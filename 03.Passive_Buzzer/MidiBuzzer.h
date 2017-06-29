/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __MIDIBUZZER_H__
#define __MIDIBUZZER_H__
#include <reg52.h>
#include "boolean.h"

sbit MidiBuzzer_Pin = P2^2;

typedef enum 
{
    BuzzerTone_L_1Do,
    BuzzerTone_L_2Re,
    BuzzerTone_L_3Mi,
    BuzzerTone_L_4Fa,
    BuzzerTone_L_5So,
    BuzzerTone_L_6La,
    BuzzerTone_L_7Xi,
    BuzzerTone_M_1Do,
    BuzzerTone_M_2Re,
    BuzzerTone_M_3Mi,
    BuzzerTone_M_4Fa,
    BuzzerTone_M_5So,
    BuzzerTone_M_6La,
    BuzzerTone_M_7Xi,
    BuzzerTone_H_1Do,
    BuzzerTone_H_2Re,
    BuzzerTone_H_3Mi,
    BuzzerTone_H_4Fa,
    BuzzerTone_H_5So,
    BuzzerTone_H_6La,
    BuzzerTone_H_7Xi,
    BuzzerTone_0Zero,
}BuzzerTone;

typedef enum
{
    BeatTime_End = 0,
    BeatTime_Half = 1,
    BeatTime_One,
    BeatTime_OneAndHalf,
    BeatTime_Two,
}BeatTime;

typedef struct
{
    BuzzerTone tone;
    BeatTime time;
}MidiSegment;

#define MidiSegment_End {BuzzerTone_0Zero,BeatTime_End}

void MidiBuzzer_Init(void);
bool MidiBuzzer_Ring(MidiSegment midi);
void MidiBuzzer_Sing(MidiSegment song[]);

#endif
