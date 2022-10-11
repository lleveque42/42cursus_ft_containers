/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/11 17:35:20 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/containers/vector.hpp"
# include <iostream>
# include <vector>

// int main(void) {

// 	ft::vector<int> myvide;
// 	std::vector<int> ogvide;
// 	ft::vector<int> my(1, 1);
// 	std::vector<int> og(1, 1);
// 	ft::vector<int> my2(3, 10);
// 	std::vector<int> og2(3, 10);

// 	my.push_back(2);
// 	my.push_back(3);
// 	my.push_back(4);
// 	my.push_back(5);
// 	my.push_back(6);
// 	my.push_back(7);
// 	my.push_back(8);
// 	my.push_back(9);
// 	og.push_back(2);
// 	og.push_back(3);
// 	og.push_back(4);
// 	og.push_back(5);
// 	og.push_back(6);
// 	og.push_back(7);
// 	og.push_back(8);
// 	og.push_back(9);
// 	std::cout << " BEFORE INSERT " << std::endl;
// 	ft::vector<int>::iterator itm = my.begin();
// 	std::vector<int>::iterator ito = og.begin();
// 	while (itm < my.end()) {
// 		std::cout << *itm << " || " << *ito << std::endl;
// 		itm++;
// 		ito++;
// 	}
// 	itm = my.insert(my.begin() + 5, 21);
// 	ito = og.insert(og.begin() + 5, 21);
// 	my.insert(itm + 1, my2.begin(), my2.end());
// 	og.insert(ito + 1, og2.begin(), og2.end());
// 	itm = my.begin();
// 	ito = og.begin();
// 	std::cout << " AFTER INSERT " << std::endl;
// 	while (itm < my.end()) {
// 		std::cout << *itm << " || " << *ito << std::endl;
// 		itm++;
// 		ito++;
// 	}
// 	itm = my.begin();
// 	ito = og.begin();
// 	itm++;
// 	itm++;
// 	itm++;
// 	itm++;
// 	itm++;
// 	ito++;
// 	ito++;
// 	ito++;
// 	ito++;
// 	ito++;
// 	std::cout << *my.erase(itm) << std::endl;
// 	std::cout << *og.erase(ito) << std::endl;
// 	itm = my.begin();
// 	ito = og.begin();
// 	std::cout << " AFTER ERASE " << std::endl;
// 	while (itm < my.end()) {
// 		std::cout << *itm << " || " << *ito << std::endl;
// 		itm++;
// 		ito++;
// 	}
// 	ft::vector<int>::iterator it1 = my.begin();
// 	ft::vector<int>::iterator it2 = my.end();
// 	it1++;
// 	it1++;
// 	it1++;
// 	it2--;
// 	it2--;
// 	it2--;
// 	std::vector<int>::iterator it3 = og.begin();
// 	std::vector<int>::iterator it4 = og.end();
// 	it3++;
// 	it3++;
// 	it3++;
// 	it4--;
// 	it4--;
// 	it4--;
// 	std::cout << *my.erase(it1, it2) << std::endl;
// 	std::cout << *og.erase(it3, it4) << std::endl;
// 	itm = my.begin();
// 	ito = og.begin();
// 	std::cout << " AFTER ERASE " << std::endl;
// 	while (itm < my.end()) {
// 		std::cout << *itm << " || " << *ito << std::endl;
// 		itm++;
// 		ito++;
// 	}
// 	return (0);
// }

// #define TESTED_TYPE std::string

// int		main(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(8);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		it[i] = std::string((vct.size() - i), i + 65);
// 	// print_vec(vct, true);

// 	std::cout << "push_back():\n" << std::endl;

// 	vct.push_back("One long string");
// 	vct2.push_back("Another long string");

// 	// print_vec(vct);
// 	// print_vec(vct2);

// 	vct.pop_back();
// 	vct2.pop_back();

// 	// print_vec(vct);
// 	// print_vec(vct2);

// 	return (0);
// }


#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
// #define TESTED_TYPE std::string

// #define TESTED_TYPE int

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(); // <-- error expected

	for (int i = 0; i < size; ++i) {
		std::cout << "1: " << it[i] << ", " << vct[i] << std::endl;
		it[i] = i;
		std::cout << "2: " << it[i] << ", " << vct[i] << std::endl;
	}

	return (0);
}


void print_vec(TESTED_NAMESPACE::vector<TESTED_TYPE> vec)
{
	if (vec.empty())
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Vec's empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vec.begin();
		TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator ite = vec.end();
		std::cout << "-----------------" << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
		std::cout << "Capacity : " << vec.capacity() << std::endl;
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl << "-----------------" << std::endl;
	}
}



