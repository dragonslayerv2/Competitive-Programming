#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],c[100],d[100];
    int vpos1,vpos2,hpos1,hpos2;
    while(1)
    {
            scanf("%s",a);
            if(a[0]=='#') 
                          break;
            scanf("%s",b);
            scanf("%s",c);
            scanf("%s",d);
            char *hor1,*hor2,*ver1,*ver2;
            int pos1=-1,pos2=-1,pos3=-1,pos4=-1;
                        
            int l1=strlen(a),l2=strlen(b),l3=strlen(c),l4=strlen(d);
            
            for(int i=1;i<l1;i++)
            {
                    for(int j=1;j<l2;j++)
                    {
                                     if(a[i]==b[j])
                                     {
                                                  if(pos1==-1) 
                                                  {            hor1=a;
                                                               ver1=b;
                                                               pos1=i;
                                                               pos2=j; 
                                                  }
                                                  else if( j<pos1)
                                                  {
                                                       hor1=b;
                                                       ver1=a;
                                                       pos1=j;
                                                       pos2=i;
                                                  }
                                     }
                    }
            }
            
            if(pos1==-1) { printf("Unable to make two crosses");continue;}
           
            for(int i=1;i<l3;i++)
            {
                    for(int j=1;j<l4;j++)
                    {
                                     if(c[i]==d[j])
                                     {
                                                  if(pos3==-1) 
                                                  {            hor2=c;
                                                               ver2=d;
                                                               pos3=i;
                                                               pos4=j; 
                                                  }
                                                  else if( j<pos1)
                                                  {
                                                       hor2=c;
                                                       ver2=d;
                                                       pos3=j;
                                                       pos4=i;
                                                  }
                                     }
                    }
            } 
            if(pos3==-1) { printf("Unable to make two crosses");continue;}
            int i;
            for( i=0;i<pos2-pos4;i++)
            {
                    for(int j=0;j<pos1;j++)
                    {printf(" ");}
                    printf("%c",ver1[i]);
                    printf("\n");
            }
            for(int k=0;k<pos4;k++)
            {
                    for(int j=0;j<pos1;j++)
                    {printf(" ");}
                    printf("%c",ver1[i+k]);
                    for(int j=0;j<l1-pos1-1+3+pos3;j++)
                    {printf(" ");}
                    printf("%c",ver2[k]);
                    printf("\n");
            }
            printf("%s   %s",hor1,hor2); 
            
            
    }
}
