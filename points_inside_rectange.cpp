/*
	Name: Number of points inside a rectange (0,0,x,y). Utilises a 2D bit and a map.
	Author: Shobhit Saxena
	Date: 18/09/14 00:30
	Description: Queries are of the type.
	I x y: Insert a point at x,y
	D x y: Delete a point at x,y
	Q x y: Returns the number of points inside the rectange x,y
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct query{
	char type;
	int x,y;
	query(char type='\0',int x=-1,int y=-1){
		this->type=type;
		this->x=x;
		this->y=y;
	}
};

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
//	freopen("rectTest.txt","r",stdin);
	int q;
	cin>>q;
	vector<query> queries;
	queries.reserve(q);

	map<int,int> xCoordinateRank;
	while(q--){
		char type;
		cin>>type;
		int x,y;
		cin>>x>>y;
		queries.push_back(query(type,x,y));
	}
	
	// rank the x coordinate
	xCoordinateRank[0];
	for(int i=0;i<queries.size();i++)	
		xCoordinateRank[queries[i].x];
	
	int currentRank=0;
	for(map<int,int>::iterator i=xCoordinateRank.begin();i!=xCoordinateRank.end();i++){
		currentRank++;
		i->second=currentRank;
	}
	
	vector<map<int,int> > BITMap(xCoordinateRank.size()+1);
	
	// generate the BITMap
	for(int i=0;i<queries.size();i++){
		int idx=xCoordinateRank[queries[i].x];
		while(idx>0)
		{
			BITMap[idx][queries[i].y]; 
			idx-=(idx&(-idx));
		}
		
		idx=xCoordinateRank[queries[i].x];
		while (idx < BITMap.size())
		{ 
			BITMap[idx][queries[i].y]; 
			idx += (idx & (- idx)); 
		}
	}
	
	for(int i=0;i<BITMap.size();i++){
		int currentRank=0;
		for(map<int,int>::iterator j=BITMap[i].begin();j!=BITMap[i].end();j++){
			currentRank++;
			j->second=currentRank;
		}
	}
	
	vector<BIT<int> > bits(BITMap.size());
	for(int i=0;i<bits.size();i++)
		bits[i].assign(BITMap[i].size());
	
	for(int i=0;i<queries.size();i++)
	{
		int x=queries[i].x,y=queries[i].y;
		int xRank = xCoordinateRank[x];
		int idx=xRank;
		switch(queries[i].type)
		{
			case 'I': 

					while (idx < BITMap.size())
					{ 
						bits[idx].increase(BITMap[idx][y],1); 
						idx += (idx & (- idx)); 
					}
					break;
			case 'D':
					while (idx < BITMap.size())
					{ 
						bits[idx].increase(BITMap[idx][y],-1); 
						idx += (idx & (- idx)); 
					}
					break;
			case 'Q':
					int sum=0;
					while(idx>0)
					{
						sum+=bits[idx].read(BITMap[idx][y]);
						idx-=(idx&(-idx));
					}
					cout<<sum<<endl;
					break;
		}
	}
}
