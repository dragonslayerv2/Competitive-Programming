#include<iostream>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

map<long long,int> elements;
map<int,long long> invRank;


//#define DEBUG
template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
		
		void increase(int idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
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
	
	 	value_type query(int idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
				
			}
			return sum;
		}
		
		value_type update(int a,int b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,-value);
		}
		void clear()
		{
			tree.clear();
		}
};
//------------------------ FOR 1st query --------------------------------------

#define LESS_THAN -1
#define GREATER_THAN 1
#define BETTER 0
#define WORSE 2

pair<int,long long> range(long long u1,long long a1,long long b1,long long u2,long long a2,long long b2)
{
	if(b2-b1==0)
	{
		if(a1-b1*u1>=a2-b2*u1)
			return make_pair(BETTER,BETTER);
		else
			return make_pair(WORSE,WORSE);
	}
	else if(b2-b1>0)
		return make_pair(LESS_THAN,((a1-a2)-(b1*u1-b2*u2))/(b2-b1)-((((a1-a2)-(b1*u1-b2*u2))%(b2-b1))==0));	
	else
		return make_pair(GREATER_THAN,((a1-a2)-(b1*u1-b2*u2))/(b2-b1)+1);
}	

class segmentTree
{
	private:
		vector<long long> u;
		vector<long long> a;
		vector<long long> b;
		vector<bool>      present;
		
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
		
		inline long long calculate(long long u,long long a,long long b,long long x)
		{
			return b*(x-u)+a;
		}
		
