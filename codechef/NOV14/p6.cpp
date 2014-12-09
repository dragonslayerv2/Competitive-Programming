#include<iostream>
#include<vector>
using namespace std;

pair<int,int> factors[100005][6];
int factorCount[100005];
long long primeCount[100005];
int tree[20][400005];
int n,m;

long long p(long long n,long long m,int MOD)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


template<class T> class winner_tree
{
	int size;
	public:
		winner_tree()
		{
			int array_size=n+1;
			size=0;
			while(array_size)
			{
				size++;
				array_size>>=1;
			}
			size++;
			for(int i=0;i<size;i++)
				for(int j=0;j<=(1<<(size-1));j++){
					tree[i][j]=1;
				}
		}

		void update(int pos,T value)
		{
			tree[0][pos]=value%m;
			int current_level=1;
			while(current_level<size)
			{
				pos/=2;
				tree[current_level][pos]=1;
				if(2*pos<n+1)
					tree[current_level][pos]=tree[current_level-1][2*pos];
				
				if(2*pos+1<n+1){
					tree[current_level][pos]=((long long)tree[current_level-1][2*pos+1]*tree[current_level][pos])%m;
				}
				current_level++;
			}
		}
		T query()
		{
			return tree[size-1][0];
		}
};

#include<cstdio>
int main(){
	ios::sync_with_stdio(false);
	for(int i=2;i<=100000;i++)
	{
		int iCopy=i;
		for(int j=2;j*j<=i;j++){
			if(!(iCopy%j)){
				factors[i][factorCount[i]].first=j;
				while(!(iCopy%j)){
					factors[i][factorCount[i]].second++;
					iCopy/=j;
				}
				factorCount[i]++;
			}
		}
		if(iCopy!=1){
			factors[i][factorCount[i]].first=iCopy;
			factors[i][factorCount[i]].second=1;
			factorCount[i]++;
		}
	}

	int t;
	cin>>t;
	
	while(t--){
		int q;
		cin>>n>>m>>q;
		
		for(int i=0;i<=n;i++)
			primeCount[i]=0;
		
		winner_tree<long long> winTree;
		vector<int> solutions(n+1);
		for(int r=1;r<=n-r;r++)
		{
			int num=n-r+1;
			int den=r;
			for(int i=0;i<factorCount[num];i++){
				primeCount[factors[num][i].first]+=num*factors[num][i].second;
				winTree.update(factors[num][i].first,p(factors[num][i].first,primeCount[factors[num][i].first],m));
			}
				
			
			for(int i=0;i<factorCount[den];i++){
				primeCount[factors[den][i].first]-=den*factors[den][i].second;
				winTree.update(factors[den][i].first,p(factors[den][i].first,primeCount[factors[den][i].first],m));
			}
			solutions[r]=winTree.query();			
		}	
		while(q--){
			int r;
			cin>>r;
			cout<<solutions[min(r,n-r)]<<endl;
		}
		
	}	
}
