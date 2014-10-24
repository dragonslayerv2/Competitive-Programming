#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define mod 1000000007
class matrix
{	
	private:
		vector<vector<int> > M;
	public:
		matrix(){}
		
		matrix(int rSize,int cSize)
		{
			M.assign(rSize,vector<int>(cSize));	
		}

		void assign(int rSize,int cSize)
		{
			M.assign(rSize,vector<int>(cSize));	
		}
		
		vector<int>& operator[](int i)
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
		matrix operator *(matrix B) //assumes matricces are multiplicable
		{
			matrix &A=*this;
			matrix temp(A.rowSize(),B.columnSize());
			
			for(int i=0;i<temp.rowSize();i++){
				for(int j=0;j<temp.columnSize();j++){
					int ans=0;
					for(int k=0;k<B.rowSize();k++){
						ans+=(A[i][k]*(long long)B[k][j])%mod;
						ans %= mod;
					}
					temp[i][j]=ans;
				}
			}
			
			return temp;
		}
		
		matrix operator %(int MOD)
		{
			matrix temp(rowSize(),columnSize());
			for(int i=0;i<rowSize();i++)
				for(int j=0;j<columnSize();j++)
					temp[i][j]=M[i][j]%MOD;
			return temp;
		}
		void clear()
		{
			M.clear();
		}
		
		static matrix identity(int i)
		{
			matrix X;
			X.assign(i,i);
			for(int j=0;j<i;j++)
				X[j][j]=1;	
			return X;
		}
};

matrix p(matrix n,int m,int MOD)
{
    if(m==1)
	return n;
	
	matrix ans = n*n;
    ans = p(ans, m/2,MOD);
    if(m&1) ans = ans*n;
    return ans;
	
}


int main()
{
	
	int t;
	
	matrix matrix1(2,2);
	matrix matrix2(2,1);
	matrix1[0][0]=0;
	matrix1[0][1]=1;
	matrix1[1][0]=2;
	matrix1[1][1]=2;
		
	matrix2[0][0]=1;
	matrix2[1][0]=3;
	
	scanf("%d",&t);
	while(t--){
		int N;
		scanf("%d",&N);

		
		if(N==1){
			cout<<"1\n";
		}
		else if(N==2){
			cout<<"3\n";
		}
		
		else{
		
			printf("%d\n",(matrix1*p(matrix2,N-2,mod))[1][0]);
		}
		
	}
}
