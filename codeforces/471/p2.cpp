#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
//	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	vector<pair<int,int> > a;
	int twoCount=0;
	int threeCount=0;
	map<int,int> count;
	for(int i=0;i<n;i++)	
	{
		int x;
		cin>>x;
		a.push_back(make_pair(x,i+1));
		
		count[x]++;
		if(count[x]==2)
			twoCount++;
		else if(count[x]==3)
			threeCount++;
	}
	if(twoCount>1||threeCount>=1){
		cout<<"YES"<<endl;
		sort(a.begin(),a.end());	
		
		int current=0;
		vector<vector<int> > plans(3);
		
		int turn=0;
		while(current<n){
			int last=current;
			while(last<n&&a[last].first==a[current].first)
				last++;
			if(last==current+1){
				plans[0].push_back(a[current].second);
				plans[1].push_back(a[current].second);
				plans[2].push_back(a[current].second);
			}
			else{
				vector<int> positions;
				
				for(int i=current;i<last;i++){
					positions.push_back(a[i].second);
				}

				sort(positions.begin(),positions.end());
				
				if(positions.size()==2)
				{
					for(int i=0;i<positions.size();i++){
						plans[0].push_back(positions[i]);
					}
					for(int i=positions.size()-1;i>=0;i--)
						plans[1+turn].push_back(positions[i]);
					for(int i=0;i<positions.size();i++)
						plans[1+(turn+1)%2].push_back(positions[i]);
					turn^=1;
				}
				else
				{
					for(int i=0;i<positions.size();i++)
						plans[0].push_back(positions[i]);
					
					next_permutation(positions.begin(),positions.end());
					for(int i=0;i<positions.size();i++)
						plans[1].push_back(positions[i]);
					
					next_permutation(positions.begin(),positions.end());
					for(int i=0;i<positions.size();i++)
						plans[2].push_back(positions[i]);
				}
			}
			current=last;
		}
		
		
		
		
		for(int i=0;i<plans.size();i++)
		{
			for(int j=0;j<plans[i].size();j++)
				cout<<plans[i][j]<<" ";
			cout<<endl;
		}	
	}
	else
		cout<<"NO";
}
