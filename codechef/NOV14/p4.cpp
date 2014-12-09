#include<iostream>
#include<cstring>
#include<set>
using namespace std;


double prob[26][26];
double kProb[26][26];
void getPower(long long k)
{
    if(k==0) 
		return;
    
    getPower(k/2);
    double temp[26][26];
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			temp[i][j]=0;
	
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			for(int k=0;k<26;k++)
				temp[i][j]+=kProb[i][k]*kProb[k][j];
				
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			kProb[i][j]=temp[i][j];
			
    if(k%2){
    	for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				temp[i][j]=0;
			
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				for(int k=0;k<26;k++)
					temp[i][j]+=kProb[i][k]*prob[k][j];
		
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				kProb[i][j]=temp[i][j];
    }
}
#include<cstdio>
int main(){
//	freopen("test4.txt","r",stdin);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		char initialString[5];
		cin>>initialString;
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++){
				kProb[i][j]=0;
				cin>>prob[i][j];
			}
				
		
		for(int i=0;i<26;i++)
			kProb[i][i]=1;
		getPower(k);
			
		double ans=0;
		set<string> SET;
		while(n--){
			string newString;
			cin>>newString;
			if(newString.length()==strlen(initialString)){
				if(SET.find(newString)==SET.end()){
					SET.insert(newString);
					double currentAnswer=1;
					for(int i=0;newString[i];i++)
						currentAnswer*=kProb[initialString[i]-'a'][newString[i]-'a'];
					ans+=currentAnswer;	
				}
				
			}
		}
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<ans<<endl;
	}
}
