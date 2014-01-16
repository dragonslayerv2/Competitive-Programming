#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;

//--------------- SIEVE OPTIMISED VERSION --------------------------------------
#define MAX 60000
int isprime[MAX/32+2];

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
}

//------------------------------------------------------------------------------

vector<map<int,int> > children;
vector<deque<map<int, int> > > individual_list;
vector<bool> istraversed;

void inorder(vector<list<int> > &tree,int node)
{
	
	children[node][0]=1;
	istraversed[node]=true;
	
	for(list<int>::iterator i=tree[node].begin();i!=tree[node].end();i++)
	{
		if(!istraversed[*i])
		{
			inorder(tree,*i);
			
			individual_list[node].push_back(map<int,int>());			
			for(map<int,int>::iterator j=children[*i].begin(); j!=children[*i].end();j++)
			{
				individual_list[node].back()[j->first+1]+=j->second;
				children[node][j->first+1]+=j->second;
			}
				
		}
	}
}

long long prime_paths()
{
//	cout<<"Calculating Prime Paths";
	long long paths=0;
	
	// counting all paths for which i th node falls in that path...
	for(int i=1;i<individual_list.size();i++)
	{
		//cout<<"For node "<<i<<endl;
		for(int j=0;j<individual_list[i].size();j++)
		{
		//	cout<<"Child Number "<<j<<endl;
			for(int k=j+1;k<individual_list[i].size();k++)
			{
		//			cout<<"With child number "<< k<<endl;
				for(map<int,int>::iterator first=individual_list[i][j].begin();first!=individual_list[i][j].end();first++)
				{
					for(map<int,int>::iterator second=individual_list[i][k].begin();second!=individual_list[i][k].end();second++)
					{
		//				cout<<"Checking for "<<first->first<<" "<<second->first<<endl;
						if(isSet(first->first+second->first))
						{
		//					cout<<"Prime... ";
		//					cout<<"Adding "<<(first->second)*(second->second)<<endl;
							paths+=(first->second)*(second->second);
		//					cout<<"Paths = "<<paths<<endl;
						}
					}
				}
			}	
		}
	}
	
//	cout<<"now checking children list"<<endl;
		
	// counting all paths thar starts from ith node
	for(int i=1;i<children.size();i++)
	{
//		cout<<"For node "<<i<<endl;
		for(map<int,int>::iterator j=children[i].begin(); j!=children[i].end();j++)
		{
//			cout<<"Checking for" <<j->first<<endl;
			if(isSet(j->first))
			{
//				cout<<"Prime";
				paths+=j->second;
//				cout<<"Adding "<<j->second;
//				cout<<" Paths = "<<paths;
			}
		}
	}	
	return paths;
}

//------------------------------------------------------------------------------
void debug()
{
//	for(int i=1;i<individual_list.size();i++)
//	{
//		cout<<"Individual List for "<<i<<endl;
//		for(int j=0;j<individual_list[i].size();j++)
//		{
//			cout<<"Child number "<<j<<endl; 
//			for(map<int,int>::iterator k=individual_list[i][j].begin();k!=individual_list[i][j].end();k++)
//			{
//				cout<<k->first<<" "<<k->second<<endl;
//			}
//		}
//	}
}
//------------------------------------------------------------------------------
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("testprimedst.txt","r",stdin);
	#endif
	sieve();
	int n;
	cin>>n;
	vector<list<int> > tree;

	tree.resize(n+1);
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	istraversed.resize(n+1);
	children.resize(n+1);
	individual_list.resize(n+1);
	inorder(tree,1);
//	debug();
	
	long long total_paths=(n*(n-1))/2;
	cout<<(double(prime_paths()))/total_paths<<endl;
}

