/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __T2_DELAY_H__
#define __T2_DELAY_H__

#define HALF_NUM(iNum)  ((iNum) >> 1)
#define COMPLEMENT_NUM(iNum)	((~(iNum)) + 1)
#define ROUND_NUM(fNum)	((fNum) + 0.5)

#define XTAL_FREQUENCY_MHZ 11.0592f
#define US2CLOCKF(us)	((us) * XTAL_FREQUENCY_MHZ / 12)

#define T2Deley_Ticks2COUNT(nTicks) COMPLEMENT_NUM(nTicks)
#define T2Delay_US2COUNT(us)    		COMPLEMENT_NUM((unsigned int)ROUND_NUM(US2CLOCKF(us)))

void T2Delay_Init();
void T2Delay_DelayCount(unsigned int nCount);

void T2Delay_DelayTicks(unsigned int nTicks);
void T2Delay_DelayUS(unsigned int us);

#endif