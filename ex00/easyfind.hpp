#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <exception>

class NotFoundException : public std::exception {
	public :
		const char * what() const throw();
};

template <template <typename, typename> class Container>
typename Container<int, std::allocator<int> >::iterator easyfind(Container <int, std::allocator<int> > & container, const int nb);

#include "easyfind.tpp"
