#include<stdio.h>
#include<string.h>
int main()
{
long int T;
scanf("%d",&T);
char S[101][101];
for(int i=0;i<T;i++)
{
for(int j=0;j<T;j++)
{
char temp[5];
scanf("%s",temp);
if(!strcmp(temp,"NO")){S[i][j]='N';}
else{S[i][j]='Y';}
}
S[i][T]='\0';
}
int ans=-1;
for(int i=0;i<T;i++)
{
int flag=1;
for(int j=0;j<T;j++)
{
if(S[i][j]=='Y')
{
//cout<<S[i]<<"\n"<<S[j]<<"\n";
if(strcmp(S[j],S[i])){flag=0;break;}
}
else if(S[i][j]=='N')
{
//cout<<S[i]<<"\n"<<S[j]<<"\n";
if(!strcmp(S[j],S[i])){flag=0;break;}
}
}
if(flag==1)
{
ans=i;
break;
}
}
if(ans!=-1)
{
for(int i=0;i<T;i++)
{
if(S[ans][i]=='N'){printf("NO\n");}
else if(S[ans][i]=='Y'){printf("YES\n");}
}
}
else
{
for(int i=0;i<T;i++)
{
{printf("NO\n");}
}
}
//getch();
getchar();
return 0;
}
