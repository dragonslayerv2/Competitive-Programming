#include<bits/stdc++.h>
using namespace std;

#define SMAX 1000006
//-----------------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------------
int N, m, *SA;
char str[SMAX]; 
//---------------------------------------------------------------------------------------
char mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:((char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))

// find the start or end of each bucket
void getBuckets(char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, sum = 0;
    for (i = 0; i <= K; i++)
        bkt[i] = 0; // clear all buckets
    for (i = 0; i < n; i++)
        bkt[chr(i)]++; // compute the size of each bucket
    for (i = 0; i <= K; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}
// compute SAl
void induceSAl(char *t, int *SA, char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
    for (i = 0; i < n; i++) {
        j = SA[i] - 1;
        if (j >= 0 && !tget(j))
            SA[bkt[chr(j)]++] = j;
    }
}
// compute SAs
void induceSAs(char *t, int *SA, char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
    for (i = n - 1; i >= 0; i--) {
        j = SA[i] - 1;
        if (j >= 0 && tget(j))
            SA[--bkt[chr(j)]] = j;
    }
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
void SA_IS(char *s, int *SA, int n, int K, int cs) {
    int i, j;
    char *t = (char *) malloc(n / 8 + 1); // LS-type array in bits
    // Classify the type of each character
    tset(n-2, 0);
    tset(n-1, 1); // the sentinel must be in s1, important!!!
    for (i = n - 3; i >= 0; i--)
        tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
    // stage 1: reduce the problem by at least 1/2
    // sort all the S-substrings
    int *bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
    getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
    for (i = 0; i < n; i++)
        SA[i] = -1;
    for (i = 1; i < n; i++)
        if (isLMS(i))
            SA[--bkt[chr(i)]] = i;
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    // compact all the sorted substrings into the first n1 items of SA
    // 2*n1 must be not larger than n (proveable)
    int n1 = 0;
    for (i = 0; i < n; i++)
        if (isLMS(SA[i]))
            SA[n1++] = SA[i];
    // find the lexicographic names of all substrings
    for (i = n1; i < n; i++)
        SA[i] = -1; // init the name array buffer
    int name = 0, prev = -1;
    for (i = 0; i < n1; i++) {
        int pos = SA[i];
        bool diff = false;
        for (int d = 0; d < n; d++)
            if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                diff = true;
                break;
            } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                break;
        if (diff) {
            name++;
            prev = pos;
        }
        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
        SA[n1 + pos] = name - 1;
    }
    for (i = n - 1, j = n - 1; i >= n1; i--)
        if (SA[i] >= 0)
            SA[j--] = SA[i];
    // stage 2: solve the reduced problem
    // recurse if names are not yet unique
    int *SA1 = SA, *s1 = SA + n - n1;
    if (name < n1)
        SA_IS((char*) s1, SA1, n1, name - 1, sizeof(int));
    else
        // generate the suffix array of s1 directly
        for (i = 0; i < n1; i++)
            SA1[s1[i]] = i;
    // stage 3: induce the result for the original problem
    bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
    // put all left-most S characters into their buckets
    getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
    for (i = 1, j = 0; i < n; i++)
        if (isLMS(i))
            s1[j++] = i; // get p1
    for (i = 0; i < n1; i++)
        SA1[i] = s1[SA1[i]]; // get index in s
    for (i = n1; i < n; i++)
        SA[i] = -1; // init SA[n1..n-1]
    for (i = n1 - 1; i >= 0; i--) {
        j = SA[i];
        SA[i] = -1;
        SA[--bkt[chr(j)]] = j;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    free(t);
}
//---------------------------------------------------------------------------------------
int rankArray[SMAX], LCP[SMAX];
void generateLCP () {
    for (int i = 0, j, k = 0; i < N; LCP[rankArray[i++]]=k)
        if (rankArray[i] > 0) for (k ? k-- : 0, j = SA[rankArray[i] - 1]; str [i + k] == str [j + k]; k++);
        else k = 0;
}
//------------------------------------------------------------------------------------
void suffixArray () {
	SA=new int[SMAX];
	SA_IS(str, SA, N+1, 256, 1);
	SA=SA+1;
}
//-------------------------------------------------------------------------------------
int pow2[SMAX];
void generatePow2(int n){
	int pow=0;
	while((1<<pow)<SMAX){
		pow2[1<<pow]=pow;
		pow++;
	}
	for(int i=1;i<SMAX;i++){
		if(!pow2[i])
			pow2[i]=pow2[i-1];
	}
}
//------------------------------------------------------------------------------------
int RMQ[SMAX][30];
class rmq
{
	public:
		void generate()
		{
			for(int i=0;i<N;i++)
				RMQ[i][0]=LCP[i];
	
			for(int j=1,p=2;p<=N;j++,p*=2)
				for(int i=0;i+p<=N;i++)
					RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+p/2][j-1]);
		}
		
		inline int query(int i,int j)
		{
			int gap=j-i+1;
			int p=pow2[gap];
			int po=(1<<p);
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
} rMQ;
//-------------------------------------------------------------------------------------


#define lcp(a,b) ((a)==(b)?(N-(a)):rMQ.query(min(rankArray[a],rankArray[b])+1,max(rankArray[a],rankArray[b])))

int leftCompare(int l,int r, int targetPosition,int LCP){
	int count=r-l+1;
	while(count>0){
		int currentPosition=l;
		int step=count>>1;
		currentPosition+=step;
		if(lcp(SA[currentPosition],SA[targetPosition])<LCP){
			l=++currentPosition;
			count-=step+1;
		}
		else
			count=step;
	}
	return l;
}

int rightCompare(int l,int r,int targetPosition,int LCP){
	int count=r-l+1;
	while(count>0){
		
		int currentPosition=r;
		int step=count>>1;
		currentPosition-=step;
		//cerr<<"At "<<r<<" "<<targetPosition<<" targetLCP is "<<LCP<<" LCP is "<<lcp(SA[r],SA[targetPosition])<<endl;
		if(lcp(SA[currentPosition],SA[targetPosition])<LCP){
			r=--currentPosition;
			count-=step+1;
		}
		else
			count=step;
	}
	return r;
}

long long prefixSum[SMAX];


//--------------------------------------------
class myTimer{
		clock_t start;
		clock_t end;
		double time;
		string tag;
	public:
		myTimer(string tag){
			this->tag=tag;
			time=0;
		}
		void reset(){
			time=0;
		}
		void printTime(){
			cerr<<tag<<": "<<time<<endl;
		}
		void startTimer(){
			start=clock();
		}		
		void endTime(){
			end=clock();
			time+=((double)end-start)/CLK_TCK;
		}
};
//--------------------------------------
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out1.txt","r",stdout);
	
myTimer preprocessTime("Preprocess Time"),inputTime("Input Time"),outputTime("Output Time"),rankQueryTime("Rank Query Time"), kthQueryTime("kth Query Time");
	
preprocessTime.startTimer();
	generatePow2(SMAX);
	ios::sync_with_stdio(false);
	inputTime.startTimer();
	cin.getline(str,sizeof(str));
	inputTime.endTime();
	N=strlen(str);
	suffixArray();
	for(int i=0;i<N;i++)
		rankArray[SA[i]]=i;
	generateLCP();
	
	int n=N;	
	prefixSum[0]=1;
	for(int i=1;i<=n;i++)
		prefixSum[i]=n-SA[i-1]+prefixSum[i-1]-LCP[i-1];
	
	rMQ.generate();
	for(int i=0;i<N;i++)
		rankArray[SA[i]]=i;
		
	segmentTree rankTree(SA,n,::rankTree);
	segmentTree kthTree(rankArray,n,::kthTree);
preprocessTime.endTime();
	int q;
	cin>>q;
	char type[7];
	while(q--){
inputTime.startTimer();
		cin>>type;
inputTime.endTime();
		if(type[0]=='S')
		{
			long long k1;
			int k2;
inputTime.startTimer();
			cin>>k1>>k2;
inputTime.endTime();
kthQueryTime.startTimer();
			int lEnd=lower_bound(prefixSum,prefixSum+n+1,k1)-prefixSum;
			if(prefixSum[lEnd]>k1)
				lEnd--;
			
			int length=k1-prefixSum[lEnd]+1+LCP[lEnd];
			int rEnd=rightCompare(lEnd,n-1,lEnd,length);
			int l=kthTree.kthQuery(lEnd,rEnd,k2)+1;
			// query here
kthQueryTime.endTime();
outputTime.startTimer();
			cout<<l<<" "<<l+length-1<<endl;
outputTime.endTime();
		}
		else
		{
			int l,r;
inputTime.startTimer();
			cin>>l>>r;
inputTime.endTime();
rankQueryTime.startTimer();
			l--;
			r--;
			int lEnd=leftCompare(0,rankArray[l],rankArray[l],r-l+1);
			int rEnd=rightCompare(rankArray[l],n-1,rankArray[l],r-l+1);
			
//			cerr<<"LEND "<<lEnd<<" rEnd = "<<rEnd<<endl;
rankQueryTime.endTime();
			int rankQuery=rankTree.rankQuery(lEnd,rEnd,l)+1;

outputTime.startTimer();
//cerr<<"PrefixSum = "<<prefixSum[lEnd]<<" new Additions = "<<(r-l)-LCP[lEnd]<<endl;
			cout<<prefixSum[lEnd]+(r-l)-LCP[lEnd]<<" "<<rankQuery<<endl;
outputTime.endTime();
		}
	}
preprocessTime.printTime();
inputTime.printTime();
rankQueryTime.printTime();
outputTime.printTime();	
}
