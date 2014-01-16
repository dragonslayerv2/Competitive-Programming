#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> LIS(n);
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		int max=1;
		LIS[0]=1;
		for(int i=0;i<n;i++)
		{
			LIS[i]=0;
			for(int j=0;j<i;j++)
			{
				if(LIS[i]<LIS[j]&&a[i]>=a[j])
					LIS[i]=LIS[j];
			}
			LIS[i]++;
			if(LIS[i]>max)
				max=LIS[i];
		}
		cout<<max<<endl;
	}

}
