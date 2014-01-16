inline int numrev(int n)
{
       int c=n;
       int x=0;
       while(c)
       {
               x=x*10+c%10;
               c/=10;
       }
       return x;
}
