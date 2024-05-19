#pragma once

#include <iostream>
#include <stack>
#include <algorithm>

//Last in first out

template <typename T>
class MutantStack : public std::stack<T>
{
public :
	MutantStack<T>(void) {return;}
	~MutantStack<T>(void) {return;}
	MutantStack<T>(MutantStack<T> const & copy) {*this = copy;}

	MutantStack<T> & operator =(MutantStack<T> const & src) {
		(void) src;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}
};
