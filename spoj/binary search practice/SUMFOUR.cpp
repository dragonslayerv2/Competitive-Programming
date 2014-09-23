#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
using namespace std;

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
    }
    return sign*n;
}

int main(){
//	freopen("t.txt","r",stdin);
	int n=readlong();
	int values[n][4];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
			values[i][j]=readlong();
		
	map<int,int> cdCount;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cdCount[values[i][2]+values[j][3]]++;
	
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			map<int,int>::iterator invertValue = cdCount.find(-(values[i][0]+values[j][1]));
			if(invertValue!=cdCount.end())
				ans+=invertValue->second;	
		}
	cout<<ans;
}
