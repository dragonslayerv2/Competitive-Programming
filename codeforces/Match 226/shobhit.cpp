#include<iostream>
using namespace std;


int main()
{
	string a;
	cin>>a;
	
	int last_h=a.size()-1;
	int h=a.size()-1;
	int count=0;
	
	while(h>=0)
	{
		count++;
		while(h>=0&&a[h]=='0')	
			h--;
		if((last_h-h+1)==((h-1)-(0)+1))
		{
			if(a.substr(0,(h-1)-(0)+1)<a.substr(h,(last_h-h+1)))
				h--;
		}
		if((last_h-h+1)>((h-1)-(0)+1))
			break;
		h--;
		last_h=h;
	}
	cout<<count;
}
