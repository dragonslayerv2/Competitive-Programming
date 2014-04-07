#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int kSize,sSize;
	cin>>kSize>>sSize;
	
	vector<int> K(kSize);
	for(int i=0;i<K.size();i++)
		cin>>K[i];
	sort(K.begin(),K.end());
	
	vector<int> S(sSize);
	for(int i=0;i<S.size();i++)
		cin>>S[i];
	sort(S.begin(),S.end());
		
	const int maxQuery=100001;
	vector<bool> sWon(maxQuery),kWon(maxQuery);
	for(int i=1;i<maxQuery;i++)
	{
		bool sLose=false;
		for(int j=0;j<K.size()&&i-K[j]>=0;j++)
			if(sWon[i-K[j]]==false)
			{
				sLose=true;
				break;
			}
		kWon[i]=sLose;
		
		bool kLose=false;
		for(int j=0;j<S.size()&&i-S[j]>=0;j++)
			if(kWon[i-S[j]]==false)
			{
				kLose=true;
				break;
			}
		sWon[i]=kLose;
	}
	
	int Q;
	cin>>Q;
	
	while(Q--)
	{
		int n;
		char firstPlayer;	
		cin>>n>>firstPlayer;
		
		bool iWon=false;
			
		if(firstPlayer=='K'&&kWon[n]==false)
			iWon=true;
		else if(firstPlayer=='S'&&sWon[n]==true)
			iWon=true;
		
		cout<<(iWon?"YES":"NO")<<endl;
	}
}
