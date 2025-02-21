#include "controller/tek_ctrl.h"
#include "string.h"

float tek_pidInit(tek_pidCore *core) { memset(core, 0, sizeof(tek_pidCore)); }

float tek_pidUpdate(tek_pidCore *core, float inputVal)
{
    float err;
    float diff;

    err = core->target - inputVal;
    core->__intVal += err;

    diff = err - core->__err_last;
    core->__err_last = err;

    if (core->intLimit)
    {
        if (core->__intVal > core->intLimit)
            core->__intVal = core->intLimit;
        else if (core->__intVal < (-core->intLimit))
            core->__intVal = (-core->intLimit);
    }
    if (core->decayFactor > 0)
        core->__intVal *= core->decayFactor;
    return (core->kp * err) + (core->ki * core->__intVal) + (core->kd * diff);
}
