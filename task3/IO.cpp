#ifndef __IO_CPP__
#define __IO_CPP__

#include<iostream>
#include"Resistance.hpp"

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
	cout<<endl;

	/****** ******/
	cout<<"===== Front Resistance ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"\tI = "<<TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[0][i]<<" mV"<<endl;
		cout<<"\tRs = "<<Resistance[0][i]<<" Omi"<<endl;
		cout<<endl;
		cout<<"\tI = "<<(-1)*TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[1][i]<<" mV"<<endl;
		cout<<"\tRs = "<<Resistance[1][i]<<" Omi"<<endl;
		cout<<endl;
	}
	cout<<"The average of the front resistance is "<<Rs_F<<" Omi"<<"\n"<<endl;
	cout<<"The Non-Uniformity of the front resistance is "<<Nonuniformity_E_F*100<<"%"<<"\n"<<endl;

	/****** ******/
	cout<<"===== Back Resistance ====="<<"\n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Point "<<i+1<<":"<<"\n"<<endl;
		cout<<"\tI = "<<TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[0][i]<<" mV"<<endl;
		cout<<"\tRs = "<<Resistance[0][i]<<" Omi"<<endl;
		cout<<endl;
		cout<<"\tI = "<<(-1)*TestCurrent<<" mA"<<endl;
		cout<<"\tV = "<<Voltages[1][i]<<" mV"<<endl;
		cout<<"\tRs = "<<Resistance[1][i]<<" Omi"<<endl;
		cout<<endl;
	}
	cout<<"The average of the back resistance is "<<Rs_B<<" Omi*cm"<<"\n"<<endl;
	cout<<"The Non-Uniformity of the back resistance is "<<Nonuniformity_E_B*100<<"%"<<"\n"<<endl;

	/****** ******/
	cout<<"===== Sample Properties ====="<<"\n"<<endl;
	/*cout<<"\tIt's a/an ";
	switch(SampleType)
	{
		case Inf: cout<<"/Infinity";break;
		case Cir: cout<<"/Semi-Circle";break;
		case Squ: cout<<"/Square";break;
	}
	cout<<" Silicon."<<endl;*/
	cout<<"\tSquare Resistance: "<<Rs_<<" Omi"<<endl;
	cout<<endl;
}

#endif

