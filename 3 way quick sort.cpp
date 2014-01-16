/*
	Name: 3 Way Quick Sort Algorithm
	Copyright: 
	Author: Shobhit Saxena
	Date: 11/12/13 14:29
	Description: This is the 3 way quick sort implementation that sort strings in O(nlogn ) character comparisons.
				Can be used to sorr numbers but  a lot slower than original Quicksort.
				O(n^2) time in worst case. But O(n logn) average case.
				Adaptive to single occurence to pivot.
				Refer to Princeton lectures for explanation
*/

class referenced_string
{
	const char *_string;
	size_t length;
	
	public:
		referenced_string()
		{
			_string=NULL;
			length=0;
		}
		referenced_string(const char *STRING,size_t L)
		{
			assign(STRING,L);
		}
		void assign(const char *STRING,size_t L)
		{
			_string=STRING;
			length=L;
		}
		char operator [](size_t pos)
		{
			if(pos<length)
				return _string[pos];
			else
				return NULL;
		}
		void print()
		{
			for(int i=0;operator[](i);i++)
				cout<<operator[](i);
			cout<<endl;
		}
};

void sort(const vector<referenced_string>::iterator &_begin,const vector<referenced_string>::iterator &_end,size_t digit=0)
{
	if(_begin+1<_end)
	{
		#ifdef QSORT_DEBUG
		cout<<"Before"<<endl;
		for(vector<referenced_string>::iterator i=_begin;i!=_end;i++)
			cout<<i->operator[](digit);
		cout<<endl;
		#endif
		vector<referenced_string>::iterator begin=_begin;
		vector<referenced_string>::iterator end=_end;

		vector<referenced_string>::iterator eq_begin=end-1;
		vector<referenced_string>::iterator greater_begin=begin;
		
		vector<referenced_string>::iterator pivot=begin+(rand()%(end-begin));
		swap(*pivot,*(end-1));
		pivot=end-1;
		
		#ifdef QSORT_DEBUG
		cout<<"Pivoting around "<<pivot->operator[](digit)<<endl;
		#endif
		
		bool al_null=true;
	
		if((*(end-1))[digit])
			al_null=false;
		while(begin<eq_begin)
		{
			if((*begin)[digit])
				al_null=false;			
			if((*begin)[digit]<(*pivot)[digit])
			{
				swap(*begin,*greater_begin);
				greater_begin++;
				begin++;
			}
		
			else	 if((*begin)[digit]==(*pivot)[digit])
				swap(*begin,*(--eq_begin));
			
			else
				begin++;
		}	
		vector<referenced_string>::iterator equal_begin_final=greater_begin;
		while(eq_begin!=end)
		{
			swap(*eq_begin,*greater_begin);
			eq_begin++;
			greater_begin++;
		}
		#ifdef QSORT_DEBUG	
		cout<<"After"<<endl;
		for(vector<referenced_string>::iterator i=_begin;i!=_end;i++)
			cout<<i->operator[](digit);
		cout<<endl;
		#endif
		//cin.get();
		sort(_begin,equal_begin_final,digit);
		if(!al_null)
			sort(equal_begin_final,greater_begin,digit+1);
		sort(greater_begin,_end,digit);
		
		#ifdef QSORT_DEBUG
		for(vector<referenced_string>::iterator i=_begin;i!=_end;i++)
			cout<<i->operator[](digit);
		cout<<endl;
		#endif
	}
}
