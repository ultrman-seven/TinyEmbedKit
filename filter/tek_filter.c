#include "filter/tek_filter.h"
void tek_lowpassFilterInit(tek_lowpassFilterCore *core, float c)
{
    core->result = 0;
    core->coeff = c;
}
void tek_lowpassFilterUpdate(tek_lowpassFilterCore *core, float d)
{
    core->result = core->result * (1 - core->coeff) + d * core->coeff;
}

void tek_averageFilterInit(tek_averageFilterCore *core, void *buf, uint32_t bufSize)
{
    tek_FifoInit(&core->fifo, buf, bufSize, sizeof(float));
    core->__sum = 0;
    core->len = (core->fifo.bufLen) / (sizeof(float));
    core->result = 0;
}

void tek_averageFilterUpdate(tek_averageFilterCore *core, float data)
{
    float tmp;
    core->__sum += data;
    if(tek_FifoGetDataLength(&core->fifo) >= core->len)
    {
        tek_FifoGet(&core->fifo,&tmp);
        core->__sum -= tmp;
    }
    tmp = data;
    tek_FifoPush(&core->fifo, &tmp);
    core->result = core->__sum / core->len;
}

void tek_highpassFilterInit(tek_highpassFilterCore *core, float c)
{
    core->result = 0;
    core->coeff = c;
    core->prevInput = 0;
}

void tek_highpassFilterUpdate(tek_highpassFilterCore *core, float d)
{
    core->result = core->coeff * (core->result + d - core->prevInput);
    core->prevInput = d;
}
