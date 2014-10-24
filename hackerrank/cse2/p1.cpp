#include<iostream>
#include<vector>
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
			return read(b)-read(a-1);
		}
		void clear()
		{
			tree.clear();
		}
};

#define chunksize 100

inline int getPos(int pos){
	return (pos/chunksize)+1;
}
int main(){
//	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	vector<long long> l(n+2);
	for(int i=1;i<=n;i++)
		cin>>l[i];
		
	vector<long long> a(n+2);
	for(int i=1;i<=n;i++)
		cin>>a[i];

	BIT<long long> bit(n+1);
	for(int i=1;i<=n;i++)
		bit.increase(i,a[i]-l[i]);
		
	vector<long long> sqrtMin(n/chunksize+2,INT_MAX);

	for(int i=1;i<=n;i++)
		sqrtMin[getPos(i)]=min(sqrtMin[getPos(i)],bit.query(1,i));
	
	int q;
	cin>>q;
	while(q--){
		
		int type;
		cin>>type;
		if(type==1){
			long long c,d;
			cin>>c>>d;
			for(int i=getPos(c)+1;i<=getPos(n);i++)
				sqrtMin[i]+=d-a[c];
			
			bit.increase(c,d-a[c]);
			a[c]=d;
			int sqrtNumber=getPos(c);
			sqrtMin[sqrtNumber]=INT_MAX;
			for(int i=(sqrtNumber-1)*100;i<=n&&i<sqrtNumber*100;i++)
				sqrtMin[sqrtNumber]=min(sqrtMin[sqrtNumber],bit.query(1,i));
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
			while(e<n&&e%100){
				if(bit.query(1,e)<Lprefix){
					break;
				}
				e++;
			}
			while(e<=n){
				if(sqrtMin[getPos(e)]<Lprefix){
					bool isBreak=false;
					while(e<=n&&e%100){
						if(bit.query(1,e)<Lprefix){
							isBreak=true;
							break;
						}
						e++;
					}
					if(isBreak)
						break;			
				}
				else
					e+=100;	
			}
			if(e>n)
				e=n+1;
			cout<<e<<endl;;
		}
	}
}
