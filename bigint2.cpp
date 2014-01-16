#include<bits/stdc++.h>
using namespace std;

#define HASHVAL 1000000007

template<size_t SIZE> class bigint
{
	private:
		const static size_t SCALE = 100000000; 
		const static size_t WEIGHT = 8;
		long long digit[SIZE];
		size_t firstdigit;
		size_t lastdigit;
		void itoa(long long a,char *result,int &i)
		{
			char temp[20];
			int temppos=0;
			while(a)
			{
				char last_digit=(a%10)+'0';
				temp[temppos++]=last_digit;
				a/=10;
			}	
			for(int j=temppos-1;j>=0;j--)
				result[i++]=temp[j];
			result[i]='\0';
		}

	public:
		bigint()
		{
			reset();
		}
		
		bigint(long long a)
        {
            reset();
            do
            {
                digit[firstdigit--]=a%SCALE;
                a/=SCALE;
            }while(a);    
        }
		
		bigint(const bigint &a)
		{
			firstdigit=a.firstdigit;
			lastdigit=a.lastdigit;
			for(int i=firstdigit+1;i<=lastdigit;i++)
			{
				digit[i]=a.digit[i];
			}
		}
		
		void reset()
		{
			firstdigit=lastdigit=SIZE-1;
		}
		
		bool operator ==(const bigint &num)
		{	
			for(int i=firstdigit+1;i<=lastdigit;i++)
			{
				if(digit[i]!=num.digits[i])
					return false;
			}
			return true;
		}
		
		bigint operator +=(const bigint &a)
		{
			size_t i;
			for(i=a.firstdigit+1;i<firstdigit+1;i++) // pad zeros in front
				digit[i]=a.digit[i];
			
			for(i=firstdigit+1;i<=a.firstdigit;i++);
			
			for(;i<=lastdigit;i++)
				digit[i]+=a.digit[i];
			
			long long carry=0;
			firstdigit=min(firstdigit,a.firstdigit);
			for(i=lastdigit;i>firstdigit;i--)
			{
				digit[i]=digit[i]+carry;
				carry=digit[i]/SCALE;
				digit[i]=digit[i]%SCALE;
			}
			
			
			
			if(carry)
			{
				digit[firstdigit]=carry;
				firstdigit--;
			}
			return *this;
		}
		
		string  to_string()		
		{
		   char a[(lastdigit-firstdigit+1)*8];
		   int pos=0;
		   for(size_t i=firstdigit+1;i<=lastdigit;i++)
           {         
                        itoa(digit[i],a,pos);
                        if(i!=lastdigit)
                        {
                                      int numzeros=WEIGHT-1;
                                      long long x=digit[i+1];
                                      while(x)
                                      {
                                        numzeros--;
                                        x/=10;
                                      }
                                      if(digit[i+1]!=0)
                                            numzeros++;
                                      
                                      for(int j=0;j<numzeros;j++)
                                          a[pos++]='0';
                        }   
                                      
           }
           a[pos]='\0';
           return a;
		}
		bigint operator +(const bigint &a)
		{
			bigint temp=*this;
			temp+=a;
			
			return temp;
		}
		
		void debug() const
		{
			for(int i=firstdigit+1;i<=lastdigit;i++)
				cout<<digit[i];
			cout<<endl;
		}
		
		long long operator %(long long num)
		{
			long long result=0;
			for(int i=firstdigit+1;i<=lastdigit;i++)
				result=(result*SCALE+digit[i])%num;
			return result;
		}
		
		bool operator == (const string &a)
		{
			return to_string()==a;
		}
};

#define FIBO_SIZE 5000
vector<pair<string,long long> >  fibo(FIBO_SIZE);
long long hash_string(const string &a, long long p)
{
	long long hash=0;
	for(int i=0;i<a.size();i++)
	{
		hash=hash*10+a[i]-'0';
		hash%=p;
	}
	return hash;
}
void preprocess()
{
	bigint<1000> a=0;
	bigint<1000> b=1;
	bigint<1000> c;
	
	fibo[0].first="0";
	fibo[0].second=0;
	for(size_t i=1;i<FIBO_SIZE;i++)
	{
		c=a+b;
		a=b;
		b=c;
		fibo[i].first=(c.to_string());
		fibo[i].second=(hash_string(fibo[i].first,HASHVAL));
	}
}

int main()
{
	preprocess();
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string a;
		cin>>a;
		long long hash=hash_string(a,HASHVAL);
		bool ans=false;
		for(int i=0;i<fibo.size();i++)
		{
			if(fibo[i].second==hash&&fibo[i].first==a)
			{
				ans=true;
				break;
			}
		}
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
