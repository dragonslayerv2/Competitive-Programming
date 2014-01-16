#include<iostream>
#include<vector>
using namespace std;

template<class type> class PRG
{
	public: virtual type next()=0;
}; 



template<class type> class lcg:public PRG<type> //linear congurential generator
{
	type seed;
	type last;
	type a, b, p;
	
	public:
		lcg(type SEED,type A,type B,type P):seed(SEED), last(SEED),a(A),b(B),p(P)
		{}
		void reset(){last=seed;}

		type next()
		{
			last=(last*a+b)%p;
			return last;
		}
};

template<class type>  class stream_cipher
{
	PRG<typename type::value_type> &prg;
	public:
		template<class T> stream_cipher(T ob):prg(ob){}

		type encrypt(const type & data)
		{
			type output;
			for(int i=0;i<data.size();i++)
			{
				
				output.push_back(data[i]^prg.next());
				
			}
			return output;
		}
};

int main()
{
	stream_cipher<string > machine(lcg<char>(20,100,111,119));
	
	string a="aaa";
	cout<<machine.encrypt(a)[1];
}
