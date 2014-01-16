#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    ifstream t1("out1.txt");
    if(!t1) cout<<"O1.txt not found\n";
    ifstream t2("out2.txt");
    if(!t2) cout<<"O2.txt not found\n";
    
    FILE *test=fopen("test.txt","r");
    FILE *log=fopen("log.txt","w");
    int n1,n2;
    int i=1;
    char a[100];
    fgets(a,100,test);
    while(t1&&t2)
    {
                
              t1>>n1;
              t2>>n2;
          
              if(n1!=n2)
                        {printf("LINE NO=%d\tn1=%d\tn2=%d\n",i,n1,n2);
						 fprintf(log,"LINE NO=%d\tn1=%d\tn2=%d\n",i,n1,n2);getchar();}   
              i++;
              
              
    }
    printf("Over\n");
    getchar();
}
