#include<stdio.h>

using namespace std;
int main()
{
    int ans=-1;
    while(1)
    {
        char c=getchar();
        if(c=='\n') break;
        if(c=='a')  ans*=-1;
        else        ans=-1;
    }
    printf("%s",ans==1?"TRUE":"FALSE");

}
