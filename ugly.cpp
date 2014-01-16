#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<long long> uglynumber;
	uglynumber.reserve(n);
	uglynumber.push_back(2);
	uglynumber.push_back(3);
	uglynumber.push_back(5);
	int pos_two=0;
	int pos_three=0;
	int pos_five=0;
	while(uglynumber.size()<n)
	{
		if(uglynumber[pos_two]*2<uglynumber[pos_three]*3&&uglynumber[pos_two]*2<uglynumber[pos_five]*5)
		{
			uglynumber.push_back(uglynumber[pos_two]*2);
			pos_two++;
		}
		else if(uglynumber[pos_three]*3>uglynumber[pos_two]*2&&uglynumber[pos_three]*3<uglynumber[pos_five]*5)
		{
			uglynumber.push_back(uglynumber[pos_three]*3);
			pos_three++;
		}
		else
		{
			uglynumber.push_back(uglynumber[pos_five]*5);
			pos_five++;
		}
		cout<<uglynumber.back();
	}
}
