#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int main(void)
{
    Span span(5);
	Span span2(1);

    span.addNumber(12);
    span.addNumber(-3);
    span.addNumber(78124);
	span.addNumber(342);
	span.addNumber(-728);

    try
    {
        span.addNumber(-4214);
    }
    catch (Span::ArrayFullException & e)
    {
        std::cerr  << e.what() << std::endl;
    }
    span.printVector();

	std::cout << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	try
	{
		std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
	}
	catch(Span::NoSpanException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest span: " << span2.longestSpan() << std::endl;

	}
	catch(Span::NoSpanException & e)
	{
		std::cerr << e.what() << std::endl;;
	}

	{
		int N = 100001;
		srand(time(NULL));

		std::cout << std::endl;
		std::cout << "Span tests with over 10000 numbers: " << std::endl;
		Span huge(N);

		try
		{
			for (int i = 0; i < N; i++)
			{
				huge.addNumber(rand());
			}
		}
		catch(Span::ArrayFullException & e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "Size of huge is " << huge.getSize() << std::endl;
		try
		{
			std::cout << "Shortest span of huge: " << huge.shortestSpan() << std::endl;
			std::cout << "Longest span of huge: " << huge.longestSpan() << std::endl;
		}
		catch(Span::NoSpanException & e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		std::cout << "Add by range tests: " << std::endl;
		Span range(9);

		std::vector<int> toAdd (5, 42);

		try
		{
			std::cout << "First try: ";
			range.addRange(toAdd.begin(), toAdd.end());
			std::cout << "Success!" << std::endl;
			std::cout << "Second try: ";
			range.addRange(toAdd.begin(), toAdd.end());
			std::cout << "Success!" << std::endl;
		}
		catch(Span::ArrayFullException & e)
		{
			std::cerr << e.what() << std::endl;
		}

		range.printVector();

	}
    return (0);
}
