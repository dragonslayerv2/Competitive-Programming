#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define CHUNK_SIZE 320

struct query{
	pair<int,int> range;
	int id;
};

bool cmp(query a,query b){
	a.range.first/=CHUNK_SIZE;
	b.range.first/=CHUNK_SIZE;
	return a.range<b.range;
}

vector<int> a;
vector<int> frequency(1000007);
long long answer=0;

void remove(int pos){
	answer-=frequency[a[pos]]*frequency[a[pos]]*a[pos];
	frequency[a[pos]]--;
	answer+=frequency[a[pos]]*frequency[a[pos]]*a[pos];
}

void add(int pos){
	answer-=frequency[a[pos]]*frequency[a[pos]]*a[pos];
	frequency[a[pos]]++;
	answer+=frequency[a[pos]]*frequency[a[pos]]*a[pos];
}

int getAnswer(){
	return answer;
}

int main(){
	
	int n,t;
	cin>>n>>t;
	a.assign(n,0);
	vector<query> queries(t);
	vector<long long> answers(t);
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<t;i++){
		cin>>queries[i].range.first>>queries[i].range.second;
		queries[i].range.first--;
		queries[i].range.second--;
		queries[i].id=i;
	}
	
	sort(queries.begin(),queries.end(),cmp);
	
	int l=0,r=-1;
	
	for(int i=0;i<queries.size();i++){
		while(l<queries[i].range.first){
			remove(l);
			l++;
		}
		while(l>queries[i].range.first){
			l--;
			add(l);
		}
		while(r<queries[i].range.second){
			r++;
			add(r);
		}
		while(r>queries[i].range.second){
			remove(r);
			r--;
		}
		answers[queries[i].id]=getAnswer();
	}
	
	for(int i=0;i<answers.size();i++)
		cout<<answers[i]<<endl;
}
