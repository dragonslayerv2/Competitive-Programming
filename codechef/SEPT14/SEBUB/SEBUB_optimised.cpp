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

double solve(int value,int steps,int n){
	vector<double> suffixSum(((n*(n-1))/2)+1);
	suffixSum[(n*(n-1))/2]=result[n][(n*(n-1))/2];
	for(int i=((n*(n-1))/2)-1;i>=0;i--)
		suffixSum[i]=result[n][i]+suffixSum[i+1];	
	
	vector<double> apSum(((n*(n-1))/2)+1);
	apSum[(n*(n-1))/2]=result[n][(n*(n-1))/2];
	for(int i=((n*(n-1))/2)-1;i>=0;i--)
		apSum[i]=suffixSum[i]+apSum[i+1];	
	
	double alpha=0;
	for(int f=0;f<=(n*(n-1))/2;f++)
		alpha+=result[n][f]*f;
	
	double ans1 = max(0,value-steps);
	double ans2=INT_MAX; 
	if(steps>=1){
		for(int k=1;k<steps;k++)
			alpha=apSum[k+1]-apSum[k+(int)alpha+1]+((alpha-(int)(alpha))*(suffixSum[k+(int)alpha+1]));
		ans2=alpha;
	}
	return min(ans1,ans2);
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
		//cout<<"f = "<<f<<endl;
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
