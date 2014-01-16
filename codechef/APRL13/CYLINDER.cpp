#include<stdio.h>
#include<iostream>
using namespace std;


#define PI 3.1415926535897932384626//Extend it further

double FindMaxV(double H,double W)
{ 
   //case 1
   double r=min((H/(2*(PI+1))),W/4);
   double h=W;
   double Vol_1=PI*r*r*h;
   
   //printf("//case 1 \nR = %g A = %g\n",r,h); 
   
   //case 2
   r=min((H/3),(W/(2*PI)));
   h=H-2*r;
   double Vol_2=PI*r*r*h;
   
   //printf("//case 2 \nR = %g A = %g\n",r,h); 

   //case 3
   r=min((H/(4+2*PI)),(W/2));
   h=W;
   double Vol_3=PI*r*r*h;

   //printf("//case 2 \nR = %g A = %g\n",r,h); 

   //case 4
   r=min(H/6,(W/(2*PI)));
   h=H-(4*r);
   double Vol_4=PI*r*r*h;

   //printf("//case 2 \nR = %g A = %g\n",r,h); 

return  max(max(max(Vol_1,Vol_2),Vol_3),Vol_4);
}

int main()
{
  int T;
  scanf("%d",&T);
  	cout<<fixed;
	cout.precision(11);
  while(T--)
  {
	int W,H; 	
	scanf("%lld %lld",&W,&H);
    double MaxV=max(FindMaxV(H,W),FindMaxV(W,H));//Max Volume

	cout<<MaxV<<endl;
  }
}
