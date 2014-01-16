#include<fstream>
#include<iostream>

using namespace std;
int main()
{
    ifstream t1("o1.txt");
    if(!t1) cout<<"O1.txt not found\n";
    ifstream t2("o2.txt");
    if(!t2) cout<<"O2.txt not found\n";
    int n1,n2;
    int i=1;
    while(t1&&t2)
    {
              t1>>n1;
              t2>>n2;
              if(n1!=n2)
                        printf("Line=>%d n1=%d, n2=%d\n",i,n1,n2);   
              i++;
    }
    printf("Over\n");
    getchar();
}
