#ifndef AF39161A_4503_4CD6_A8CF_4B651C049F65
#define AF39161A_4503_4CD6_A8CF_4B651C049F65

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"

typedef struct
{
    float result;
    float coeff;
} tek_lowpassFilterCore;

typedef struct
{
    float result;
} tek_averageFilterCore;

typedef struct
{
    uint8_t result;
    float threshold;
} tek_ZeroCrossingComparatorCore;

typedef struct
{
    uint8_t result;
    float thresholdHigh;
    float thresholdLow;
} tek_HysteresisComparatorCore;

void tek_lowpassFilterInit(tek_lowpassFilterCore *core, float c);
void tek_lowpassFilterUpdate(tek_lowpassFilterCore *core, float d);

void tek_ZeroCrossingComparatorInit(tek_ZeroCrossingComparatorCore *core, float threshold);
void tek_ZeroCrossingComparatorUpdate(tek_ZeroCrossingComparatorCore *core, float dat);

void tek_HysteresisComparatorUpdate(tek_HysteresisComparatorCore *core, float dat);
void tek_HysteresisComparatorInit(tek_HysteresisComparatorCore *core, float th, float tl);

#ifdef __cplusplus
}
#endif

#endif /* AF39161A_4503_4CD6_A8CF_4B651C049F65 */
