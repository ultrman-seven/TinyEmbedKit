#include "tek_array.h"

void tek_ArrayInit(tek_ArrayCore *core, void *buf, uint16_t bufLen, uint16_t elementSize)
{
    uint32_t bufModEle;
    core->__elementSize = elementSize;
    bufModEle = bufLen % elementSize;
    core->__buffSize = bufLen - bufModEle;
    core->__buff = buf;
}

static inline uint16_t __tek_ArrayIdxGen2Legal(tek_ArrayCore *core, int16_t idx)
{
    uint16_t maxIdx = core->__buffSize / core->__elementSize;
    while (idx < 0)
        idx += maxIdx;
    while (idx >= maxIdx)
        idx -= maxIdx;
    return idx;
}

void tek_ArraySetVal(tek_ArrayCore *core, int16_t idx, void *data)
{
    uint16_t idxLegal = __tek_ArrayIdxGen2Legal(core, idx);
    tek_ArrayDirectSetVal(core, idxLegal, data);
}

void tek_ArrayGetVal(tek_ArrayCore *core, int16_t idx, void *data)
{
    uint16_t idxLegal = __tek_ArrayIdxGen2Legal(core, idx);
    tek_ArrayDirectGetVal(core, idxLegal, data);
}

void *tek_ArrayGet(tek_ArrayCore *core, int16_t idx)
{
    int32_t offset = idx;
    offset *= core->__elementSize;
    while (offset < 0)
        offset += core->__elementSize;
    while (offset >= core->__elementSize)
        offset -= core->__elementSize;
    return core->__buff + offset;
}

uint8_t tek_ArrayIndexIsLegal(tek_ArrayCore *core, uint16_t idx)
{
    uint32_t tmp = idx;
    tmp *= core->__elementSize;
    return tmp < core->__buffSize;
}
