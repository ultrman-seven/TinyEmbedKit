#ifndef D8D89089_9520_4448_9195_2D76253F1471
#define D8D89089_9520_4448_9195_2D76253F1471

#include "adt/tek_fifo.h"

typedef struct
{
    uint8_t __mkLen;
    uint8_t __sumCheck;
    uint16_t argBufSize;
    const char *markStart;
    tek_FifoCore fifo;
    uint8_t *argBuf;
} tek_protocolCore;

#endif /* D8D89089_9520_4448_9195_2D76253F1471 */
