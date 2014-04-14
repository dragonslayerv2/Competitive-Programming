#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n;
		cin>>n;
		vector<double> N(n),K(n);
		for(int i=0;i<n;i++)
			cin>>N[i];
			
		for(int i=0;i<n;i++)
			cin>>K[i];
		
		sort(N.begin(),N.end());
		sort(K.begin(),K.end());
		
		int normal=0;
		
		int Kpointer=0;
		for(int Npointer=0;Npointer<n;Npointer++)
		{
			while(Kpointer<n&&K[Kpointer]<N[Npointer])
			{
				normal++;
				Kpointer++;
			}
			Kpointer++;
		}
	
	
		int Kbegin=0,Kend=n-1;
		
		
		int deciteful=0;	
		
		for(int nBegin=0;nBegin<n;nBegin++)
		{
			if(N[nBegin]>K[Kbegin])
			{
				Kbegin++;
				deciteful++;
			}
			else
				Kend--;
		}
		
		cout<<"Case #"<<T<<": "<<deciteful<<" "<<normal<<endl;		
	}	
}
