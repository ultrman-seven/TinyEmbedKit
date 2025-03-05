#ifndef AF39161A_4503_4CD6_A8CF_4B651C049F65
#define AF39161A_4503_4CD6_A8CF_4B651C049F65

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "adt/tek_fifo.h"

typedef struct
{
    float result;
    float coeff;
} tek_lowpassFilterCore;

typedef struct
{
    float result;
    uint32_t len;
    float __sum;
    tek_FifoCore fifo;
} tek_averageFilterCore;

typedef struct
{
    float result;
    float coeff;
    float prevInput;
}tek_highpassFilterCore;

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

void tek_highpassFilterInit(tek_highpassFilterCore *core, float c);
void tek_highpassFilterUpdate(tek_highpassFilterCore *core, float d);

void tek_averageFilterInit(tek_averageFilterCore *core, void *buf, uint32_t bufSize);
void tek_averageFilterUpdate(tek_averageFilterCore *core, float data);

void tek_ZeroCrossingComparatorInit(tek_ZeroCrossingComparatorCore *core, float threshold);
void tek_ZeroCrossingComparatorUpdate(tek_ZeroCrossingComparatorCore *core, float dat);

void tek_HysteresisComparatorUpdate(tek_HysteresisComparatorCore *core, float dat);
void tek_HysteresisComparatorInit(tek_HysteresisComparatorCore *core, float th, float tl);

#ifdef __cplusplus
}
#endif

#endif /* AF39161A_4503_4CD6_A8CF_4B651C049F65 */
