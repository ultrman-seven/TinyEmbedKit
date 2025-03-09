#include "controller/tek_ctrl.h"
#include "string.h"

void tek_pidInit(tek_pidCore *core) { memset(core, 0, sizeof(tek_pidCore)); }

void tek_pidSetParam(tek_pidCore *core, float p, float i, float d)
{
    core->kp = p;
    core->ki = i;
    core->kd = d;
}

float tek_pidUpdate(tek_pidCore *core, float inputVal, float dt)
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
    return (core->kp * err) + (core->ki * core->__intVal * dt) + (core->kd * diff / dt);
}
