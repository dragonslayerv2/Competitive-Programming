#include<iostream>
using namespace std;
int check(long long n)
{
    long long k=0;
    long long temp=n;
    while(temp)
    {
               k=k*10+temp%10;
               temp/=10;
    }
    
    return (n==k);
}
int main()
{
    
    int t;
    scanf("%d",&t);
    int m=0;
    while(t--)
    {
              m++;
             
              long long n;
              cin>>n;
               /*if(m==2)
                      {cout<<"9 3317667133\n";continue;}// Tweak because of ur */
              int i=0;
              while(!check(n))
              {
                              long long k=0;
                              long long temp=n;
                              while(temp)
                              {
                                         k=k*10+temp%10;
                                         temp/=10;
                              }                         
                              n+=k;
                              i++;
                              cout<<i<<" "<<n<<endl;
                              getchar();
              }
              cout<<i<<" "<<n<<endl;
    }
    return 0;
}
