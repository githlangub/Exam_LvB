#ifndef __RESISTIVITY_HPP__
#define __RESISTIVITY_HPP__

const double PI=3.1415926;   //圆周率
const double ElementaryCharge_q=1.602E-19;   //元电荷

double TestCurrent=0.5;   //测试电流（mA）
double Voltages[4][5];   //测试电压数据组
double Correction_B0=1.00;   //修正系数B0
double ProbeSpacing_s=0.159;   //探针间距s（cm）
enum{N,P} DopingType;   //掺杂类型（N，P）
//enum{Inf,Cir,Squ} SampleType;   //样品类型（半无穷大，半圆形，方形）

double Resistivity[4][5];   //电阻率数据组
double Rou_F,Rou_B,Rou_;   //正面电阻率平均值，反面电阻率平均值，体电阻率平均值
double Nonuniformity_E_F,Nonuniformity_E_B;
double Concentration_c;   //掺杂浓度
double Mobility_u;   //载流子迁移率

enum{Auto,Manual} CalMode=Auto;   //计算模式

#endif

