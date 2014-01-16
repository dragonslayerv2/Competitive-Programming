#include<stdio.h>
#include<ctype.h>

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        putchar_unlocked(buf[i]);
     } while (buf[i++] != '\n');
}

int main()
{
    char a[200];
    char ch;
    int i;
    for(i=0;a[i-1]!='\n';i++)
    {
            a[i]=getchar_unlocked();
    }
    a[i]=NULL;
    
    
    fflush(stdin);
    ch=getchar_unlocked();
    
    int count=0;
    for(int i=0;a[i]!=NULL;i++)
    {
            if(toupper(a[i])==toupper(ch)) count++;
    }
    writeINT(count);
    return 0;
}
