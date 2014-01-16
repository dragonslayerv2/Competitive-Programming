#include<iostream>
#include<cstring>
using namespace std;
#define MAX 25010 

#define max(a,b) a>b?a:b
int LCS(char *a,char *b)
{
    int LCS[MAX];
    memset(LCS,0,sizeof(LCS));
    int up,diagnol;
    int i;
    for(;*b;*b++)
    {
                 diagnol=0;
                for(i=1;a[i-1];i++)
                 {
                         up=LCS[i];        
                         if(a[i-1]==*b) LCS[i]=diagnol+1;
                         else LCS[i]=max(LCS[i-1],up);
                         diagnol=up;
                 }
    }
    return LCS[i-1];

}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[MAX],b[MAX];
		cin>>a>>b;
		int la=strlen(a);
		int lb=strlen(b);
		int lLCS=LCS(a,b);
		
		if(la==lLCS||lb==lLCS)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;	
	}
}
