#ifndef C6A84A49_E425_4F5C_ABF5_A5DB6092F327
#define C6A84A49_E425_4F5C_ABF5_A5DB6092F327
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    void *buffer;
    uint32_t idxFront;
    uint32_t bufLen;
    uint8_t elementSize;
    uint32_t dataLen;
} tek_FifoCore;

void tek_FifoInit(tek_FifoCore *fifo, void *buffer, uint32_t buffSize, uint32_t elementSize);
void tek_FifoPush(tek_FifoCore *fifo, void *data);
void tek_FifoTop(tek_FifoCore *fifo, void *data);
void tek_FifoPop(tek_FifoCore *fifo);
void tek_FifoGet(tek_FifoCore *fifo, void *data);
uint32_t tek_FifoGetDataLength(tek_FifoCore *fifo);

#ifdef __cplusplus
}
#endif
#endif /* C6A84A49_E425_4F5C_ABF5_A5DB6092F327 */
