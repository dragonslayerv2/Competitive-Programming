#include<iostream>
#include<vector>
#include<list>
#include<sstream>
using namespace std;

#define MOD 1000000007

int numberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

vector<vector<int> > personWithShirt;

vector<vector<int> > DP;
long long combinations(int shirtNumber,int assignedPersonSet, int totalPersons)
{
	if(DP[shirtNumber][assignedPersonSet]==-1){
	
		if(shirtNumber==100){
			if(numberOfSetBits(assignedPersonSet)==totalPersons)
				DP[shirtNumber][assignedPersonSet]=1;
			else
				DP[shirtNumber][assignedPersonSet]=0;
			
		}
		else{
			long long ans = 0;
			for(int i=0;i<personWithShirt[shirtNumber].size();i++)
				if(!(assignedPersonSet&(1<<personWithShirt[shirtNumber][i])))
				{
					ans += combinations(shirtNumber+1,assignedPersonSet|(1<<personWithShirt[shirtNumber][i]),totalPersons);
					ans%=MOD;
				}
			ans += combinations(shirtNumber+1,assignedPersonSet,totalPersons);	
			ans%=MOD;
			DP[shirtNumber][assignedPersonSet]=ans;
		}
	}
	return DP[shirtNumber][assignedPersonSet];
}

int main(){
	//freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		
		personWithShirt.assign(100,vector<int>());
		int n;
		cin>>n;
		DP.assign(101,vector<int>((1<<n),-1));
		getchar();
		for(int i=0;i<n;i++){
			char s[10000];
			cin.getline(s,sizeof(s));
			stringstream sin(s);
			while(!sin.eof()){
				int shirtNumber;
				sin>>shirtNumber;
				shirtNumber--;
				personWithShirt[shirtNumber].push_back(i);
			}
		}
		cout<<combinations(0,0,n)<<endl;
	}
}
