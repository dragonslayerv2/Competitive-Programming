#include<stdio.h>
#include<vector>
using namespace std;

#define MOD 1000000009LL
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
    }
    return sign*n;
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

//--------------- DIRECT ADDRESSING IN O(1)
template<size_t sz>class directmap
{
	private:
		int _set[sz];
		int _stack[sz];
		int _top;
		
	public:
		directmap()
		{
			clear();
		}
		void set(size_t pos)
		{
			if(!isSet(pos))
			{
				_top++;
				_set[pos]=_top;
				_stack[_top]=pos;
			}
		}
		bool isSet(size_t pos)
		{
			if(_top<=0)
				return false;
			else
			{
				if(_set[pos]<=_top&&_stack[_set[pos]]==pos)
					return true;
				else
					return false;
			}
		}
		
		void reset(size_t pos)
		{
			if(isSet(pos))
			{
				_set[_stack[_top]]=_set[pos]; 
				swap(_stack[_top],_stack[_set[pos]]);
				_set[pos]=_top;
				_top--;
			}
		}
		
		size_t size()
		{
			return sz;
		}
		
		void clear(){
			_top=0;
		}
		
};
//-----------------------------

#define MAX 3000000
int height[MAX];
int sequence[MAX];

long long dp[MAX];

#define MAX_ELEMENT 5000000

directmap<2*MAX_ELEMENT> directMap;
int lastOccurence[2*MAX_ELEMENT];

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("%d",&height[i]);
		for(int i=0;i<n-1;i++)
			sequence[i+1]=height[i+1]-height[i];

		directMap.clear();
		
		dp[0]=1;
		for(int i=1;i<n;i++)
		{
			dp[i]=(2*dp[i-1])%MOD;
			
			int elementHash = sequence[i]+MAX_ELEMENT;
			
			if(directMap.isSet(elementHash)) 
				dp[i]=(MOD+dp[i]-dp[lastOccurence[elementHash]-1])%MOD;
			else
				directMap.set(elementHash);
			lastOccurence[elementHash]=i;
		}
		printf("%d\n",dp[n-1]-1);
	}	
}
