#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

#ifdef ONLINE_JUDGE
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
#define GETCHAR getchar
#define PUTCHAR putchar
#endif
struct probe
{
	int id;
	int i,j;
	
	probe(int ID,int I,int J)
	{
		id=ID;
		i=I;
		j=J;
	}
	probe()	{}
};

int main()
{
//	freopen("testD.txt","r",stdin);
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b;
		char A[100],B[100];
		scanf("%s%s",&A,&B);
		a=A;
		b=B;
		vector<vector<int> > LCS(a.size()+1,vector<int>(b.size()+1));
		
		for(int i=1;i<=a.size();i++)
		{
			for(int j=1;j<=b.size();j++)
			{
				if(a[i-1]==b[j-1])
					LCS[i][j]=LCS[i-1][j-1]+1;
				else
					LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
			}
		}
		
		vector<string> strings;
		strings.reserve(10000);
		strings.push_back("");
		queue<probe> Q;
		Q.push(probe(0,a.size(),b.size()));
		
		int lastId=0;
		while(!Q.empty())
		{
			
			probe top=Q.front();
	//		cout<<"At "<<top.id<<" "<<top.i<<" "<<top.j<<endl;
			Q.pop();
			if(LCS[top.i][top.j]==0)
				continue;
			else
			{
	//			cout<<"Not zero"<<endl;
				bool probeAlreadyUsed=false;
	//			cout<<"Trying the way 1"<<endl;
				if(top.i-1>=0&&LCS[top.i][top.j]==LCS[top.i-1][top.j])
				{
	//				cout<<"Entered the first way"<<endl;
					if(probeAlreadyUsed)
					{
	//					cout<<"Creating a new probe"<<endl;
						lastId=strings.size();
						strings.push_back(strings[top.id]);
						Q.push(probe(lastId,top.i-1,top.j));
					}
					else
					{
						probeAlreadyUsed=true;
						Q.push(probe(top.id,top.i-1,top.j));
					}
				}
	//			cout<<"Trying the second phase"<<endl;
				if(top.j-1>=0&&LCS[top.i][top.j]==LCS[top.i][top.j-1])
				{
	//				cout<<"Entered the second phase"<<endl;
					if(probeAlreadyUsed)
					{
	//					cout<<"Creating a new probe"<<endl;
						lastId=strings.size();
						strings.push_back(strings[top.id]);
						Q.push(probe(lastId,top.i,top.j-1));
					}
					else
					{
						probeAlreadyUsed=true;
						Q.push(probe(top.id,top.i,top.j-1));
					}
				}
	//			cout<<"Trying the third phase"<<endl;
				if(a[top.i-1]==b[top.j-1])
				{
	//				cout<<"Entered the third phase"<<endl;
					if(probeAlreadyUsed)
					{
	//					cout<<"Creating a new probe";
						lastId=strings.size();
						strings.push_back(strings[top.id]);
						
						strings.back()=a[top.i-1]+strings.back();
						Q.push(probe(lastId,top.i-1,top.j-1));
					}
					else
					{
						probeAlreadyUsed=true;
						strings[top.id]=a[top.i-1]+strings[top.id];
						Q.push(probe(top.id,top.i-1,top.j-1));
					}
				}
			}
		}
		
	//	cout<<"Done ";
		sort(strings.begin(),strings.end());
		strings.erase(unique(strings.begin(),strings.end()),strings.end());

		for(vector<string>::iterator i=strings.begin();i!=strings.end();i++)
		{
			for(int j=0;j<i->size();j++)
				PUTCHAR((*i)[j]);
			PUTCHAR('\n');
		}
		PUTCHAR('\n');
	}
}
