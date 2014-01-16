#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define POW2 70368744177664LL
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long sum=0;
		vector<long long> maxo(100);
		for(int i=0;i<n;i++)
		{
			int pilesize;
			cin>>pilesize;
			bool iseven;
			long long current;
			int location=0;
			vector<long long> pile(pilesize);
			vector<long long> weight(pilesize);
			for(int j=0;j<pilesize;j++)
				cin>>pile[j];
						
			sort(pile.begin(),pile.end());
			
			int cost=1;
			weight[pile.size()-1]=cost;
			
			for(int j=pile.size()-2;j>=0;j--)
			{
				if(pile[j]!=pile[j+1])
				{
					if((pile[j]&1&&pile[j+1]&1)||(!(pile[j]&1)&&!(pile[j+1]&1)))
						cost++;
					else
						cost=1;
				}
				weight[j]=cost;
			}
			
			
			for(int j=0;j<pile.size();j++)
			{
				long long value=pile[j];
				if(j==0)
				{
					current=1;
					if(value&1)
						iseven=false;
					else
					{
						iseven=true;
						current*=-1;
					}
				}			
				else
				{
					if(pile[j-1]!=pile[j])
						location++;
					if((iseven&&value&1)||(!iseven&&!(value&1)))
					{
						current*=-1;
						if(iseven)
							iseven=false;
						else
							iseven=true;
					}
				}	
				maxo[location]+=current*weight[j];
			}	
		}
		bool allzero=true;
		int pos;
		for(int i=0;i<maxo.size();i++)
			if(maxo[i])
			{
				allzero=false;
				pos=i;
				break;
			}
		
		if(allzero)
		{
			cout<<"DON'T PLAY"<<endl;
		}
		else
		{
			sum=maxo[pos];
			if(sum>0)
			{
				cout<<"ODD"<<endl;
			}
			else if(sum<0)
			{
				cout<<"EVEN"<<endl;
			}
		}
	}
}
