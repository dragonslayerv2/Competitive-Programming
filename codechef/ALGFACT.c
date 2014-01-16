#include<stdio.h>

#define MAXDIGITS 20
#define MOD 100000000
#define weight 8

long long digits[MAXDIGITS];
int last_digit;
int first_digit;

void display()
{
int i,j;
for(i=first_digit+1;i<=last_digit;i++)
{
printf("%lld",digits[i]);
if(i!=last_digit)
{
int numzeros=weight-1;
long long x=digits[i+1];
while(x)
{
numzeros--;
x/=10;
}
if(digits[i+1]!=0)
numzeros++;                                      
for(j=0;j<numzeros;j++)
printf("0");                                      
}                                         
}
}
void multiply(int a)
{
int i;
for(i=last_digit;i>first_digit;i--)
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
int t,i;
scanf("%d",&t);
while(t--)
{
first_digit=last_digit=MAXDIGITS-1;          
digits[first_digit--]=1;              
int n;
scanf("%d",&n);  
for(i=2;i<=n;i++)
multiply(i);
display();
printf("\n");
}
return 0;    
}
