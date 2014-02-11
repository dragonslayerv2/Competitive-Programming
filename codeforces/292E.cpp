#include<iostream>
#include<vector>
using namespace std;

vector<int> lazytree;

bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) 
{
	if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
		return false;
	
	return true;
}
		
void update(int queryLeft,int queryRight,int value,int nodeLeft,int nodeRight,int node)
{
	if(nodeLeft>nodeRight)
		return;

	if(lazytree[node]!=-1&&nodeLeft!=nodeRight)
	{
		lazytree[2*node+1]=lazytree[node];
		lazytree[2*node+2]=lazytree[node]+(nodeRight-nodeLeft)/2+1;
		lazytree[node]=-1;
	}
	
	if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
		return;
	else if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
		lazytree[node]=value+(nodeLeft-queryLeft);
	else
	{
		update(queryLeft,queryRight,value,nodeLeft,(nodeLeft+nodeRight)/2,node*2+1);
		update(queryLeft,queryRight,value,(nodeLeft+nodeRight)/2+1,nodeRight,node*2+2);
	}
}

int query(int pos,int nodeLeft,int nodeRight,int node)
{
	if(nodeLeft==nodeRight)
		return lazytree[node];
	
	else
	{
		if(lazytree[node]!=-1)
		{
			lazytree[2*node+1]=lazytree[node];
			lazytree[2*node+2]=lazytree[node]+(nodeRight-nodeLeft)/2+1;	
			lazytree[node]=-1;
		}
		bool leftInRange=inRange(pos,pos,nodeLeft,(nodeLeft+nodeRight)/2);
		bool rightInRange=inRange(pos,pos,(nodeLeft+nodeRight)/2+1,nodeRight);	
		
		if(leftInRange&&!rightInRange)
			return query(pos,nodeLeft,(nodeLeft+nodeRight)/2,node*2+1);
		else if(!leftInRange&&rightInRange)
			return query(pos,(nodeLeft+nodeRight)/2+1,nodeRight,node*2+2);
	}
}



int main()
{
//	freopen("test.txt","r",stdin);
	int n,q;
	cin>>n>>q;

	lazytree.resize(4*n,-1);
	
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];

	while(q--)
	{
		int type;
		cin>>type;
		switch(type)
		{
			case 1:	int aLoc,bLoc,size;
					cin>>aLoc>>bLoc>>size;
					aLoc--;
					bLoc--;
					update(bLoc,bLoc+size-1,aLoc,0,n-1,0);
					break;
			case 2:	int pos;
					cin>>pos;
					pos--;
					int Q=query(pos,0,n-1,0);
					
					if(Q==-1)
						cout<<b[pos];
					else
						cout<<a[Q];
					cout<<endl;
					break;
		}
	}
}
