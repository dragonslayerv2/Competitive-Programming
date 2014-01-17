#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	
	sort(array.begin(),array.end());
	set<int> solution;
	if(array.size()==1)
		cout<<-1;
	else
	{
		if(array.size()==2)
		{
		if((array[0]+array[1])%2==0)
			solution.insert((array[0]+array[1])/2);
		
		solution.insert(2*array[0]-array[1]);
		solution.insert(2*array[1]-array[0]);
		}
	else if(array.size()==3)
	{
		int a=array[0],b=array[1],c=array[2];
		if(array[1]-array[0]==array[2]-array[1])
		{
			solution.insert(2*array[0]-array[1]);
			solution.insert(2*array[2]-array[1]);
		}
		
		else if(array[1]-array[0]>array[2]-array[1])
		{
			int x=2*array[1]-array[2];
			if((b+a)%2==0&&(b+a)/2==x&&a+c-b==x)
				solution.insert(x);
		}
		else
		{
			int x=2*b-a;
			//cout<<x;
			
			if((b+c)%2==0&&(b+c)/2==x&&x==c+a-b)
				solution.insert(x);
		}
	}
	else
	{
		map<int,pair<int,int> > differences;
		for(int i=1;i<array.size();i++)
		{
			differences[array[i]-array[i-1]].first++;
			differences[array[i]-array[i-1]].second=i;
		}
		if(differences.size()==1)
		{
			solution.insert(2*array[0]-array[1]);
			solution.insert(2*array[n-1]-array[n-2]);
		}
		else if(differences.size()==2)
		{
			map<int,pair<int,int> >::iterator dif1=differences.begin();
			map<int,pair<int,int> >::iterator dif2=differences.begin();
			dif2++;
			if(dif1->second.first==1)
			{
				if(dif1->first%2==0&&dif1->first/2==dif2->first)
				{
					solution.insert(array[dif1->second.second]-dif2->first);
				}
			}
			else if(dif2->second.first==1)
			{
				if(dif2->first%2==0&&dif2->first/2==dif1->first)
				{
					solution.insert(array[dif2->second.second]-dif1->first);
				}
			}
		}
	}
	cout<<solution.size()<<endl;
	for(set<int>::iterator i=solution.begin();i!=solution.end();i++)
		cout<<*i<<" ";
	}
}

