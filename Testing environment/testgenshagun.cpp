#include<iostream>

#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	freopen("test.txt","w",stdout);
	int t=1000;
	cout<<t<<endl;
	while(t--)
	{
		string a="abcdefghhijklmnopqrstuvwxyz";
		
		for(int i=0;i<26;i++)
			swap(a[i],a[rand()%a.size()]);
		cout<<a<<endl;
		char specialchars[]={'!','@','!','@','#','$','%','^','&','*','(',')'};
		for(int i=0;i<100000;i++)
		{
			int cases=rand()%4;
			if(cases==0)
				cout<<" ";
			else if(cases==1)
				cout<<(char)('a'+rand()%26);
			else if(cases==2)
				cout<<(char)('A'+rand()%26);
			else
				cout<<specialchars[rand()%(sizeof(specialchars))];
		}
		cout<<endl;
	}
}
