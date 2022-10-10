/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/10 12:36:15 by lleveque         ###   ########.fr       */
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

// #include "test_utils.hpp"
// #include "VECTOR_UC.HPP"
// #include <vector>

// #ifndef STD
# define NAMESPACE ft
// #else
// # define NAMESPACE std
// #endif

using namespace NAMESPACE;

int main ()
{
  vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}


