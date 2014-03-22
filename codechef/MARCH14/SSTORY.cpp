/*
	Name: Longest Common Substring of m strings.
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/12/13 16:28
	Description: This code finds the longest common substring of m strings in O(nmlogmn) time and O(nmlogmn) memory.
				The code can be reduced to O(mn) and O(mn) time using a linear algorithm to find the suffix arrays.
				The idea is to concatenate the strings and generate the lcp array and iterate over it.
				This can also be done with KMP algotihm which utilises a O(n^2m) time for matching.				
*/

#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
//-------------SUFFIX ARRAY ALGORITHM-------------------------------------------
class suffix_array
{
	private:	
		string _s;
		vector<vector<int> > _P; // this can be made of O(n) size but 
		vector<int> _sa;
		void _build_suffix_array()
		{
			//----------Determining the size of Matrix------------------------
			size_t lgsize;
			{	
				size_t _size;
				for(lgsize=0,_size=(int)(_s.size())-1;_size;_size>>=1,lgsize++);
			}
	
			 _P.resize(lgsize+1,vector<int>(_s.size()));
	
			//------------ Sorting initial character in O(nlog(sigma))-----------------
			map<char,int> char_map;
			for(int i=0;i<_s.size();i++)
				char_map[_s[i]]=0;
	
			int k=0;
			for(map<char,int>::iterator i=char_map.begin();i!=char_map.end();i++,k++)
				i->second=k;
	
			for(int i=0;i<_s.size();i++)
				_P[0][i]=char_map[_s[i]];
			//-------------------------------------------------------------------------
	
	
			typedef pair<pair<int,int>,int > entry;
			for(int step=1;(1<<(step-1))<_s.size();step++)
			{
				vector<entry> L(_s.size());
				for(int i=0;i<_s.size();i++)
				{
					L[i].first.first=_P[step-1][i];
					if((i+(1<<(step-1)))<_s.size())
						L[i].first.second=_P[step-1][i+(1<<(step-1))];
					else
						L[i].first.second=-1;
					L[i].second=i;
				}		
				sort(L.begin(),L.end());
		
				int k=0;
				_P[step][L[0].second]=0;
				for(int i=1,k=0;i<_s.size();i++)
				{
					if(L[i].first!=L[i-1].first)
						k++;
					_P[step][L[i].second]=k;	
				}
			}
			#ifdef SUFFIX_ARRAY_DEBUG
			for(int i=0;i<_P.size();i++)
			{
				for(int j=0;j<_P[i].size();j++)
					cout<<_P[i][j]<<" ";
				cout<<endl;
			}
			#endif
			_sa.resize(_s.size());
			for(int i=0;i<_s.size();i++)
				_sa[_P[_P.size()-1][i]]=i;
		}

	public:
		suffix_array()
		{
		}
		suffix_array(const string &S)
		{
			assign(S);
		}
		
		void assign(const string &S)
		{
			_P.clear();
			_s=S;
			_build_suffix_array();
		}
		
		int operator [](size_t pos) const
		{
			return _sa[pos];
		}
		
		int lcp(size_t a,size_t b) const
		{
			int ans=0;
			for(int k=_P.size()-1;k>=0;k--)
				if(_P[k][a]==_P[k][b])
				{
					ans+=(1<<k);
					a+=(1<<k);
					b+=(1<<k);
				}
			return ans;
		}
		
		void clear()
		{
			_P.clear();
			_s.clear();
		}
		~suffix_array()
		{
			clear();
		}
		size_t size() const
		{
			if(_P.size())
				return _P[0].size();
			else
				return 0;
		}
};
//------------------------------------------------------------------------------

int which_suffix(vector<string> &s,size_t pos)
{
	int suffix_pos=0;
	while(pos>s[suffix_pos].size())
	{
		pos-=s[suffix_pos].size();
		suffix_pos++;
		
		pos--;
	}
	if(pos==s[suffix_pos].size())
		return -1;
	else
		return suffix_pos;
}
//------------------------------------------------------------------------------


int main()
{
	
	int n;
	n=2;
	vector<string> strings(n);
	for(int i=0;i<n;i++)
		cin>>strings[i];
	
	string bigstring;
	bigstring=strings[1]+(char)(1)+strings[0];
	
	suffix_array sa(bigstring);	
	
	vector<int> string_count(strings.size());
	int total_string_present=0;
	
	int maximum=numeric_limits<int>::min();
	int pos=0;
	
	
	#ifdef DEBUG
	for(int i=0;i<sa.size();i++)
	{
		cout<<i<<" "<<bigstring.substr(sa[i])<<endl;
	}
	#endif
	for(int i=0,j=0;i<sa.size();i++)
	{
		int i_string=which_suffix(strings,sa[i]);
		if(i>j)
		{
			if(i_string!=-1)
			{
				string_count[i_string]++;
				if(string_count[i_string]==1)
				total_string_present++;
			}
		}
		#ifdef DEBUG
			cout<<"I at "<<i<<endl;
		#endif			
		while((j)<sa.size()&&total_string_present<strings.size())
		{
			j++;
			if(j>=sa.size())
				break;
			#ifdef DEBUG
				cout<<"J at "<<j<<endl;
			#endif
			if(j>i)
			{
			int j_string=which_suffix(strings,sa[j]);
			if(j_string!=-1)
			{
				string_count[j_string]++;
				if(string_count[j_string]==1)
					total_string_present++;
			}}	
		}
		#ifdef DEBUG
		cout<<"Finally J at "<<j<<endl;
		cout<<"Total strings "<<total_string_present<<endl;
		cin.get();
		#endif
		if(i==sa.size())	break;
		if(j==sa.size()) break;
		if(total_string_present==strings.size())
		{
			int lcp=sa.lcp(sa[i],sa[j]);
			if(lcp>maximum)
			{
				maximum=lcp;
			}
			if(lcp==maximum&&sa[i]<pos)
			{
				pos=sa[i];
			}
			if(lcp==maximum&&sa[j]<pos)
			{
				pos=sa[j];
			}
			
		}
		
		string_count[i_string]--;
		if(string_count[i_string]==0)
		{
			#ifdef DEBUG
				cout<<"String "<<i_string<<" vanished"<<endl;
			#endif
			total_string_present--;
		}
	}
	if(maximum)
	{
		cout<<bigstring.substr(pos,maximum)<<endl;	
		cout<<maximum<<endl;
	}
	else
		cout<<0<<endl;
	return 0;
}
