#ifndef A6FF991A_4290_4FC6_8AAF_6748268D597F
#define A6FF991A_4290_4FC6_8AAF_6748268D597F

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct __tek_pidCore tek_pidCore;

struct __tek_pidCore
{
    float kp, ki, kd;
    float target;
    float intLimit;
    float decayFactor;
    float __err_last;
    float __intVal;
};

float tek_pidInit(tek_pidCore *core);
void tek_pidSetParam(tek_pidCore *core, float p, float i, float d);
float tek_pidUpdate(tek_pidCore *core, float inputVal);

#ifdef __cplusplus
}
#endif

#endif /* A6FF991A_4290_4FC6_8AAF_6748268D597F */
