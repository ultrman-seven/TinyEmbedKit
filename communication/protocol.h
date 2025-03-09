#ifndef D8D89089_9520_4448_9195_2D76253F1471
#define D8D89089_9520_4448_9195_2D76253F1471

#include "adt/tek_fifo.h"

typedef struct
{
    struct
    {
        uint16_t waitingStart : 1;
        uint16_t fifoReseting : 1;
        uint16_t Ok : 1;
        uint16_t cached : 1;
        uint16_t mkSum : 8;
        uint16_t mkLen : 8;
        uint16_t headCnt : 8;
    } __state;
    // uint8_t __sumCheck;
    // uint16_t argBufSize;
    const char *markStart;
    void (*__callback)(uint32_t, void *);
    tek_FifoCore fifo;
    // uint8_t *argBuf;
} tek_protocolCore;

void tek_protocolInit(tek_protocolCore *core, const char *start, uint8_t *db, uint8_t dbSz, void (*callback)(uint32_t argc, void *argv));

#endif /* D8D89089_9520_4448_9195_2D76253F1471 */
