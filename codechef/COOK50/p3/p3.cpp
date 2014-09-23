#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
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


int main(){
	//freopen("in.txt","r",stdin);
	sieve S(1000000);
	vector<int> primes;
	primes.reserve(100000);
	for(int i=2;i<=1000000;i++)
		if(S.isPrime(i)){
			primes.push_back(i);
		}
	
	vector<vector<int> > factors(1000001);
	for(int i=2;i<factors.size();i++){
		int currentNumber=i;
		int iterations=sqrt(currentNumber);
		for(int j=0;j<=iterations;j++){
			if(!(currentNumber%primes[j])){
				factors[i].push_back(primes[j]);
				while(!(currentNumber%primes[j]))
					currentNumber/=primes[j];
			}
		}
		if(currentNumber!=1)
			factors[i].push_back(currentNumber);
	}
	
	int t=readInt();
	vector<int> lastOccurances;
	lastOccurances.resize(1000001);
	
	while(t--){
		for(int i=0;i<primes.size();i++)
			lastOccurances[primes[i]]=lastOccurances.size()-1;			
		
		int n=readInt();
		vector<int> conflicting(n,INT_MAX);			
		
		for(int last=0;last<n;last++){
			int currentNumber=readInt();
			if(last!=0){
				for(int i=0;i<factors[currentNumber].size();i++)
					if(lastOccurances[factors[currentNumber][i]]>-1)
						conflicting[lastOccurances[factors[currentNumber][i]]]=min(last-1,conflicting[lastOccurances[factors[currentNumber][i]]]);
			}
			for(int i=0;i<factors[currentNumber].size();i++)
				lastOccurances[factors[currentNumber][i]]=last;
		}
		
		int longestStreak=-1;
		segmentTree<int> T(lastOccurances);
		for(int i=0;i<n;i++)
			longestStreak=max(longestStreak,T.query(i,lastOccurances.size())-i+1);
		
		if(longestStreak<=1)
			cout<<-1;
		else
			cout<<longestStreak;
		cout<<endl;
	}
}
