#include<map>
#include<iostream>
using namespace std;


typedef pair<int,int> point;

int main()
{
	int n;
	cin>>n;
	
	map<point,bool> points;
	
	while(n--)
	{
		string command;
		cin>>command;
		
		point a;
		cin>>a.first>>a.second;
		
		if(command=="add")
			points[a]=true;

		else if(command=="erase")
			points.erase(a);
		
		else
		{
			bool to_erase=false;
			if(points[a]==false)
				to_erase=true;
			
			point ans=make_pair(-1,-1);
			for(map<point,bool>::iterator i=points.begin();i!=points.end();i++)
			{
				if(i->first.first>a.first&&i->first.second>a.second)
				{
					ans=i->first;
					break;
				}
			}
			if(ans==make_pair(-1,-1))
				cout<<-1<<endl;		
			else
				cout<<ans.first<<" "<<ans.second<<endl;
								
			if(to_erase)
				points.erase(a);
		}
	}
}
