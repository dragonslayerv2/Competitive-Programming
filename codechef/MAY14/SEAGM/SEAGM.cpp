#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
using namespace std;

class primeSieve
{
	private:
		int *isprime;
		int MAX;
		bool isSet(int n) const
		{
			return (isprime[n>>5]&(1<<(n&31)));
		}
		bool unSet(int n)
		{
			isprime[n>>5] &= ~(1<<(n&31));
		}
		
	public:
		primeSieve(int size)
		{
			MAX=size;
			isprime=new int[MAX/32+10];
		
		    int i,j;
		    isprime[0]=0xA28A28AC;
		    
   			for(int i=1;i<=MAX/32+1;i+=3)
    		{
    			isprime[i]  =0x28A28A28;
        		isprime[i+1]=0x8A28A28A;
        		isprime[i+2]=0xA28A28A2;
    		}
    		
    		for(i=5;i*i<=MAX;i+=2)
        		if(isSet(i))
            		for(j=i*i;j<=MAX;j+=i)
                		unSet(j);
		}
		bool isPrime(int n) const
		{	
			return isSet(n);
		}		
		int size() const
		{
			return MAX+1;
		}
		~primeSieve()
		{
			delete [] isprime;
		}
};

inline int newSet(int set1,int set2)  // return the new G set
{
	return set1&(~(set1^set2));
}

vector<vector<int> > multiplicants;
vector<int> primeHash;
int arraySize;

struct returnValue
{
	long long optimalValue;
	double probability;	
	returnValue(){}
	
	returnValue(long long o,double p)
	{
		optimalValue=o;
		probability=p;
	}
};

map<pair<int,int>,returnValue> DP;

returnValue playOptimally(int turn,int Gset)
{
	//cout<<"AT turn "<<turn<<" "<<Gset<<endl;
	if(DP.find(make_pair(turn,Gset))==DP.end())
	{
		int iWon;	
		
		double probability=0;
		if(Gset==0)
		{
		//	cout<<"Gset became 1"<<endl;
			iWon=1;
			probability=1;
		}
			
		
		else if(turn==arraySize)
		{
		//	cout<<"No elements left"<<endl;
			iWon=0;
			probability=0;
		}
			
		
		else
		{
			bool sameSolved=false;
			int primeIndex=0;
			iWon=0;
			int GsetCopy=Gset;
			
			set<int> alreadyTaken;
			while(GsetCopy)
			{
				if((GsetCopy&1)&&multiplicants[primeIndex].size()>turn)
				{
					int sameCount=0;
					for(int i=0;i<multiplicants[primeIndex].size();i++)
					{
						if(newSet(Gset,primeHash[multiplicants[primeIndex][i]])==Gset)
							sameCount++;
						else if(alreadyTaken.find(multiplicants[primeIndex][i])==alreadyTaken.end())
						{
					//		cout<<"Taking "<<multiplicants[primeIndex][i]<<endl;
							returnValue oppositionTurn=playOptimally(turn+1,newSet(Gset,primeHash[multiplicants[primeIndex][i]]));
					//		cout<<"Returned."<<endl;
					//		cout<<"Got oppostionProbability = "<<oppositionTurn.probability<<endl;
							
							iWon=iWon||(!oppositionTurn.optimalValue);
							probability+=(1-oppositionTurn.probability);
						}
					}
					for(int i=0;i<multiplicants[primeIndex].size();i++)
						alreadyTaken.insert(multiplicants[primeIndex][i]);
					if(!sameSolved&&sameCount>turn)
					{
					//	cout<<"Going with the same Elements"<<endl;
						returnValue oppositionTurn=playOptimally(turn+1,Gset);
						iWon=iWon||(!oppositionTurn.optimalValue);
					//	cout<<"Same Count = " <<sameCount-turn<<endl;
					//	cout<<"OppositionProbablity = "<<oppositionTurn.probability<<endl;
						probability+=(1-oppositionTurn.probability)*(sameCount-turn);
						sameSolved=true;		
					}
				}
				GsetCopy>>=1;
				primeIndex++;
			}
		}
		if(turn==arraySize||Gset==0)
		{
	//		cout<<"Returning "<<iWon<<" "<<iWon<<endl;
			DP[make_pair(turn,Gset)]=returnValue(iWon,iWon);
		}
			
		else
		{
	//		cout<<"Returing "<<iWon<<" "<<probability/(arraySize-turn)<<endl;
			DP[make_pair(turn,Gset)]=returnValue(iWon,probability/(arraySize-turn));
		}
			
	}
	return DP[make_pair(turn,Gset)];
}

int main()
{	
	//freopen("in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	
	
	primeSieve sieve(100);
	
	
	vector<int> primeList;
	primeList.reserve(30);
	for(int i=0;i<sieve.size();i++)
		if(sieve.isPrime(i))
			primeList.push_back(i);
			
	
	multiplicants.resize(primeList.size());
	primeHash.resize(101);
	for(int a=1;a<primeHash.size();a++)
	{
		int aHash=0;
		for(int k=0;k<primeList.size();k++)
			if(a%primeList[k]==0)
				aHash=aHash|(1<<k);
		primeHash[a]=aHash;
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		
		for(int i=0;i<multiplicants.size();i++)
			if(multiplicants.size())
				multiplicants[i].clear();
		
		if(DP.size())
			DP.clear();
			
		int n;
		cin>>n;
		arraySize=n;
		vector<int> array(n);
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			array[i]=a;
			
			for(int k=0;k<primeList.size();k++)
				if(a%primeList[k]==0)
					multiplicants[k].push_back(a);
		}
		
		int won=0;
		double probability=0;
		for(int i=0;i<array.size();i++)
		{
	//		cout<<"*Trying with "<<array[i]<<" Hash = "<<primeHash[array[i]]<<endl;
			returnValue oppositionTurn=playOptimally(1,primeHash[array[i]]);
			won|=!oppositionTurn.optimalValue;
	//		cout<<"*Got return probability as "<<oppositionTurn.probability<<endl;
	//		cout<<"My won probability = "<<(1-oppositionTurn.probability)/array.size()<<endl;
			
			probability+=(1-oppositionTurn.probability)/array.size();
		}	

		printf("%d %.4lf\n",won,probability);
	}
	return 0;
}
