#include<iostream>
#include<windows.h>
#include<vector>
#include<climits>
#include<limits>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
	public:
		BIT(){}
		
		BIT(int n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type read(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		class operationOn0Exception{};
		void increase(size_t idx, const value_type &val)
		{ 
			if(idx==0)
				throw operationOn0Exception();
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		value_type query(size_t a,size_t b) const
		{
			if(a>b)
				return 0;
			return read(b);
		}
		void clear()
		{
			tree.clear();
		}
};

#define chunksize 500

#define getPos(pos) ((pos/chunksize)+1)

long long a[1000000],l[1000000],sqrtMin[1000000/chunksize+2];


int maxIterations=0;
#include<ctime>
int main(){
	freopen("test.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>l[i];
		
	for(int i=1;i<=n;i++)
		cin>>a[i];

	BIT<long long> bit(n+1);
	cerr<<n<<endl;
	
	for(int i=1;i<=n;i++)
		bit.increase(i,a[i]-l[i]);
		
	for(int i=0;i<1000000/chunksize+2;i++)
		sqrtMin[i]=numeric_limits<long long>::max();

	long long query=0;
	for(int i=1;i<=n;i++){
		query+=a[i]-l[i];
		sqrtMin[getPos(i)]=min(sqrtMin[getPos(i)],query);
	}
		
	 
	int q;
	cin>>q;
	cerr<<q<<endl;
	
	double time1=0,time2=0;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
	//		clock_t start=clock();
			long long c,d;
			cin>>c>>d;
			for(int i=getPos(c)+1;i<=getPos(n);i++)
				sqrtMin[i]+=d-a[c];
			
			bit.increase(c,d-a[c]);
	//cerr<<"Increasing "<<c<<" by"<<d-a[c]<<endl;
			a[c]=d;
			
	//Sleep(200);
			int sqrtNumber=getPos(c);
			sqrtMin[sqrtNumber]=numeric_limits<long long>::max();
			int i=(sqrtNumber-1)*chunksize;
			if(i==0)
				i++;
				
			
			long long query=bit.query(1,i-1);
			for(;i<=n&&i<sqrtNumber*chunksize;i++){
				query+=a[i]-l[i];
				sqrtMin[sqrtNumber]=min(sqrtMin[sqrtNumber],query);
			}
		//	clock_t end=clock();
		//	time1+=((double)end-start)/CLK_TCK;
		}
		else{
			int e;
			cin>>e;
			
			
			long long Lprefix;
			if(e==1)
				Lprefix=0;
			else
				Lprefix=bit.query(1,e-1);
			
			int ans=-1;
			bool isBreaked=false;
			while(e<=n&&e%chunksize){
				if(bit.query(1,e)<Lprefix){
					isBreaked=true;
					break;
				}
				e++;
			}
			
			if(!isBreaked){
				while(e<=n){
					if(sqrtMin[getPos(e)]<Lprefix){
						long long query=bit.query(1,e);
						while(e<=n){
							if(query<Lprefix){
								break;
							}
							e++;
							query+=a[e]-l[e];
						}
//						maxIterations=max(maxIterations,currentIterations);
//	clock_t end=clock();
//	time2+=((double)end-start)/CLK_TCK;
//	cerr<<endl;
						break;			
					}
					else
						e+=chunksize;	
				}
	
			}
	
			
			if(e>n)
				e=n+1;
			cout<<e<<endl;
		}
	}
//	cerr<<maxIterations<<endl;
//	cerr<<time1<<" "<<time2<<endl;
}
