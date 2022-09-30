# include "vector.hpp"
# include <iostream>
# include <vector>

int main(void) {

	ft::vector<int> my(10, 2);
	std::vector<int> og(10, 2);

	my.print();
	for (size_t i = 0; i < og.size(); i++)
		std::cout << "og[" << i << "]" << og[i] << std::endl;
	try
	{
		my.assign(10, 21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	my.print();
	std::cout << my.size() << std::endl;
	try
	{
		og.assign(10, 21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (size_t i = 0; i < og.size(); i++)
		std::cout << "og[" << i << "]" << og[i] << std::endl;
	std::cout << og.size() << std::endl;
	return (0);
}
