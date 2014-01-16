#include<iostream>
#include<cstring>
using namespace std;


int main()
{
	while(1)
	{
		char code[6000];
		cin>>code;
		if(code[0]=='0')
			break;
		int len=strlen(code);
		long long DP[6000];
		DP[len-1]=code[len-1]!='0';
		DP[len]=1;
		for(int i=len-2;i>=0;i--)
		{
			if(code[i]=='0')
				DP[i]=0;
			else
			{	
				DP[i]=DP[i+1];
				if((code[i]-'0')*10+(code[i+1]-'0')<=26)
					DP[i]+=DP[i+2];
			}
		}
		cout<<DP[0]<<endl;
	}
}
