#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

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
	 	 	
	 	template<class input_iterator_type> pair<bool,input_iterator_type> read_character(const input_iterator_type &i) throw (MACHINE_NOT_ACTIVE);
		
	public:
		
		turingMachine();
		turingMachine(const size_t INITIAL_STATE,const transition_function_type &TRANSITION_FUNCTION, const size_t HALT_STATE,const input_type HASH=input_type());
		void initialise(const size_t INITIAL_STATE,const transition_function_type &TRANSITION_FUNCTION, const size_t HALT_STATE, const input_type HASH=input_type());
		bool is_active() const;		
		void reset();	
		size_t current_state() throw (MACHINE_NOT_ACTIVE);	
		template<class input_iterator_type> input_iterator_type parse(const input_iterator_type &iterator) throw (MACHINE_NOT_ACTIVE);
};
#endif
