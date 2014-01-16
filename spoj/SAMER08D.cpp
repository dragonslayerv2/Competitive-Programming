#include<iostream>
#include<cstring>
using namespace std;

#define MAX 2005
int solution[MAX][MAX];
bool exist[MAX][MAX];


int solve(char *a,char *b,int k,int a_len,int b_len,int a_present=0,int b_present=0)
{
	if(a_present==a_len)
		return 0;
	if(b_present==b_len)
		return 0;
	
	if(!exist[a_present][b_present])
	{
		int len=0;
		while((a_present+len)<a_len&&(b_present+len)<b_len&&a[a_present+len]==b[b_present+len])
			len++;
		int result=0;
		if(len>=k)
			result=len+solve(a,b,k,a_len,b_len,a_present+len,b_present+len);
		
			result=max(result,max(solve(a,b,k,a_len,b_len,a_present+1,b_present),solve(a,b,k,a_len,b_len,a_present,b_present+1)));
		
		exist[a_present][b_present]=true;
		solution[a_present][b_present]=result;
	}
	return solution[a_present][b_present];
}


int main()
{
	int k;
	char a[MAX],b[MAX];
	
	while(1)
	{
		scanf("%d",&k);
		if(k==0)
			break;
		
		scanf("%s%s",a,b);
		int l1=strlen(a),l2=strlen(b);
		for(int i=0;i<l1;i++)
			for(int j=0;j<l2;j++)
				exist[i][j]=false;	
		
		cout<<solve(a,b,k,l1,l2)<<endl;
	}
}
