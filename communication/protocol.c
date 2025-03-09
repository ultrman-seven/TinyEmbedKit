#include "communication/protocol.h"
#include "string.h"

void tek_protocolInit(tek_protocolCore *core, const char *start, uint8_t *db, uint8_t dbSz, void (*callback)(uint32_t, void *))
{
    tek_FifoInit(&core->fifo, db, dbSz, sizeof(uint8_t));
    core->markStart = start;
    core->__state.mkLen = strlen(start);
    core->__callback = callback;
    core->__state.waitingStart = 1;
    core->__state.fifoReseting = 0;
    core->__state.headCnt = 0;
    core->__state.cached = 0;
}

void tek_protocolByteProcess(tek_protocolCore *core, uint8_t d)
{
    uint8_t data;
    if (core->__state.fifoReseting)
    {
        core->__state.cached = 1;
        core->__state.headCnt = d;
        return;
    }
    if (core->__state.cached)
    {
        data = core->__state.headCnt;
        tek_FifoPush(&core->fifo, &data);
        core->__state.cached = 0;
    }
    data = d;
    tek_FifoPush(&core->fifo, &data);
}

void tek_protocolLoop(tek_protocolCore *core)
{
    if (core->__state.waitingStart)
    {
        if (tek_FifoGetDataLength(&core->fifo) >= core->__state.mkLen)
        {
            uint8_t tmp;
            tek_FifoGet(&core->fifo, &tmp);
            while (tmp == core->markStart[core->__state.headCnt])
            {
                ++core->__state.headCnt;
                if (core->__state.headCnt >= core->__state.mkLen)
                {
                    core->__state.fifoReseting = 1;

                    core->__state.fifoReseting = 0;
                    core->__state.waitingStart = 0;
                    return;
                }
            }
            core->__state.headCnt = 0;
            return;
        }
    }
    else
    {
        uint32_t dl = tek_FifoGetDataLength(&core->fifo);
        if (dl && dl > (uint8_t *)(core->fifo.__arr.__buff)[0])
        {
            core->__callback((uint8_t *)(core->fifo.__arr.__buff)[0], (uint8_t *)(core->fifo.__arr.__buff) + 1);

        }
    }
}
