#include<iostream>
#include<limits>
#include<cmath>
#include<vector>
using namespace std;


template<class T> class rmq
{
	private:
		vector<vector<T> > RMQ;
		vector<int> pow2;
		void generatePow2(int n){
			int pow=0;
			while((1<<pow)<=n){
				pow2[1<<pow]=pow;
				pow++;
			}
			for(int i=1;i<=n;i++){
				if(!pow2[i])
					pow2[i]=pow2[i-1];
			}
		}

	public:
		rmq(vector<T> &arr)
		{
			pow2.resize(arr.size()+10);
			generatePow2(arr.size());
			int n=arr.size();
			RMQ.resize(n);
			int len=1+ceil(log(arr.size()));
			for(int i=0;i<n;i++)
			{
				RMQ[i].resize(len);
			}
			
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
			int p=pow2[gap];
			int po=(1<<p);
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
};


