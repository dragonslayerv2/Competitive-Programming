#include<iostream>
using namespace std;

int solve(string &s,int l,int h)
{
	cout<<"solving for"<<s.substr(l,h-l+1)<<endl;
	if(l==h-1)
	{
		if(s[l]>=s[h])
			return 2;
		else
			return 1;
	}
	else if(l>h)
		return 0;
	else if(l==h)
		return 1;
	else
	{
		int mid=(l+h)/2;
		if(((h-l+1)%2)==0&&(mid==(l+h)/2)&&s[l]<s[mid+1])// odd cases
			mid++;
		while(mid+1<s.size()&&s[mid+1]=='0')
				mid++;
		if(mid>=h||mid<=l)
			return 1;
		else
			return  solve(s,l,mid)+solve(s,mid+1,h);
	}
}

int main()
{
	string s;
	cin>>s;
	cout<<solve(s,0,s.size()-1);
}
