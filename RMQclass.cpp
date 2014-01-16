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


class isSet
{
	vector<int> count;
	vector<bool> isset;
	public:
		isSet(int n):isset(n),count(n){}
		
		void query(int L,int R)
		{
			count[L]++;
			count[R]--;
		}
		
		void process()
		{
			int counts=0;
			int n=isset.size();
			for(int i=0;i<n;i++)
			{
				if(count[i]>0)
					counts+=count[i];
				if(counts)
					isset[i]=true;
				if(count[i]<0)
					counts+=count[i];
			}
			
		}
		
		bool query(int pos)
		{
			return isset[pos];
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
	isSet burn(n);
	
	
	int q;
	cin>>q;
	long long MIN=numeric_limits<long long>::max();
	
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		burn.query(l,r);
		MIN=min(MIN,RMQ.query(l,r));
	}
	
	burn.process();
	
	double time=0;
	
	for(int i=0;i<n;i++)
	{
		double t;
		if(burn.query(i))	
			t=MIN+(double)(t-MIN)/2;
		else
		{
			t=MIN+arr[i];
				
		}
		
		if(t>time)
			time=t;
	}
	
	cout<<fixed;
	cout.precision(1);
	cout<<time;
	
	return 0;
}


