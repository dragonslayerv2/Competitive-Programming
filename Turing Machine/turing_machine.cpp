#include"turing_machine.h"


template<class I,class T,class input_iterator_type>input_iterator_type turingMachine<I,T>::parse(const input_iterator_type &iterator) throw(typename turingMachine<I,T>::MACHINE_NOT_ACTIVE)
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

