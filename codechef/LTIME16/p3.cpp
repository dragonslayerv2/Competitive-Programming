/*
	Name: Rabnge Update Point Query BIT
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/02/14 19:08
	Description: http://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
		
		void increase(size_t idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
	public:
		BIT(){}
		
		BIT(size_t n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type query(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		value_type update(size_t a,size_t b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,-value);
			
		}
		void clear()
		{
			tree.clear();
		}
};


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	BIT<long long> bit2(n+1);
	BIT<long long> bit3(n+1);
	BIT<long long> bit5(n+1);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		switch(type){
			case 1:
				int l,r,p;
				cin>>l>>r>>p;
				if(p==2)
					bit2.update(l,r,1);
				else if(p==3)	
					bit3.update(l,r,1);
				else
					bit5.update(l,r,1);
				break;
			case 2:
				int i,v;
				cin>>i>>v;
				a[i-1]=v;
				bit2.update(i,i,-bit2.query(i));
				bit3.update(i,i,-bit3.query(i));
				bit5.update(i,i,-bit5.query(i));
				
				break;
		}
	}
	
	for(int i=0;i<a.size();i++)
	{
		int count2=bit2.query(i+1);
		int count3=bit3.query(i+1);
		int count5=bit5.query(i+1);
		while(a[i]%2==0&&count2){
			a[i]/=2;
			count2--;
		}
		while(a[i]%3==0&&count3){
			a[i]/=3;
			count3--;
		}
		while(a[i]%5==0&&count5){
			a[i]/=5;
			count5--;
		}
		cout<<a[i]<<" ";
	}
}
