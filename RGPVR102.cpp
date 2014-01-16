#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int max=0;
		int points[50]={0};
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>points[i];
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			points[i]=points[i]*3+temp;
			if(points[i]>max)
				max=points[i];
		}
		cout<<max<<endl;
	}
	return 0;
}
