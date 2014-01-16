#include<iostream>

using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int s,t,d;
		cin>>s>>t>>d;
		int sum;
		if(s+t==d||((s+t>d)&&(s+d>t)&&(d+t>s))) sum=0;
		else
			sum=d-(s+t);
		if(sum<0) sum*=-1;
		
		cout<<sum<<endl;
	}
	return 0;
}
