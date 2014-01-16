// check for 2^63 -1
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

vector<unsigned long long> Lpower;

inline unsigned long long gcf(unsigned long long a, unsigned long long b)
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

void calcpower(unsigned long long size)
{
	if(size==1)
		for(int i=0;i<=50;i++)
			Lpower.push_back(1);
	else
	{
		Lpower.push_back(1);
		for(int i=1;numeric_limits<unsigned long long>::max()/size>=Lpower[i-1];i++)
			Lpower.push_back(Lpower[i-1]*size);
		Lpower.push_back(numeric_limits<unsigned long long>::max());
	}
}

unsigned long long gamma(unsigned long long pos)
{
	if(Lpower[1]==1)
		return pos;
	else
	{
		if(pos==Lpower.size()-1)
			return Lpower[Lpower.size()-1];
		
		unsigned long long numerator1=(Lpower[pos]-1);
		unsigned long long numerator2=Lpower[1];
		unsigned long long denominator=Lpower[1]-1;
		
		unsigned long long GCD1=gcf(numerator1,denominator);
		numerator1/=GCD1;
		denominator/=GCD1;
		
		numerator2/=denominator;
		return numerator1*numerator2;
	
	}
}


int main()
{
	freopen("output1.txt","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		Lpower.clear();
		string L;
		unsigned long long N;
		cin>>L>>N;
		
		calcpower(L.size());
		
		
		size_t j;
		for( j=1;;j++)
			if(gamma(j-1)>=N)
				break;
		j--;
		N-=gamma(j-1)+1;
		
		string output="";
		for(size_t k=1;k<=j;k++)
		{
		//	cout<<"Adding character"<<L[(N%L.size())]<<endl;
			output=L[(N%L.size())]+output;
			N/=L.size();
		}
		cout<<"Case #"<<i<<": "<<output<<endl;
	}
}
