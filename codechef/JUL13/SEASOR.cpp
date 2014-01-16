#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

//kashish version



void print(vector<int> &a)
{
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<int> array(n);
		vector<int> sort1(n);
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			array[i]=sort1[i]=a;
		}
		
		vector<int> i1;
		i1.reserve(n);
		for(int i=0;i<n-1;i++)
		{
			if(array[i]>array[i+1])
			{
				sort(array.begin()+i,array.begin()+min((i+k-1),(n-1))+1);
				i1.push_back(i+1) ;
				i = -1;
			}
		}
		
		copy(sort1.begin(),sort1.end(),array.begin());
		
		vector<int> i2;
		i2.reserve(n);
		for(int i=n-1;i>0;i--)
		{
			if(array[i-1]>array[i])
			{
				sort(array.begin()+i-1,array.begin()+min((i+k-2),(n-1))+1);
				i2.push_back(i);	
			 	i = n;
			}
		}
		
		copy(sort1.begin(),sort1.end(),array.begin());
		
		int i=0;
		int l=n-1;
		
		vector<int> i3;
		i3.reserve(n);
		while(i<n-1 && l>0)
		{
			for(;i<n-1;i++)
			{
				if(array[i]>array[i+1])
				{
		              	sort(array.begin()+i,array.begin()+min((n-1),(i+k-1))+1);
						i3.push_back(i+1);
						i = 0;
						break;
				}
			} 
			
			for(;l>0;l--)
			{
				if(array[l-1]>array[l])
				{
			    	int m= l-k+1;
			    	if(m<0)
			    		m=0;
					sort(array.begin()+m,array.begin()+l+1);
					i3.push_back( m+1);	
			 		l = n-1;
			 		break;
				}
			}	
		}
		copy(sort1.begin(),sort1.end(),array.begin());
		
		i=0;
		l=n-1;
		vector<int> i4;
		i4.reserve(n);
		while(i<n-1 && l>0)
		{
			for(;l>0;l--)
			{
				if(array[l-1]>array[l])
				{
			    	int m= l-k+1;
			    	if(m<0)
			    		m=0;
					sort(array.begin()+m,array.begin()+l+1);
					i4.push_back(m+1);	
			 		l = n-1;
			 		break;
				}
			}
			for(;i<n-1;i++)
			{
				if(array[i]>array[i+1])
				{
					int m = min((n-1),(i+k-1));
		           	sort(array.begin()+i,array.begin()+m+1);
					i4.push_back( i+1);
					i = 0;
					break;
				}
			} 	
		}
		copy(sort1.begin(),sort1.end(),array.begin());
		
		
		
		bool flag1=true,flag2=true;
		vector<int> i5;
		i5.reserve(n);
	    while(flag1||flag2)
		{
			flag1 =flag2=false;
			for(l=n-1;l>0;l--)
			{
			
				if(array[l-1]>array[l])
				{
			    	int m= l-k+1;
			    	if(m<0)
			    		m=0;
					sort(array.begin()+m,array.begin()+l+1);
					i5.push_back(m+1);
					flag1=true;
				}
			}
			for(i=0;i<n-1;i++)
			{
				if(array[i]>array[i+1])
				{
					int m = min((n-1),(i+k-1));
		            sort(array.begin()+i,array.begin()+m+1);
					i5.push_back(i+1);
					flag2=true;
				}
			} 
		
		}
		
		size_t minj = min(i1.size(),i2.size());
		minj	 = min(minj     ,i3.size());     
		minj	 = min(minj     ,i4.size());
		minj	 = min(minj     ,i5.size());
		
		
		if(minj==i1.size())
			print(i1);
		else if(minj==i2.size())
			print(i2);
		else if(minj==i3.size())
			print(i3);
		else if(minj==i4.size())
			print(i4);
		else if(minj==i5.size())
			print(i5);
			
	}
}
