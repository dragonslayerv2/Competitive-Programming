#include<iostream>
#include<vector>
using namespace std;

inline unsigned long long gcd(unsigned long long a, unsigned long long b)
{
   unsigned long long temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}
vector<int> array;
vector<bool> isTaken;
double iWonProbability=0.0;

bool won(int G,int count,int turn,double probability)
{
	bool iWon=false;
	if(G==1)
	{
		if(turn%2==0)
			iWonProbability+=probability;
		return true;
	}	
	else if(count==0)
	{
		if(turn%2!=0)
			iWonProbability+=probability;
		return false;
	}
		
	for(int i=0;i<array.size();i++)
	{
		if(!isTaken[i])
		{
			isTaken[i]=true;
			iWon=(iWon|(!won(gcd(array[i],G),count-1,turn+1,probability/count)));
			isTaken[i]=false;
		}
	}
	return iWon;
}
int main()
{
//	freopen("sample.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		array.assign(n,0);
		isTaken.resize(n,false);
		for(int i=0;i<n;i++)
			cin>>array[i];
			
		iWonProbability=0;
		cout<<won(0,array.size(),0,1)<<" ";
		cout.precision(4);
		cout.setf(ios::fixed);
		cout<<iWonProbability<<endl;
	}
}
