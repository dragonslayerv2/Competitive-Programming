#include<iostream>
using namespace std;


//--------------------- formula---------------------
double C,F,X;
bool isCalculated;

inline double time(int Fcount)
{
	double t=0;
	for(int i=0;i<Fcount;i++)
		t+=C/(i*F+2);
	t+=X/(Fcount*F+2);
	return t;
} 


int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		isCalculated=false;
		cin>>C>>F>>X;
		
		double minTime=X/2+100;
		
		for(int i=0;i<=(int)(X+1);i++)
			minTime=min(minTime,time(i));
		
		cout<<"Case #"<<T<<": ";
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<minTime<<endl;
 	}
}
