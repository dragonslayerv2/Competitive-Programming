#include<iostream>
#include<cstring>
using namespace std;


bool islapindrome(char *a,char *b,int l)
{
	int hash[26]={0};
	for(int i=0;i<l;i++)
	{
		hash[a[i]-'a']++;
		hash[b[i]-'a']--;
	}
	for(int i=0;i<26;i++)
	{
		if(hash[i])	return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[2000];
		cin>>a;
		int l=strlen(a);
		int ans;
		if(l%2==0)
			ans=islapindrome(a,a+l/2,l/2);
		else
			ans=islapindrome(a,a+l/2+1,l/2);
		cout<<(ans?"YES":"NO")<<endl;
	}
	return 0;
}
