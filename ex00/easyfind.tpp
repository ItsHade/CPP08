#pragma once

#include "easyfind.hpp"

const char * NotFoundException::what() const throw() {
	return ("Number not found in container");
}

template <template <typename, typename> class Container>
typename Container<int, std::allocator<int> >::iterator easyfind(Container <int, std::allocator<int> > & container, const int nb)
{
	typename Container<int, std::allocator<int> >::iterator it = std::find(container.begin(), container.end(), nb);
    if (it == container.end())
		throw NotFoundException();
	return (it);
}
