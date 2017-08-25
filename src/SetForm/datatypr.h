#ifndef DATATYPR_H
#define DATATYPR_H
typedef struct MFaultParametervalue
{
  int  startime;//开始时间
  int type;//1阶跃 2斜坡
   int lenth;//时长
   int SatNO;//卫星号
   double value;//变化值
}FaultParametervalue;
#endif // DATATYPR_H
