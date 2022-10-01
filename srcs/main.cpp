# include "vector.hpp"
# include <iostream>
# include <vector>

int main(void) {

	ft::vector<int> my(10, 2);
	std::vector<int> og(13, 2);

	my.print();
	for (size_t i = 0; i < og.size(); i++)
		std::cout << "og[" << i << "]" << og[i] << std::endl;
	try
	{
		std::cout << my.at(32) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << og.at(32) << std::endl;
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
