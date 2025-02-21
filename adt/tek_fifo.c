#include "adt/tek_fifo.h"
#include "string.h"

void tek_FifoInit(tek_FifoCore *fifo, void *buffer, uint32_t bufSize, uint32_t elementSize)
{
    uint32_t bufModEle;

    fifo->buffer = buffer;
    fifo->idxFront = 0;
    fifo->elementSize = elementSize;

    bufModEle = bufSize % elementSize;
    fifo->bufLen = bufSize - bufModEle;
    fifo->dataLen = 0;
}

uint32_t tek_FifoGetDataLength(tek_FifoCore *fifo)
{
    return fifo->dataLen;
}

void tek_FifoPush(tek_FifoCore *fifo, void *data)
{
    uint32_t offset;

    offset = fifo->idxFront + (fifo->dataLen * fifo->elementSize);

    if (offset >= fifo->bufLen)
        memcpy((char *)fifo->buffer + offset - fifo->bufLen, data, fifo->elementSize);
    else
        memcpy((char *)fifo->buffer + offset, data, fifo->elementSize);

    ++(fifo->dataLen);
    if ((fifo->dataLen * fifo->elementSize) > fifo->bufLen)
        tek_FifoPop(fifo);
}

void tek_FifoPop(tek_FifoCore *fifo)
{
    if (fifo->dataLen == 0)
        return; // FIFO is empty
    --fifo->dataLen;
    if (fifo->idxFront + fifo->elementSize < fifo->bufLen)
        fifo->idxFront += fifo->elementSize;
    else
        fifo->idxFront = 0;
}

void tek_FifoTop(tek_FifoCore *fifo, void *data)
{
    if (fifo->dataLen == 0)
        return; // FIFO is empty

    memcpy(data, (char *)fifo->buffer + (fifo->idxFront), fifo->elementSize);
}

void tek_FifoGet(tek_FifoCore *fifo, void *data)
{
    tek_FifoTop(fifo, data);
    tek_FifoPop(fifo);
}
