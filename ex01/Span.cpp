#include "Span.hpp"

Span::Span() : _N(0)
{
    return ;
}

Span::Span(unsigned int const N) : _N(N)
{
    return ;
}

Span::Span(Span const & copy)
{
    *this = copy;
    return ;
}

Span::~Span()
{
    return ;
}

Span & Span::operator=(Span const & src)
{
    if (this != &src)
    {
        _N = src._N;
        _span = src._span;
    }
    return (*this);
}

int Span::getSize()
{
	return (_span.size());
}

void Span::addNumber(int const nb)
{
    if (_span.size() >= _N)
        throw ArrayFullException();
    else
    {
        _span.push_back(nb);
    }
    return ;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int> tmp(begin, end);

	if (_span.size() + tmp.size() > _N)
		throw ArrayFullException();
	copy(tmp.begin(), tmp.end(), std::back_inserter(_span));

}

int Span::shortestSpan()
{
	std::vector<int> tmp = _span;
	std::vector<int>::iterator it;
	int span = -1;

	if (_span.size() <= 1)
		throw NoSpanException();
	sort(tmp.begin(), tmp.end());
	span = *(tmp.begin() + 1) - *tmp.begin();
	if (_span.size() == 2)
		return (span);
	for (it = tmp.begin() + 1; it != tmp.end() - 1 && span != 0; it++)
	{
		if (*(it + 1) - *it < span)
			span = *(it + 1) - *it;
	}

	return (span);
}

int Span::longestSpan()
{
	std::vector<int> tmp = _span;
	std::vector<int>::iterator it;
	int span = -1;

    if (_span.size() <= 1)
		throw NoSpanException();
	sort(tmp.begin(), tmp.end());
	span = *(tmp.end() - 1) - *tmp.begin();
    return (span);

}

void Span::printVector()
{
    std::cout << "Vector content: " << std::endl;
    for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

const char *Span::ArrayFullException::what() const throw()
{
    return "Vector is full, can't add number";
}

const char *Span::NoSpanException::what() const throw()
{
    return "No numbers or no span found";
}




