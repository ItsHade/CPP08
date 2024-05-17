#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(42);
	lst.push_back(214);
	lst.push_back(-22);

	try
	{
		std::cout << "Found: " << *::easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}