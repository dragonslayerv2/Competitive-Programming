#include<iostream>
#include<vector>
using namespace std;

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
	
	 	value_type read(int idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		value_type query(int a,int b) const
		{
			//cout<<"Query "<<a<<" "<<b<<endl;
			return read(b)-read(a-1);
			
		}
		void clear()
		{
			tree.clear();
		}
};

// sqrt decomposition template shobhitsaxena@live.com
#define chunkSize 300   //define chunk size here
#define getChunkNumber(nodePosition)  (nodePosition/chunkSize+1)
#define getFirstElement(chunkNumber)  ((chunkNumber-1)*chunkSize)
#define getLastElement(chunkNumber)   (chunkNumber*chunkSize-1)
#define isInBoundary(position) 		  ((position%chunkSize)==0)
#define getChunksCount(count) 		  ((count)/chunkSize+2)
#include<cstdio>
int main(){
//	freopen("in.txt","r",stdin);
	
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	
	vector<int> a(n+1);
	BIT<long long> arrayBit(n+1);
	vector<long long> chunk(getChunksCount(n));

	for(int i=1;i<=n;i++){
		cin>>a[i];
		arrayBit.increase(i,a[i]);
	}
	
	vector<pair<int,int> > segments(n+1);
	
	vector<vector<int> > elementsFrequency(getChunksCount(n),vector<int>(n+1));
	for(int i=1;i<=n;i++){
		cin>>segments[i].first>>segments[i].second;
		elementsFrequency[getChunkNumber(i)][segments[i].first]++;
		if(segments[i].second+1<elementsFrequency[getChunkNumber(i)].size())
		elementsFrequency[getChunkNumber(i)][segments[i].second+1]--;
	}
	
	for(int i=1;i<elementsFrequency.size();i++){
		int prefix=0;
		for(int j=1;j<elementsFrequency[i].size();j++){
			prefix+=elementsFrequency[i][j];
			elementsFrequency[i][j]=prefix;
		}
	}
	
	vector<long long> chunkSum(getChunksCount(n));
	
	for(int i=1;i<segments.size();i++){
		long long sum=arrayBit.query(segments[i].first,segments[i].second);
		chunkSum[getChunkNumber(i)]+=sum;
	}
	
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int pos,y;
			cin>>pos>>y;
			long long oldValue=a[pos];
			long long newValue=y;
			long long difference=newValue-oldValue;
			a[pos]+=difference;
			arrayBit.increase(pos,difference);
			for(int i=1;i<chunkSum.size();i++)
				chunkSum[i]+=elementsFrequency[i][pos]*difference;
		}
		else{
			int l,r;
			cin>>l>>r;
			long long ans=0;
			if(getChunkNumber(l)!=getChunkNumber(r)){
				while(l<=r&&!isInBoundary(l)){
					ans+=arrayBit.query(segments[l].first,segments[l].second);
					l++;
				}						
				
				while(l<=r&&getChunkNumber(l)!=getChunkNumber(r)){
					ans+=chunkSum[getChunkNumber(l)];
					l+=chunkSize;
				}						
			}						
			while(l<=r){				
				ans+=arrayBit.query(segments[l].first,segments[l].second);
				l++;
			}			 			
			cout<<ans<<endl;
		}
	}
}
