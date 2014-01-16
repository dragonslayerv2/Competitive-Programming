#include<iostream>
#include<cstdio>
using namespace std;

const long long len=1000001 ;
 char ns[len];
   int n[len];
void swap(long int & fv,long int & sv)
{
     long int temp;
     temp=fv;
     fv=sv;
     sv=temp;
}


int main()
{
    long int T;
    cin>>T;
    while(T--)
    {
             
            
              scanf("%s",ns);
              long int i=0,j=0,m=0,k=0;
              for(m=0;(int)(ns[m])==48;m++);
              n[0]=0;
              for(j=m,i=0;ns[j]!='\0';j++,i++)
              {
                      n[i+1]=int(ns[j])-48;                   
              }
              n[i]++;
              for(long int k=i;k>=1;k--)
              {
                   n[k-1]+=(n[k]/10);
                   n[k]%=10; 
              }
              for((n[0])?k=0:k=1,m=i;k<=i;k++,m--)
              {
                   int c=m;
                   while(n[c]/10>0)
                   {
                   if(c){n[c-1]+=(n[c]/10);}
                   n[c]%=10;
                   c--;
                   }     
                           int flag=0;
                           if(m<k)
                           {
                                  flag=1;
                                  swap(m,k);
                           }
                           //cout<<k<<" "<<m<<" "<<n[k]<<"  "<<n[m]<<"\n" ;
                           if(n[k]%10<n[m])
                           {
                                   n[m]=n[k];
                                   n[m-1]+=1;        
                           }
                           if(n[m]<n[k]%10)
                           {
                                n[m]=n[k];        
                           }
                           //cout<<k<<" "<<m<<" "<<n[k]<<"  "<<n[m]<<"\n" ; 
                           if(flag){swap(m,k);}  
              }
              for((n[0])?k=0:k=1;k<=i;k++)
              {
                       cout<<n[k];
              }
              cout<<"\n";
    }
	return 0;
}
