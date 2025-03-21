#include "adt/tek_fifo.h"
#include "string.h"

/// @brief 初始化FIFO
/// @param fifo
/// @param buffer
/// @param bufSize
/// @param elementSize
void tek_FifoInit(tek_FifoCore *fifo, void *buffer, uint32_t bufSize, uint32_t elementSize)
{
    tek_ArrayInit(&fifo->__arr, buffer, bufSize, elementSize);
    fifo->idxFront = 0;
    fifo->dataLen = 0;
}

/// @brief 获取FIFO中的数据长度
/// @param fifo
/// @return
uint32_t tek_FifoGetDataLength(tek_FifoCore *fifo)
{
    return fifo->dataLen;
}

/// @brief 将数据压入FIFO
/// @param fifo
/// @param data
void tek_FifoPush(tek_FifoCore *fifo, void *data)
{
    uint32_t offset;

    offset = fifo->idxFront + (fifo->dataLen * fifo->__arr.__elementSize);

    if (offset >= fifo->__arr.__buffSize)
        memcpy((char *)fifo->__arr.__buff + offset - fifo->__arr.__buffSize, data, fifo->__arr.__elementSize);
    else
        memcpy((char *)fifo->__arr.__buff + offset, data, fifo->__arr.__elementSize);

    ++(fifo->dataLen);
    if ((fifo->dataLen * fifo->__arr.__elementSize) > fifo->__arr.__buffSize)
        tek_FifoPop(fifo);
}

/// @brief 弹出FIFO中的数据
/// @param fifo
void tek_FifoPop(tek_FifoCore *fifo)
{
    if (fifo->dataLen == 0)
        return; // FIFO is empty
    --fifo->dataLen;
    if (fifo->idxFront + fifo->__arr.__elementSize < fifo->__arr.__buffSize)
        fifo->idxFront += fifo->__arr.__elementSize;
    else
        fifo->idxFront = 0;
}

/// @brief 获取FIFO中的数据
/// @param fifo
/// @param data
void tek_FifoTop(tek_FifoCore *fifo, void *data)
{
    if (fifo->dataLen == 0)
        return; // FIFO is empty

    memcpy(data, (char *)fifo->__arr.__buff + (fifo->idxFront), fifo->__arr.__elementSize);
}

/// @brief 获取FIFO中的数据
/// @param fifo
/// @param data
/// @param len
void tek_FifoGetBytes(tek_FifoCore *fifo, void *data, uint8_t len)
{
    uint8_t *dptr = data;
    while (len--)
    {
        tek_FifoTop(fifo, dptr);
        tek_FifoPop(fifo);
        dptr += fifo->__arr.__elementSize;
    }
}

void tek_FifoGet(tek_FifoCore *fifo, void *data)
{
    tek_FifoTop(fifo, data);
    tek_FifoPop(fifo);
}
