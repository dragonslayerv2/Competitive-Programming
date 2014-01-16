#include<iostream>
#include<vector>
using namespace std;


class RC4
{
	private:
		string key;
		basic_string<unsigned char> S;
		size_t I,J;
		void KSA()// key scheduling algorithm
		{
		
			for(int i=0;i<256;i++)
  			  S+= (unsigned char)(i);
			int j = 0;
			for (int i=0;i<256;i++)
			{
				j = (j + S[i] + key[i % key.size()]) % 256;
				swap(S[i],S[j]);
			}
		}
	public:
		
		class key_size_error{};
		
		RC4(const string& KEY):I(0),J(0)
		{
			if(KEY.size()<=256)
			{
				key=KEY;
				KSA(); 
			}
			else 
				throw key_size_error();
		}
		unsigned char next()
		{
    		I = (I + 1) % 256;
    		J = (J + S[I])% 256;
    	
			swap(S[I], S[J]);
			size_t a=S[I];
			size_t b=S[J];
    		return S[(a+b) % 256];
		}
};

int main()
{
	RC4 machine("swapnil");
	string message="Plaintext";
	for(int i=0;i<message.size();i++)
	{
		cout<<hex<<(int)(machine.next()^message[i]);
	}
	
}
