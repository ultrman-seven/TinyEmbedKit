# TinyEmbedKit

适用于嵌入式设备的常用工具包，包含容器、控制器、滤波器等组件。

特点：

+ 无需移植，各平台通用：8051, arm, risc-v...

+ 轻量化、rom/ram需求低、不使用堆内存(无malloc、无new)

+ 针对单片机开发，同时Linux/Windows也能用

## 使用

1. 如果项目是使用CMake进行构建

    直接将把仓库克隆到您的项目文件夹中，在您项目的CMakeLists中使用`add_subdirectory(TinyEmbedKit)`添加本库文件夹，然后在`target_link_libraries`中添加`tek`。

2. 如果是使用Keil或其他工具

    要添加相应的头文件目录和源文件，具体为：
    1. 头文件目录：本库(即TinyEmbedKit)
    2. 源文件：本库中所有.c文件

## 详细功能介绍

### adt-容器

#### Array

数组

+ `void tek_ArrayInit(tek_ArrayCore *core, void *buf, uint16_t bufLen, uint16_t elementSize);`
+ `void tek_ArraySetVal(tek_ArrayCore *core, int16_t idx, void *data);`
+ `void tek_ArrayGetVal(tek_ArrayCore *core, int16_t idx, void *data);`
+ `void *tek_ArrayGet(tek_ArrayCore *core, int16_t idx);`
+ `uint8_t tek_ArrayIndexIsLegal(tek_ArrayCore *core, uint16_t idx);`

#### FIFO

先进先出/队列

+ 初始化函数`void tek_FifoInit(tek_FifoCore *fifo, void *buffer, uint32_t buffSize, uint32_t elementSize);`
+ 入队`void tek_FifoPush(tek_FifoCore *fifo, void *data);`
+ 查询队首数据`void tek_FifoTop(tek_FifoCore *fifo, void *data);`
+ 出队`void tek_FifoPop(tek_FifoCore *fifo);`
+ 查询队首数据并`void tek_FifoGet(tek_FifoCore *fifo, void *data);`
+ 获取当前队列中数据个数`uint32_t tek_FifoGetDataLength(tek_FifoCore *fifo);`
+ 批量查询并出队`void tek_FifoGetBytes(tek_FifoCore *fifo, void *data, uint8_t len);`

#### Stack

栈

+ 初始化`void tek_stackInit(tek_stackCore *core, void *buf, uint16_t bufSize, uint16_t elementSize);`
+ pop`uint8_t tek_stackPop(tek_stackCore *core, void *dPtr);`
+ push`uint8_t tek_stackPush(tek_stackCore *core, void *dPtr);`
+ 查询栈顶数据`uint8_t tek_stackTop(tek_stackCore *core, void *dPtr);`

### filter-滤波器

#### 低通滤波器

`void tek_lowpassFilterInit(tek_lowpassFilterCore *core, float c);`
`void tek_lowpassFilterUpdate(tek_lowpassFilterCore *core, float d);`

#### 高通滤波器

`void tek_highpassFilterInit(tek_highpassFilterCore *core, float c);`
`void tek_highpassFilterUpdate(tek_highpassFilterCore *core, float d);`

#### 均值滤波器

`void tek_averageFilterInit(tek_averageFilterCore *core, void *buf, uint32_t bufSize);`
`void tek_averageFilterUpdate(tek_averageFilterCore *core, float data);`

#### 迟滞比较器

`void tek_HysteresisComparatorUpdate(tek_HysteresisComparatorCore *core, float dat);`
`void tek_HysteresisComparatorInit(tek_HysteresisComparatorCore *core, float th, float tl);`

#### 带通滤波器

#### 过零比较器

`void tek_ZeroCrossingComparatorInit(tek_ZeroCrossingComparatorCore *core, float threshold);`
`void tek_ZeroCrossingComparatorUpdate(tek_ZeroCrossingComparatorCore *core, float dat);`

#### kalman滤波器

#### LGB观测器

### controller-控制器

#### PID控制器

+ 初始化`void tek_pidInit(tek_pidCore *core);`
+ 设置参数`void tek_pidSetParam(tek_pidCore *core, float p, float i, float d);`
+ 更新`float tek_pidUpdate(tek_pidCore *core, float inputVal);`

#### MPC控制器

#### Fuzzy控制器

#### 滑模控制器

### communication-通信协议
