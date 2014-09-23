#include<iostream>
using namespace std;
#include<vector>
#include<stdio.h>
#include<iomanip>
long double table[50000][150]={{0}};

long double result[150][50000]={{0}};
#include<time.h>

long double alpha[120]={0};
long double factorial[120];

void preprocess()
 {	int i,st,ctr=1,j,k;
  //clock_t ti=clock();
 	table[0][1]=0;
 	factorial[0]=1;
 	for(i=1;i<=100;i++)
 	  {factorial[i]=i*factorial[i-1];
 	  }
 	alpha[1]=0;
 	for(i=2;i<=100;i++)
 	  {
 	  alpha[i]=alpha[i-1]+(i-1)/2.0;
 	  }
 	  
 	table[1][1]=1;
 	int size=1,start,end,small;
 	int oldsize;
 	
 	result[1][0]=0;
 	
 	for(j=2;j<=100;j++)
 	   { int size=2+(j*(j-1))/2;
 	   	
 	   	 vector<long double> temp(size);
 	   	 
 	   	 int prev=1+((j-2)*(j-1))/2;
 	   	 for(i=0;i<prev;i++)
 	   	    temp[i]=table[i][j-1];
 	   	 for(i=0,k=size-1;i<prev;i++,k--)
 	   	    temp[k]=(temp[k]-table[i][j-1]);
 	   	
 	   	table[0][j]=1;
 	   	
 	   	 for(i=1;i<=size-1;i++)
 	   	   {
	   	   	 table[i][j]=(table[i-1][j]+temp[i]);
 	   	   	
 	   	   }
 	   	for(i=0;i<=size-2;i++)
 	   	   { result[j][i]=table[i][j]/factorial[j];
 	       }
 	    
 	   	 
 	   	 
 	   }
 	   
 }
 
 
 
 int main()
  {
  	
  	preprocess();
  	int t,n,i,j;
  	long long k;
  	cin>>t;
  	while(t--)
  	  {
  	  	cin>>n>>k;
  	  	vector<int> a(n),b(n);
  	  	for(i=0;i<n;i++)
  	  	  {cin>>a[i];
  	  	   b[i]=a[i];
  	  	  }
  	  	int fa=0;
  	  	for(i=0;i<n;i++)
  	      {for(j=0;j<n-1;j++)
  	         {if(b[j]>b[j+1])
  	            {
  	            	swap(b[j],b[j+1]);
  	            	fa++;
  	            }
  	         }
  	      }
  	    
  	    if(fa<=k)
  	      {cout<<"0.000000"<<endl;
  	       continue;
  	      }
  	    int size=(n*(n-1))/2;
  	    long double initial=fa,ans=0;
  	    if(k==0)
  	      {	cout << std::fixed;
  		std::cout << std::setprecision(6) <<initial << '\n';
  	       continue;
  	      }
  	    	int loop=2;
		if(fa-1<alpha[n])
		
		  {
		  	long double value=fa-k;
		 	cout << std::fixed;
  		std::cout << std::setprecision(6) << value << '\n';
		  continue;
		  }
		vector<long double> array(size+1);
		for(i=0;i<=size;i++)  	    
		   {array[i]=result[n][i];
		    //cout<<array[i]<<" ";
		    
		   }
	
		for(loop;loop<=k;loop++)
		   {array[0]=0;
		   /*for(i=0;i<=size;i++)
		     cout<<array[i]*factorial[n]<<" ";
		    cout<<endl;
		   	*/
			   for(i=1;i<=alpha[n];i++)
		   	  {array[i-1]=array[i];
		   	   array[i]=0;
		   	  }
		   	/* for(j=0;j<=size;j++)
		     cout<<array[j]*factorial[n]<<" ";
		    cout<<endl;
		   	*/
			vector<long double> temp(size+1,0);
		   	for(i;i<=size;i++)
		   	  {
		   	  	for(j=0;j<=size;j++)  	    
		  			 {temp[j]+=result[n][j]*array[i];
		   		     }
		   		array[i]=0;
		   	  }
		   	
		   	for(i=0;i<=size;i++)
		   	  array[i]+=temp[i];
		   	
		   }
		   /*  for(i=0;i<=size;i++)
		     cout<<array[i]*factorial[n]<<" ";
		    cout<<endl;*/
		ans=0;
		for(i=0;i<=size;i++)
		  ans+=array[i]*i;
		 	cout << std::fixed;
  		std::cout << std::setprecision(6) << ans << '\n';
		
		   
  	  	
  	  }
  	
  }
