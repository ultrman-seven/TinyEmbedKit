#ifndef EB1E7F21_A6BA_4846_92EA_B98D50E181E4
#define EB1E7F21_A6BA_4846_92EA_B98D50E181E4
#include "stdint.h"
#include "string.h"

typedef struct
{
    // uint16_t __buffSize;
    // uint16_t __elementSize;
    uint32_t __buffSize : 16;
    uint32_t __elementSize : 16;
    uint8_t *__buff;
} tek_ArrayCore;

void tek_ArrayInit(tek_ArrayCore *core, void *buf, uint16_t bufLen, uint16_t elementSize);
void tek_ArraySetVal(tek_ArrayCore *core, int16_t idx, void *data);
void tek_ArrayGetVal(tek_ArrayCore *core, int16_t idx, void *data);
void *tek_ArrayGet(tek_ArrayCore *core, int16_t idx);
uint8_t tek_ArrayIndexIsLegal(tek_ArrayCore *core, uint16_t idx);

#define tek_ArrayDirectSetVal(__core, __idx, __valPtr)          \
    memcpy(                                                     \
        (__core)->__buff + (__idx) * ((__core)->__elementSize), \
        __valPtr,                                               \
        (__core)->__elementSize)

#define tek_ArrayDirectGetVal(__core, __idx, __valPtr)          \
    memcpy(                                                     \
        __valPtr,                                               \
        (__core)->__buff + (__idx) * ((__core)->__elementSize), \
        (__core)->__elementSize)

#endif /* EB1E7F21_A6BA_4846_92EA_B98D50E181E4 */
