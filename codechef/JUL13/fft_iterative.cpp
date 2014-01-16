#include<iostream>
#include<vector>
#include<complex>
using namespace std;
#define PI 3.14159265358979323846
#define EPSILON 0.000001
int reverse(int k,int bits)
{
	int result=0;
	while(bits)
	{
		result<<=1;
		if(k&1)
			result++;
		k>>=1;
		bits--;
	}
	return result;
}
template<class T> vector<complex<double> > bit_reverse_copy(const vector<T> &a)
{
	vector<complex<double> > result(a.size());
	//------------- calculate bits in size
	int size=a.size();
	int bits=0;
	while(size)
	{
		bits++;
		size>>=1;
	}
	bits--;
	//-------------------------------------
	for(int k=0;k<a.size();k++)
	{
	//	cout<<reverse(k,bits)<<"<==="<<k<<endl;
		result[reverse(k,bits)]=complex<double>(a[k]);
	}
	return result;
}

template<class T> vector<complex<double> > fft(const vector<T> &poly, const long long bound,bool inverse=false)
{
	vector<complex<double> > a=bit_reverse_copy(poly);
	//-----------------------------------
	int size=a.size();
	int lgn=0;
	while(size)
	{
		lgn++;
		size>>=1;
	}
	lgn--;
	//-----------------------------------
	
	for(int s=1;s<=lgn;s++)
	{
		int m=1<<s; // 2^s
		complex<double> wm(cos((2*PI)/m), sin((2*PI)/m));; // nth root of unity
		if(inverse)
			wm=complex<double>(cos((-2*PI)/m), sin((-2*PI)/m));
		for(int k=0;k<a.size();k+=m)
		{
			complex<double> w(1);
			for(int j=0;j<m/2;j++)
			{
				complex<double> t=w*a[k+j+m/2];
				complex<double> u=a[k+j];
				a[k+j]=u+t;
				a[k+j+m/2]=u-t;
				w=w*wm;
			}
		}
	}
	return a;	
}


int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	auto b=fft(a,a.size());
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i];
	}
}
