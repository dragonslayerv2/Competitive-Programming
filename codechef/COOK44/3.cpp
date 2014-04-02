#include<iostream>
#include<map>
#include<vector>
using namespace std;


#define A vec(2,-1,-1)
#define B vec(-1,2,-1)
#define C vec(-1,-1,2)

struct vec
{
	int x,y,z;
	vec()
	{
		x=y=z=0;
	}
	vec(int X,int Y,int Z)
	{
		x=X;
		y=Y;
		z=Z;
	}	
	vec operator +(vec b)
	{
		vec temp=*this;
		temp.x+=b.x;
		temp.y+=b.y;
		temp.z+=b.z;
		return temp;
	}
	bool operator <(const vec b)const
	{
		if(x!=b.x)
			return x<b.x;
		else if(y!=b.y)
			return y<b.y;
		else
			return z<b.z;
	}
	
	bool operator ==(const vec b) const
	{
		return x==b.x&&y==b.y&&z==b.z;
	}
	
	
};

ostream &operator <<(ostream &stream, vec b)
{
	cout<<b.x<<" "<<b.y<<" "<<b.z;
}


inline long long nC2(long long x)
{
	return (x*(x-1))/2;
}
int main()
{
	string a;
	cin>>a;
	
	vector<vec> prefixSum(a.size());
	
	if(a[0]=='A')		prefixSum[0]=A;
	else if(a[0]=='B')	prefixSum[0]=B;
	else if(a[0]=='C')	prefixSum[0]=C;

	for(int i=1;i<a.size();i++)
	{
			if(a[i]=='A')		prefixSum[i]=A;
			else if(a[i]=='B')	prefixSum[i]=B;
			else if(a[i]=='C')	prefixSum[i]=C;
		
			prefixSum[i]=prefixSum[i]+prefixSum[i-1];
	}
	
	map<vec,long long> countMap;
	
	for(int i=0;i<prefixSum.size();i++)
		countMap[prefixSum[i]]++;
	
	long long sum=0;
	
	for(map<vec,long long>::iterator i=countMap.begin();i!=countMap.end();i++)
		if(i->first==vec(0,0,0))
			sum+=i->second+nC2(i->second);
		else
			sum+=nC2(i->second);
	cout<<sum;
}
