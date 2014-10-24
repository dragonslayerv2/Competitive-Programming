#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
		int n;
		cin>>n;
		vector<pair<int,int> > villagers;
		vector<pair<int,int> > dino;
		long long mean=0;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			mean+=arr[i];
		}
		mean/=n;
		
		for(int i=0;i<n;i++)
		{
			int x=arr[i]-mean;
			if(x<0)
				dino.push_back(make_pair(i,-x));
			else
				villagers.push_back(make_pair(i,x));
		}
		long long ans=0;
		int dinoAt=0;
		int villagerAt=0;
		while(dinoAt!=dino.size()&&villagerAt!=villagers.size()){
			int decrement=min(villagers[villagerAt].second,dino[dinoAt].second);
			dino[dinoAt].second-=decrement;
			villagers[villagerAt].second-=decrement;
			
			ans+=decrement*(abs(dino[dinoAt].first-villagers[villagerAt].first));
			
			if(!dino[dinoAt].second)
				dinoAt++;
			if(!villagers[villagerAt].second)
				villagerAt++;
		}
		cout<<ans<<endl;
}
