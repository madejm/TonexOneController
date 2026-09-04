
#pragma once

typedef enum
{
    MODELLER_PARAM_TYPE_SWITCH,        // on/off
    MODELLER_PARAM_TYPE_SELECT,        // 0,1,2,3 etc
    MODELLER_PARAM_TYPE_RANGE          // floating point range
} ParamType_t;

#define MAX_PARAM_NAME          12

typedef struct
{
    float Value;
    float Min;
    float Max;
    char Name[MAX_PARAM_NAME];
    ParamType_t Type;
    uint8_t Data1;  // usage depends on connected modeller
    uint8_t Data2;  // usage depends on connected modeller
    uint8_t Data3;  // usage depends on connected modeller
} tModellerParameter;
