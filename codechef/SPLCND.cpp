#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


typedef pair<bool,long long> entry;
vector<vector<entry> > lookuptable;

long long sum(vector<int> &array)
{
	long long S=0;
	for(int &i:array)
	{
		S+=i;
	}
	return S;
}

long long total_bugs=0;

long long subsetsum(vector<int> &bugs,long long pumba,long long timon=0,int pos=0)
{
	if(pos==bugs.size())
	{
		if(timon==pumba&&pumba!=0)
			return total_bugs-pumba;
		return -1;
	}
	else
	{
		if(lookuptable[pos][timon].first==false)
		{
			lookuptable[pos][timon].first=true;
			lookuptable[pos][timon].second=max(subsetsum(bugs,pumba-bugs[pos],timon^bugs[pos],pos+1),subsetsum(bugs,pumba,timon,pos+1));
		}
		
		return lookuptable[pos][timon].second;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> bugs(n);
		long long x=0;
		for(int i=0;i<n;i++)
		{	
			cin>>bugs[i];
			x^=bugs[i];
		}
		if(!x)
		{
		 
		 total_bugs=sum(bugs);
		 int MAX=*max_element(bugs.begin(),bugs.end());
		 long long size=1;
		 while(MAX)
		 {
		 	size=size<<1;
		 	size|=1;
		 	MAX>>=1;
		 }
		 size>>=1;
		// cout<<size;
		 lookuptable.assign(n,vector<entry>(size+1));
		 long long ans=subsetsum(bugs,total_bugs);
		
		 if(ans==-1)
		 	cout<<"NO"<<endl;
		  else
			cout<<ans<<endl;		
		}
		else
			cout<<"NO"<<endl;
	}
}
