#include "communication/protocol.h"
#include "string.h"

void tek_protocolInit(tek_protocolCore *core, const char *start, uint8_t *db, uint8_t dbSz, uint8_t *ab, uint16_t abSz)
{
    tek_FifoInit(&core->fifo, db, dbSz, sizeof(uint8_t));
    core->argBuf = ab;
    core->argBufSize = abSz;
    core->markStart = start;
    core->__sumCheck = 0;
    core->__mkLen = strlen(start);
}

void tek_protocolByteProcess(tek_protocolCore *core, uint8_t d)
{
    uint8_t data = d;
    tek_FifoPush(&core->fifo, &data);
}
