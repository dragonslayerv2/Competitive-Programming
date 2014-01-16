    #include<stdio.h>
    #include<iostream>
    #include<math.h>
    using namespace std;
    int main()
    {
        long int n;
        int t,z=0;
        register int i;
        scanf("%d",&t);
        while(t>0)
        {
                  scanf("%d",&n);
                  for(i=1;;i++)
                  {
                               printf("%d\n",n/pow(5,i));
                               if(((int)n/pow(5,i))>=1)
                                                       {cout<<"y"<<" ";z+= (int)n/pow(5,i);}
                               else break;
                  }
                  printf("%d\n",z);
                  z=0;
                  t--;
        }
        return 0;
    } 
