#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


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
struct song
{
	unsigned long long band;
	unsigned long long length;
};


int main()
{
	int t;
	t=readInt();
	while(t--)
	{
		unsigned long long sweetness=0;
		int n;
		n-readInt();
		
		map<unsigned long long,unsigned long long> minlengthsong;
		
		int distinct=0;
		for(int i=0;i<n;i++)
		{
			song temp;
			cin>>temp.band>>temp.length;
			
			if(minlengthsong[temp.band]==0)
				{
					minlengthsong[temp.band]=temp.length;
					distinct++;
				}
			else
				{
					if(minlengthsong[temp.band]<temp.length)
						sweetness+=temp.length;
					else
					{
						sweetness+=minlengthsong[temp.band];
						minlengthsong[temp.band]=temp.length;
					}
				}
		}
		sweetness*=distinct;
		
		unsigned long long minlist[minlengthsong.size()];
		int j=0;
		for(map<unsigned long long,unsigned long long>::iterator i=minlengthsong.begin();i!=minlengthsong.end();i++,j++)
		{
			minlist[j]=(*i).second;
		}
		sort(minlist,minlist+minlengthsong.size());
		
		for(int i=0;i<distinct;i++)
		{
			sweetness+=minlist[i]*(i+1);
		}
		writeInt(sweetness);
	}
		return 0;
}
