#include<bits/stdc++.h>
using namespace std;
typedef struct trie_node trieNode;
typedef struct trie trieTree;
struct trie_node
{
    int value;
    trieNode *children[26];
};
struct trie
{
    trieNode *root;
    int count;
};
trieNode *getNode()
{
    trieNode *pNode=NULL;
    pNode=(trieNode *)malloc(sizeof(trieNode));
    if(pNode)
    {
        pNode->value=0;
        for(int i=0;i<26;i++)
            pNode->children[i]=NULL;
    }
    return pNode;
}
void init(trieTree *pTrie)
{
    pTrie->root=getNode();
    pTrie->count=0;
}
void insert(trieTree *pTrie,string key)
{
    trieNode *pCrawl;
    pTrie->count++;
    pCrawl=pTrie->root;
    for(int level=0;level<key.length();level++)
    {
        int index=((int)key[level])-(int)'a';
        if(!pCrawl->children[index])
            pCrawl->children[index]=getNode(); 
        pCrawl=pCrawl->children[index];
    }
    pCrawl->value=pTrie->count;
}
int search(trieTree *pTrie,string key)
{
    trieNode *pCrawl;
    pCrawl=pTrie->root;
    for(int level=0;level<key.length();level++)
    {
        int index=((int)key[level])-(int)'a';
        if(!pCrawl->children[index])
            return 0; 
        pCrawl=pCrawl->children[index];
    }
    return(0!=pCrawl && pCrawl->value);
}
vector<string> generateMisTypedStrings(string s){
	vector<string> misTypedStrings;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<26;j++){
			string temp;
			int posToChange=i;
			temp=s.substr(0,posToChange) + (char)(j+97)  +s.substr(posToChange+1,s.length()-posToChange);
			misTypedStrings.push_back(temp);
			//cout<<temp<<"\n";
		}
	}
	return misTypedStrings;
}
vector<string> generateIrrelevantCharStrings(string s){
	vector<string> irrelevantCharStrings;
	for(int i=0;i<s.length();i++){
		int posToDelete = i;
		string temp = s.substr(0,posToDelete) + s.substr(posToDelete+1,s.length()-posToDelete);
		irrelevantCharStrings.push_back(temp);
	}
	return irrelevantCharStrings;
}
vector<string> generateSkippedCharStrings(string s){
	vector<string> skippedCharStrings;
	for(int i=0;i<s.length();i++){
		for(int j=0;j<26;j++){
			string temp;
			char letterToInsert = (char)(j+97);
			temp= s.substr(0,i) + letterToInsert + s.substr(i,s.length()-i+1);
			skippedCharStrings.push_back(temp);
		}
	}
	for(int j=0;j<26;j++){
			string temp;
			char letterToInsert = (char)(j+97);
			temp= s.substr(0,s.length()) + letterToInsert;
			skippedCharStrings.push_back(temp);
	}
	return skippedCharStrings;
}
vector<string> generateSwappedCharStrings(string s){
	vector<string> swapedCharStrings;
	for(int i=0;i<s.length();i++){
		for(int j=i+1;j<s.length();j++){
			char firstPos = s[j];
			char secondPos = s[i];		
			string temp = s.substr(0,i) + s[j] + s.substr(i+1,j-i-1) + s[i] + s.substr(j+1,s.length()-j);
			swapedCharStrings.push_back(temp);
		}
	}
	return swapedCharStrings;
}
int main(){
	set<string> dictionary;
	int t;
	cin>>t;
	while(t--)
	{
	 	string temp;
	 	cin>>temp;
	 	dictionary.insert(temp);
	}
	trieTree T;
	init(&T);
	for(set<string>::iterator i=dictionary.begin();i!=dictionary.end();i++)
    {
        insert(&T,*i);
    }
	
	//cout<<search(&T,"gorv")<<" "<<search(&T,"smu")<<"\n";
	
	vector<string> words;
	
	char x;
	string temp;
	char xx=getchar();
    while(x=getchar())
	{   
    	if(x=='\n'||x=='\0')
       		break;
    	else if(x==' ')
    	{
    		words.push_back(temp);
    		temp="";
    	}
    	else
    	{
    		temp=temp+x;
    	}
        	
	}
	words.push_back(temp);
	
	/*
	for(int i=0;i<words.size();i++){
		cout<<words[i]<<" ";
	}
	*/
	int iterations=words.size();
	double percentageChanged;
	int errors=0;
	int stopLoop;
	for(int i=0;i<words.size();i++){
		percentageChanged = (double)errors/(double)words.size();
		
		if(percentageChanged > 0.04)
		{
			stopLoop=i;
			break;
		}
		int allAphabets=true;
		for(int j=0;j<words[i].length();j++){
			if(!(words[i][j]>='a' && words[i][j]<='z')){
				allAphabets=false;
				break;
			}
		}
		if(!allAphabets){
			if(i!=words.size()-1)
			cout<<words[i]<<" ";
			else
			cout<<words[i]<<"\n";
		}
		else{
			int isMatched=false;
			string toDisplay;
			if(search(&T,words[i]))
			{
				isMatched=true;
				toDisplay=words[i];
			}
			
			if(isMatched==false){
				vector<string> misTypedStrings = generateMisTypedStrings(words[i]);
				for(int j=0;j<misTypedStrings.size();j++){
					if(search(&T,misTypedStrings[j]))
					{
						isMatched=true;
						errors++;
						toDisplay=misTypedStrings[j];
						break;
					}
				}
			}
			
			if(isMatched==false){
				vector<string> irrelevantCharStrings = generateIrrelevantCharStrings(words[i]);
				for(int j=0;j<irrelevantCharStrings.size();j++){
					if(search(&T,irrelevantCharStrings[j]))
					{
						isMatched=true;
						toDisplay=irrelevantCharStrings[j];
						errors++;
						break;
					}
				}
			}
			
			if(isMatched==false){
				vector<string> skippedCharStrings = generateSkippedCharStrings(words[i]);
				for(int j=0;j<skippedCharStrings.size();j++){
					if(search(&T,skippedCharStrings[j]))
					{
						isMatched=true;
						toDisplay=skippedCharStrings[j];
						errors++;
						break;
					}
				}
			}
			
			
			if(isMatched==false){
				vector<string> swapedCharStrings = generateSwappedCharStrings(words[i]);
				for(int j=0;j<swapedCharStrings.size();j++){
					if(search(&T,swapedCharStrings[j]))
					{
						isMatched=true;
						toDisplay=swapedCharStrings[j];
						errors++;
						break;
					}
				}
			}
			if(isMatched==false){
				toDisplay=words[i];
			}
			
			if(i!=words.size()-1)
			cout<<toDisplay<<" ";
			else
			cout<<toDisplay<<"\n";		
		}
	}
	//cout<<percentageChanged<<"\n";
	for(int i=stopLoop;i<words.size();i++){
		if(i!=words.size()-1)
			cout<<words[i]<<" ";
		else
			cout<<words[i]<<"\n";
	}
}
