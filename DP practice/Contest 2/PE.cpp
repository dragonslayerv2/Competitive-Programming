#include<iostream>
#include<limits>
#include<vector>
#include<ctype.h>
using namespace std;

int main()
{
	freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		vector<int> operands;
		vector<char> operators;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='+'||a[i]=='*')
				operators.push_back(a[i]);
			else
				operands.push_back(a[i]-'0');
		}
		
		vector<vector<long long> > DPmin(operands.size(),vector<long long>(operands.size(),numeric_limits<long long>::max()));
		vector<vector<long long> > DPmax(operands.size(),vector<long long>(operands.size()));
		
		for(int len=0;len<operands.size();len++)
			for(int i=0;i+len<operands.size();i++)
		{
						//cout<<"Calculating for"<<i<<" "<<i+len<<endl;
				if(len==0)
					DPmin[i][i]=DPmax[i][i]=operands[i];
				else
				{
					int j=i+len;
					for(int k=i;k<j;k++)
					{
						//cout<<"Going for"<<i<<" "<<j<<endl;
						if(operators[k]=='+')
						{
							DPmax[i][j]=max(DPmax[i][j],DPmax[i][k]+DPmax[k+1][j]);
							DPmin[i][j]=min(DPmin[i][j],DPmin[i][k]+DPmin[k+1][j]);
						}
						else
						{
							DPmax[i][j]=max(DPmax[i][j],DPmax[i][k]*DPmax[k+1][j]);
							DPmin[i][j]=min(DPmin[i][j],DPmin[i][k]*DPmin[k+1][j]);
						}
					} 
				}
			}
		cout<<DPmax.front().back()<<" "<<DPmin.front().back()<<endl;
	}
}
