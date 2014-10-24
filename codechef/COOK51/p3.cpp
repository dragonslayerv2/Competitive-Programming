#include<iostream>
#include<map>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int pow2=(1<<n);
		map<int,int> sums;

		for(int i=0;i<(1<<n);i++)
		{
			int x;
			cin>>x;
			sums[x]++;
		}
		
		vector<int> numbers;
		vector<int> newSet;
		newSet.push_back(0);
		newSet.reserve(1<<n);
		while(n--){
			int newNumber;
			for(map<int,int>::iterator i=sums.begin();i!=sums.end();i++)
			{
				if(i->first&&i->second)
				{
					newNumber=i->first;
					break;
				}
			}
				

			numbers.push_back(newNumber);
			
			int newSetSize=newSet.size();
			for(int i=0;i<newSetSize;i++){
				newSet.push_back(newSet[i]+newNumber);
				sums[newSet.back()]--;
			}
		}
		sort(numbers.begin(),numbers.end());
		for(int i=0;i<numbers.size();i++)
			cout<<numbers[i]<<" ";
		cout<<endl;
	}
}
