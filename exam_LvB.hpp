#ifndef __EXAM_LVB_HPP__
#define __EXAM_LVB_HPP__

const double TestCurrent=0.5;   //测试电流（mA）

double Voltages[4][5];   //测试电压数据组
double Correction_B0;   //修正系数B0
double ProbeSpacing_s;   //探针间距s
enum{N,P} DopingType;   //掺杂类型（N，P）
enum{Inf,Cir,Squ} SampleType;   //样品类型（半无穷大，半圆形，方形）

#endif

