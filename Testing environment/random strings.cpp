#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
char *genstring(char *a)
{
     int i;
     int length=1+rand()%9;
     for(i=0;i<length;i++)
             a[i]='a'+rand()%26;
     a[i]=NULL;  
     return a;  
}
int main()
{
    srand(time(NULL));
    char a[100];

    ofstream ob("test.txt");
    ob<<"100\n";

    for(int i=0;i<100;i++)
    {
            ob<<genstring(a)<<" ";
            ob<<genstring(a)<<endl;       
    }
}
