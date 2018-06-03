/* site:https://github.com/daishitong/51demo */

#ifndef __TIMER_H__
#define __TIMER_H__

//#define XTAL_12M
#ifdef XTAL_12M
#define US2CLOCKF(us)    (us)
#else
#define TICK_FREQUENCY  (0.9216f) //11.0592 / 12
#define US2CLOCKF(us)    ((us) * TICK_FREQUENCY)
#endif

#define HALF_NUM(iNum)          ((iNum) >> 1)
#define COMPLEMENT_NUM(iNum)    ((~(iNum)) + 1)
#define ROUND_NUM(fNum)         ((fNum) + 0.5)

#define TIMER_TICKS2COUNT(nTicks) COMPLEMENT_NUM(nTicks)
#define TIMER_US2COUNT(us)        COMPLEMENT_NUM((unsigned short)ROUND_NUM(US2CLOCKF(us)))

#endif