#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
using namespace std;

class number
{
    int digit[10];
    public:

        number(char *p)
        {
            memset(digit,0,sizeof(digit));
            int n=strlen(p)-1;
            for(int i=9;n>=0;i--,n--)
                digit[i]=p[n]-'0';
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
//---------------
#define MAX 1000000
#define TOT 24
long long series[MAX]={0};
int k=1;
char series1[TOT][15] = {"125874","1025874","1245789","10025874", "10245789", "12356784", "12457899","100025874", "100245789", "102356784", "102457899","123456789", "124578999","1000025874", "1000245789", "1002356784", "1002457899", "1023456789","1024578999", "1122556284","1233566784", "1234567899","1245789999","1573788744l"};


int search(long long c)
{
    long long *a=series;

    int l=1;
    int h=k+1;
    int pos;
    while(l<=h)
    {
     pos=(l+h)/2;
     if(a[pos]==c)
                  return pos;
     else if(a[pos]<c)
                      l=pos+1;
     else
                      h=pos-1;
    }
    return 0;
}


//---------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int i, int n)
{

   int j;
   if (i == n)
    {
        number n1(a);
        if(n1==n1*2)
        {
                long long n=atol(a);
                series[k++]=n;
        }
    }
   else
   {
        for (j = i; j <= n; j++)
       {

          swap((a+i), (a+j));
          if(a[0]!='0')
                permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}
//----------------------------------------------------------------------------------
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}



void prepros()
{
      for(int i=0;i<TOT;i++)
        {
            permute(series1[i], 0, strlen(series1[i]));
        }
        printf("k=%d ",k);
        qsort (series+1, k-1, sizeof(int), compare);
        for(int i=1;i<k;i++)
        {
            printf("%d",series[i]);
            getchar();
        }
}
int main()
{
      prepros();
      //  for(int i=0;)

}
