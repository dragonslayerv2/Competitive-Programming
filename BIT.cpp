class BIT
{
	long long tree[100010];
	int n;
	
	public:
		BIT(int A[],int N)
		{
			n=N;
			for(int i=0;i<=n;i++)
				tree[i]=0;
			
			for(int i=1;i<=n;i++)
				increase(i,A[i]);
		}
		long long read(int idx)
		{
			int sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, int val)
		{ 
			while (idx <= n)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		long long query(int a,int b)
		{
			return read(b)-read(a-1);
		}
};


int main()
{
	int n,q;
	cin>>n>>q;
	BIT tree(n);
	for(int i=1;i<=n;i++)
	{
		long long temp;
		cin>>temp;
		
	}
	

}
}
