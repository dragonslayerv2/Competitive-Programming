#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    long long count=0;
    for(int i=1;i<10;i++)
    {
            for(int j=1;j<10;j++)
            {
                    for(int k=1;k<10;k++)
                    {
                            for(int l=1;l<10;l++)
                            {
                                    for(int m=1;m<10;m++)
                                    {
                                            int number=(((((i*10+j)*10)+k)*10+l)*10+m);
                                            if(!(number%3)) count++;
                                    }
                            }
                    }
            }        
    }
    cout<<count;
    getchar();
    return 0;
}
