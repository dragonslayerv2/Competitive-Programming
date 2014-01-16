#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

typedef map<int,map<int,map<int,double> > > MAP;

int Total,k1;
class hash
{
	private:
		double data[1001][110][300];
		bool ispresent[1001][101][300];
	public:
	
	double find(double pi,int k,int G)
	{
		if((Total-G)-(k1-k)>=k1)
			return 0;
		if(G<k)
			return 0.0;
		if(k==0)
			return 1;
		
		/*if((int)(pi*1000)>=1000)
			return 1.0;
		if((int)(pi*1000)<=0)
			return 0.0;
		*/
		if(ispresent[int(pi*1000)][k][G])
			return data[int(pi*1000)][k][G];
		else
			return 100.0;
	}
	void push(double pi,int k,int G,double value)
	{
		ispresent[int(pi*1000)][k][G]=true;
		data[int(pi*1000)][k][G]=value;
	}
	void reset(int k)
	{
		for(int i=0;i<=1000;i++)
		{
			for(int j=0;j<=k+1;j++)
			{
				for(int l=0;l<=2*k;l++)
					ispresent[i][j][l]=false;
			}
		}
	}
}HASH;

double ps,pr,PI,pu,pw,pd,pl;
double solve(double pi,int k,int G)
{
	if((int)(pi*1000)>=1000)
			pi= 1.0;
		if((int)(pi*1000)<=0)
			pi= 0.0;
	
	if(HASH.find(pi,k,G)<20.0)
	{
		return HASH.find(pi,k,G);
	}
	else
	{
	//	cout<<pi<<" "<<k<<" "<<G<<endl;
	
		
	
		double winprob=pi*ps+(1.0-pi)*pr;
		double solution=winprob*(pw*solve(pi+pu,k-1,G-1)+(1.0-pw)*solve(pi,k-1,G-1))+(1-winprob)*(pl*solve(pi-pd,k,G-1)+(1-pl)*solve(pi,k,G-1));
		HASH.push(pi,k,G,solution);
		return solution;
	}
}

int main()
{
	//freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		
		int k;
		cin>>k;
		HASH.reset(k);		
		cin>>ps>>pr>>PI>>pu>>pw>>pd>>pl;
		Total=2*k-1;
		k1=k;
		cout<<"Case #"<<T<<": ";
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<solve(PI,k,2*k-1)<<endl;
		cin.get();
	}
}
