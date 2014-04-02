#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	vector<int> maxPieces(n+1,0);
	for(int i=min(min(a,b),c);i<=n;i++)
	{
		int currentAns=0;
		if(i-a==0)
			currentAns=1;
		else if(i-b==0)
			currentAns=1;
		else if(i-c==0)
			currentAns=1;
		
		if(i-a>0&&maxPieces[i-a]!=0)
			currentAns=max(currentAns,maxPieces[i-a]+1);
		if(i-b>0&&maxPieces[i-b]!=0)
			currentAns=max(currentAns,maxPieces[i-b]+1);
		if(i-c>0&&maxPieces[i-c]!=0)
			currentAns=max(currentAns,maxPieces[i-c]+1);
			
		maxPieces[i]=currentAns;
	}
	cout<<maxPieces[n];
}
