#ifndef EB1E7F21_A6BA_4846_92EA_B98D50E181E4
#define EB1E7F21_A6BA_4846_92EA_B98D50E181E4
#include "stdint.h"
#include "string.h"

typedef struct
{
    // uint16_t __buffSize;
    // uint16_t __elementSize;
    uint32_t __buffSize : 16;
    uint32_t __elementSize : 16;
    uint8_t *__buff;
} tek_ArrayCore;

/// @brief 初始化数组
/// @param core tek_ArrayCore* 数组结构体指针
/// @param buf void* 数据缓冲区指针
/// @param bufLen uint16_t 数据缓冲区长度
/// @param elementSize uint16_t 元素大小
void tek_ArrayInit(tek_ArrayCore *core, void *buf, uint16_t bufLen, uint16_t elementSize);

/// @brief 设置数组元素
/// @param core tek_ArrayCore* 数组结构体指针
/// @param idx int16_t 下标
/// @param data void* 数据指针
void tek_ArraySetVal(tek_ArrayCore *core, int16_t idx, void *data);

/// @brief 获取数组元素
/// @param core tek_ArrayCore* 数组结构体指针
/// @param idx int16_t 下标
/// @param data void* 数据接收指针
void tek_ArrayGetVal(tek_ArrayCore *core, int16_t idx, void *data);

/// @brief 获取数组对应元素的指针
/// @param core tek_ArrayCore* 数组结构体指针
/// @param idx int16_t 下标
/// @return void* 数据指针
void *tek_ArrayGet(tek_ArrayCore *core, int16_t idx);

/// @brief 检查数组下标是否合法
/// @param core
/// @param idx
/// @return
uint8_t tek_ArrayIndexIsLegal(tek_ArrayCore *core, uint16_t idx);

/// @brief 直接设置数组元素
/// @param core tek_ArrayCore* 数组结构体指针
/// @param idx int16_t 下标
/// @param valPtr void* 数据指针
#define tek_ArrayDirectSetVal(__core, __idx, __valPtr)          \
    memcpy(                                                     \
        (__core)->__buff + (__idx) * ((__core)->__elementSize), \
        __valPtr,                                               \
        (__core)->__elementSize)

/// @brief 直接获取数组元素
/// @param core tek_ArrayCore* 数组结构体指针
/// @param idx  int16_t 下标
/// @param valPtr   void* 数据指针
#define tek_ArrayDirectGetVal(__core, __idx, __valPtr)          \
    memcpy(                                                     \
        __valPtr,                                               \
        (__core)->__buff + (__idx) * ((__core)->__elementSize), \
        (__core)->__elementSize)

#endif /* EB1E7F21_A6BA_4846_92EA_B98D50E181E4 */
