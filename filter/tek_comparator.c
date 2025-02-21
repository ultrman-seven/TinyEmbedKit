#include "filter/tek_filter.h"

void tek_ZeroCrossingComparatorInit(tek_ZeroCrossingComparatorCore *core, float threshold)
{
    core->result = 0;
    core->threshold = threshold;
}

void tek_ZeroCrossingComparatorUpdate(tek_ZeroCrossingComparatorCore *core, float dat)
{
    core->result = (dat > core->threshold);
}

void tek_HysteresisComparatorInit(tek_HysteresisComparatorCore *core, float th, float tl)
{
    core->result = 0;
    core->thresholdHigh = th;
    core->thresholdLow = tl;
}

void tek_HysteresisComparatorUpdate(tek_HysteresisComparatorCore *core, float dat)
{
    if (core->result) // activated
    {
        if (dat < core->thresholdLow)
            core->result = 0;
    }
    else
    {
        if (dat > core->thresholdHigh)
            core->result = 1;
    }
}
