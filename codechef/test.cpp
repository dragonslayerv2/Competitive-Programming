#include<fstream>
using namespace std;
int main()
{
    ofstream test("test.txt");
    test<<10000<<endl;
    for(int i=0;i<10000;i++)
    {
            test<<i<<endl;
    }
    test.close();
    return 0;
}
