/*

	Name: Finite State Machine
	Copyright: 
	Author: Shobhit
	Date: 23/10/13 21:36
	Description: I added few more thing. active machine means which is liked with a transition function and initialised. 
				 _active stores whether a machine is properly initialised. If not all functions throw an exception MACHINE_NOT_ACTIVE				
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;


template<class value_type,class transition_function_type> class FSM
{
	private:
		size_t _current_state;  // current state
		size_t _initial_state;	//initial state
		size_t _final_state;	//final state
		transition_function_type _trans_func; // transtion function
		bool _active; 							// checks whether the machine is active or not
		
		value_type _hash;			// stores the hash value to be subtraced each time. It must be a function pointer but tere liye itna kafi hai...:P
	
		void change_state(value_type INPUT)  // function to change the state for each input. parse uses this by passing each character one by one.
		{
			_current_state=_trans_func[_current_state][INPUT-_hash];
		}
	
	public:
		
		class MACHINE_NOT_ACTIVE{}; // exception class. All functions throw this exception when machine is not active.
		
		
		FSM() // default constructor. Creates an inactive machine. This can help u to create array of machines and dynamic machines as well..
		{
			_active=false;
		}
		
		FSM(const transition_function_type &TRANS_FUNC,const size_t INITIAL_STATE,const size_t FINAL_STATE,value_type HASH=0) // paramaterised constructor
		{
			initialise(TRANS_FUNC,INITIAL_STATE,FINAL_STATE,HASH);
		}
		
		void reset() // reset the machine for fresh input
		{
			_current_state=_initial_state;
		}	
		
		void initialise(const transition_function_type &TRANS_FUNC,const size_t INITIAL_STATE,const size_t FINAL_STATE,value_type HASH=0) // initialises the machine. Constructor also uses this function
		{
			_active=true; // to make the machine active
			_trans_func=TRANS_FUNC;
			_initial_state=INITIAL_STATE;
			_final_state=FINAL_STATE;
			_hash=HASH;
			reset();
		}
		
		bool is_active() const // returns whether the machine is properly initialised or not
		{
			return _active;
		}
		
		size_t current_state() const // return the current state. Can be helpful in some cases as the one we did today. We can use this function to return the %3 value of the string read so far.
		{
			if(!is_active())
				throw MACHINE_NOT_ACTIVE();
			return _current_state;
		}
		
		bool is_accepted() const // returns wheter the string is accepted or not
		{
			if(!is_active())
				throw MACHINE_NOT_ACTIVE();
			return current_state()==_final_state;
		}
		
		template<class STRING> void parse(const STRING &S) // parse a group of characters. Group can be supplied in form of any container which provides iterators to access them.
		{
			if(!is_active())
				throw MACHINE_NOT_ACTIVE();
			for(typename STRING::const_iterator i=S.begin();i!=S.end();i++)
				change_state(*i);
		}			
		
		template<class ITERATOR> void parse(ITERATOR begin,ITERATOR end)
		{
			if(!is_active())
				throw MACHINE_NOT_ACTIVE();
			while(begin!=end)
				change_state(*i);
		}
		
		void read_char(value_type character)
		{
			if(!is_active())
				throw MACHINE_NOT_ACTIVE();
			change_state(character);
		}
};



int main()
{
	typedef vector<map<char, size_t> > transition_function; // type of the transition function. 
	
	
	//----------------TRanstition function for odd number of 1----------------
	
	transition_function trans(2); // 2 states
	trans[0]['0']=0;
	trans[0]['1']=1;
	trans[1]['0']=1;
	trans[1]['1']=0;
	//------------------------------------------------------------------------
	
	FSM<char,transition_function> machine;
	//machine.initialise(trans,0,0);	// machine with initial and final state 0 with transition function trans
	//------------------------------------------------------------------------
	
	string A="010101010101";
	string B="0101010101011";
	
	machine.parse(A);
	cout<<machine.is_accepted();
	
	
	machine.reset(); // to reset the machine for fresh use.
	machine.parse(B);
	cout<<machine.is_accepted();
}
