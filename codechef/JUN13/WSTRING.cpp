#include<iostream>
#include<cstring>
using namespace std;

int midsolve(char *s,int i)
{
	int MAX=0;
	int hashmap[255]={0};
	for(;s[i]!='\0'&&s[i]!='#';i++)
	{
	
		hashmap[s[i]]++;
		MAX=max(MAX,hashmap[s[i]]);
	}
	return MAX;
}

int ispossible(int i,int lcount[],int mcount[],int rcount[])
{
if(lcount[i]&&mcount[i]&&mcount[i+1]&&rcount[i+3])
return lcount[i]+ mcount[i]+ mcount[i+1]+ rcount[i+3]+3;
else return 0;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char s[20010];
		cin>>(s);

		int midcount[10010]={0};
		int lcount[10010]={0};
		int rcount[10010]={0};
		
		int hashm=0;
		int hashl=0;
		int hashr=0;
//------------------------------------------------------------------------------
		for(int i=0;s[i];i++)
		{
			if(s[i]=='#')
			{
				midcount[hashm++]=midsolve(s,i+1);		
			}
		}
//------------------------------------------------------------------------------
		int hashmap[255]={0};
		int MAX=0;
		for(int i=0;s[i]!=NULL;i++)
		{
			for(;s[i]!='\0'&&s[i]!='#';i++)
			{
	
				hashmap[s[i]]++;
				MAX=max(MAX,hashmap[s[i]]);
			}
			lcount[hashl++]=MAX;
		}
//------------------------------------------------------------------------------
		for(int i=0;i<255;i++)
			hashmap[i]=0;
			
		MAX=0;
		int l=strlen(s);
		hashr=hashm;
		for(int i=l-1;i>=0;i--)
		{
			for(;s[i]!='#'&&i>=0;i--)
			{
	
				hashmap[s[i]]++;
				MAX=max(MAX,hashmap[s[i]]);
			}
			rcount[hashr--]=MAX;
			
		}
		hashr=hashm+1;
		
		
//------------------------------------------------------------------------------
	/*	cout<<"Left"<<endl;
		for(int i=0;i<hashm;i++)
		{
			cout<<midcount[i]<<" ";
		}
		cout<<endl;
		cout<<"RIGHT"<<endl;
		for(int i=0;i<hashr;i++)
		{
			cout<<rcount[i]<<" ";
		}
		cout<<endl;
		cout<<"LEFT"<<endl;
		for(int i=0;i<hashl;i++)
		{
			cout<<lcount[i]<<" ";
		}
		cout<<endl;
		
	*/	
		int ans=0;
		for(int i=0;i<=hashm-3;i++)
		{
			int ans2=ispossible(i,lcount,midcount,rcount);
			if(ans2>0)
				ans=max(ans,ans2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
