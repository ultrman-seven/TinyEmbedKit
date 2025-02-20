
#define __Tek_Namespace_Ctrl_Start \
    namespace tek                  \
    {                              \
        namespace ctrl             \
        {

#define __Tek_Namespace_Ctrl_End \
    }                            \
    }

__Tek_Namespace_Ctrl_Start;

class ControllerBase
{
protected:
    float target;

public:
    ControllerBase();
    ~ControllerBase();
};

ControllerBase::ControllerBase()
{
}

ControllerBase::~ControllerBase()
{
}

class PID_Unit
{
private:
    float kp, ki, kd;

public:
    PID_Unit(/* args */);
};

PID_Unit::PID_Unit(/* args */)
{
}

__Tek_Namespace_Ctrl_End;
