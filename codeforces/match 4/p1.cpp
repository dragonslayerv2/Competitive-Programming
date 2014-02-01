#include<iostream>
#include<cstdio>
using namespace std;


string padzero(int a)
{
	string s="00";
	s[1]+=a%10;
	s[0]+=a/10;
	return s;
}
int main()
{
	int sH,sM;
	int tH,tM;
	char temp;
	scanf("%d:%d",&sH,&sM);
	scanf("%d:%d",&tH,&tM);
	
	int ans=(sH-tH)*60+(sM-tM);
	if(ans<0)
		ans+=24*60;	
	
	cout<<padzero(ans/60)<<":"<<padzero(ans%60);
	
}
