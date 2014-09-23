#include<iostream>
using namespace std;

class array
{
	public:
		int *arr;
		size_t size;
		int first;
		int last;
	public:
		array(size_t SIZE)
		{
			size=SIZE;
			arr=new int[size];
			first=0;
			last=size-1;
		}
		
		int &operator [](size_t pos)
		{
			return arr[(first+pos)%size];
		}
		
		void rotateAntiClockwise(size_t pos)
		{
			first=(size+(last-pos+1))%size;
			last=(size+(first-1))%size;
		}
		
		void rotateClockwise(size_t pos)
		{
			first=(first+pos)%size;
			last=(last+pos)%size;
		}
		
		void print(){
			for(int i=0;i<size;i++)
				cout<<(*this)[i]<<" ";
			cout<<endl;
		}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	array A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	
	while(m--){
		char queryType;
		int d;
		cin>>queryType>>d;
		switch(queryType){
			case 'C': A.rotateClockwise(d);
					break;
			case 'A': A.rotateAntiClockwise(d);
					break;
			case 'R': cout<<A[d-1]<<endl;
					
					break;
		}
	}
}
