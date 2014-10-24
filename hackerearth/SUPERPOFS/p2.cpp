#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXDIGITS 10000
#define MOD 10
#define weight 1
class verybig
{
       private:
               long long digits[MAXDIGITS];
               int last_digit;
               int first_digit;
       public: 
               
               verybig(int a=0)
               {
                        first_digit=last_digit=MAXDIGITS-1;
                       
                        do
                        {
                                 digits[first_digit--]=a%MOD;
                                 a/=MOD;
                        }while(a);
                        
               }
               int getsum();
               void multiply(int a);
                  
};


int verybig::getsum()
{
	int sum=0;
           for(int i=first_digit+1;i<=last_digit;i++)
           {
           		while(digits[i]){
           			sum+=digits[i]%10;
           			digits[i]/=10;
           		}
           	}
	return sum;
}
void verybig::multiply(int a)
{
           for(int i=last_digit;i>first_digit;i--)
           {
                   digits[i]*=a;
                   if(i!=last_digit)
                   {
                                    digits[i]+=digits[i+1]/MOD;
                                    digits[i+1]%=MOD;                 
                   }
           }
           if(digits[first_digit+1]/MOD!=0)
           {
                                           digits[first_digit]=digits[first_digit+1]/MOD;
                                           digits[first_digit+1]%=MOD;
                                           first_digit--;
           }
}

int main()
{
	 int t;
	 cin>>t;
	 while(t--){
	 	int n;
	 	cin>>n;
	 	verybig ob(1);
		for(int i=2;i<=n;i++)
			ob.multiply(i);
		cout<<ob.getsum()<<endl;
	 }
}
