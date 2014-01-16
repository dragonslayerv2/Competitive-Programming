#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int QUEUESTATE;
struct player
{
	string name;
	int shots;
	int height;
	
	bool operator <(const player &p2) const
	{
		if(shots<p2.shots)
			return true;
		if(shots==p2.shots&&height<p2.height)
			return true;
		else
			return false;
	}
};


struct active_player
{
	int time;
	int draft;
	string *name;
	int lastpush;
	public:
		active_player(int T,int D,string *N,int L)
		{
			time=T;
			draft=D;
			name=N;
			lastpush=L;
		}
};

class active_player_lesser
{
public:
	bool operator ()(active_player a,active_player b)
	{
		if(a.lastpush!=-1)
			a.time=a.time+QUEUESTATE-a.lastpush;
		if(b.lastpush!=-1)
			b.time=b.time+QUEUESTATE-b.lastpush;
		
	//	cout<<"Comparing "<<*a.name<<" = "<<a.time;
	//	cout<<"Comparing "<<*b.name<<" = "<<b.time;
	//	cout<<endl;
		if(a.time<b.time)
			return true;
		if(a.time==b.time&&a.draft<b.draft)
			return true;
		else
			return false;
	}
};
class inactive_player_lesser
{
public:
	bool operator ()(active_player a,active_player b)
	{
		if(a.time>b.time)
			return true;
		if(a.time==b.time&&a.draft>b.draft)
			return true;
		else
			return false;
	}
};

template<class T> void print(T a)
{
	while(a.size())
	{
		cout<<*a.top().name<<" ";
		a.pop();
	}
	cout<<endl;
}

int main()
{
//	freopen("out2.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n,m,p;
		cin>>n>>m>>p;
		vector<player> players(n);
		for(int i=0;i<n;i++)
		{
			cin>>players[i].name;
			cin>>players[i].shots;
			cin>>players[i].height;
		}
		sort(players.rbegin(),players.rend());
		
		QUEUESTATE=0;
		priority_queue<active_player,vector<active_player>,active_player_lesser> play1,play2;
		
		for(int i=0;i<p;i++)
			play1.push(active_player(0,i,&players[2*i].name,QUEUESTATE));
		for(int i=0;i<p;i++)
			play2.push(active_player(0,i,&players[2*i+1].name,QUEUESTATE));
		
		priority_queue<active_player,vector<active_player>,inactive_player_lesser> team1,team2;
		for(int i=2*p;i<n;i+=2)
			team1.push(active_player(0,i/2,&players[i].name,-1));
		for(int i=2*p+1;i<n;i+=2)
			team2.push(active_player(0,i/2,&players[i].name,-1));
		
		for(int i=0;i<m;i++)
		{
			QUEUESTATE++;
			if(play1.size()&&team1.size())
			{
				active_player team1_active=play1.top();
				play1.pop();
					
				team1_active.time+=QUEUESTATE-team1_active.lastpush;
				team1_active.lastpush=-1;
				
				active_player team1_inactive=team1.top();
				team1.pop();
				
				team1_inactive.lastpush=QUEUESTATE;
				
				play1.push(team1_inactive);
				team1.push(team1_active);
				
				//cout<<"Poped"<<*team1_active.name<<team1_active.time<<" Pushed "<<*team1_inactive.name<<" "<<team1_inactive.time<<endl;
				
			}
			
			if(play2.size()&&team2.size())
			{
				active_player team2_active=play2.top();
				play2.pop();
				
				team2_active.time+=QUEUESTATE-team2_active.lastpush;
				team2_active.lastpush=-1;
				
				active_player team2_inactive=team2.top();
				team2.pop();
				
				team2_inactive.lastpush=QUEUESTATE;
				
				play2.push(team2_inactive);
				team2.push(team2_active);
				
			}
		}
		
		vector<string> solution; 
		while(play1.size())
		{
				solution.push_back(*play1.top().name);
				play1.pop();	
		}
		
		while(play2.size())
		{
				solution.push_back(*play2.top().name);
				play2.pop();	
		}
		sort(solution.begin(),solution.end());
		
		cout<<"Case #"<<T<<": ";
		for(int i=0;i<solution.size();i++)
			cout<<solution[i]<<" ";
		cout<<endl;
	}
}

