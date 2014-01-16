#include<iostream.h>
using namespace std;


int main()
{
    int t;
    int s[5000];
    int n;
    scanf("%d",&t);
    while(t--)
    {
              unsigned int n;
              cin>>n;
              unsigned int m=n;
              if(!(m%2)){n--;}
              
              unsigned int ans=((n-1)*(n+1)/2)+2;
              
              if(!(m%2))
              {
                        ans=ans+m%1000000007;
                        ans=ans%1000000007;
              }
              cout<<ans<<endl;
    }
    
    return 0;
}
