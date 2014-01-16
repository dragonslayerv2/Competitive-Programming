//deChef submission 900305 (C++ 4.0.0-8) plaintext list. Status: AC, problem ALGFACT, contest AGTK2012. By shobhit94 (shobhit94), 2012-03-08 21:59:49.

    #include<stdio.h>
  #include<conio.h>   
     
    #define size 1000
    int x[size];
    void multiply(int n)
    {
    for(int i=size-1;i>=0;i--)
    {
    x[i]=x[i]*n+x[i+1]/10;
    }
    for(int i=size-1;i>=0;i--)
    {
    x[i]=x[i]%10;
    }
    }
    int print()
    {int i=0;
    for(;x[i]==0;i++)
    {}
    for(;i<size-1;i++)
    printf("%d",x[i]);
     
    }
    void reset()
    {
    for(int i=0;i<size;i++)
    {
    x[i]=0;
    }
    x[size-2]=1;
     
    }
    int main()
    {
    int l;
    int n;
    scanf("%d",&l);
    int m[10];
    for(int i=0;i<l;i++)
    {
    scanf("%d",&m[i]);
    }
    for(int j=0;j<l;j++)
    {
    reset();
    for(int i=2;i<=m[j];i++)
    {
    multiply(i);
    }
    print();
    printf("\n");
    getch();
    }
    }
