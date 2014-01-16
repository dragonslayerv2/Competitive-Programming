#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 1000000

int series[MAX];
int k=0;

class number
{
    int digit[10];
    public:
        number()
        {
            memset(digit,0,sizeof(digit));
        }
        number(int n)
        {
            digit[9]=n;
            for(int i=8;i>=0;i--)
            {
                digit[i]=(digit[i+1]/10);
                digit[i+1]%=10;
            }
        }
        number(char *p)
        {
            memset(digit,0,sizeof(digit));
            int n=strlen(p)-1;
            for(int i=9;n>=0;i--,n--)
                digit[i]=p[n]-'0';
        }
        void print()
        {
            int l1=0;

            for(int i=0;i<10;i++)
            {
                printf("%d",digit[i]);
            }
            printf("\n");
        }
        number operator +(int n)
        {
            number nm=*(this);
            nm.digit[9]+=n;
            for(int i=8;i>=0;i--)
            {
                nm.digit[i]+=(nm.digit[i+1]/10);
                nm.digit[i+1]%=10;
            }
            return nm;
        }
        number operator *(int n)
        {
             number nm=*(this);
            nm.digit[9]*=n;
            for(int i=8;i>=0;i--)
            {
                nm.digit[i]=(nm.digit[i]*n+ nm.digit[i+1]/10);
                nm.digit[i+1]%=10;
            }
            return nm;
        }

        int operator ==(number n)
        {
            int numbers[10];
            int l1=0,l2=0;
            while(!digit[l1])
                l1++;
            while(!n.digit[l2])
                l2++;
            if(l1!=l2) return 0;


            for(int i=0;i<10;i++)
                numbers[i]=0;

            int count=0;
            for(;l1<10;l1++)
            {
                numbers[digit[l1]]++;
                count++;
            }
            for(;l2<10;l2++)
            {
                if(numbers[n.digit[l2]]>0)
                    {numbers[n.digit[l2]]--;count--;}
                else
                    return 0;
            }
            if(count==0) return 1;
            return 0;
        }
};
static int count;
int main()
{
    number n1,n2;
    int a;
    int l;
    for(int i=125874;i<10000000000;i++)
    {
        n1=number(i);
        n2=n1*2;

        if(n1==n2) {n1.print();count++;getchar();}

    }
    printf("       %d",count);
}
