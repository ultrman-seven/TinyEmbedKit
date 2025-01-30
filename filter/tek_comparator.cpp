

#define __Tek_Namespace_Filter_End \
    }                              \
    }

#define __Tek_Namespace_Filter_Start \
    namespace tek                    \
    {                                \
        namespace filter             \
        {

__Tek_Namespace_Filter_Start;

class ZeroCrossingComparator
{
private:
    /* data */
public:
    ZeroCrossingComparator();
};

class HysteresisComparator
{
private:
public:
    HysteresisComparator();
    ~HysteresisComparator();
};

HysteresisComparator::HysteresisComparator(/* args */)
{
}

__Tek_Namespace_Filter_End;
