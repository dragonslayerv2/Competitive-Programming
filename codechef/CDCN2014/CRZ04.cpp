#include<iostream>
#include<math.h>
using namespace std;

double abs(double x)
{
	if(x<0)
		return 360+x;
	else
		return x;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,m;
		cin>>h>>m;
		
		if(h<0||h>23||m<0||m>59)
			cout<<"Invalid Time"<<endl;
		else
		{
			h%=12;
			cout.setf(ios::fixed);
			cout.precision(1);
			double ans=abs(((double)(h*60+m))/2-m*6);
			ans=min(ans,360-ans);
			cout<<ans<<endl;
		}
	}
}
