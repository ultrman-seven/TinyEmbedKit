#ifndef E483CC35_3A6F_4EB9_B1B7_EDC90826FF08
#define E483CC35_3A6F_4EB9_B1B7_EDC90826FF08

#include "stdint.h"
#include "tek_array.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct
{
    tek_ArrayCore __arr;
    uint16_t __topIdx;
} tek_stackCore;

void tek_stackInit(tek_stackCore *core, void *buf, uint16_t bufSize, uint16_t elementSize);
uint8_t tek_stackPop(tek_stackCore *core, void *dPtr);
uint8_t tek_stackPush(tek_stackCore *core, void *dPtr);
uint8_t tek_stackTop(tek_stackCore *core, void *dPtr);

#ifdef __cplusplus
}
#endif

#endif /* E483CC35_3A6F_4EB9_B1B7_EDC90826FF08 */
