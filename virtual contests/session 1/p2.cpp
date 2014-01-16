#include<iostream>
using namespace std;

int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	
	long long solution1=a/3+b/3+c/3;
	
	long long solution2=0;
	if(a&&b&&c)
		solution2=1+(a-1)/3+(b-1)/3+(c-1)/3;
		
	long long solution3=0;
	if(a>=2&&b>=2&&c>=2)
		solution3=2+(a-2)/3+(b-2)/3+(c-2)/3;
	
	cout<<max(solution1,max(solution2,solution3));
}
