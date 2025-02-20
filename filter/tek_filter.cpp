#include "filter/tek_filter.hpp"

#define __Tek_Namespace_Filter_End \
    }                              \
    }

#define __Tek_Namespace_Filter_Start \
    namespace tek                    \
    {                                \
        namespace filter             \
        {

__Tek_Namespace_Filter_Start;

Lowpass::Lowpass(const float c) : coeff(c)
{
}

void Lowpass::update(float d)
{
    this->val = this->val * (1 - this->coeff) + d * this->coeff;
}

__Tek_Namespace_Filter_End;
