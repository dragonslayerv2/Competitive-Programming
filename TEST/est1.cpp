#include<iostream>
using namespace std;

class feet{
      public:
      int a;
      
             feet()
             {
                   a=0;
             }             
             
             feet(int x)
             {
                      a=x;
                               
             }
      
};


class inch
{
      public:
      int data;
      
                operator feet()
               {
                    feet temp;
                    temp.a=data;
                    return temp;
               }
 };

int main()
{
    feet ob;
    inch ob2;
    ob2.data=2;
    ob=ob2;
    cout<<ob.a;
    cin>>ob.a;
    return 0;
}
