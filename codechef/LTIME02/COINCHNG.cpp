#include<iostream>
using namespace std;

int check(int amount,int value)
{
	cout<<"Going for"<<amount<<endl;
	int power=1;
	
	int coins=0;
	while(power<amount) // um.. O(n) can be made much faster using binary search
	{
		power=power*value;
	}
	while(amount!=0)
	{
		while(power>amount&&power!=0)
		{
			power/=value;
		}
		coins+=amount/power;
		amount-=(amount/power)*power;
		
	}
	return coins;
}

int mat[51][501];
int generate_cs_matrix()
{
	
	for(int c=2;c<=10;c++)
	{
		for(int s=1;s<=10;s++)
		{
			cout<<"At "<<c<<" "<<s<<endl;
			int present=0;
			int count=0;
			while(count<1)
			{
				present++;
				int coins=check(present,c);
				cout<<"Checking for"<<present<<"got"<<coins<<endl;
	//			cin.get();
				if(coins==s)
				{
					count++;
				}
			}
			mat[c][s]=present;
		}
	}
}


int main()
{
	generate_cs_matrix();
	for(int i=2;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	/*int t;
	cin>>t;
	while(t--)
	{
		int c,s,k;
		cin>>c>>s>>k;
		if(k==1)
		int present=0;
		int count=0;
		while(count<k)
		{
			present++;
			int coins=check(present,c);
		//	cout<<"Checking for"<<present<<" Required ="<<coins<<endl;
			if(coins==s)
			{
				count++;
			}
		}
		cout<<present<<endl;
	}*/
}
