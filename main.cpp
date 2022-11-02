/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/11/02 16:36:01 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/containers/vector.hpp"
# include "include/containers/stack.hpp"
# include "include/containers/map.hpp"
# include <iostream>
# include <vector>
# include <stack>
# include <map>

# define STD
# ifndef STD
# define NAMESPACE std
# else
# define NAMESPACE ft
# endif

int main() {
	NAMESPACE::map<int, int> my;
	std::map<int, int> test;
	std::cout << "insert 50" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(50, 21)).second << std::endl;
	std::cout << "insert 40" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(40, 21)).second << std::endl;
	std::cout << "insert 60" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(60, 21)).second << std::endl;
	std::cout << "insert 70" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(70, 21)).second << std::endl;
	std::cout << "insert 100" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(100, 21)).second << std::endl;
	std::cout << "insert 80" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(80, 21)).second << std::endl;
	std::cout << "insert 75" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(75, 21)).second << std::endl;
	std::cout << "insert 85" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(85, 21)).second << std::endl;
	// std::cout << "insert 78" << std::endl;
	// std::cout << my.insert(NAMESPACE::make_pair<int, int>(78, 21)).second << std::endl;
	// std::cout << "insert 79" << std::endl;
	// std::cout << my.insert(NAMESPACE::make_pair<int, int>(79, 21)).second << std::endl;
	// std::cout << "insert 110" << std::endl;
	// std::cout << my.insert(NAMESPACE::make_pair<int, int>(110, 21)).second << std::endl;
	std::cout << "insert 30" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(30, 21)).second << std::endl;
	std::cout << "insert 35" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(35, 21)).second << std::endl;
	std::cout << "insert 31" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(31, 21)).second << std::endl;
	std::cout << "insert 33" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(33, 21)).second << std::endl;
	// NAMESPACE::map<int, int>::iterator it = my.begin();
	// NAMESPACE::map<int, int>::iterator ite = my.end();
	// for (; it != ite; it++)
		// std::cout << "first: " <<  << " | second: " << *it << std::endl;
	// srand(time(NULL));
	// for (int i = 0; i < 100; i++)
	// 	std::cout << rand() % 1000 << std::endl;
	// 	my.insert(NAMESPACE::make_pair<int, int>(rand() % 10000, i));
	// my.insert(NAMESPACE::make_pair<int, int>(339, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(938, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(404, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(950, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(186, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(17, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(385, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(220, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(970, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(537, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(914, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(162, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(831, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(353, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(808, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(122, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(147, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(839, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(732, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(966, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(588, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(382, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(771, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(499, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(193, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(49, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(648, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(376, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(185, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(183, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(195, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(467, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(902, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(338, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(79, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(913, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(282, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(346, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(858, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(487, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(819, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(436, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(674, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(111, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(65, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(101, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(597, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(522, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(716, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(900, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(263, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(525, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(146, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(507, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(32, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(241, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(734, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(579, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(719, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(764, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(824, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(625, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(866, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(332, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(414, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(851, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(51, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(747, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(721, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(845, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(979, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(484, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(828, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(435, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(674, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(596, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(520, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(642, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(687, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(775, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(73, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(243, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(308, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(947, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(507, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(846, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(495, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(159, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(714, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(93, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(759, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(208, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(494, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(598, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(848, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(986, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(615, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(94, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(385, 21));
	// my.insert(NAMESPACE::make_pair<int, int>(133, 21));
	my.printMap();
	// std::cout << "erase 35" << std::endl;
	// my.erase(35);
	// my.swapNodes(35, 31);
	my.erase(35);
	my.printMap();
	std::cout << "NEW ERASE\n";
	my.erase(31);
	my.printMap();
	// my.at(85);
}

