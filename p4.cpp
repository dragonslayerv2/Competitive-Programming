#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct result{
	long long time;
	long long w;
	long long h;
	
	result(long long time=0,int w=0, int h=0){
		this->time=time;
		this->w=w;
		this->h=h;
	}
	bool operator<(const result t2) const
	{
		if(time!=t2.time)
			return time<t2.time;
		else
			return make_pair(w,h)<make_pair(w,h);
	}
};

vector<int> tank;
vector<vector<result> > solution;

result solve(int l,int r,int c){
	if(l==r)
		return result(0,tank[l],1);
	else{
		if(solution[l][r].h==-1){
			solution[l][r]=result(INT_MAX,0,0);
			for(int i=l;i<r;i++){
				result left=solve(l,i,c);
				result right=solve(i+1,r,c);
				result newResult=result(max(left.time+right.time+left.w*left.h+right.w+right.h-c,0LL),left.w+right.w,left.h+right.h);
				solution[l][r]=min(solution[l][r],newResult);	
			}
			
		}
		return solution[l][r];
	}			
}

int main(){
	//freopen("test.txt","r",stdin);
	int n,t;
	cin>>n>>t;
	tank.resize(n);
	
	for(int i=0;i<n;i++)
		cin>>tank[i];
	
	
	
	
	int l=0;
	int r=t;
	while(l<=r){
		//cout<<"Between "<<l<<" "<<r<<endl;
		solution.assign(n,vector<result>(n,result(0,0,-1)));
		int mid	= (l+r)/2;
		//cout<<"Checking mid";
		if(solve(0,n-1,mid).time<=t){
		//	cout<<"True"<<endl;
			r=mid-1;
		}
		else{
		//	cout<<"False"<<endl;
			l=mid+1;
		}
			
	}
	cout<<l;
}
