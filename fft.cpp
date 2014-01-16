#include<iostream>
#include<complex>
#include<vector>
#include<map>
using namespace std;

#define PI 3.14159265
#define EPSILON 0.000001
template<class T> vector<complex<double> > fft(const vector<T> &poly, const long long bound,bool inverse=false,const long long begin_pos=0,const long long dif=1)
{
	if(bound==1) // base case
	{
		vector<complex<double> > y(1);
		y[0]=poly[begin_pos];
		return y;
	}
	
	complex<double> wn(cos((2*PI)/bound), sin((2*PI)/bound));; // nth root of unity
	if(inverse)
		wn=complex<double>(cos((-2*PI)/bound), sin((-2*PI)/bound));
		
	complex<double> w(1); // stores currect cube root of unity
	
	// partition of the polynomial is done through ap mapping
	vector<complex<double> > y0=fft(poly,bound/2,inverse,begin_pos,dif*2); 
	vector<complex<double> > y1=fft(poly,bound/2,inverse,begin_pos+dif,dif*2);
	
	vector<complex<double> > y(bound);// keeping this here preserves memory loss. At any time only O(n) memory is requeired not O(nlogn)
	for(long long k=0;k<bound/2;k++)
	{
		y[k]=(y0[k]+w*y1[k]);
		y[bound/2+k]=(y0[k]-w*y1[k]);
		w=w*wn; //  to get the value of the next omega
	}
	return y;
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
