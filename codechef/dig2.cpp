    #include<stdio.h>
    int count;
    int divd(int num)
    {
    int i=1;
    while(num!=0)
    {
    i=i*10;
    num /=10;
    }
    i=i/10;
    return i;
    }
    int fun1(int num)
    {
    int div= divd(num);
    int mod= num%div;
    int j,val;
    j= (num- mod) / div;
    val=mod*10 + j;
    if(j==0)
    { val=val/10;
    // div=div/10;
    }
    return val;
    }
    int fun2(int num)
    {
    int mod,j,val, div=divd(num);
    mod=num%10;
    j=num/10;
    // if(j==0)
    // div1=div1/10;
    val=mod*div + j;
    return val;
    }
    int main()
    {
    int no,i,max,T;
    int a;
    scanf("%d",&T);
    while(T--)
    {
    count=0;
    scanf("%d",&no);
    a=no;
    while(a!=0)
    { count++;
    a=a/10;
    }
    a=no;
    max=fun1(fun2(no));
    a= fun2(fun1(no));
    if(a>max)
    max=a;
    a=no;
    for(i=0;i<count;i++)
    {
    a=fun1(a);
    if(a>max)
    max=a;
    }
    a=no;
    for(i=0;i<count;i++)
    {
    a=fun2(a);
    if(a>max)
    max=a;
    }
    printf("%d\n",max);
    }//main test case while
    return 0;
    } 
