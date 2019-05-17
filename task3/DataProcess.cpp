#ifndef __DATAPROCESS_CPP__
#define __DATAPROCESS_CPP__

#include<iostream>
#include<cmath>
#include"Resistance.hpp"

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



void Rs_Cal(void)
{
	double Rs_Sum=Rs_F=Rs_B=Rs_=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
		{
			Resistance[i][j]=Correction_B0*(Voltages[i][j]/TestCurrent);
			Resistance[i][j]=fabs(Resistance[i][j]);
			Rs_Sum+=Resistance[i][j];
		}
	}
	Rs_F=Rs_Sum/10;
	for(int i=2;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			Resistance[i][j]=Correction_B0*(Voltages[i][j]/(TestCurrent));
			Resistance[i][j]=fabs(Resistance[i][j]);
			Rs_Sum+=Resistance[i][j];
		}
	}
	Rs_B=(Rs_Sum-(Rs_F*10))/10;
	Rs_=Rs_Sum/20;
}



void E_Cal(void)
{
	double Rs_max,Rs_min;

	/****** ******/
	Rs_max=Rs_min=Resistance[0][0];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(Resistance[i][j]>Rs_max)
			{
				Rs_max=Resistance[i][j];
			}
			else if(Resistance[i][j]<Rs_min)
			{
				Rs_min=Resistance[i][j];
			}
		}
	}
	Nonuniformity_E_F=(Rs_max-Rs_min)/(0.5*(Rs_max+Rs_min));

	/****** ******/
	Rs_max=Rs_min=Resistance[2][0];
	for(int i=2;i<4;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(Resistance[i][j]>Rs_max)
			{
				Rs_max=Resistance[i][j];
			}
			else if(Resistance[i][j]<Rs_min)
			{
				Rs_min=Resistance[i][j];
			}
		}
	}
	Nonuniformity_E_B=(Rs_max-Rs_min)/(0.5*(Rs_max+Rs_min));
}

#endif

