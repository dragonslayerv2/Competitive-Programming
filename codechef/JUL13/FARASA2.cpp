#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<hash_map>
#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked
using namespace std;
using namespace __gnu_cxx;


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

template <size_t size> class hasher
{
	map<long long, bool>  bucket[size];
	public:
		
		
		bool insert(long long n)
		{
			int pos=n%size;
			if((bucket[pos])[n])
				return false;
			else
				(bucket[pos])[n]=true;
			return true;
		}
};


hasher<99991> hash;
int main()
{
	
	int n;
	n=readInt();
	vector<int> array;
	array.reserve(n);
	for(int i=0;i<n;i++)
	{
		int c=readInt();
		if(c>0)
			array.push_back(c);
	}
	long long count=0;
	n=array.size();
	for(int i=0;i<n;i++)
	{
		long long sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=array[j];
			
			if(::hash.insert(sum))
			{
				cout<<sum<<endl;
				count++;
			}
			
		}
	}
	if(count==0)
		cout<<0;
	else
		cout<<count-1<<endl;
	
	
}
