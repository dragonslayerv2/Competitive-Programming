#include<stdio.h>

#include<cstdio>
#include<vector>
#include<list>
using namespace std;


#include<stdio.h>

#include<cstdio>
#include<vector>
#include<list>
using namespace std;


long long power(long long n,long long m,long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=power(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


long long sump1[4*100010], sump2[4*100010],Ap1[4*100010],Ap2[4*100010],Dp1[4*100010],Dp2[4*100010];
bool isLazy[4*100010];

long long Rpower[2][100100];

class segmentTree
{
	long long p1,p2,R;
	int sz;
	long long inversePower[2];
	void buildTree(vector<int> &A,size_t low,size_t high, size_t node)
	{
		if(low==high)
		{
			sump1[node]=A[low]%p1;
			sump2[node]=A[low]%p2;
		}
			
		else if(low>high)
			return;
		else
		{
			buildTree(A,low,(low+high)/2,leftChild(node));
			buildTree(A,(low+high)/2+1,high,rightChild(node));
			
			sump1[node]=sump1[leftChild(node)]+sump1[rightChild(node)];
			sump1[node]%=p1;
			sump2[node]=sump2[leftChild(node)]+sump2[rightChild(node)];
			sump2[node]%=p2;
		}
	}

	inline bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) const
	{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
	}
		
	inline int leftChild(int node)
	{
			return (node<<1)+1;
	}
	
	inline int rightChild(int node)
	{
			return (node<<1)+2;
	}
	
	

		
long long sumofAGP(long long A,long long D,long long R,long long n,long long MOD)
	{
		A%=MOD;
		D%=MOD;
		R%=MOD;
		
		if(R==1)
		{
			long long ans1=(((A*n)%MOD)+((((n*(n-1))/2)%MOD)*D)%MOD)%MOD;
			return ans1;
		}
		else
		{
			long long ans1=A*(1-R);
			ans1%=MOD;
			ans1+=MOD;
			ans1%=MOD;
			
			long long ans2=(D*((Rpower[MOD==p2][n]-R+MOD)%MOD))%MOD;
			ans2+=MOD;
			ans2%=MOD;
			
			long long ans3= (((A+(n-1)*D)%MOD)*((Rpower[MOD==p2][n]*(MOD+1-R)%MOD)%MOD))%MOD;
			
			ans1-=(ans2+ans3)%MOD;
			ans1+=MOD;
			ans1%=MOD;
			
			
			ans1*=inversePower[MOD==p2];
			ans1%=MOD;
			return ans1;
		}
	}

	
	inline void pushLazy(int nodeLeft,int nodeRight,int node)
	{
		if(isLazy[node])
		{
			sump1[node]+=sumofAGP(Ap1[node],Dp1[node],R,nodeRight-nodeLeft+1,p1);
			if(nodeLeft==nodeRight)
			{
				sump2[node]+=sumofAGP(Ap2[node],Dp2[node],R,nodeRight-nodeLeft+1,p2);
				sump2[node]%=p2;
			}
			
			sump1[node]%=p1;
			
			if(nodeLeft!=nodeRight)
			{
				isLazy[leftChild(node)]	=true;
				isLazy[rightChild(node)]=true;
				
				Ap1[leftChild(node)]	+=Ap1[node];
				
				Ap1[rightChild(node)]	+=((Ap1[node]+Dp1[node]*(((nodeLeft+nodeRight)/2+1)-nodeLeft))%p1)*Rpower[0][((nodeLeft+nodeRight)/2+1)-nodeLeft];
				
				Ap2[leftChild(node)]	+=Ap2[node];
				Ap2[rightChild(node)]	+=((Ap2[node]+Dp2[node]*(((nodeLeft+nodeRight)/2+1)-nodeLeft))%p2)*Rpower[1][((nodeLeft+nodeRight)/2+1)-nodeLeft];
				
				Dp1[leftChild(node)]	+=Dp1[node];
				Dp1[rightChild(node)]	+=Dp1[node]*Rpower[0][((nodeLeft+nodeRight)/2+1)-nodeLeft];
				
				Dp2[leftChild(node)]	+=Dp2[node];
				Dp2[rightChild(node)]	+=Dp2[node]*Rpower[1][((nodeLeft+nodeRight)/2+1)-nodeLeft];
				
				Ap1[leftChild(node)]%=p1;
				Ap1[rightChild(node)]%=p1;
				
				Ap2[leftChild(node)]%=p2;
				Ap2[rightChild(node)]%=p2;
				
				Dp1[leftChild(node)]%=p1;
				Dp1[rightChild(node)]%=p1;
				
				Dp2[leftChild(node)]%=p2;
				Dp2[rightChild(node)]%=p2;
			}
			Ap1[node]=Ap2[node]=Dp1[node]=Dp2[node]=0;
			isLazy[node]=false;
			
		}
	}
	
	long long query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
	{
		 pushLazy(nodeLeft,nodeRight,node);
		 if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			 return 0;
		 	
		 if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		 	return sump1[node];
			
		 else
		 	return (query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node))+query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)))%p1;
	}  
	
	void updateSummation(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,long long A,long long D)
	{
		if(nodeLeft>nodeRight)
			return;	
		pushLazy(nodeLeft,nodeRight,node);
		if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			return;
		
		if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		{
			isLazy[node]=true;
			
			Ap1[node]+=((A+D*(nodeLeft-queryLeft))%p1)*Rpower[0][nodeLeft-queryLeft];
			Ap2[node]+=((A+D*(nodeLeft-queryLeft))%p2)*Rpower[1][nodeLeft-queryLeft];
			
			Dp1[node]+=D*Rpower[0][nodeLeft-queryLeft];
			Dp2[node]+=D*Rpower[1][nodeLeft-queryLeft];
			
			Ap1[node]%=p1;
			Dp1[node]%=p1;
			
			Ap2[node]%=p2;
			Dp2[node]%=p2;
			
			pushLazy(nodeLeft,nodeRight,node);
		}
		else
		{
			updateSummation(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),A,D);
			updateSummation(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),A,D);
			sump1[node]=(sump1[leftChild(node)]+sump1[rightChild(node)])%p1;
			sump2[node]=(sump2[leftChild(node)]+sump2[rightChild(node)])%p2;
		}
	}
	void updateG(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,long long G)
	{
		if(nodeLeft>nodeRight)
		{
			return;
		}
		pushLazy(nodeLeft,nodeRight,node);
		if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			return;
			
		if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		{
			sump2[node]=power(sump2[node],G,p2);
			sump1[node]=sump2[node]%p1;
		}
		else
		{
			updateG(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),G);
			updateG(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),G);
			sump1[node]=(sump1[leftChild(node)]+sump1[rightChild(node)])%p1;
			sump2[node]=(sump2[leftChild(node)]+sump2[rightChild(node)])%p2;
		}
	}

	public:
		segmentTree()
		{
			sz=0;
		}
		
		segmentTree(vector<int> &a,long long r,long long P1,long long P2)
		{
			sz=a.size();
			R=r;
			p1=P1;
			p2=P2;
			
			inversePower[0]=power(((1-R)*(1-R))%p1,p1-2,p1);
			inversePower[1]=power(((1-R)*(1-R))%p2,p2-2,p2);
			
			for(int i=0;i<4*sz;i++)
			{
				isLazy[i]=false;
				Ap1[i]=Ap2[i]=Dp1[i]=Dp2[i]=sump1[i]=sump2[i]=0;
			}
			buildTree(a,0,sz-1,0);
		}
		
		void updateG(int queryLeft,int queryRight,int G)
		{
			updateG(queryLeft,queryRight,0,sz-1,0,G);
		}
		
		void updateSummation(int queryLeft,int queryRight,int A,int D)
		{
			updateSummation(queryLeft,queryRight,0,sz-1,0,A,D);
		}
		
		long long query(int queryLeft,int queryRight)
		{
			return query(queryLeft,queryRight,0,sz-1,0);
		}
		
}; 


  
  #include<stdio.h>
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif
	
