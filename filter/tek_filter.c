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
