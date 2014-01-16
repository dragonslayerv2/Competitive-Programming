
/*
	Name: Polynomial Multiplication through FFT
	Copyright: 
	Author: Shobhit Saxena
	Date: 12/07/13 15:33
	Description: 
*/
#include<iostream>
#include<complex>
#include<vector>
#include<map>
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


vector<double> inverse_fft(const vector<complex<double> > &poly, const long long bound)
{
	vector<complex<double> > y=fft(poly,bound,true);
	vector<double> a(y.size());
	for(long long i=0;i<y.size();i++)
		a[i]=(y[i].real()/bound);
	return a;
}

template<class T> vector<T> operator *(vector<T> &p1,vector<T> &p2)
{
	long long size1=p1.size();
	long long size2=p2.size();
	
	long long maxsize=max(p1.size(),p2.size());
	
	//----- find the power of 2 greater than size
	long long pos=0;
	long long count=0;
	while(maxsize)
	{
		if(maxsize&1)
			count++;
		maxsize>>=1;
		pos++;		
	}
	maxsize=1<<(pos+1);
	
	p1.resize(maxsize,0);
	p2.resize(maxsize,0);
	
	vector<complex<double> > p1_trans=fft(p1,p1.size());
	vector<complex<double> > p2_trans=fft(p2,p2.size());
	
	vector<complex<double> > trans(p1_trans.size());
	for(long long i=0;i<trans.size();i++)
	{
		trans[i]=p1_trans[i]*p2_trans[i];
	}
	vector<double> result=inverse_fft(trans,trans.size());
	return result;
}
void print_poly(vector<double> &a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>EPSILON)
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

#define GETCHAR getchar_unlocked

inline int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}




int main()
{
	long long n;
	n=readlong();
	if(n==1)
	{
	
		readlong();
		cout<<0;
	}
		
		
	else if(n<3000)
	{
		vector<long long> array;
		array.reserve(n);
		for(long long i=0;i<n;i++)
		{
			long long a;
			a=readlong();
			array.push_back(a);
		}
		map<long long,bool> sums;
		for(long long i=0;i<n;i++)
		{
			long long sum=0;
			for(long long j=i;j<n;j++)
			{
				sum+=array[j];
				sums[sum]=true;
			}
		}
		cout<<sums.size()-1<<endl;
	}
	else
	{
//	throw 1;
	vector<long long> array;
	array.reserve(n);
	for(long long i=0;i<n;i++)
	{
		long long a;
		a=readlong();
		array.push_back(a);
	}
	
	vector<long long> sums(n);
	sums[0]=array[0];
	for(long long i=1;i<n;i++)
	{
		sums[i]=sums[i-1]+array[i];
	}
	
	vector<double> p1,p2;
	p1.resize(sums[n-1]+1,0); 
	p2.resize(sums[n-1]+1,0); 
	
	for(long long i=0;i<n;i++)
		p1[sums[i]]=1;	
	
	for(long long i=0;i<n;i++)
		p2[sums[n-1]-sums[i]]=1;
	p2[sums[n-1]]=1;
    vector<double> result = p1*p2;
    //print_poly(p1);
    //print_poly(p2);
    //print_poly(result);
    long long count=0;
	for(long long i=sums[n-1]+1;i<result.size();i++)
	{
		if(result[i]>EPSILON)	
		{
			count++;
		}
	}
	
	cout<<count-1<<endl;
	}
}
