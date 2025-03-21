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
    core->len = (core->fifo.__arr.__buffSize) / (sizeof(float));
    core->result = 0;
}

void tek_averageFilterUpdate_WithoutResult(tek_averageFilterCore *core, float data)
{
    float tmp;
    core->__sum += data;
    if (tek_FifoGetDataLength(&core->fifo) >= core->len)
    {
        tek_FifoGet(&core->fifo, &tmp);
        core->__sum -= tmp;
    }
    tmp = data;
    tek_FifoPush(&core->fifo, &tmp);
}

float tek_averageFilterGetResult(tek_averageFilterCore *core) { return core->__sum / core->len; }

void tek_averageFilterUpdate(tek_averageFilterCore *core, float data)
{
    float tmp;
    core->__sum += data;
    if (tek_FifoGetDataLength(&core->fifo) >= core->len)
    {
        tek_FifoGet(&core->fifo, &tmp);
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

typedef struct
{
    float result;
    float coeff1;
    float coeff2;
    float prevInput;
    float prevOutput;
} tek_bandpassFilterCore;

// 带通滤波器
void tek_bandpassFilterInit(tek_bandpassFilterCore *core, float c1, float c2)
{
    core->result = 0;
    core->coeff1 = c1;
    core->coeff2 = c2;
    core->prevInput = 0;
    core->prevOutput = 0;
}

void tek_bandpassFilterUpdate(tek_bandpassFilterCore *core, float d)
{
    core->result = core->coeff1 * (d - core->prevInput) + core->coeff2 * core->prevOutput;
    core->prevInput = d;
    core->prevOutput = core->result;
}

// 带阻滤波器
typedef struct
{
    float result;
    float coeff1;
    float coeff2;
    float prevInput;
    float prevOutput;
    float prevPrevOutput;
} tek_bandstopFilterCore;

void tek_bandstopFilterInit(tek_bandstopFilterCore *core, float c1, float c2)
{
    core->result = 0;
    core->coeff1 = c1;
    core->coeff2 = c2;
    core->prevInput = 0;
    core->prevOutput = 0;
    core->prevPrevOutput = 0;
}

void tek_bandstopFilterUpdate(tek_bandstopFilterCore *core, float d)
{
    core->result = core->coeff1 * d + core->coeff2 * core->prevInput + core->coeff1 * core->prevPrevOutput;
    core->prevInput = d;
    core->prevPrevOutput = core->prevOutput;
    core->prevOutput = core->result;
}

// 卡尔曼滤波器
typedef struct
{
    float result;
    float p;
    float q;
    float r;
    float x;
    float k;
} tek_kalmanFilterCore;

void tek_kalmanFilterInit(tek_kalmanFilterCore *core, float q, float r)
{
    core->result = 0;
    core->p = 1;
    core->q = q;
    core->r = r;
    core->x = 0;
    core->k = 0;
}

void tek_kalmanFilterUpdate(tek_kalmanFilterCore *core, float d)
{
    core->p = core->p + core->q;
    core->k = core->p / (core->p + core->r);
    core->x = core->x + core->k * (d - core->x);
    core->p = (1 - core->k) * core->p;
    core->result = core->x;
}

// 一阶滞后滤波器
typedef struct
{
    float result;
    float coeff;
    float prevOutput;
} tek_lagFilterCore;

void tek_lagFilterInit(tek_lagFilterCore *core, float c)
{
    core->result = 0;
    core->coeff = c;
    core->prevOutput = 0;
}

void tek_lagFilterUpdate(tek_lagFilterCore *core, float d)
{
    core->result = core->coeff * d + (1 - core->coeff) * core->prevOutput;
    core->prevOutput = core->result;
}
