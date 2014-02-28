#include<iostream>
#include<climits>
#include<map>
using namespace std;

map<pair<bool,pair<int,int> > , long long> DP;


long long solve(string &s,int pos,int count,bool insertAllowed)
{
	if(pos==s.size())
	{
		if(count<=0)
			return INT_MAX;
		else
			return count-1;
	}
	
	if(DP.find(make_pair(insertAllowed,make_pair(pos,count)))==DP.end())
	{	
		long long corrections;
		if(count<=0&&pos>0)
			corrections=INT_MAX;
		else
		{
			if(s[pos]=='x')
				corrections=solve(s,pos+1,count+1,true);
			else
				corrections=solve(s,pos+1,count-1,true);
	
			// replace
	
			if(s[pos]=='x')
				corrections=min(corrections,1+solve(s,pos+1,count-1,true));
			else
				corrections=min(corrections,1+solve(s,pos+1,count+1,true));
			
			//delete
			corrections=min(corrections,1+solve(s,pos+1,count,true));
			
			//insert
			if(insertAllowed)
			{
				for(int i=1;i<4;i++)
				{
					if(s[pos]=='x')
					{
						corrections=min(corrections,i+solve(s,pos,count+1+i,false)); // x add
						corrections=min(corrections,i+solve(s,pos,count+1-i,false)); //* add
					}
					else
					{
						corrections=min(corrections,i+solve(s,pos,count-1-i,false));						
						corrections=min(corrections,i+solve(s,pos,count-1+i,false));
					}
				}
			}
		}
		DP[make_pair(insertAllowed,make_pair(pos,count))]=corrections;	
	}
	return DP[make_pair(insertAllowed,make_pair(pos,count))];
}
int main()
{
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		DP.clear();
		char a[1000];
		cin.getline(a,sizeof(a));
		string s=a;
		if(s.size()==0)
			cout<<1<<endl;
		else
			cout<<solve(s,0,0,true)<<endl;
	}
}
