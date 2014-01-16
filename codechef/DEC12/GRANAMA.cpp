#include<stdio.h>
#include<string.h>
inline int solve(char *a,char *b)
{
       int i;
    int freq1[26];
    int freq2[26];
    memset(freq1,0,sizeof(freq1));
    memset(freq2,0,sizeof(freq2));
    
    while(*a)
    {
             freq1[(*a)-'a']++;    
             a++;
    }  
    while(*b)
    {
             freq2[(*b)-'a']++;    
             b++;
    }

    int chefans=1;
    int origans=1;
    for(i=0;i<26;i++)
    {
          
            if((freq1[i]==0&&freq2[i])||(freq2[i]==0&&freq1[i])) {chefans=0;origans=0;}
            if(freq1[i]!=freq2[i]) origans= 0;
            
    }
    return chefans==origans;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              char a[1001],b[1001];
              scanf("%s",a);
              scanf("%s",b);
              printf("%s\n",solve(a,b)?"YES":"NO");
    }
    return 0;
}
