#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	
	long long alpha=min(a,min(b,c));
	a-=alpha;
	b-=alpha;
	c-=alpha;
	
	long long term1,term2;
	if(c==0){
		term1=a;
		term2=b;
	}
	else if(b==0){
		term1=a;
		term2=c;
	}
	else
	{
		term1=b;
		term2=c;
	}
	
	long long difference=max(term1,term2)-min(term1,term2);
	long long beta=min(term1,min(term2,difference));	
	if(max(term1,term2)==term1){
		term1-=2*beta;
		term2-=beta;	
	}
	else{
		term1-=beta;
		term2-=2*beta;	
	}
	
	long long gamma=0;
	if(term1&&term2)
	
		gamma=(2*term2)/3;
	cout<<alpha+beta+gamma;
}
