#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<vector>
using namespace std;

class sieve
{
	private:
		vector<int> isprime;
		bool isSet(int n) const
		{
			return (isprime[n>>5]&(1<<(n&31)));
		}
		bool unSet(int n)
		{
			isprime[n>>5] &= ~(1<<(n&31));
		}
		
		
	public:
		sieve(int MAX)
		{
			isprime.resize(MAX/32+10);
		
		    int i,j;
		    isprime[0]=0xA28A28AC;
   			for(int i=1;i<=MAX/32+1;i+=3)
    		{
    			isprime[i]  =0x28A28A28;
        		isprime[i+1]=0x8A28A28A;
        		isprime[i+2]=0xA28A28A2;
    		}
    		for(i=5;i*i<=MAX;i+=2)
        		if(isSet(i))
            		for(j=i*i;j<=MAX;j+=i)
                		unSet(j);
		}
		
		bool isPrime(int n) const
		{
			return isSet(n);
		}		
};

template<class T> class segmentTree
{
	public:
		typedef T value_type;
	
	private:
		vector<value_type> tree;
		int sz;
		
		bool inRange(int queryLeft,int queryRight,int nodeLeft,int nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}
		
		int leftChild(int node)
		{
			return (node<<1)+1;
		}
		int rightChild(int node)
		{
			return (node<<1)+2;
		}
		
		void buildTree(vector<value_type> &A,int low,int high, int node)
		{
			
			if(low==high)
				tree[node]=A[low];
			else if(low>high)
				return;
			else
			{
				int leftTree=leftChild(node);
				int rightTree=rightChild(node);
				buildTree(A,low,(low+high)/2,leftTree);
				buildTree(A,(low+high)/2+1,high,rightTree);
				tree[node]=min(tree[leftTree],tree[rightTree]);
			}
		}
		
		value_type query(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node)
		{
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
				return tree[node];
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);
			
			
				int leftTree=leftChild(node);
				int rightTree=rightChild(node);
				if(leftInRange&&!rightInRange)
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftTree);

				else if(!leftInRange&&rightInRange)
					return query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightTree);
				
				else			
					return min(query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftTree),query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightTree));
			}
		}
		
		void update(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node,value_type value)
		{			
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;
			
			if(nodeLeft==nodeRight)
				tree[node]=value;
			else
			{
				int leftTree=leftChild(node);
				int rightTree=rightChild(node);
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftTree,value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightTree,value);
				
				tree[node]=min(tree[leftTree],tree[rightTree]);	
			}
		}
		
	public:
		
		void buildTree(vector<value_type> &A)
		{
			buildTree(A,0,A.size()-1,0);	
		}
		segmentTree()
		{
			sz=0;
		}
		
		segmentTree(int size,value_type initial=value_type())
		{
			assign(size,initial);
		}
		
		segmentTree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}
		
		void assign(int size,value_type initial=value_type())
		{
			clear();
			sz=size;
			tree.resize(4*size,initial);
		}
		
		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
		}
		
		void clear()
		{
			sz=0;
			tree.clear();
		}
		
		void update(int pos,const value_type &value)
		{
			update(pos,pos,0,sz-1,0,value);
		}
		
		value_type query(int low,int high)
		{
			return query(low,high,0,sz-1,0);
		}
		~segmentTree()
		{
			clear();
		}	
};

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
   }
    return sign*n;
}
/*
void printTime(double start,double end,string s){
	cout<<s<<" "<<((double)end-start)/CLK_TCK<<endl;
}
*/
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	
	//clock_t start,end;
	//start=clock();
	sieve S(1000000);
	vector<int> primes;
	primes.reserve(100000);
	
	for(int i=2;i<=1000000;i++)
		if(S.isPrime(i))
			primes.push_back(i);
	
	segmentTree<int> T(1000001);
	int t;
	cin>>t;
	vector<vector<int> > occurances;

	vector<int > at;
	//end=clock();
	//printTime(start,end,"Initial Settlement");
	while(t--){
	//	cout<<"--------------"<<endl;
		occurances.clear();
	
		at.clear();
		occurances.resize(1000001);
	
		at.resize(1000001);
		int n=readInt();
		vector<int> a(n);
		vector<vector<int> > factors(n);
		
		//start=clock();
		for(int i=0;i<n;i++){
			factors[i].reserve(20);
			a[i]=readInt();
			
			for(int j=0;a[i]!=1;j++){
				if(S.isPrime(a[i])){
					occurances[a[i]].push_back(i);
					factors[i].push_back(a[i]);
					break;
				}
				if(!(a[i]%primes[j]))
				{
					occurances[primes[j]].push_back(i);
					factors[i].push_back(primes[j]);
					while(!(a[i]%primes[j]))
						a[i]/=primes[j];
				}
			}	
		}
		//end=clock();
		//printTime(start,end,"Generating Factors");
		
		//start=clock();
		vector<int> secondOccurance(occurances.size(),INT_MAX);
		
		for(int i=0;i<occurances.size();i++)
		{
			at[i]=1;
			if(occurances[i].size()>=2)
				secondOccurance[i]=occurances[i][1];
		}
		T.buildTree(secondOccurance);
		//end=clock();
		//printTime(start,end,"Occurances update in tree");
		//start=clock();
		int longestStreak=min((int)a.size(),T.query(0,primes.size()-1));
		for(int i=1;i<a.size();i++){
			for(int j=0;j<factors[i].size();j++){
				int rank= factors[i][j];
				at[rank]++;
				if(at[rank]>=occurances[rank].size())
					T.update(rank,INT_MAX);
				else
					T.update(rank,occurances[rank][at[rank]]);
			}
			
			longestStreak=max(longestStreak,min((int)a.size(),T.query(0,occurances.size()-1))-i);		
		}	
		//end=clock();
		//printTime(start,end,"Computing Answer ");
		if(longestStreak<=1)
			cout<<-1;
		else
			cout<<longestStreak;
		cout<<endl;
	}
}
