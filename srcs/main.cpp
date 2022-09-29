# include "vector.hpp"
# include <iostream>
# include <vector>

int main(void) {

	ft::vector<int> my(100, 2);
	std::vector<int> og(100, 2);

	try {
		my.reserve(21474836470);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		og.reserve(21474836470);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
