#include<iostream>
#include<vector>
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

int main()
{
	long long Tmatrix[][5]={{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{1,2,3,2,1}};
	long long Fmatrix[][1]={{1},{2},{3},{2},{1}};
	
	matrix<long long> T(5,5);
	matrix<long long> F(5,1);
	T.assign(5,5);
	
	for(int i=0;i<T.rowSize();i++)
		for(int j=0;j<T.columnSize();j++)
			T[i][j]=Tmatrix[i][j];
	
	for(int i=0;i<F.rowSize();i++)
		for(int j=0;j<F.columnSize();j++)
			F[i][j]=Fmatrix[i][j];
	
	const int MOD = 10000007;
	
	int n;
	cin>>n;
	while(n--)
	{
		long long a;
		cin>>a;
		
		switch(a)
		{
			case 1: cout<<1<<endl;break;
			case 2: cout<<2<<endl;break;
			case 3: cout<<3<<endl;break;
			case 4: cout<<2<<endl;break;
			case 5: cout<<1<<endl;break;
			default: cout<<((p(T,a-5,MOD)*F)%MOD)[4][0]<<endl;
		}
	}	
}
