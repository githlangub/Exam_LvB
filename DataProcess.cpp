#ifndef __DATAPROCESS_CPP__
#define __DATAPROCESS_CPP__

#include<iostream>
#include<cmath>
#include"Exam_LvB.hpp"

double B0_Confirm(void)
{
	using namespace std;

	for(char choice=0;choice!='y'&&choice!='N';)
        {
		cout<<"Set the correction coefficent manually? [y/N]: ";
                cin>>choice;
                cout<<endl;
                if(choice=='y')
                {
                        cout<<"\tGive the correction coefficent: B0 = ";
			cin>>Correction_B0;
			cout<<endl;
                }
                else if(choice=='N')
                {
                        ;
                }
                else
		{
                        cout<<"Try again."<<endl;
                }
        }
	/*switch(SampleType)
	{
		case "Inf": return(1.00);
		case "Cir": return(1.35);
		case "Squ": return(0.01);
	}*/
}



void Rou_Cal(void)
{
	double Rou_Sum=Rou_F=Rou_B=Rou_=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
		{
			Resistivity[i][j]=(2*PI*ProbeSpacing_s/Correction_B0)*(Voltages[i][j]/TestCurrent);
			Resistivity[i][j]=fabs(Resistivity[i][j]);
			Rou_Sum+=Resistivity[i][j];
		}
	}
	Rou_F=Rou_Sum/10;
	for(int i=2;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			Resistivity[i][j]=(2*PI*ProbeSpacing_s/Correction_B0)*(Voltages[i][j]/(TestCurrent));
			Resistivity[i][j]=fabs(Resistivity[i][j]);
			Rou_Sum+=Resistivity[i][j];
		}
	}
	Rou_B=(Rou_Sum-(Rou_F*10))/10;
	Rou_=Rou_Sum/20;
}



void c_Cal(void)
{
	Mobility_u=(DopingType==N)?1350.00:500.00;
	Concentration_c=1/(Rou_*ElementaryCharge_q*Mobility_u);
}

#endif

