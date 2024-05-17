#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

class Span
{

public :

    Span();
    Span(unsigned int const N);
    Span(Span const & copy);
    ~Span();

    Span & operator =(Span const & src);

	int getSize();

    void addNumber(int const nb);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    void printVector();

    class ArrayFullException : public std::exception {
        public :
            const char *what() const throw();
    };

    class NoSpanException : public std::exception {
        public :
            const char *what() const throw();
    };


private :

    unsigned int _N;
    std::vector<int>   _span;

};
