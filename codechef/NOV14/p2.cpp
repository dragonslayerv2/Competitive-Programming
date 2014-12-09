#include<iostream>
#include<cstring>
using namespace std;


char s[100005];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int first=0;
		int last=strlen(s)-1;
		while(first<last)
		{
			if(s[first]==s[last])
			{
				first++;
				last--;
			}
			else
				break;
		}
		int first1=first+1;
		int last1=last;
		while(first1<last1)
		{	
			if(s[first1]==s[last1])
			{
				first1++;
				last1--;
			}
			else
				break;
		}
		int first2=first;
		int last2=last-1;
		while(first2<last2)
		{	
			if(s[first2]==s[last2])
			{
				first2++;
				last2--;
			}
			else
				break;
		}
		if(first>=last||first1>=last1||first2>=last2)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}
