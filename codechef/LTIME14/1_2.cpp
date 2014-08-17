#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node
{
	node *character[2];
	node *parent;
	
};
void number_to_string(int number,char *number_string)
{
	int k=29;
	while(number)
	{
		number_string[k]='0'+(number&1);
		number>>=1;
		k--;
	}
	while(k>=0)
		number_string[k--]='0';
}

void insert_trie(node *root,int number)
{
	char number_string[30];
	number_to_string(number,number_string);
	node *trie=root;
	for(int i=0;i<30;i++)
	{
		if(!trie->character[number_string[i]-'0'])
		{
			trie->character[number_string[i]-'0']=new node;
			trie->character[number_string[i]-'0']->parent=trie;
			trie->character[number_string[i]-'0']->character[0]=trie->character[number_string[i]-'0']->character[1]=NULL;
		}
		trie=trie->character[number_string[i]-'0'];
	}
}

int get_max(node *root,int number)
{
	char number_string[30];
	number_to_string(number,number_string);
	node *trie=root;
	long long result=0;
	for(int i=0;i<30;i++)
	{
		result*=2;
		
		if(trie->character[(number_string[i]-'0')])
		{
			result+=(number_string[i]-'0');
			trie=trie->character[(number_string[i]-'0')];
		}
		else
			trie=trie->character[(number_string[i]-'0')^1];
	}
	return result;
}
int main()
{
	int t=1;
	while(t--)
	{
		map<int,size_t> count;
		node *trie=new node;
		trie->parent=trie->character[0]=trie->character[1]=NULL;
		int n;
		cin>>n;
		vector<int> number(n);
		for(int i=0;i<n;i++)
		{
			cin>>number[i];
			count[number[i]]++;
		}
		
		insert_trie(trie,number[0]);
		
		int result=0;
		for(int j=1;j<n;j++)
		{
				result=max(result,get_max(trie,number[j]));
				insert_trie(trie,number[j]);
		}
			
		
		cout<<result<<endl;
	}
}
