/* site:https://github.com/daishitong/51demo */

#ifndef __MUTEX_H__
#define __MUTEX_H__

typedef bit object;
#define true  1
#define false 0

#define Mutex_Create(name)  volatile object object_##name = false
#define Mutex_Enter(name)   {while(object_##name); object_##name = true;}
#define Mutex_Exit(name)    {object_##name = false;}

#define Mutex_IsUsed(name)  (object_##name)

#endif