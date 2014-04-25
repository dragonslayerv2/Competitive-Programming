#include<iostream>
#include<vector>
using namespace std;

#define EPS 0.001F
int main()
{
	//freopen("testF.txt","r",stdin);
	vector<float> hanging;
	hanging.resize(600);
	for(int i=1;i<hanging.size();i++)
		hanging[i]=hanging[i-1]+(1/(double)(i+1));
	
	while(1)
	{
		float a;
		cin>>a;
		if(a+EPS>=0.00F&&a-EPS<=0.00F)
			break;
		
		for(int i=0;i<hanging.size();i++)
			if(hanging[i]>=a)
			{
				cout<<i<<" card(s)"<<endl;
				break;
			}
	}
}
