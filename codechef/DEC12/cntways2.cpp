#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

#define MOD 1000000007

unsigned long long C(int n,int r)
{
         unsigned long long nm=1;
    unsigned long long rm=1;
    while(r)
    {
              nm=(nm*(n--));
              rm=(rm*(r--));
    }
    return nm/rm;
}

int main()
{


                    int n,m,a,b;
                    for(n=1;n<10;n++)
                    {
                                     for(m=1;m<10;m++)
                                     {
                                                      for(a=1;a<n;a++)
                                                      {
                                                                      for(b=1;b<m;b++)
                                                                      {
                                                                                      
                                                                                      unsigned long long total=C(m+n,n);
                                                                                      unsigned long long subt=0;
                                                                                      for(int i=1;i<=b;i++)
                                                                                      {
                                                                                              subt=(subt+(C(n-a+i,n-a+1)*C(m+a-i,a-1))%MOD)%MOD;
                                                                                      }
                                                                                      cout<<n<<" "<<m<<" "<<" "<<a<<" "<<b<<" "<<total-subt<<endl;
                                                                                      getch();
                                                                      }
                                                      }
                                     }
                    }
                   getchar();                   
}
