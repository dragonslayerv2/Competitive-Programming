#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<climits>
#include<stdio.h>
using namespace std;

long double table[50000][150]={{0}};

long double result[150][50000]={{0}};

long double alpha[120]={0};
long double factorial[120];

void preprocess(){
	int i,st,ctr=1,j,k;
 	table[0][1]=0;
 	factorial[0]=1;
 	
 	for(i=1;i<=100;i++)
 	  factorial[i]=i*factorial[i-1];
 	  
 	alpha[1]=0;
 	for(i=2;i<=100;i++)
 	  alpha[i]=alpha[i-1]+(i-1)/2.0;
 	  
 	table[1][1]=1;
 	int size=1,start,end,small;
 	int oldsize;
 	
 	result[1][0]=0;
 	
 	for(j=2;j<=100;j++)
    {
 	   	 int size=2+(j*(j-1))/2;
 	   	
 	   	 vector<long double> temp(size);
 	   	 
 	   	 int prev=1+((j-2)*(j-1))/2;
 	   	 for(i=0;i<prev;i++)
 	   	    temp[i]=table[i][j-1];

 	   	 for(i=0,k=size-1;i<prev;i++,k--)
 	   	    temp[k]=(temp[k]-table[i][j-1]);
 	   	
 	   	table[0][j]=1;
 	   	
 	   	 for(i=1;i<=size-1;i++)
 	   	   	 table[i][j]=(table[i-1][j]+temp[i]);
 	   	   	 
 	   	for(i=0;i<=size-2;i++)
 	   	     result[j][i]=table[i][j]/factorial[j];
 	}
}


long double solve(long long f,int k,int n){
	if(f==0)
		return 0;
	else if(k==0)
		return f;
	else{
		long double ans1 = solve(f-1,k-1,n);
		long double ans2 = 0;
		for(int i=0;i<=(n*(n-1))/2;i++){
			
			long double value = solve(i,k-1,n);
			ans2+=(result[n][i]*value);
		}
		return min(ans1,ans2);
	}
}
int main()
{	
	preprocess();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long k;
		cin>>k;
		//cerr<<"Got "<<n<<" "<<k<<endl;
		vector<int> array(n);
		for(int i=0;i<n;i++)
			cin>>array[i];
		
	//	for(int i=0;i<n;i++)
			//cerr<<array[i]<<" ";
		//cerr<<endl;
		
		long long f = 0;
		vector<int> arrayCopy=array;
	
		for(int i=0;i<n;i++)
			for(int j=1;j<n;j++)
				if(arrayCopy[j-1]>arrayCopy[j]){
					swap(arrayCopy[j-1],arrayCopy[j]);
					f++;
				}
				
		//cerr<<"Got f = "<<f<<endl;
		long double ans;
		if(f<=k)
			ans=0;
		else
			ans=solve(f,k,array.size());
		
		cout << std::fixed;
  		std::cout << std::setprecision(7) << ans << '\n';
		//cerr<<"-------------------------"<<endl;
	}
}
