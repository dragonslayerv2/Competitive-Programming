#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<climits>
#include<stdio.h>
using namespace std;

double table[50000][150]={{0}};

double result[150][50000]={{0}};

double alpha[120]={0};
double factorial[120];

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
 	   	
 	   	 vector<double> temp(size);
 	   	 
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

double dp[10000][10000];
//				f		k

double solve(long long value,int steps,int n){
	for(int f=0;f<=(n*(n-1))/2;f++)
		dp[f][0]=f;
	
	int pos=INT_MAX;
	for(int k=1;k<=steps;k++){
		double lastSum=0;
		for(int f=1;f<=(n*(n-1))/2;f++) 
			lastSum+=result[n][f]*dp[f][k-1];
	
		if(lastSum<=0.0000001&&lastSum>=-0.0000001){
			pos=k;
			break;
		}
		for(int f=1;f<=(n*(n-1))/2;f++){
			dp[f][k]=min(dp[f-1][k-1],lastSum);
		}
			
	}
	if(steps>=pos)
		return 0;
	return dp[value][steps];
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
	//	cout<<"f = "<<f<<endl;
		//cerr<<"Got f = "<<f<<endl;
		double ans;
		if(f<=k)
			ans=0;
		else
			ans=solve(f,k,array.size());
		
		cout << std::fixed;
  		std::cout << std::setprecision(6) << ans << '\n';
		//cerr<<"-------------------------"<<endl;
	}
}
