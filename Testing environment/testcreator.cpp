#include<iostream>
#include<fstream>
#include<stdio.h>
#include<process.h>

using namespace std;
#define MAX 10
int main()
{
    ofstream out("test.txt");
    if(!out) {perror("");exit(1);}
    int count=1296;
    out<<count<<endl;
    for(int n=2;n<MAX;n++)
    {
            for(int m=2;m<MAX;m++)
            {
                    for(int a=1;a<n;a++)
                    {
                            for(int b=1;b<m;b++)
                            {
                                    out<<n<<" "<<m<<" "<<a<<" "<<b<<endl;
                            }
                    }
            }
    }
    return 0;
}

