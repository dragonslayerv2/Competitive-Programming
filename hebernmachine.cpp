#include<iostream>
#include<vector>
using namespace std;

class hebern_machine
{
	string key;
	int currentpos;
	int hash;
	int mod;
	
	public:
		hebern_machine(string KEY,int HASH='A',int MOD=26):key(KEY),hash(HASH),mod(MOD){}
		
		void reset() {currentpos=0;}
		
		string encrypt(const string &data)
		{
			string output;
			for(int i=0;i<data.size();i++)
			{
				if(currentpos>=key.size()) reset();
				output+=key[(currentpos+data[i]-hash)%mod];
				currentpos++;		
			}
			return output;
		}
		
		string decrypt(const string &data)
		{
			string output;
			for(int i=0;i<data.size();i++)
			{
				if(currentpos>=key.size()) reset();
				int pos=-1;
				
				for(int j=0;j<key.size();j++)
				{
					if(key[j]==data[i])
					{
						pos=j;
						break;
					}
				}
				output+=hash+(mod+pos-currentpos)%mod;
				currentpos++;
			}	
			return output;	
		}

};
int main()
{
	hebern_machine machine("ABCDEF",'A',6);
	string s=machine.encrypt("ABCDEFABCEEF");
	machine.reset();
	cout<<machine.decrypt(s);
}
