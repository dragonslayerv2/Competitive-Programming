#include<stdio.h>
inline int func(int z)
 {z++;}
int main()
{
    int z=1;
    func(z);    
    printf("%d",z);
    getchar();
}
