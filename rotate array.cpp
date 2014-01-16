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
		
		void rotate(size_t pos)
		{
			first=(size+(last-pos+1))%size;
			last=(size+(first-1))%size;
		}
};

int main()
{
	array arr(10);
	for(int i=0;i<10;i++)
	{
		arr[i]=i;
	}
	arr.rotate(200);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i];
	}
	
}
