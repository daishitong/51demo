/* site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "MidiBuzzer.h"

const MidiSegment code song_twoTiger[] = {
  {BuzzerTone_M_1Do, BeatTime_Half}, {BuzzerTone_M_2Re, BeatTime_Half}
  , {BuzzerTone_M_3Mi, BeatTime_Half}, {BuzzerTone_M_1Do, BeatTime_Half}
  , {BuzzerTone_M_1Do, BeatTime_Half}, {BuzzerTone_M_2Re, BeatTime_Half}
  , {BuzzerTone_M_3Mi, BeatTime_Half}, {BuzzerTone_M_1Do, BeatTime_Half}
  , {BuzzerTone_M_3Mi, BeatTime_Half}, {BuzzerTone_M_4Fa, BeatTime_Half}
  , {BuzzerTone_M_5So, BeatTime_One}, {BuzzerTone_M_3Mi, BeatTime_Half}
  , {BuzzerTone_M_4Fa, BeatTime_Half}, {BuzzerTone_M_5So, BeatTime_One}
  , {BuzzerTone_M_5So, BeatTime_Half}, {BuzzerTone_M_6La, BeatTime_Half}
  , {BuzzerTone_M_5So, BeatTime_Half}, {BuzzerTone_M_4Fa, BeatTime_Half}
  , {BuzzerTone_M_3Mi, BeatTime_One}, {BuzzerTone_M_1Do, BeatTime_One}
  , {BuzzerTone_M_5So, BeatTime_Half}, {BuzzerTone_M_6La, BeatTime_Half}
  , {BuzzerTone_M_5So, BeatTime_Half}, {BuzzerTone_M_4Fa, BeatTime_Half}
  , {BuzzerTone_M_3Mi, BeatTime_One}, {BuzzerTone_M_1Do, BeatTime_One}
  , {BuzzerTone_M_2Re, BeatTime_One}, {BuzzerTone_L_5So, BeatTime_One}
  , {BuzzerTone_M_1Do, BeatTime_One}, {BuzzerTone_0Zero, BeatTime_One}
  , {BuzzerTone_M_2Re, BeatTime_One}, {BuzzerTone_L_5So, BeatTime_One}
  , {BuzzerTone_M_1Do, BeatTime_One}, {BuzzerTone_0Zero, BeatTime_One}
  , MidiSegment_End};

void main()
{
  while(1)
  {
    MidiBuzzer_Sing(song_twoTiger);
  }
}