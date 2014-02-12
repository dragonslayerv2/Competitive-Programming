#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n,k,w;
	cin>>n>>k>>w;
	string box;
	cin>>box;
	
	vector<vector<int> > prefix_array(k,vector<int>(n));
	for(int i=0;i<k;i++)
	{
		for(int j=i;j<n;j++)
		{
			if((j-i+1)%k==0)
				prefix_array[i][j]=(box[j]!='1');
			else
				prefix_array[i][j]=(box[j]!='0');
		}
	}
	
	for(int i=0;i<k;i++)
		for(int j=1;j<n;j++)
			prefix_array[i][j]+=prefix_array[i][j-1];
	
	while(w--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		
		
		int high=prefix_array[x%k][y];
		int low;
		if(x-1>=0)
			low=prefix_array[x%k][x-1];
		else
			low=0;
		cout<<high-low<<endl;
	}
	
}
