#include<iostream>
#include<limits>
#include<cmath>
#include<vector>
using namespace std;


template<class T> class rmq
{
	private:
		vector<vector<T> > RMQ;
	public:
		rmq(vector<T> &arr)
		{
	//------------------------------------------------
			int n=arr.size();
			RMQ.resize(n);
			int len=1+ceil(log(arr.size()));
			for(int i=0;i<n;i++)
			{
				RMQ[i].resize(len);
			}
			
			
	//----------------------------------------------
			for(int i=0;i<n;i++)
			RMQ[i][0]=arr[i];
	
			for(int j=1,p=2;p<=n;j++,p*=2)
			{
				for(int i=0;i+p<=n;i++)
				RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+p/2][j-1]);
			}
		}
		
		T query(int i,int j)
		{
			int gap=j-i+1;
			int p=-1;
			int po=1;
	
			while(gap) // calculates 2^(floor(logk)) and floor(logk)
			{
				gap=gap>>1;
				p++;
				po<<=1;
			}
			po>>=1;
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
};

template<class T> class rmaxq
{
	private:
		vector<vector<T> > RMQ;
	public:
		rmaxq(vector<T> &arr)
		{
	//------------------------------------------------
			int n=arr.size();
			RMQ.resize(n);
			int len=1+ceil(log(arr.size()));
			for(int i=0;i<n;i++)
			{
				RMQ[i].resize(len);
			}
			
			
	//----------------------------------------------
			for(int i=0;i<n;i++)
			RMQ[i][0]=arr[i];
	
			for(int j=1,p=2;p<=n;j++,p*=2)
			{
				for(int i=0;i+p<=n;i++)
				RMQ[i][j]=max(RMQ[i][j-1],RMQ[i+p/2][j-1]);
			}
		}
		
		T query(int i,int j)
		{
			int gap=j-i+1;
			int p=-1;
			int po=1;
	
			while(gap) // calculates 2^(floor(logk)) and floor(logk)
			{
				gap=gap>>1;
				p++;
				po<<=1;
			}
			po>>=1;
			return max(RMQ[i][p],RMQ[j-po+1][p]);
		}
};


int main()
{

	
	int n;
	cin>>n;
	
	vector<long long> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	rmq<long long> RMQ(arr);
	rmaxq<long long> RMAXQ(arr);
	
	int q;
	cin>>q;
	
	
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		
		long long MIN=RMQ.query(l,r);
		
		long long maxburn=RMAXQ.query(l,r);
		long long maxunburn=0;
		
		if(l>0)
		{
			maxunburn=RMAXQ.query(0,l-1);
		}
		
		if(r<n-1)
		{
			maxunburn=max(maxunburn,RMAXQ.query(r+1,n-1));
		}
	
		
		double time=max(MIN+(double)(maxburn-MIN)/2,(double)MIN+maxunburn);
		cout<<fixed;
		cout.precision(1);
		cout<<time<<endl;
	}
	return 0;

}


