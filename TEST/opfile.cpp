#include<fstream>
using namespace std;

int main()
{
 ofstream test("test.txt");
 test<<"100000\n";
 for(int i=1;i<=100000;i++)
 {
         test<<i<<endl;
 }
 test.close();
 
}
