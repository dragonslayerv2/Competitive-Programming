inline int ispallindrome(int n)
{
       int x=0,c=n;
       while(c)
       {
               x=x*10+c%10;
               c/=10;
       }
       if(x==n) return 1;
       else return 0;
}
