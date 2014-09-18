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
		this->type==type;
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
		while (idx < BITMap.size())
		{ 
			BITMap[idx][queries[i].y]; // make an entry for y coordinate in the BITMap
			idx += (idx & (- idx)); 
		}
	}
	
	for(int i=0;i<BITMap.size();i++){
		int currentRank=0;
		for(map<int,int>::iterator i=BITMap[i].begin();i!=BITMap[i].end();i++){
			currentRank++;
			i->second=currentRank;
		}
	}
	
	vector<BIT> bits(BITMap.size())
}
