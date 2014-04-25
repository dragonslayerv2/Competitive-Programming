#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct box
{
	int l,b,h;
	box(int L=0,int B=0,int H=0)
	{
		l=L;
		b=B;
		h=H;
	}
};

ostream & operator <<(ostream &stream,box b)
{
	stream <<"("<<b.l<<b.b<<b.h<<")";
	return stream;
}

bool Lcmp(const box A,const box B)
{
	return A.l<B.l;
}

bool isPossible(box a,box b)
{
	return (a.l<b.l)&&(a.b<b.b);
}


int main()
{
	freopen("test.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<box> B;
		B.reserve(6*n);
		B.push_back(box(INT_MAX,INT_MAX,0));
	
		for(int i=0;i<n;i++)
		{
			int l,b,h;
			cin>>l>>b>>h;
			B.push_back(box(l,b,h));
			B.push_back(box(l,h,b));
			B.push_back(box(b,l,h));
			B.push_back(box(b,h,l));
			B.push_back(box(h,l,b));
			B.push_back(box(h,b,l));			
		}
		
		sort(B.rbegin(),B.rend(),Lcmp);
		
		vector<vector<int> > DP(B.size(),vector<int>(B.size()));
		
		for(int lastTaken=0;lastTaken<B.size()-1;lastTaken++)
		{
			//cout<<"Trying to put "<<B[B.size()-1]<<" over "<<B[lastTaken]<<" "<<isPossible(B.back(),B[lastTaken])<<endl;
			
			DP[B.size()-1][lastTaken]=(isPossible(B[B.size()-1],B[lastTaken])?B[B.size()-1].h:0);
		}
			
		for(int i=B.size()-2;i>=0;i--)
			for(int lastTaken=0;lastTaken<i;lastTaken++)
			{
			//	cout<<"Trying to put "<<B[B.size()-1]<<" over "<<B[lastTaken]<<" "<<isPossible(B[i],B[lastTaken])<<endl;	
				DP[i][lastTaken]=DP[i+1][lastTaken];
				if(isPossible(B[i],B[lastTaken]))
					DP[i][lastTaken]=max(DP[i][lastTaken],B[i].h+DP[i+1][i]);	
			}	

		cout<<DP[1][0]<<endl;
	}
}
