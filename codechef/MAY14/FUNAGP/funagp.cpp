#include<stdio.h>
//#include<iostream>
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


class segmentTree
{
	int p1,p2,R;
	vector<long long> sump1;
	vector<long long> sump2;
	vector<long long> Ap1,Dp1,Ap2,Dp2;
	vector<bool> isLazy;
	int sz;
	
	
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

	bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) const
	{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
	}
		
	size_t leftChild(size_t node)
	{
			return (node<<1)+1;
	}
	
	size_t rightChild(size_t node)
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
			
			long long ans2=(D*((power(R,n,MOD)-R+MOD)%MOD))%MOD;
			ans2+=MOD;
			ans2%=MOD;
			
			long long ans3= (((A+(n-1)*D)%MOD)*((power(R,n,MOD)*(MOD+1-R)%MOD)%MOD))%MOD;
			
			ans1-=(ans2+ans3)%MOD;
			ans1+=MOD;
			ans1%=MOD;
			
			ans1*=power(((1-R)*(1-R))%MOD,MOD-2,MOD);
			ans1%=MOD;
			return ans1;
		}
	}
	
	
	void pushLazy(int nodeLeft,int nodeRight,int node)
	{
	//	cerr<<"At lazy Propogator for node "<<nodeLeft<<" "<<nodeRight<<endl;
		if(isLazy[node])
		{
	//		cerr<<"Yee, I have a lazy value"<<endl;
	//		cerr<<"Ap1 = "<<Ap1[node]<<" Ap2 = "<<Ap2[node]<<endl;
	//		cerr<<"Dp1 = "<<Dp1[node]<<" Dp2 = "<<Dp2[node]<<endl;
	//		cerr<<"Adding "<<sumofAGP(Ap1[node],Dp1[node],R,nodeRight-nodeLeft+1,p1)<<" to sump1";
	//		cerr<<"Adding "<<sumofAGP(Ap2[node],Dp2[node],R,nodeRight-nodeLeft+1,p2)<<" to sump2";
			sump1[node]+=sumofAGP(Ap1[node],Dp1[node],R,nodeRight-nodeLeft+1,p1);
			sump2[node]+=sumofAGP(Ap2[node],Dp2[node],R,nodeRight-nodeLeft+1,p2);
			sump1[node]%=p1;
			sump2[node]%=p2;
	//		cout<<"New values = "<<sump1[node]<<" "<<sump2[node]<<endl;
			
			if(nodeLeft!=nodeRight)
			{
	//			cerr<<"Pushing Values to left and right Childs"<<endl;
				isLazy[leftChild(node)]	=true;
				isLazy[rightChild(node)]=true;
				
				Ap1[leftChild(node)]	+=Ap1[node];
				
				Ap1[rightChild(node)]	+=((Ap1[node]+Dp1[node]*(((nodeLeft+nodeRight)/2+1)-nodeLeft))%p1)*power(R,((nodeLeft+nodeRight)/2+1)-nodeLeft,p1);
				
				Ap2[leftChild(node)]	+=Ap2[node];
				Ap2[rightChild(node)]	+=((Ap2[node]+Dp2[node]*(((nodeLeft+nodeRight)/2+1)-nodeLeft))%p2)*power(R,((nodeLeft+nodeRight)/2+1)-nodeLeft,p2);
				
				Dp1[leftChild(node)]	+=Dp1[node];
				Dp1[rightChild(node)]	+=Dp1[node]*power(R,((nodeLeft+nodeRight)/2+1)-nodeLeft,p1);
				
				Dp2[leftChild(node)]	+=Dp2[node];
				Dp2[rightChild(node)]	+=Dp2[node]*power(R,((nodeLeft+nodeRight)/2+1)-nodeLeft,p2);
				
				Ap1[leftChild(node)]%=p1;
				Ap1[rightChild(node)]%=p1;
				
				Ap2[leftChild(node)]%=p2;
				Ap2[rightChild(node)]%=p2;
				
				Dp1[leftChild(node)]%=p1;
				Dp1[rightChild(node)]%=p1;
				
				Dp2[leftChild(node)]%=p2;
				Dp2[rightChild(node)]%=p2;
			}
	//		cerr<<"Resetting my lazy values"<<endl;
			Ap1[node]=Ap2[node]=Dp1[node]=Dp2[node]=0;
			isLazy[node]=false;
			
		}
	}
	
	long long query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
	{
//		cerr<<"At node "<<node<<" nodeLeft = "<<nodeLeft<<" nodeRight = "<<nodeRight<<endl;
//		cerr<<"Calling lazy"<<endl;
		 pushLazy(nodeLeft,nodeRight,node);
//		 cerr<<"Lazy up";
		 if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
		 {
//		 	cerr<<"Not in range"<<endl;
			 return 0;
		 	
		 }
		 	
		 if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		 {
//		 	cerr<<"Completely inside returngin "<<sump1[node]<<endl;
		 	return sump1[node];
		 }
			
		 else
		 	return (query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node))+query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)))%p1;
	}  
	
	void updateSummation(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,long long A,long long D)
	{
	//	cerr<<"At node "<<node<<" nodeLeft = "<<nodeLeft<<" nodeRight = "<<nodeRight<<endl;
		if(nodeLeft>nodeRight)
		{
	//		cerr<<"Invalid Node"<<"Returning"<<endl;
			return;	
		}
		
	//	cerr<<"Calling Lazy Propogator"<<endl;
		pushLazy(nodeLeft,nodeRight,node);
	//	cerr<<"Lazy propogation done successfully"<<endl;
		if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			return;
		
		if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		{
	//		cerr<<"Thios node is completely under query"<<endl;
			
			isLazy[node]=true;
			
			Ap1[node]+=((A+D*(nodeLeft-queryLeft))%p1)*power(R,nodeLeft-queryLeft,p1);
			Ap2[node]+=((A+D*(nodeLeft-queryLeft))%p2)*power(R,nodeLeft-queryLeft,p2);
			
			Dp1[node]+=D*power(R,nodeLeft-queryLeft,p1);
			Dp2[node]+=D*power(R,nodeLeft-queryLeft,p2);
			
			Ap1[node]%=p1;
			Dp1[node]%=p1;
			
			Ap2[node]%=p2;
			Dp2[node]%=p2;
			
	//		cerr<<"Setting AP1 = "<<Ap1[node]<<endl;
	//		cerr<<"Setting AP2 = "<<Ap2[node]<<endl;
	//		cerr<<"Setting Dp1 = "<<Dp1[node]<<endl;
	//		cerr<<"Setting Dp2 = "<<Dp2[node]<<endl;
			pushLazy(nodeLeft,nodeRight,node);
		}
		else
		{
			updateSummation(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),A,D);
			updateSummation(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),A,D);
			sump1[node]=(sump1[leftChild(node)]+sump1[rightChild(node)])%p1;
			sump2[node]=(sump2[leftChild(node)]+sump2[rightChild(node)])%p2;
	//		cout<<"Updating internal node "<<node<<" New values = "<<sump1[node]<<" "<<sump2[node]<<endl;
		}
	}
	void updateG(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,long long G)
	{
	//	cerr<<"At "<<nodeLeft<<" "<<nodeRight<<" "<<endl;
		
		if(nodeLeft>nodeRight)
		{
	//		cerr<<"Invalid Node"<<endl;
			return;
		}
	//	cerr<<"Pushing lazy"<<endl;
		pushLazy(nodeLeft,nodeRight,node);
	//	cerr<<"Lazy up"<<endl;
		if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			return;
			
		if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		{
			
			sump2[node]=power(sump2[node],G,p2);
			sump1[node]=sump2[node]%p1;
	//		cerr<<"At leaf node. Updating sump1 and sum p2 to "<<sump2[node]<<" "<<sump1[node]<<endl;
		}
		else
		{
			updateG(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),G);
			updateG(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),G);
			sump1[node]=(sump1[leftChild(node)]+sump1[rightChild(node)])%p1;
			sump2[node]=(sump2[leftChild(node)]+sump2[rightChild(node)])%p2;
	//		cout<<"Updating internal node "<<node<<" New values = "<<sump1[node]<<" "<<sump2[node]<<endl;
		}
	}

	public:
		segmentTree()
		{
			sz=0;
		}
		
		segmentTree(vector<int> a,int r,int P1,int P2)
		{
			sz=a.size();
			R=r;
			p1=P1;
			p2=P2;
			isLazy.resize(4*sz);
			sump1.resize(4*sz);
			sump2.resize(4*sz);
			Ap1.resize(4*sz);
			Ap2.resize(4*sz);
			Dp1.resize(4*sz);
			Dp2.resize(4*sz);
			
			buildTree(a,0,sz-1,0);
		}
		
		void updateG(int queryLeft,int queryRight,int G)
		{
	//		cerr<<"UpdateG function called with parameters "<<queryLeft<<" "<<queryRight<<" "<<G<<endl;
			updateG(queryLeft,queryRight,0,sz-1,0,G);
		}
		
		void updateSummation(int queryLeft,int queryRight,int A,int D)
		{
	//		cerr<<"*Calling Internal update Summation Function with parameters "<<queryLeft<<" "<<queryRight<<" "<<0<<" "<<sz-1<<endl;
			updateSummation(queryLeft,queryRight,0,sz-1,0,A,D);
		}
		
		long long query(int queryLeft,int queryRight)
		{
	//		cerr<<"Inside the segment tree query Calling internal functions"<<endl;
	//		cerr<<"Parameters passed = "<<queryLeft<<" "<<queryRight<<" "<<0<<" "<<sz-1<<endl;
			
			return query(queryLeft,queryRight,0,sz-1,0);
		}
		
};  
int main()
{   
	//freopen("inwrong.txt","r",stdin);
	//ios_base::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q,r,p1,p2;
		//cin>>n>>q>>r>>p1>>p2;
		scanf("%d %d %d %d %d",&n,&q,&r,&p1,&p2);
		vector<int> array(n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
			
		segmentTree ST(array,r,p1,p2);
		while(q--)
		{
			int type;
			scanf("%d",&type);
			if(type==0)
			{
				int s,d,x,y;
				//cin>>s>>d>>x>>y;
				scanf("%d %d %d %d",&s,&d,&x,&y);
				x--;
				y--;
			//	cerr<<"Type zero Query on "<<x<<y<<endl;
			//	cerr<<"Calling update Summation Function"<<endl;
				ST.updateSummation(x,y,s,d);
			}
			else if(type==1)
			{
				
				int x,g;
				
				//cin>>x>>g;
				scanf("%d %d",&x,&g);
				x--;
			//	cerr<<"Type 1 query on"<<x<<" with g = "<<g<<endl;
				ST.updateG(x,x,g);
			}
			else if(type==2)
			{
				int x,y;
				
				//cin>>x>>y;
				scanf("%d %d",&x,&y);
				x--;
				y--;
			//	cerr<<"Type 2 query on"<<x<<" "<<y<<endl;
			//	cerr<<"Ans = ";
				printf("%lld\n",ST.query(x,y)%p1);
			}
		}
	}
}
