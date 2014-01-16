#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;
//------------------------------------------------------------------------------
#define MAX 100000
int isprime[MAX/32+2];
int primes[100000];
int prime_count;
#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));
void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
    prime_count=0;
    for(int i=0;i<MAX;i++)
    {
		if(isSet(i))
		{
			primes[prime_count]=i;
			prime_count++;
		}
	}
    
}
//------------------------------------------------------------------------------
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
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}
 
//------------------------------------------------------------------------------
vector<vector<int> > children;
vector<vector<vector<int> > > individual_list;
vector<bool> istraversed;

void inorder(vector<list<int> > &tree,int node)
{
	//cout<<"At "<<node<<endl;
	children[node].resize(1);
	children[node].reserve(100);
	
	children[node][0]=1;
	istraversed[node]=true;
	
	for(list<int>::iterator i=tree[node].begin();i!=tree[node].end();i++)
	{
		if(!istraversed[*i])
		{
	//		cout<<"going to "<<*i<<endl;
			inorder(tree,*i);
	//		cout<<"back to "<<node<<endl;
			individual_list[node].push_back(vector<int>());	
			individual_list[node].back().reserve(100);
	//		cout<<"Creating new individual list"<<endl;
	//		cout<<"Size of children list"<<children[*i].size();
			for(int j=0; j<children[*i].size();j++)
			{
				if(individual_list[node].back().size()<=j+1)
				{
	//				cout<<"Resizing individual list"<<individual_list[node].back().size()<<endl;
					individual_list[node].back().resize(j+2);
	//				cout<<"New individual list"<<individual_list[node].back().size()<<endl;
				}
				
				if(children[node].size()<=j+1)
				{
	//				cout<<"Resizing children size"<<children[node].size()<<endl;
					children[node].resize(j+2);
	//				cout<<"new children size"<<children[node].size()<<endl;
				}
					
	//			cout<<"Adding "<<children[*i][j]<<" to "<<j+1<<"individuals"<< endl;
	//			cout<<"Adding "<<children[*i][j]<<" to "<<j+1<<"children"<<endl;
				
				individual_list[node].back()[j+1]+=children[*i][j];
				children[node][j+1]+=children[*i][j];
			}
		}
	}
}
//------------------------------------------------------------------------------
long long prime_paths()
{
	//cout<<"Calculating Prime Paths";
	long long paths=0;
	
	 //cout<<"counting all paths for which i th node falls in that path...";
	for(int i=1;i<individual_list.size();i++)
	{
		if(individual_list[i].size()>1)
		{		
		for(int j=0;j<individual_list[i].size();j++)
		{
			for(int first=1;first<individual_list[i][j].size();first++)
				{
					for(int second=1;second<children[i].size();second++)
					{
						long long x;
						if(individual_list[i][j].size()>second)
						 	x=individual_list[i][j][second];
						else
							x=0;
						//cout<<"Checking for "<<first<<" "<<second<<" "<<children[i][second]-x<<endl;
						
						if(children[i][second]-x>0)
						{
						//	cout<<"Checking for "<<first<<" "<<second<<endl;
								if(isSet(first+second))
								{
						//			cout<<"Prime";
									paths+=((long long)individual_list[i][j][first])*(children[i][second]-x);
						//			cout<<"Paths = "<<paths<<endl;
								}
						}
						
					}	
				}
		}
		}
	}
	paths=paths/2;
	//cout<<"now checking children list"<<endl;
		

	for(int i=1;i<children.size();i++)
	{
	//	cout<<"For node "<<i<<endl;
		for(int j=0;primes[j]<children[i].size();j++)
		{
	//		cout<<"Going for "<<primes[j]<<"Adding "<<children[i][primes[j]]<<endl;
			paths+=children[i][primes[j]];
		}	
	}	
	return paths;
}

//------------------------------------------------------------------------------
void debug()
{
	for(int i=1;i<individual_list.size();i++)
	{
		cout<<"Individual List for "<<i<<endl;
		for(int j=0;j<individual_list[i].size();j++)
		{
			cout<<"Child number "<<j<<endl; 
			for(int k=0;k!=individual_list[i][j].size();k++)
			{
				cout<<k<<" "<<individual_list[i][j][k]<<endl;
			}
		}
		cout<<"Child list  for "<<i<<endl;
		for(int k=0;k!=children[i].size();k++)
			{
				cout<<k<<" "<<children[i][k]<<endl;
			}
		
	}
}

//------------------------------------------------------------------------------
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("testprimedst.txt","r",stdin);
	#endif
	sieve();
	long long n;
	n=readlong();
	vector<list<int> > tree;
	vector<int> children_count;
	int childpos=-1;
	int max_child=-1;
	tree.resize(n+1);
	children_count.resize(n+1);
	
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=readlong();
		b=readlong();
		tree[a].push_back(b);
		tree[b].push_back(a);
		children_count[a]++;
		children_count[b]++;
		if(max_child<children_count[a])
		{
			max_child=children_count[a];
			childpos=a;
		}
		if(max_child<children_count[b])
		{
			max_child=children_count[b];
			childpos=b;
		}
	}
	istraversed.resize(n+1);
	children.resize(n+1);
	individual_list.resize(n+1);
//	cout<<"Doing inorder traversal"<<endl;
	inorder(tree,childpos);
	
//	cout<<"Traversal done"<<endl;
//	debug();
	long long total_paths=(n*(n-1))/2;
	cout<<fixed<<setprecision(6)<<(double(prime_paths()))/total_paths;
}

