#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include<vector>
using namespace std;

struct trieNode{
	bool isLeaf;
	trieNode *next[26];
	trieNode *parent;
	char parentEdgeChar;
	trieNode(){
		isLeaf=false;
		parent=NULL;
		parentEdgeChar='\0';
		for(int i=0;i<26;i++)
			next[i]=NULL;
	}
};

trieNode *root= new trieNode();

#include<cstdio>
char tempWord[1000000];
bool isError;
bool matched(trieNode *root, char *word, bool canChange){
//	cout<<"AT on "<<*word<<endl;
	if(!(*word))
	{
		if(root->isLeaf){
			int tempPos=999;
			while(root->parent){
				tempWord[tempPos--]=root->parentEdgeChar;
				root=root->parent;
			}
			for(int i=tempPos+1;i<=999;i++)
				cout<<tempWord[i];
			if(!canChange)
				isError=true;
			return true;
		}
		else 
		{
			bool hasDone=false;
			if(canChange){
				for(int i=0;i<26;i++)
					if(root->next[i]){
						hasDone=(hasDone||matched(root->next[i],word,false));
						if(hasDone)
							break;
					}
			}
			return hasDone;
		}
	}
//	cout<<"Trying direct match"<<endl;
	if(root->next[(*word)-'a'])
		if(matched(root->next[(*word)-'a'],word+1,canChange))
			return true;
//	cout<<"Indirect match phase started"<<endl;
	if(canChange){
		//insertion & replace
		bool hasDone=false;
		for(int i=0;i<26;i++){
			
			if(root->next[i]){
				//insert
				hasDone=(hasDone||matched(root->next[i],word,false));
				if(hasDone)
					return true;
				//replace
				hasDone=(hasDone||matched(root->next[i],word+1,false));
				if(hasDone)
					return true;
			}
		}
		//deletion
		hasDone=(hasDone||matched(root,word+1,false));
		if(hasDone)
			return true;
		else
			return false;
	}
	return false;
}

char inputString[100000000];
char dictionaryWord[1000000];
char word[1000000];
int main(){
//	freopen("in9.txt","r",stdin);
//	ios::sync_with_stdio(false);
	int d;
	cin>>d;	
	
	while(d--){
		cin>>dictionaryWord;
		trieNode *current=root;
		for(int i=0;dictionaryWord[i];i++){
			int hash=dictionaryWord[i]-'a';
			if(!current->next[hash]){
				current->next[hash]=new trieNode();
				current->next[hash]->parentEdgeChar='a'+hash;
				current->next[hash]->parent=current;
			}
			current=current->next[hash];
		}
		current->isLeaf=true;
	}
	getchar();
	int dest=0;
	int error=0;
	int total=0;	
	bool allAlpha=true;
	int i=0;
	while((word[i]=getchar())!='\n'){
		total++;
		if(word[i]==' '||word[i]=='\n')
		{
			word[i]='\0';
			isError=false;
			if(allAlpha&&strlen(word)>0&&error/((double)total)<0.03){
				bool hasDone=false;
				hasDone=(hasDone||matched(root,word,true));
			
				if(!hasDone){
					for(int i=0;word[i];i++){
						for(int j=i+1;word[j];j++){
							swap(word[i],word[j]);
							hasDone=(hasDone||matched(root,word,false));
							swap(word[i],word[j]);
							if(hasDone)
								break;
						}
						if(hasDone)
						break;
					}
				}
			
				if(isError)
					error+=strlen(word);	
				if(!hasDone)
					cout<<word;
			}
			else
				cout<<word;
			cout<<" ";
			i=-1;
			allAlpha=true;
		}
		else if(!isalpha(word[i]))
			allAlpha=false;
		i++;
	}
}
