int rankTree[30*SMAX];
int kthTree[30*SMAX];

class segmentTree
{
	#define getPosition(level,size,position) ((level)*(size)+position)
	public:
		int *tree;
		int size;
	private:
		//----------------------------------------------------------------------
		bool inRange(int nodeLeft,int nodeRight,int queryLeft,int queryRight)
		{
			if(nodeLeft>nodeRight||nodeRight<queryLeft||nodeLeft>queryRight)
				return false;
			else
				return true;
		}
		//----------------------------------------------------------------------
		
		void buildTree(int *A,int low,int high,int level)
		{
			if(low==high)
				tree[getPosition(level,size,low)]=A[low];
			else if(low>high)
				return;
			else
			{
				int leftBegin=low;
				int leftEnd=(low+high)/2;
				int rightBegin=(low+high)/2+1;
				int rightEnd=high;
				buildTree(A,leftBegin,leftEnd,level+1);
				buildTree(A,rightBegin,rightEnd,level+1);
				merge(	tree+getPosition(level+1,size,leftBegin), 
						tree+getPosition(level+1,size,leftEnd+1),
						tree+getPosition(level+1,size,rightBegin), 
						tree+getPosition(level+1,size,rightEnd+1),
						tree+getPosition(level,size,low));
			}
		}
		
		int rankQuery(int qLeft,int qRight,int value, int nLeft, int nRight, int level)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return 0;
			else if(nLeft>=qLeft&&nRight<=qRight)
				return distance(tree+getPosition(level,size,nLeft),lower_bound(tree+getPosition(level,size,nLeft),tree+getPosition(level,size,nRight+1),value));
			else
				return rankQuery(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,level+1)+rankQuery(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,level+1);
		}
		
		int kthQuery(int qLeft,int qRight, int rank, int nLeft,int nRight,int level){
			if(nLeft==nRight)
				return nLeft;
			else {
				int leftBegin=nLeft;
				int leftEnd=(nLeft+nRight)/2;
				int inRangeLeftElements=distance(lower_bound(tree+getPosition(level+1,size,leftBegin),tree+getPosition(level+1,size,leftEnd+1),qLeft),
												 upper_bound(tree+getPosition(level+1,size,leftBegin),tree+getPosition(level+1,size,leftEnd+1),qRight));
				if(inRangeLeftElements>=rank)
					return kthQuery(qLeft,qRight,rank,nLeft,(nLeft+nRight)/2,level+1);
				else{
					return kthQuery(qLeft,qRight,rank-inRangeLeftElements,(nLeft+nRight)/2+1,nRight,level+1);
				}
			}
		}
		
	public:
		segmentTree()
		{}
		
		segmentTree(int *A,int size, int *destArray)
		{
			assign(A,size,destArray);
		}
		
		void assign(int *A,int size, int *destArray)
		{
			tree=destArray;
			this->size=size;
			buildTree(A,0,size-1,0);
		}
		
		int rankQuery(int left,int right,int value)
		{
			return rankQuery(left,right,value,0,size-1,0);
		}
		
		int kthQuery(int left,int right,int rank){
			return kthQuery(left,right,rank,0,size-1,0);
		}
		#undef getPosition
};
