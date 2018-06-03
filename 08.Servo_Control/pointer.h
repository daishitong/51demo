/* site:https://github.com/daishitong/51demo */

#ifndef __POINTER_H__
#define __POINTER_H__

#include "boolean.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef void (*Action)();
typedef bool (*CheckHandler)();

#endif