#ifndef __RESISTANCE_HPP__
#define __RESISTANCE_HPP__

const double PI=3.1415926;   //圆周率

double TestCurrent=0.5;   //测试电流（mA）
double Voltages[4][5];   //测试电压数据组
double Correction_B0=4.5324;   //修正系数B0
//double ProbeSpacing_s=0.159;   //探针间距s（cm）
//enum{N,P} DopingType;   //掺杂类型（N，P）
//enum{Inf,Cir,Squ} SampleType;   //样品类型（半无穷大，半圆形，方形）

double Resistance[4][5];   //方块电阻数据组
double Rs_F,Rs_B,Rs_;   //正面方块电阻平均值，反面方块电阻平均值，体方块电阻平均值
double Nonuniformity_E_F,Nonuniformity_E_B;

enum{Auto,Manual} CalMode=Auto;   //计算模式

#endif

