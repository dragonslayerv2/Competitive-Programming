#include<iostream>
using namespace std;


const int maxsize=4;
const int Max=101;


int C(int n,int r)
{ 
int tmp=1;
for (int i=r+1;i<=n;i++)
{
	tmp*=i;
}
for (int i=1;i<=r;i++)
{
	tmp/=r;
}
return tmp;
}


int det(int a[][maxsize],int n)
{
	int ans=0;
	
	int row=0,col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;
//cout<<product;
		while(i<n)
		{
//cout<<"*"<<a[i][j];
			product*=a[i][j];
			i++;
			j++;
			j%=n;
		}
		ans+=product;	
//cout<<"+";
		col++;
	}
	
	row=col=0;
	
	for(int k=0;k<n;k++)
	{
		int i=row;
		int j=col;
		int product=1;
//cout<<product;
		while(i<n)
		{
//cout<<"*"<<a[i][j];
			product*=a[i][j];
			i++;
			j--;
			j=(j+n)%n;
		}
		ans-=product;	
//cout<<"+";
		col++;
	}
	return ans;
}

int inside(int x[],int y[])
{
	  int D[4][4]={0};
	      
	  if() return -1;;  
	    
	  for(int i=0;i<4;i++) D[i][0]=x[i]*x[i]+y[i]*y[i];
	  for(int i=0;i<4;i++) D[i][1]=x[i];
	  for(int i=0;i<4;i++) D[i][2]=y[i];
	  for(int i=0;i<4;i++) D[i][3]=1;
	  
	  if(det(D,4)<=0)
	  {
	  	if(det(D2,3)>0) return 1;
	  	else return 0;
	  }
	  else
	  {
	  	if(det(D2,3)<0) return 1;
	  	else return 0;
	  }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x[Max],y[Max],pointsout=0,selx[4]={0},sely[4]={0};
		
		cin>>n;
		
		for(int i=0;i<n;i++)  cin>>x[i]>>y[i];

		  for(int i=0;i<n-2;i++)
		  {
			selx[0]=x[i];
			sely[0]=y[i];
			for(int j=i+1;j<n-1;j++)
		    { 
		          selx[1]=x[j];
			      sely[1]=y[j];
				  for(int k=j+1;k<n;k++)
		          { 
			           selx[2]=x[k];
			           sely[2]=y[k];
					   for(int l=0;l<n;l++)
		               { 
						    cout<<k<<" ";
						    
							selx[3]=x[l];
			                sely[3]=y[l];
			                
							int res=inside(selx,sely);
							if(res==-1) {pointsout+=n-3;break;}
							else if(!res) {pointsout++;}
	                   }
	              }	
		   } 
		  }
	    
	    double probab=(1-(pointsout/((n-3)*C(n,3))));
		cout<<probab<<"\n";
		
	}
}
