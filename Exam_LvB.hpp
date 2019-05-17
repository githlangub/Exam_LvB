#ifndef __EXAM_LVB_HPP__
#define __EXAM_LVB_HPP__

const double PI=3.1415926;   //
const double ElementaryCharge_q=1.602E-19;   //

double TestCurrent=0.5;   //测试电流（mA）
double Voltages[4][5];   //测试电压数据组
double Correction_B0=1.00;   //修正系数B0
double ProbeSpacing_s=0.159;   //探针间距s（cm）
enum{N,P} DopingType;   //掺杂类型（N，P）
//enum{Inf,Cir,Squ} SampleType;   //样品类型（半无穷大，半圆形，方形）

double Resistivity[4][5];   //
double Rou_F,Rou_B,Rou_;   //
double Concentration_c;   //
double Mobility_u;   //

enum{Auto,Manual} CalMode=Auto;   //

#endif

