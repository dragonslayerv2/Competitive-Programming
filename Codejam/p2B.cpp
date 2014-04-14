#include<iostream>
#include<vector>
using namespace std;


int main()
{
	//freopen("B-large.in","r",stdin);
	vector<double> D;
	D.reserve(1000000);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		double C,F,X;
		cin>>C>>F>>X;
		
		D.clear();
		D.resize(int(X+2));
		
		double minTime=X;
		for(int i=0;i<(int)(X+2);i++)
		{
			if(i!=0)
				D[i]=D[i-1]+C/((i-1)*F+2);
			
			minTime=min(minTime,D[i]+X/(i*F+2));
		}
		
		cout<<"Case #"<<T<<": ";
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<minTime<<endl;
	}
}