inline long long readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}

int main()
{   
	int t;
	t=readlong();
	while(t--)
	{
		long long n,q,r,p1,p2;
		n=readlong();
		q=readlong();
		r=readlong();
		p1=readlong();
		p2=readlong();

		vector<int> array(n);
		for(int i=0;i<n;i++)
			array[i]=readlong();
		
		Rpower[0][0]=1%p1;
		Rpower[1][0]=1%p2;
		
		for(int i=1;i<=n;i++)
		{
			Rpower[0][i]=Rpower[0][i-1]*(r)%p1;
			Rpower[1][i]=Rpower[1][i-1]*(r)%p2;
			
			Rpower[0][i]%=p1;
			Rpower[1][i]%=p2;
		}
		
		segmentTree ST(array,r,p1,p2);
		while(q--)
		{
			int type;
			type=readlong();
			if(type==0)
			{
				int s,d,x,y;
				s=readlong();
				d=readlong();
				x=readlong();
				y=readlong();
				x--;
				y--;
				ST.updateSummation(x,y,s,d);
			}
			else if(type==1)
			{
				
				int x,g;
				x=readlong();
				g=readlong();
				x--;
				ST.updateG(x,x,g);
			}
			else if(type==2)
			{
				int x,y;
				x=readlong();
				y=readlong();
				x--;
				y--;
				printf("%lld\n",ST.query(x,y)%p1);
			}
		}
	}
}
