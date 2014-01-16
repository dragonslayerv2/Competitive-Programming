#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;


pair<int,pair<int,int> > LongestAP(deque<int> &set,int beg, int n)
{
    if (n == 0)  return make_pair(0,make_pair(0,0));
    if (n == 1)  return make_pair(1,make_pair(0,0));
	if (n == 2)  return make_pair(2,make_pair(0,1));
    
    vector<vector<int> > L(n,vector<int>(n));
    pair<int,pair<int,int> > ans;
    int llap = 2; 
	ans=make_pair(2,make_pair(set[0],set[1]));
    
    for (int i = 0; i < n; i++)
    {
		L[i][n-1] = 2;
	}    

    
    for (int j=n-2; j>=1; j--)
    {
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
           if (set[beg+i] + set[beg+k] < 2*set[beg+j])
               k++;

          else if (set[beg+i] + set[beg+k] > 2*set[beg+j])
           {   L[i][j] = 2, i--;   }

           else
           {
               L[i][j] = L[j][k] + 1;
		       if(L[i][j]>llap)
		       {
			   		llap = L[i][j];
			   		ans=make_pair(llap,make_pair(set[beg+i],set[beg+j]));
			   }
               i--; k++;
           }
        }

        while (i >= 0)
        {
            L[i][j] = 2;
            i--;
        }
    }
    return ans;
}
void generate_hashmap(vector<int> &array,vector<deque<int> > &hashmap,int beg)
{
	for(int i=0;i<array.size();i++)
	{
			hashmap[array[i]].push_back(beg+i);
	}
}

void deleteremaining(int size,int elements)
{
	while(elements>0)
	{
		cout<<size<<" "<<size<<endl;
		size--;
		elements--;
	}
}
typedef pair<int,vector<int> > array;

void solve(::array & a,int partition_no)
{
	cout<<"Solving for" <<partition_no<<endl;
	vector<deque<int> > hashmap(100000);
	cout<<"Generating Hashmap"<<endl;
	generate_hashmap(a.second,hashmap,a.first);
	cout<<"Hashmap Generated";
	pair<int,pair<int,int> > ans=make_pair(-1,make_pair(-1,-1));
	for(int i=0;i<hashmap.size();i++)
	{
			
			if(hashmap[i].size()>0)
			{
				cout<<"Checking hashmap number"<<i<<endl;
				pair<int,pair<int,int> > newans=LongestAP(hashmap[i],0,hashmap.size());
				cout<<"Got LAP as "<<ans.first<<endl;
				if(newans.first>ans.first)
					ans=newans;
			}
	}
	
	if(ans.first<=2)
	{
		cout<<"Deleting whole array";
		for(int i=0;i<a.second.size();i++)
		{
			cout<<a.first<<" "<<a.second.size()<<endl;
			a.first++;
		}
	}
	else
	{
		int d=ans.second.second-ans.second.first;
		int n=ans.first;
		int l=ans.second.first+(n-1)*d;
		cout<<"Deleting array after l"<<endl;
		for(int i=l+1;i<=(partition_no+1)*a.second.size();i++)
		{
			cout<<i<<" "<<a.second.size()<<endl;
			a.second.pop_back();		
		}
		cout<<"Clearing AP terms"<<endl;
		cout<<ans.second.first<<" "<<d;
		int left=a.second.size()-n;
		cout<<"Deleting left elements";
		while(left)
		{
			
			cout<<a.first<<" "<<a.second.size()<<endl;
			left--;
		}
	}
} 

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	//	freopen("out.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	
	::array arrays[10];
	
	int no_of_elements=a.size()/10;
	int remaining=a.size()%10;
	
	deleteremaining(a.size(),remaining);
		
	for(int i=0;i<10;i++)
	{
		arrays[i].first=i*no_of_elements+1;
		arrays[i].second.reserve(no_of_elements);
		
		for(int j=0;j<no_of_elements;j++)
		{
			arrays[i].second.push_back(a[i*no_of_elements+j]);
		}
	}
	
	for(int i=9;i>=0;i--)
	{
		solve(arrays[i],i);
	}	
}

