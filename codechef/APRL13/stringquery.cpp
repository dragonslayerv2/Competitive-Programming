#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
//------------------------------------------------------------------------------
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break;          
    }
    return n;
}
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}
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
	int i;
	for(i=0;(str[i]=GETCHAR())!='\n';i++);
	str[i]=0;

	//---------------------------------------------------
	init(str);
	
	int t=readInt();
	
	char query[100];
	while(t--)
	{
		
		for(i=0;query[i]=GETCHAR();i++)
			if(query[i]=='\n'||query[i]==' ') break;	
		
		query[i]=0;
		
		
		
		if(query[0]=='I')
		{
			char c=GETCHAR();		
			
			GETCHAR();
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
			for(i=0;(pattern[i]=GETCHAR())!='\n';i++);
			pattern[i]=0;
			patternsize=i;
			if(i>count) 
				{
					writeInt(0);
				}
			else
				writeInt(querypattern());		
		}
	//	print();
	}
	
//	for(int i=0;i<fs;i++)
//		cout<<array[i].left<<"\t"<<" "<<array[i].data<<"\t"<<array[i].right<<endl;
}
