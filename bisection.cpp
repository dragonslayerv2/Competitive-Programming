#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float evalpoly(float coef[], int degree, float x)
{
      float poly=0;
      for(int i=degree;i>=0;i--)
              poly=poly*x+coef[i];
      return poly;
}


int main()
{
    float coef[1000];
    int degree;
    
    //----------Input Phase-----------------------------------------------------
    printf("Degree of the polynomial = ");
    scanf("%d",&degree);
    printf("Enter the coefficients in decreasing order of exponents.");
    for(int i=degree;i>=0;i--)
            scanf("%f",&coef[i]);    
  
  
  
    float l,h;
    printf("Enter lower point and upper point");
    scanf("%f %f",&l,&h);
    
  /*  if(evalpoly(coef,degree,l)*evalpoly(coef,degree,h)>0)
    {
         printf("Error: Sign of polynomial must be opposite in lower and upper values");
         return -1;
    }*/
    
    
    float c;
    printf("l\t\th\t\tc\t\tf(c)\n"); 
    while(1)
    {
            
            c=(l+h)/2;
            float val=evalpoly(coef,degree,c);
            printf("%f\t%f\t%f\t%f\n",l,h,c,val);
            
            if(val<=0.0000001f&&val>=-0.0000001f) break;
            else if((val>0&&evalpoly(coef,degree,h)>0)|| (val<0&&evalpoly(coef,degree,h)<0))
                                        h=c;
            else
                                        l=c;                       
    }
    
    printf("Root = %f",c);
    system("timeout -1");
    return 0;
}
