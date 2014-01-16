#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#include<stdio.h>
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
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 
    			
              c=GETCHAR();
              if(c=='-')
              	sign=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return sign*n;
}
 
pair<int,int> maxsubarray(vector<int> &a)
{
	long long max_so_far=0;
	long long max_ending_here=0;
	int count_ending_here=0;
	int global_count=0;
	int global_start=0;
	int start_ending_here=0;
	
	for(int i=0;i<a.size();i++)
	{
		count_ending_here++;
		max_ending_here+=a[i];
		
		if(max_ending_here<0)
		{
			count_ending_here=0;
			start_ending_here=i+1;
			max_ending_here=0;	
		}
		
		if(max_so_far<max_ending_here)
		{
			max_so_far=max_ending_here;
			global_count=count_ending_here;
			global_start=start_ending_here;
		}
	}
	//cout<<global_start<<global_count;
	return make_pair(global_start,global_count);
}

int main()
{
	int t;
	t=readlong();
	while(t--)
	{
		int n;
		n=readlong();
		vector<int> pos_arr;
		vector<int> neg_arr;
		for(int i=0;i<n;i++)
		{
			int a=readlong();
		//	cout<<a;
			pos_arr.push_back(a);
			neg_arr.push_back(-1*a);
		}
		
		
		long long sum=0;
		pair<int,int> minarray=maxsubarray(neg_arr);
		//cout<<minarray.first<<" "<<minarray.second<<endl;
		int start=0;
		for(;start<minarray.first;start++)
		{
			sum+=pos_arr[start];	
		}
		for(int i=0;i<minarray.second;i++,start++)
		{
			sum+=neg_arr[start];
			
		}
		for(;start<n;start++)
		{
			sum+=pos_arr[start];
		}
		cout<<sum<<endl;
	}
}
