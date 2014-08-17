#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int t = 20;
    cout << t << endl;
    while (t--) {
        int n = rand() % 20 + 1, m = rand() % 40 + 1;
        cout << n << " " << m << endl;
        for (int i = 0; i < m; i++) {
            cout << rand() % 20 + 1 << " ";
        }
        cout << endl;
    }
}
