#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> a(n),b(n),c(n);
		vector<vector<vector<int> > > solution(n,vector<vector<int> >(2,vector<int>(2)));
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i]>>c[i];
		
		solution[n-1][true][false]=0;
		solution[n-1][true][true]=b[n-1];
		solution[n-1][false][true]=a[n-1];
		solution[n-1][false][false]=0;
		for(int i=n-2;i>=0;i--)
		{
			solution[i][true][true]  =max(b[i]+solution[i+1][true][false],c[i]+solution[i+1][true][true]);
			solution[i][true][false] =max(solution[i+1][false][true],solution[i+1][false][false]);
			solution[i][false][true] =max(a[i]+solution[i+1][true][false],b[i]+solution[i+1][true][true]);
			solution[i][false][false]=max(solution[i+1][false][true],solution[i+1][false][false]);
		}
		cout<<max(solution[0][false][true],solution[0][false][false])<<endl;
	}
}