		pair<bool,long long> query(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node)
		{
			#ifdef DEBUG
				cout<<"Q "<<queryLeft<<" "<<queryRight<<" "<<nodeLeft<<" "<<nodeRight<<endl;
			#endif
			if(nodeLeft==nodeRight)
			{
				#ifdef DEBUG
					cout<<"At left"<<endl;
				#endif
				if(present[node])
				{
					#ifdef DEBUG
					cout<<"Returing a value "<<calculate(u[node],a[node],b[node],invRank[queryLeft])<<endl;
					#endif
					return make_pair(true,calculate(u[node],a[node],b[node],invRank[queryLeft]));
				}
				else
				{
					#ifdef DEBUG
					cout<<"No value present here"<<endl;
					#endif
					return make_pair(false,0);
				}
			}
			else
			{
				pair<bool,long long> ans1;
				if(present[node])
				{
					#ifdef DEBUG
						cout<<"Calcualting "<<u[node]<<" "<<a[node]<<" "<<b[node]<<" "<<invRank[queryLeft]<<endl;
					#endif
					ans1=make_pair(true,calculate(u[node],a[node],b[node],invRank[queryLeft]));
				}
				else
					ans1=make_pair(false,0);
				
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);
				
				pair<bool,long long> ans2=make_pair(false,0);
				
				if(leftInRange)
					ans2=query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));
				else
					ans2=query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));			
				#ifdef DEBUG
					cout<<"Q "<<queryLeft<<" "<<queryRight<<" "<<nodeLeft<<" "<<nodeRight<<endl;
				#endif
				#ifdef DEBUG
					cout<<"Present node answer = "<<ans1.first<<" "<<ans1.second<<endl;
					cout<<"Child node answer = "<<ans2.first<<" "<<ans2.second<<endl;
					cout<<"Returning           "<<max(ans1,ans2).first<<" "<<max(ans1,ans2).second<<endl;
				#endif
				return max(ans1,ans2);
			}
		}
		void update(int queryLeft,int queryRight,int nodeLeft,int nodeRight,long long u,long long a,long long b,int node)
		{
			#ifdef DEBUG
			cout<<"Query is "<<queryLeft<<" "<<queryRight<<endl;
			cout<<"At node " << nodeLeft<<" "<<nodeRight<<endl;
			cout<<"New u a b are"<<u<<" "<<a<<" "<<b<<endl;
			#endif
		
		
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
			{
				#ifdef DEBUG
				cout<<"Out of Range..."<<endl;
				#endif
				return;
			}
			else if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
			{
				#ifdef DEBUG
				cout<<"Ohaa in Range Going to update this node"<<endl;
				#endif
				if(!present[node])
				{
					#ifdef DEBUG
					cout<<"Nothing is present."<<endl;
					cout<<"Putting Data here ."<<endl;
					#endif
					present[node]=true;
					this->u[node]=u;
					this->a[node]=a;
					this->b[node]=b;
					return;
				}
				else if(nodeLeft==nodeRight)
				{
					#ifdef DEBUG
					cout<<"At leaf of "<<invRank[nodeLeft];
					#endif
					if(calculate(u,a,b,invRank[nodeLeft])>calculate(this->u[node],this->a[node],this->b[node],invRank[nodeLeft]))
					{
						#ifdef DEBUG
							cout<<"New one is better so putting it here";
							cout<<"Previous best value is "<<calculate(this->u[node],this->a[node],this->b[node],invRank[nodeLeft])<<endl;
							cout<<"New value is "<<calculate(u,a,b,invRank[nodeLeft])<<endl;
						#endif
						
						this->u[node]=u;
						this->a[node]=a;
						this->b[node]=b;
						return;
					}
					#ifdef DEBUG
					else
						cout<<"No changes are required. Previous one is good."<<endl;
					#endif
				}
				else
				{
						
					pair<int,long long> decision=range(u,a,b,this->u[node],this->a[node],this->b[node]);
					#ifdef DEBUG
						cout<<"Got decision as "<<decision.first<<" "<<decision.second<<endl;
					#endif
					long long x=decision.second;
					long long l=invRank[nodeLeft];
					long long h=invRank[nodeRight];
					long long hl=invRank[(nodeLeft+nodeRight)/2];
					long long hr=invRank[(nodeLeft+nodeRight)/2+1];
				
					if(decision.first==LESS_THAN)
					{
						#ifdef DEBUG
							cout<<"Got Less Than.";
						#endif
						if(x<l)
						{
							#ifdef DEBUG
								cout<<"Out of range check.."<<endl;
							#endif	
							return;
						}
						else if(x<hr)
						{
							#ifdef DEBUG
								cout<<"Better for the left one. Going there.\n";
							#endif
							update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,u,a,b,leftChild(node));
						}
						else if(x<=h)
						{
							#ifdef DEBUG
								cout<<"Better for the whole node"<<"Pushing the previous value "<<endl;
							#endif
							update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,this->u[node],this->a[node],this->b[node],rightChild(node));
							this->u[node]=u;
							this->a[node]=a;
							this->b[node]=b;
						}
						else
						{
							#ifdef DEBUG
								cout<<"Better for the whole node"<<endl;
							#endif
								
							this->u[node]=u;
							this->a[node]=a;
							this->b[node]=b;
						}
					}
					else if(decision.first==GREATER_THAN)
					{
						if(x>h)
						{
							#ifdef DEBUG
								cout<<"Out of range updation"<<endl;
							#endif
							return;
						}
						else if(x>hl)
						{
							#ifdef DEBUG
								cout<<"Better for the right child goind dere"<<endl;
							#endif
							update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,u,a,b,rightChild(node));
						}
						else if(x>=l)
						{
							#ifdef DEBUG
								cout<<"Pushing older value to left"<<endl;
							#endif
							update(queryLeft,queryRight,nodeLeft,(nodeRight+nodeLeft)/2,this->u[node],this->a[node],this->b[node],leftChild(node));
							this->u[node]=u;
							this->a[node]=a;
							this->b[node]=b;
						}
						else
						{
							#ifdef DEBUG
								cout<<"Better for the whole range"<<endl;
							#endif
							this->u[node]=u;
							this->a[node]=a;
							this->b[node]=b;
						}	
					}
					
					else if(decision.first==BETTER)
					{
						#ifdef DEBUG
								cout<<"This query is better putting it here"<<endl;
							#endif
						this->u[node]=u;
						this->a[node]=a;
						this->b[node]=b;
					} 
					
					else if(decision.first==WORSE) {
							#ifdef DEBUG
								cout<<"Query of no use"<<endl;
							#endif
						return;	
					}
				}
			}
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,u,a,b,leftChild(node));
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,u,a,b,rightChild(node));
			}
		}
		
	public:
		segmentTree(int n)
		{
			present.resize(4*n);
			u.resize(4*n);
			a.resize(4*n);
			b.resize(4*n);
		}
		
		pair<bool,long long> query(long long i)
		{
			return query(i,i,1,u.size()/4,0);	
		}
		void update(int queryLeft,int queryRight,long long u,long long a,long long b)
		{
			#ifdef DEBUG
			cout<<"Got to update"<<queryLeft<<" "<<queryRight<<endl;
			#endif
			update(queryLeft,queryRight,1,present.size()/4,u,a,b,0);
		}
};
//-----------------------------------------------------------------------------
struct query
{
	int type;
	long long u,v,a,b;	
	long long i;
};

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("test.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	
	vector<query> Q(m);
	
	for(int i=0;i<m;i++)
	{
		scanf("%d",&Q[i].type);
		if(Q[i].type==3)
			scanf("%lld",&Q[i].i);
		else
			scanf("%lld%lld%lld%lld",&Q[i].u,&Q[i].v,&Q[i].b,&Q[i].a);
	}
	
	for(int i=0;i<m;i++)
	{
		if(Q[i].type==3)
			elements[Q[i].i];
		else
		{
			elements[Q[i].u];
			elements[Q[i].v];
		}
	}
	int k=1;
	#ifdef DEBUG
	cout<<"Rank Map"<<endl;
	#endif
	for(map<long long,int>::iterator i=elements.begin();i!=elements.end();i++,k++)
	{
		
		i->second=k;
		invRank[i->second]=i->first;
		#ifdef DEBUG
			cout<<i->first<<" "<<i->second<<endl;
		#endif
	}
	
	BIT<long long> bita(elements.size()+1);
	BIT<long long> bitb(elements.size()+1);
	BIT<long long> bitub(elements.size()+1);
	segmentTree ST(elements.size());
	for(int i=0;i<m;i++)
	{
		#ifdef DEBUG
			cout<<"Query is "<<Q[i].type<<" ";
			if(Q[i].type!=3)
				cout<<Q[i].u<<" "<<Q[i].v<<" "<<Q[i].a<<" "<<Q[i].b<<endl<<endl;
			else
				cout<<Q[i].i<<endl<<endl;
		#endif
		if(Q[i].type==1)
		{
			#ifdef DEBUG
				cout<<"Going for the segment tree updation"<<endl;
				cout<<"Updating the segment Tree with "<<elements[Q[i].u]<<" "<<elements[Q[i].v]<<" "<<Q[i].u<<" "<<Q[i].a<<" "<<Q[i].b<<endl;
			#endif
			ST.update(elements[Q[i].u],elements[Q[i].v],Q[i].u,Q[i].a,Q[i].b);	
		}
	
		else if(Q[i].type==2)
		{
			#ifdef DEBUG
				cout<<"Going for the BIT updation"<<endl;
				cout<<"Updating the BIT with "<<elements[Q[i].u]<<" "<<elements[Q[i].v]<<" "<<Q[i].u<<" "<<Q[i].a<<" "<<Q[i].b<<endl;
			#endif
			bita.update (elements[Q[i].u],elements[Q[i].v],Q[i].a);	
			bitb.update (elements[Q[i].u],elements[Q[i].v],Q[i].b);	
			bitub.update(elements[Q[i].u],elements[Q[i].v],Q[i].u*Q[i].b);	
		}
	
		else if(Q[i].type==3)
		{
			#ifdef DEBUG
				cout<<"Query type query"<<endl;
				cout<<"Quering for "<<elements[Q[i].i]<<endl;
			#endif
			long long ans=bita.query(elements[Q[i].i]);
			ans+=Q[i].i*bitb.query(elements[Q[i].i]);
			ans-=bitub.query(elements[Q[i].i]);
		
			#ifdef DEBUG
			cout<<"Ans from BIT = "<<ans<<endl;
			#endif
		
			pair<bool,long long> ans2=ST.query(elements[Q[i].i]);
			
			if(ans2.first==false)
				cout<<"NA";
			else
				cout<<ans+ans2.second;
			cout<<endl;
		}
		#ifdef DEBUG
		cout<<"-----------------------------------------------------------------------------------"<<endl;
		#endif
	}

}
