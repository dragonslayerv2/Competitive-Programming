#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

void computePiFunction(char *p,int *Pi)
{
		int m=strlen(p);

		Pi[0]=-1;
		int k=-1;
		
		for(int i=1;i<m;i++)
		{
		
			while(k>=0&&p[k+1]!=p[i])
				{k=Pi[k];}
			if(p[k+1]==p[i])
				k++;
			Pi[i]=k;	
		}
}

void matcher(char *P,char *T,int *Pi,vector<int>& foundAt)
{
	int m=strlen(P);
	int q=-1;
	for(int i=0;T[i];i++)
	{
		while(q>=0&&P[q+1]!=T[i])
			q=Pi[q];
		if(P[q+1]==T[i])	
			q++;
		if(q==m-1)
		{
			foundAt.push_back(i-m+1);
			q=Pi[q];
		}
	}
}


#define PATTERN_SIZE 1000000
#define TEXT_SIZE 1000000
#define MOD 1000000007
char pattern[PATTERN_SIZE],text[TEXT_SIZE];
int Pi[PATTERN_SIZE];
int main()
{	
	cin>>text;
	cin>>pattern;
	int patternLength=strlen(pattern);
	computePiFunction(pattern,Pi);
	int textLength=strlen(text);
	vector<int> foundAt;
	matcher(pattern,text,Pi,foundAt);
	long long answer=0;
	
	vector<int> nextFound(textLength);
	
	int foundAtPos=0;
	for(int i=0;i<nextFound.size();i++){
		if(foundAtPos<foundAt.size())
		{
			nextFound[i]=foundAt[foundAtPos];
			if(i==foundAt[foundAtPos])
				foundAtPos++;
		}
		else
			nextFound[i]=-1;
	}
	
	vector<long long> solution(textLength,0);
	vector<long long> prefixSum(textLength+1,0);
	vector<long long> sumSum(textLength+1,0);
	prefixSum.back()=sumSum.back()=1;
	for(int i=solution.size()-1;i>=0;i--){
		if(nextFound[i]<0)
			solution[i]=0;
		else
			solution[i]=sumSum[nextFound[i]+patternLength];
		
		prefixSum[i]=solution[i];
		if(i+1<prefixSum.size())
		{
			prefixSum[i]+=prefixSum[i+1];
			prefixSum[i]%=MOD;
		}
		
		sumSum[i]=prefixSum[i];
		if(i+1<sumSum.size())
		{
			sumSum[i]+=sumSum[i+1];
			sumSum[i]%=MOD;
		}
	}
	for(int i=0;i<nextFound.size();i++)
		cout<<nextFound[i]<<" "<<solution[i]<<" "<<prefixSum[i]<<" "<<sumSum[i]<<endl;
	cout<<(MOD+prefixSum[0]-1)%MOD;
}
