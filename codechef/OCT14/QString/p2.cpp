#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int choose_locations(vector < int > possible_locations, int num_friends, int total_distance) 
{
	sort(possible_locations.begin(),possible_locations.end());
	int low=0;
	int high=total_distance;
	int ans=0;
	int mid;


	int x=num_friends;
	
	int flag=0;
	int n=possible_locations.size();
	while(low<=high)
	{
		int prev=0;
		mid=(low+high)/2;
		int count=1;

		for(int i=0;i<n;i++)
		{
			if(possible_locations[i]-prev>=mid)
			{
				prev=possible_locations[i];
				count++;
			}
			if(count>=x-1 && total_distance-prev>=mid)
			{
				flag=1;
				break;
			}
		}
		if(count>=x-1 && flag==1)
		{
			ans=mid;
			low=mid+1;
		}
		else
			high=mid-1;
	}
	return ans;
}

int main(){
	vector<int> pos={35, 60, 100, 335, 440, 450, 570, 880};
	int numFriends=4;
	int totalDistance=1000;
	cout<<choose_locations(pos,numFriends,totalDistance);
}
