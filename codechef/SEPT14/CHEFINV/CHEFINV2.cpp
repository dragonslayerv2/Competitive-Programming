#include<map>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readlong() 
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

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

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


int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n=readlong(),m=readlong();
	vector<int> A(n);
	
	map<int,int> rank;
	for(int i=0;i<n;i++){
		A[i]=readlong();
		rank[A[i]];
	}
	int currentRank=0;
	for(map<int,int>::iterator i=rank.begin();i!=rank.end();i++)
		i->second=(++currentRank);
	
	
	
	long long inversions = 0;
	vector<pair<int,int> > query(m);
	vector<pair<int,int> > positionQueryMap;
	positionQueryMap.reserve(2*m);
	
	vector<long long> ans(m);
	
	for(int i=0;i<m;i++) {
		query[i].first=readlong()-1;
		query[i].second=readlong()-1;
	
		if(query[i].first>query[i].second)
			swap(query[i].first,query[i].second);
		positionQueryMap.push_back(make_pair(query[i].first,i));
		positionQueryMap.push_back(make_pair(query[i].second,i));
	}
	sort(positionQueryMap.begin(),positionQueryMap.end());
	
	BIT<int> rankBIT(currentRank+10);
	
	int lastIndexInBit=-1;
	for(int i=0;i<positionQueryMap.size();i++){
		while(lastIndexInBit<positionQueryMap[i].first){
			
			lastIndexInBit++;
			int currentRank = rank[A[lastIndexInBit]];
			rankBIT.increase(currentRank,1);
			inversions+=rankBIT.query(currentRank+1,rank.size());
		}
		int queryPosition = positionQueryMap[i].second;
		int rankA= 	rank[A[query[queryPosition].first]];
		int rankB=	rank[A[query[queryPosition].second]];
		
		if(positionQueryMap[i].first==query[positionQueryMap[i].second].first){
			ans[queryPosition]-=rankBIT.query(rankA+1,rank.size());
			ans[queryPosition]+=rankBIT.read(rankA-1);
			ans[queryPosition]+=rankBIT.query(rankB+1,rank.size());
			ans[queryPosition]-=rankBIT.read(rankB-1);
		}
		else{
			ans[queryPosition]+=rankBIT.query(rankA+1,rank.size());
			ans[queryPosition]-=rankBIT.read(rankA-1);
			ans[queryPosition]-=rankBIT.query(rankB+1,rank.size());
			ans[queryPosition]+=rankBIT.read(rankB-1);
		}
	}
	while(lastIndexInBit<A.size()-1){
			lastIndexInBit++;
			int currentRank = rank[A[lastIndexInBit]];
			rankBIT.increase(currentRank,1);
			inversions+=rankBIT.query(currentRank+1,rank.size());
	}
	for(int i=0;i<ans.size();i++)
		printf("%lld\n",inversions+ans[i]);
}
