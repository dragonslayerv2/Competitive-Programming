#include<iostream>
using namespace std;

int GCD(int a, int b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double D;
		int U;
		int N;
		
		cin>>D>>U>>N;
		
		double last_cost=D*U;
		int pos=-1;
		int months=1;
		for(int i=0;i<N;i++)
		{
			int M;
			double R;
			int C;
			cin>>M>>R>>C;
			
			double present_cost=M*U*R+C;
				
			int lcm=		LCM(M,months);
			double mapped_present_cost=(lcm/M)*present_cost;
			double mapped_past_cost   =(lcm/months)*last_cost;
			if(mapped_present_cost<mapped_past_cost)
			{
				pos=i;
				months=M;
				last_cost=present_cost;
			} 
		}
		cout<<1+pos<<endl;
	}
}
