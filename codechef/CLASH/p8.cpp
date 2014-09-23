#include<bits/stdc++.h>
using namespace std;

struct node{
	node *digit[10];
	node(){
		for(int i=0;i<10;i++)
			digit[i]=NULL;
	}
};
void insert_trie(node *root,string &number){
	node *trie=root;
	for(int i=0;i<number.size();i++){
		//cout<<"Inserting "<<number[i]<<endl;
		if(!trie->digit[number[i]-'0']){
			trie->digit[number[i]-'0']=new node;
		}
		trie=trie->digit[number[i]-'0'];
	}
}

long long getMax(node *root,string &number){
	long long ans=0;
	for(int i=0;i<number.size()&&root;i++){
		int presentDigit = number[i]-'0';
		int currentMax=INT_MIN;
		int currentMaxPosition = -1;
		for(int j=0;j<10;j++)
			if(root->digit[j]&&((presentDigit+j)%10)>currentMax){
				currentMax = ((presentDigit+j)%10);
				currentMaxPosition = j;
			}
		//cout<<"Got max digit as "<<currentMaxPosition<<endl;
		if(currentMaxPosition==-1)
			return -1;	
		
		ans=ans*10+(presentDigit+currentMaxPosition)%10;
		//cout<<"new ans = "<<ans<<endl;
		root=root->digit[currentMaxPosition];
	}
	return ans;
}
int main(){
	//freopen("p8.txt","r",stdin);
	int n;
	cin>>n;
	long long ans=0;
	
	node *root = new node;
	while(n--){
		string number;
		cin>>number;
		
		string shiftedString;
		if(number.size()!=10)
			for(int i=0;i<10-number.size();i++)
				shiftedString+='0';
		shiftedString+=number;
		//cout<<shiftedString<<endl;
		ans=max(ans,getMax(root,shiftedString));
		insert_trie(root,shiftedString);	
	}
	cout<<ans<<endl;
}
