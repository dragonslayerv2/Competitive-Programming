#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
//------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#define MAX 150100
struct node
{
	char data;
	int right,left;
}array[MAX];

//------------------------------------------------------------------------------

int left,right,mid,count,fs;


#define inc 0
#define dec 1 
//------------------------------------------------------------------------------

inline void init(char *s)
{
	count=strlen(s);
	left=0;
	right=count-1;
	mid=count/2-1;
	fs=count;
	for(int i=0;i<count;i++)
	{
		array[i].left=i-1;
		array[i].data=s[i];
		array[i].right=i+1;
	}
	array[right].right=-1;
}


inline void insert_middle(char c)
{
	array[fs].data=c;
	array[fs].left=mid;
	array[fs].right=array[mid].right;
	array[mid].right=fs;
	array[array[fs].right].left=fs;
	
	if(count%2)
		mid=array[mid].right;
	
	count++;
	fs++;
}
inline void insert_left(char c)
{
	array[fs].data=c;
	array[fs].left=-1;
	array[fs].right=left;
	array[left].left=fs;
	
	left=fs;
	
	if(!(count%2))
		mid=array[mid].left;
		
	count++;
	fs++;
}
inline void insert_right(char c)
{
	array[fs].data=c;
	array[fs].left=right;
	array[fs].right=-1;
	array[right].right=fs;
	
	right=fs;
	
	if(count%2)
		mid=array[mid].right;
	
	
	count++;
	fs++;
}
inline void delete_left()
{
	left=array[left].right;
	array[left].left=-1;
	
	if(count%2)	mid=array[mid].right;
	
	count--;
	
}
inline void delete_right()
{
	right=array[right].left;
	array[right].right=-1;
	
	if(!(count%2))
		mid=array[mid].left;
	
	count--;
}
inline void delete_middle()
{
	array[mid].right=array[array[mid].right].right;
	array[array[mid].right].left=mid;
	
	if(!(count%2))
		mid=array[mid].left;
	
	count--;
}
//------------------------------------------------------------------------------
#define MAXPATTERNSIZE 1500010

char pattern[MAXPATTERNSIZE];
int Pi[MAXPATTERNSIZE];
int patternsize;

void computePiFunction()
{
		int m=patternsize;

		Pi[0]=-1;
		int k=-1;
		
		for(int i=1;i<m;i++)
		{
		
			while(k>=0&&pattern[k+1]!=pattern[i])
				{k=Pi[k];}
			if(pattern[k+1]==pattern[i])
				k++;
			Pi[i]=k;	
		}
}

void print()
{
	for(int i=left;i!=-1;i=array[i].right)
	{
		cout<<array[i].data;
	}
	cout<<endl;
}
int matcher()
{
		int count=0;
		
		int m=patternsize;
		int q=-1;
		for(int i=left;i!=-1;i=array[i].right)
		{
		
			while(q>=0&&pattern[q+1]!=array[i].data)
			{
				q=Pi[q];
			}
			if(pattern[q+1]==array[i].data)	q++;
			if(q==m-1)
			{
				count++;
				q=Pi[q];
			}
						
		}
		return count;
}




int querypattern()
{
	computePiFunction();
	return matcher();
}



//------------------------------------------------------------------------------
int main()
{
	char str[100];
	//---------------------------------------------------
	
	cin>>str;

	//---------------------------------------------------
	init(str);
	
	int t;
	cin>>t;
	
	char query[100];
	while(t--)
	{
		
		cin>>query;
		
		
		
		
		if(query[0]=='I')
		{
			char c;
			cin>>c;		
	
			switch(query[7])
			{
				case 'L':insert_left(c);break;
				case 'R':insert_right(c);break;
				case 'M':insert_middle(c);break;
			}
		}
		else if(query[0]=='D')
		{
			switch(query[7])
			{
				case 'L':delete_left();break;
				case 'R':delete_right();break;
				case 'M':delete_middle();break;
			}
		}
		else if(query[0]=='Q')
		{
			cin>>pattern;
			patternsize=strlen(pattern);
			if(patternsize>count) 
				{
				cout<<0<<endl;
				}
			else
				cout<<querypattern()<<endl;		
		}
	//	print();
	}
	
//	for(int i=0;i<fs;i++)
//		cout<<array[i].left<<"\t"<<" "<<array[i].data<<"\t"<<array[i].right<<endl;
}
