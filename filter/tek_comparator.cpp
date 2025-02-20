

#define __Tek_Namespace_Filter_End \
    }                              \
    }

#define __Tek_Namespace_Filter_Start \
    namespace tek                    \
    {                                \
        namespace filter             \
        {

__Tek_Namespace_Filter_Start;

class ComparatorBase
{
protected:
    bool state = false;

public:
    virtual void update(float dat) const = 0;
    inline bool get_result() { return state; };
};

class ZeroCrossingComparator : public ComparatorBase
{
    private:
    const float threshold;

public:
    ZeroCrossingComparator(const float t);
    virtual void update(float dat);
};

class HysteresisComparator : public ComparatorBase
{
    private:
    const float thresholdHigh;
    const float thresholdLow;

    public:
    HysteresisComparator(const float h, const float l);
    virtual void update(float dat);
};

ZeroCrossingComparator::ZeroCrossingComparator(const float t):threshold(t)
{
}

void ZeroCrossingComparator::update(float dat)
{
    this->state = (dat > this->threshold);
}

HysteresisComparator::HysteresisComparator(const float h, const float l)
    : thresholdHigh(h), thresholdLow(l)
{
}

void HysteresisComparator::update(float dat)
{
    if (this->state) // activated
    {
        if (dat < this->thresholdLow)
            this->state = false;
    }
    else
    {
        if (dat > this->thresholdHigh)
            this->state = true;
    }
}

__Tek_Namespace_Filter_End;
