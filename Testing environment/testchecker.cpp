#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    cout<<"Compiling p1.cpp";
    system("g++ p1.cpp -o p1.exe");
    
    cout<<"Compiling p2.cpp";
    system("g++ p2.cpp -o p2.exe");
	if(!ifstream("p1.exe")) 
    {                     
                          cout<<"p1.exe not found";
                          return -1;
    }
    else if(!ifstream("p2.exe"))
    {
                               cout<<"p1.exe not found";
                               return -1;
    }
    cout<<"Executing p1.exe...\n";
    system("p1.exe <test.txt >o1.txt");
    cout<<"Executing p2.exe...\n";
    system("p2.exe <test.txt >o2.txt");
    ifstream t1("o1.txt");
    if(!t1) cout<<"O1.txt not found\n";
    ifstream t2("o2.txt");
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
						 fprintf(log,"LINE NO=%d\tn1=%d\tn2=%d\n",i,n1,n2);}   
              i++;
              
              
    }
    printf("Over\n");
    getchar();
}
