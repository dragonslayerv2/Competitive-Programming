#include<iostream>
#include<vector>
#include<map>
using namespace std;

template<class I,class T> class turingMachine
{
	public:
		typedef I input_type;
		typedef T transition_function_type;
		class MACHINE_NOT_ACTIVE{};
		
	private:
		size_t _current_state;
		size_t _initial_state;
		size_t _halt_state;
	 	transition_function_type _transition_function;
	 	input_type _hash;
	 	bool _is_active;
	 	
	 	
	 	template<class input_iterator_type> pair<bool,input_iterator_type> read_character(const input_iterator_type &i) throw (MACHINE_NOT_ACTIVE)
		{
			if(is_active())
			{	
				input_iterator_type input_iterator=i;
				input_type input_character=*i; 
				
				*input_iterator=_transition_function[current_state()][input_character-_hash].second.second;
				
				if(_transition_function[current_state()][input_character-_hash].second.first=='L')
					input_iterator--;
				else if(_transition_function[current_state()][input_character-_hash].second.first=='R')
					input_iterator++;
				
				_current_state=_transition_function[current_state()][input_character-_hash].first;
				
				if(current_state()==_halt_state)
					return make_pair(true,input_iterator);
				else
					return make_pair(false,input_iterator);
			}
			else
				throw MACHINE_NOT_ACTIVE();
		}
		
	public:
		
		turingMachine()
		{
			_is_active=false;
		}
		
		turingMachine(const size_t INITIAL_STATE,const transition_function_type &TRANSITION_FUNCTION, const size_t HALT_STATE,const input_type HASH=input_type())
		{
			initialise(INITIAL_STATE,TRANSITION_FUNCTION,HALT_STATE, HASH);
		}
		
		void initialise(const size_t INITIAL_STATE,const transition_function_type &TRANSITION_FUNCTION, const size_t HALT_STATE, const input_type HASH=input_type())
		{
			
			_is_active=true;
			_initial_state=INITIAL_STATE;
			_transition_function=TRANSITION_FUNCTION;
			_hash=HASH;
			_halt_state=HALT_STATE;
			reset();
		}
		
		bool is_active() const
		{
			return _is_active;
		}
		
		void reset()
		{
			_current_state=_initial_state;
		}
		
		size_t current_state() throw (MACHINE_NOT_ACTIVE)
		{
			if(is_active())
				return _current_state;
			else
				throw MACHINE_NOT_ACTIVE();
		}
		
		template<class input_iterator_type> input_iterator_type parse(const input_iterator_type &iterator) throw (MACHINE_NOT_ACTIVE)
		{
			if(is_active())
			{
				pair<bool,input_iterator_type> current=read_character(iterator);
				while(!current.first)
						current=read_character(current.second);
				return current.second;
			}
			else
				throw MACHINE_NOT_ACTIVE();
		}
};


int main()
{
	typedef vector<map<char,pair<size_t,pair<char,char> > > > transition_function_type;
	//--------------------------------------------------------------------------
	transition_function_type transition_function(4);
	
	transition_function[0]['a']=make_pair(0,make_pair('R','A'));
	transition_function[0]['b']=make_pair(1,make_pair('R','b'));
	
	transition_function[0]['a']=make_pair(1,make_pair('R','A'));
	transition_function[0]['b']=make_pair(1,make_pair('R','b'));
	transition_function[1]['a']=make_pair(2,make_pair('R','a'));
	transition_function[1]['b']=make_pair(2,make_pair('R','B'));
	transition_function[2]['a']=make_pair(3,make_pair('L','X'));
	transition_function[2]['b']=make_pair(3,make_pair('L','X'));
	transition_function[3]['A']=make_pair(1,make_pair('S','X'));
	transition_function[3]['B']=make_pair(1,make_pair('S','X'));
	transition_function[3]['a']=make_pair(1,make_pair('S','X'));
	transition_function[3]['b']=make_pair(1,make_pair('S','X'));
//	turingMachine<char,transition_function_type> turing;
	//--------------------------------------------------------------------------
	turingMachine<char,transition_function_type> machine;
	machine.initialise(0,transition_function,1);
	//--------------------------------------------------------------------------
	string a="aaabbbaaaa";
	machine.parse(a.begin());
	cout<<a;
}
