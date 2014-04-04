#include<iostream>
#include<vector>
using namespace std;


int abs(int x)
{
	if(x<0)
		return -1*x;
	else
		return x;
}

int main()
{
	string a,b;
	cin>>a>>b;
	long long spaceWeight;
	cin>>spaceWeight;
	
	vector<vector<long long> > solution(a.size()+1,vector<long long>(b.size()+1));
	
	for(int aPos=a.size();aPos>=0;aPos--)
		for(int bPos=b.size();bPos>=0;bPos--)
		{
			if(aPos==a.size())
				solution[aPos][bPos]=(b.size()-bPos)*spaceWeight;
			else if(bPos==b.size())
				solution[aPos][bPos]=(a.size()-aPos)*spaceWeight;
			
			else
			{
				long long noSpaceAdded=abs(a[aPos]-b[bPos])+solution[aPos+1][bPos+1];
				long long aSpaceAdded =spaceWeight+solution[aPos+1][bPos];
				long long bSpaceAdded =spaceWeight+solution[aPos][bPos+1];
				solution[aPos][bPos]=min(noSpaceAdded,min(aSpaceAdded,bSpaceAdded));
			}
			
		}
		
	cout<<solution[0][0];
}
