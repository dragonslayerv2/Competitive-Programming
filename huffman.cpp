/*
	Name: Huffman Codes
	Copyright: 
	Author: Shobhit Saxena
	Date: 11-11-13 00:10
	Description: 
*/

#include<iostream>
#include<queue>
using namespace std;


struct node // this is the structure for node. Stores character frequency pair for leaves and frequency,left,right tuple for internal nodes
{
	int frequency;
	node * left, * right; // NULL for leaf nodes
	char character; // character
};

class compare_node
{
	public:
		bool operator()(const node *a,const node *b) //greater than operator. Make the priority queue a min heap. 
		{
			return a->frequency>b->frequency;				
		}
};

string gethashvalue(node *head,char a)
{
	if(head->character==a)
		return "!";
	else if(head->left==NULL&&head->right==NULL)
		return "";
	if(head->left)
	{
		string hashresult=gethashvalue(head->left,a);
		if(hashresult!="")
			return "0"+hashresult;
	}
	if(head->right)
	{
		string hashresult=gethashvalue(head->right,a);
		if(hashresult!="")
			return "1"+hashresult;
	}
	return "";
}
int main()
{
	cout<<"Enter the number of characters = ";
	int n;
	cin>>n;	
	
	node frequency_table[n];
	priority_queue<node *,vector<node*>,compare_node> Q;
	
	for(int i=0;i<n;i++)
	{
		char ch;
		int freq;
		cout<<"Character = ";
		cin>>ch;
		cout<<"Frequency = ";
		cin>>freq;
		
		
		node a;
		a.frequency=freq;
		a.character=ch;
		a.left=a.right=NULL;
		frequency_table[i]=a;
		
		Q.push(&frequency_table[i]);	
	}
	
	while(Q.size()>1)
	{
		node *z=new node;
		
		z->character=NULL;
		
		z->left=Q.top();
		Q.pop();
		
		z->right=Q.top();
		Q.pop();
		
		z->frequency=z->left->frequency+z->right->frequency;
		
		Q.push(z);
	}
	
	node *head=Q.top();
	Q.pop();
	
	cout<<"frequency table "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<frequency_table[i].character<<"\t"<<gethashvalue(head,frequency_table[i].character)<<endl;
	}
	
}
