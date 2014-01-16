#include<stdio.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b

#define PI 3.1415926535897932384626//Extend it further

double FindMaxV(double H,double W)
{ 
   //case 1
   double r=min(H/(2*(PI+1)),W/4);
   double h=W;
   double Vol_1=PI*r*r*h;
   
   //printf("//case 1 \nR = %g A = %g\n",r,h); 
   
   //case 2
   r=min(H/3,W/(2*PI));
   h=H-2*r;
   double Vol_2=PI*r*r*h;
   
   //printf("//case 2 \nR = %g A = %g\n",r,h); 

   //case 3
   r=min(H/(4+2*PI),W/2);
   h=W;
   double Vol_3=PI*r*r*h;

   //printf("//case 2 \nR = %g A = %g\n",r,h); 

   //case 4
   r=min(H/6,W/(2*PI));
   h=H-(4*r);
   double Vol_4=PI*r*r*h;

   //printf("//case 2 \nR = %g A = %g\n",r,h); 

return  max(max(max(Vol_1,Vol_2),Vol_3),Vol_4);
}

int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
	double W,H; 	
	scanf("%lg%lg",&W,&H);
        double MaxV=max(FindMaxV(H,W),FindMaxV(W,H));//Max Volume
	printf("%.13g\n",MaxV);
  }
}
