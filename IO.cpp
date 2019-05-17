#ifndef __IO_CPP__
#define __IO_CPP__

#include<iostream>
#include"Exam_LvB.hpp"

void Data_Input(void)
{
	using namespace std;

	/****** ******/
	for(unsigned choice=0;choice!=1&&choice!=2;)
	{
		cout<<"Choose the calculating mode ([1]Auto [2]Manual): ";
		cin>>choice;
		cout<<endl;
		if(choice==1)
		{
			CalMode=Auto;
		}
		else if(choice==2)
		{
			CalMode=Manual;
		}
		else
		{
			cout<<"No this Mode!Try again."<<endl;
		}
	}

	/****** ******/
	cout<<"===== Parameters Set ====="<<"\n"<<endl;
	if(CalMode==Manual)
	{
		cout<<"Set the test current(mA): I = ";
		cin>>TestCurrent;
		cout<<endl;
		cout<<"Give the spacing of probes(mm): s = ";
		cin>>ProbeSpacing_s;
		ProbeSpacing_s/=10.00;
		cout<<endl;
	}
	for(unsigned choice=0;choice!=1&&choice!=2;)
	{
		cout<<"What is the doping type of the sample? [1]p-type [2]n-type: ";
		cin>>choice;
		cout<<endl;
		if(choice==1)
		{
			DopingType=P;
		}
		else if(choice==2)
		{
			DopingType=N;
		}
		else
		{
			cout<<"No this Type!Try again."<<endl;
		}
	}

	/****** ******/
	cout<<"===== Front Voltages Input ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"Input the forward voltage(mv): V = ";
		cin>>Voltages[0][i];
		cout<<endl;
		cout<<"Input the reverse voltage(mv): V = ";
		cin>>Voltages[1][i];
		cout<<endl;
	}

	/****** ******/
	cout<<"===== Back Voltages Input ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"Input the forward voltage(mv): V = ";
		cin>>Voltages[2][i];
		cout<<endl;
		cout<<"Input the reverse voltage(mv): V = ";
		cin>>Voltages[3][i];
		cout<<endl;
	}
}



void Results_Output(void)
{
	using namespace std;

	cout.width(5);

	/****** ******/
	cout<<"===== Exam Environment ====="<<"\n"<<endl;
	cout<<"\tCorrection Coefficent: B0 = "<<Correction_B0<<endl;
	cout<<"\tProbe Spacing: s = "<<ProbeSpacing_s*10<<" mm"<<endl;
	cout<<endl;

	/****** ******/
	cout<<"===== Front Resistivity ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"\tI = "<<TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[0][i]<<" mV"<<endl;
		cout<<"\tRou = "<<Resistivity[0][i]<<" Omi*cm"<<endl;
		cout<<endl;
		cout<<"\tI = "<<(-1)*TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[1][i]<<" mV"<<endl;
		cout<<"\tRou = "<<Resistivity[1][i]<<" Omi*cm"<<endl;
		cout<<endl;
	}
	cout<<"The average of the front resistivity is "<<Rou_F<<" Omi*cm"<<"\n"<<endl;

	/****** ******/
	cout<<"===== Back Resistivity ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"\tI = "<<TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[0][i]<<" mV"<<endl;
		cout<<"\tRou = "<<Resistivity[0][i]<<" Omi*cm"<<endl;
		cout<<endl;
		cout<<"\tI = "<<(-1)*TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[1][i]<<" mV"<<endl;
		cout<<"\tRou = "<<Resistivity[1][i]<<" Omi*cm"<<endl;
		cout<<endl;
	}
	cout<<"The average of the back resistivity is "<<Rou_B<<" Omi*cm"<<"\n"<<endl;

	/****** ******/
	cout<<"===== Sample Properties ====="<<"\n"<<endl;
	cout<<"\tIt's a/an ";
	switch(DopingType)
	{
		case N: cout<<"n-type";break;
		case P: cout<<"p-type";break;
	}
	/*switch(SampleType)
	{
		case Inf: cout<<"/Infinity";break;
		case Cir: cout<<"/Semi-Circle";break;
		case Squ: cout<<"/Square";break;
	}*/
	cout<<" Silicon."<<endl;
	cout<<"\tResistivity: "<<Rou_<<" Omi*cm"<<endl;
	cout<<"\tDoping Concentration: "<<Concentration_c<<" cm^-3"<<endl;
	cout<<endl;
}

#endif

