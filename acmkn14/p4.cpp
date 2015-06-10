#include<vector>
#include<iostream>
using namespace std;

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
			
			for(int i=0;i<temp.rowSize();i++)
				for(int j=0;j<temp.columnSize();j++)
					for(int k=0;k<B.rowSize();k++)
						temp[i][j]+=A[i][k]*B[k][j];
			
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

const long long MOD = 10000007;


int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		matrix<long long> adjancy(10*k,10*k);
		for(int i=0;i<10*k;i++){
				if(i%10>3)
					continue;
				bool isTaken=(i%10)/2;
				bool previousS=(i%10)%2;
				int iK=i/10;
				
				if(!previousS){
					adjancy[i][iK*10+(isTaken*2)+1]++;
				}
				adjancy[i][(iK*10)+2]++;
				adjancy[i][((iK+1)%k)*10+isTaken*2]++;
		}	
			
		matrix<long long> powerMatrix=p(adjancy,n,MOD);
		long long ans=(powerMatrix[0][2]+powerMatrix[0][3])%MOD;
		cout<<ans<<endl;
	}
}
