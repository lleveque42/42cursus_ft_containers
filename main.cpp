/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/29 15:54:32 by lleveque         ###   ########.fr       */
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
	std::cout << "insert 78" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(78, 21)).second << std::endl;
	std::cout << "insert 79" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(79, 21)).second << std::endl;
	std::cout << "insert 110" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(110, 21)).second << std::endl;
	std::cout << "insert 30" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(30, 21)).second << std::endl;
	std::cout << "insert 35" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(35, 21)).second << std::endl;
	std::cout << "insert 31" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(31, 21)).second << std::endl;
	std::cout << "insert 33" << std::endl;
	std::cout << my.insert(NAMESPACE::make_pair<int, int>(33, 21)).second << std::endl;
	my.printMap();
}

