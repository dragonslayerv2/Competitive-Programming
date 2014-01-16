#include<iostream>
#include<map>
using namespace std;

bool ispallindrome(const string &a)
{
	int i=0;
	int j=a.size()-1;
	
	while(i<j)
	{
		if(a[i]!=a[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	
	string a;
	cin>>a;
	map<string,int> pallindromes;
	for(int i=0;i<a.size();i++)
	{
		for(int j=1;j<=a.size()-i;j++)
		{
			if(ispallindrome(a.substr(i,j)))
			{
				pallindromes[a.substr(i,j)]++;
//				if(pallindromes[a.substr(i,j)]==1)
//					cout<<a.substr(i,j)<<endl;
			}
				
			
		}
	}
	cout<<pallindromes.size();
}
