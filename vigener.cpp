#include<iostream>
#include<vector>
using namespace std;

class vigener_cipher
{
	private:
		string key;
		int mod;
		int hash;
	public:
		vigener_cipher(const string & KEY,int MOD=26,int HASH='a')
		{
			key=KEY;
			mod=MOD;
			hash=HASH;
		}
		
		string encrypt(const string &data)
		{
			string output;
			int j=0;
			for(int i=0;i<data.size();i++)
			{
				if(j>=key.size())
					j=0;
					
				char ch=data[i]-hash+key[j]-hash+1;
				ch%=mod;
				ch+=hash;
				output+=ch;

				j++;
			}
			return output;
		}
		
		string decrypt(const string &data)
		{
			string output;
			int j=0;
			for(int i=0;i<data.size();i++)
			{
				if(j>=key.size())
					j=0;
					
				char ch=data[i]-hash-(key[j]-hash+1);
				ch=(ch+mod)%mod;
				ch+=hash;
				output+=ch;
				
				j++;
			}
			return output;
		}
};


int main()
{
	vigener_cipher machine("CRYPTO",26,'A');
	cout<<machine.decrypt(machine.encrypt("WHATANICEDAYTODAY"));
}
