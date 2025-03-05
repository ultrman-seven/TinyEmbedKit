#include "adt/tek_stack.h"

void tek_stackInit(tek_stackCore *core, void *buf, uint16_t bufSize, uint16_t elementSize)
{
    tek_ArrayInit(&core->__arr, buf, bufSize, elementSize);
    core->__topIdx = 0;
}

uint8_t tek_stackPush(tek_stackCore *core, void *dPtr)
{
    if (tek_ArrayIndexIsLegal(&core->__arr, core->__topIdx + 1))
    {
        ++core->__topIdx;
        tek_ArrayDirectSetVal(&core->__arr, core->__topIdx, dPtr);
        return 0;
    }
    return 1;
}

uint8_t tek_stackPop(tek_stackCore *core, void *dPtr)
{
    if (core->__topIdx)
    {
        tek_ArrayDirectGetVal(&core->__arr, core->__topIdx, dPtr);
        --core->__topIdx;
        return 0;
    }
    return 1;
}

uint8_t tek_stackTop(tek_stackCore *core, void *dPtr)
{
    if (core->__topIdx)
    {
        tek_ArrayDirectGetVal(&core->__arr, core->__topIdx, dPtr);
        return 0;
    }
    return 1;
}
