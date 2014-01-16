#include <iostream>
using namespace std;
#define MOD 1000000007

int main()
{
    int t;
    cin>>t;
    long long a,b,c;
    while(t--)
    {

        cin>>a>>b>>c;
        if(a>c) a^=c^=a^=c;
        if(a>b) a^=b^=a^=b;
        if(b>c) b^=c^=b^=c;
        cout<<((((a%MOD)*(b-1)%MOD)%MOD)*((c-2)%MOD))%MOD<<endl;
    }
    return 0;
}
