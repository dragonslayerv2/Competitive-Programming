#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1000000000+7;

template<class T> class matrix
{	
	public:
		typedef T value_type;
	private:
		vector<vector<T> > M;
	public:
		matrix(){}
		
		matrix(int rSize,int cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));	
		}

		void assign(int rSize,int cSize)
		{
			M.assign(rSize,vector<value_type>(cSize));	
		}
		
		vector<value_type>& operator[](int i)
		{
			return M[i];
		}
		
		
		int rowSize() const
		{
			return M.size();
		}
		int columnSize() const
		{
			if(M.size()==0)
				return 0;
			else
				return M[0].size();
		}
		matrix<value_type> operator *(matrix<value_type> B) //assumes matricces are multiplicable
		{
			matrix<value_type> &A=*this;
			matrix<value_type> temp(A.rowSize(),B.columnSize());
			
			for(int i=0;i<temp.rowSize();i++){
			
				for(int j=0;j<temp.columnSize();j++){
					long long ans=0;
					for(int k=0;k<B.rowSize();k++){
						ans=(ans+A[i][k]*B[k][j])%MOD;
						ans%=MOD;
					}
					temp[i][j]=ans;
				}
			}
			return temp;
		}
		
		matrix<value_type> operator %(value_type MOD)
		{
			matrix<value_type> temp(rowSize(),columnSize());
			for(int i=0;i<rowSize();i++)
				for(int j=0;j<columnSize();j++)
					temp[i][j]=M[i][j]%MOD;
			return temp;
		}
		void clear()
		{
			M.clear();
		}
		
		static matrix<value_type> identity(int i)
		{
			matrix<value_type> X;
			X.assign(i,i);
			for(int j=0;j<i;j++)
				X[j][j]=1;	
			return X;
		}
};

template<class T> T p(T n,long long m,int MOD)
{
    if(m==0) 
		return matrix<long long>::identity(n.rowSize());
    
    T x=p(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}


int main(){
	//freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		n--;
		matrix<long long> evenTransition(m,m);
		matrix<long long> oddTransition(m,m);		

		for(int i=0;i<m;i++){
			evenTransition[i][i]=1;
			if(i-1>=0)
				evenTransition[i][i-1]=oddTransition[i][i-1]=1;
			if(i+1<m)
				evenTransition[i][i+1]=oddTransition[i][i+1]=1;
		}
		matrix<long long> baseMatrix(1,m);
		for(int i=0;i<m;i++)
			baseMatrix[0][i]=1;
		if(n==0)
			cout<<m;
		else{
			matrix<long long> newMatrix = (baseMatrix*((p(evenTransition,n/2,MOD)*p(oddTransition,n/2,MOD))%MOD))%MOD;
			if(n&1)
				newMatrix=(newMatrix*oddTransition)%MOD;
			
			long long sum=0;
			for(int i=0;i<m;i++)
				sum+=newMatrix[0][i];
			sum%=MOD;
			cout<<sum;
		}
		cout<<endl;
	}
}
