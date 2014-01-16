#include<iostream>

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
          int r;
          cin>>r;
          while(r--)
          {
                    int n,m,a,b;
                    cin>>n>>m>>a>>b;
                    unsigned long long total=C(m+n,n);
                    unsigned long long subt=0;
                    for(int i=1;i<=b;i++)
                    {
                            subt=(subt+(C(n-a+i,n-a+1)*C(m+a-i,a-1))%MOD)%MOD;
                    }
                    cout<<total-subt<<endl;
          }
          return 0;
}
