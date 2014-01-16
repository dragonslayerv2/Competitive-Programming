#include<iostream>
#include<map>
#include<vector>
using namespace std;

inline int GCF(long long a, long long b)
{
   long long temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

map<long long,int> C;


void initmap()
{
	vector<long long> nCn2;
	nCn2.push_back(1);
	while(nCn2.back()<=1000000000000000000LL)
	{
		if(nCn2.size()%2)
		{
			nCn2.push_back(nCn2.back()*2);
		}
		else
		{
			
			long long n=nCn2.size();
			
			long long den=(n+2)/2;
			long long num=nCn2.back();
			long long gcf=GCF(num,den);
			num/=gcf;
			den/=gcf;
			num*=(n+1)/den;
			nCn2.push_back(num);
		}
		
	}
	for(int i=0;i<nCn2.size();i++)
	{
		C[nCn2[i]]=i+1;
	}
}

int main()
{
	initmap();
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		int ans;
		if(C.find(n)==C.end())
		{
			C[n]=-1;
			auto i=C.find(n);
			i++;
			ans=i->second;
			C.erase(n);
		}
		else
		{
			ans=C[n];
		}
		cout<<ans<<endl;	
	}
}
