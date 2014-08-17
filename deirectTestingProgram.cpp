#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<bool> table(n);
	int m;
	cin>>m;
	while(m--)
	{
		char type;
		int a;
		cin>>type;
		
		if(type=='i')
		{
			cin>>a;
			table[a]=true;
		}
		else if(type =='d')
		{
			cin>>a;
			table[a]=false;
		}	
		else if(type=='r')
		{
		//	cout<<"Rank query";
			cin>>a;
			int k=0;
			for(int i=0;i<=a;i++)
				k+=table[i];
			cout<<k<<endl;
		}
		else if(type=='k')
		{
			cin>>a;
			int k=a;
			for(int i=0;i<n;i++)
			{
				if(table[i])
					k--;
				if(k==0)
				{
					cout<<i<<endl;
					break;
				}
			}
			if(k!=0)
				cout<<-1<<endl;
		}
		else if(type=='f')
		{
			int k=1;
			for(int i=0;i<n;i++)
			{
				if(table[i]==true)
				{
					cout<<i<<endl;
					k--;
					break;
				}
			}
			if(k!=0)
				cout<<-1<<endl;
		}
			
		else if(type=='b')
		{
			int k=1;
			for(int i=n-1;i>=0;i--)
			{
				if(table[i]==true)
				{
					cout<<i<<endl;
					k--;
					break;
				}
			}
			if(k!=0)
				cout<<-1<<endl;
		}
		else if(type=='s')
		{
			cin>>a;
			bool found=false;
			for(int i=a+1;i<n;i++)
				if(table[i])
				{
					cout<<i<<endl;
					found=true;
					break;
				}
			if(!found)
				cout<<-1<<endl;
		}
		else if(type=='p')
		{
			cin>>a;
			bool found=false;
			for(int i=a-1;i>=0;i--)
				if(table[i])
				{
					cout<<i<<endl;
					found=true;
					break;
				}
			if(!found)
				cout<<-1<<endl;
		}
	}	
}
