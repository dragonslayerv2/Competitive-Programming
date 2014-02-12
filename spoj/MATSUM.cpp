#include<stdio.h>
#include<vector>
using namespace std;

typedef int value_type;

vector<vector<value_type> > tree;

bool inRange(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2)
{
	if(nx2<nx1||ny2<ny1) // node is invalid.
		return false;
	if(qx2<nx1||qx1>nx2)  // x is out of bounds
		return false;
	if(qy2<ny1||qy1>ny2)   // y is out of bounds
		return false;
	return true;
}

inline size_t leftChild(size_t node)
{
	return node*2+1;
}

inline size_t rightChild(size_t node)
{
	return node*2+2;
}

void update(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2, size_t nodeX, size_t nodeY,value_type value)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2&&nx1==nx2&&ny1==ny2) // node is within query
		tree[nodeX][nodeY]+=value;
	else
	{
		update(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2, leftChild(nodeX), leftChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2, leftChild(nodeX), rightChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2, rightChild(nodeX), leftChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, rightChild(nodeX), rightChild(nodeY), value);
		tree[nodeX][nodeY]=tree[leftChild(nodeX)][leftChild(nodeY)]+tree[leftChild(nodeX)][rightChild(nodeY)]+tree[rightChild(nodeX)][leftChild(nodeY)]+tree[rightChild(nodeX)][rightChild(nodeY)];
	}
}

value_type query (size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2,size_t nodeX,size_t nodeY)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return 0;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2)
		return tree[nodeX][nodeY];
	else
	{
		value_type LL=query(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2, leftChild(nodeX), leftChild(nodeY));
		value_type LR=query(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2, leftChild(nodeX), rightChild(nodeY));
		value_type RL=query(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2, rightChild(nodeX), leftChild(nodeY));
		value_type RR=query(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, rightChild(nodeX), rightChild(nodeY));
		return LL+LR+RL+RR;
	}
}
#define GETCHAR getchar_unlocked

inline int readlong() 
{
	int flag=1;
    int n = 0;
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
//	freopen("test.txt","r",stdin);

	int t;
	t=readlong();
	//scanf("%d",&t);
	while(t--)
	{
		int n;
		n=readlong();
	//	scanf("%d",&n);
		
		tree.resize(10*n,vector<value_type>(10*n));
		
		while(1)
		{
			char type[4];
			type[0]=GETCHAR();
			type[1]=GETCHAR();
			type[2]=GETCHAR();
			
			//scanf("%s",type);
			if(type[0]=='E')
				break;
			else if(type[1]=='U')
			{
				int x1,x2,y1,y2;
				x1=readlong();
				y1=readlong();
				x2=readlong();
				y2=readlong();
			//	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				printf("%d\n",query(x1,x2,y1,y2,0,n-1,0,n-1,0,0));
			}
			else
			{
				int x1,y1,num;
				x1=readlong();
				y1=readlong();
				num=readlong();
			//	scanf("%d %d %d",&x1,&y1,&num);
				update(x1,x1,y1,y1,0,n-1,0,n-1,0,0,num);
			}	
		}
		printf("\n");
	}
	
}
