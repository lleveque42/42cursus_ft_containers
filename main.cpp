/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/07 11:06:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/containers/vector.hpp"
# include <iostream>
# include <vector>

int main(void) {

	// ft::vector<int> vide;
	ft::vector<int> my(10, 2);
	std::vector<int> og(10, 2);

	my.push_back(21);
	my.push_back(23);
	og.push_back(21);
	my.print();
	ft::vector<int>::iterator it = my.begin();
	ft::vector<int>::iterator ite = my.end();
	// std::vector<int>::iterator ogit = og.begin();
	// for (; ogit != og.end(); ogit++)
		// std::cout << my[10] << std::endl;
	std::cout << my.size() << std::endl;
	std::cout << og.size() << std::endl;
	// std::cout << *my.end() << std::endl;
	// std::cout << *og.end() << std::endl;
	ft::vector<int> my2(it, ite);
	ft::vector<int> my3(my2);
	ft::vector<int> vide = my3;
	my3.print();
	ft::vector<int>::iterator itvide = vide.begin();
	std::vector<int>::iterator itog1 = og.begin();
	itog1++;
	itog1++;
	itog1++;
	itog1++;
	std::cout << vide.size() << std::endl;
	vide.print();
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	itvide++;
	vide.insert(itvide, 332);
	std::cout << vide.size() << std::endl;
	vide.print();
	itvide--;
	itvide--;
	std::ptrdiff_t hello2 =  itvide - vide.begin();
	std::ptrdiff_t hello = og.begin() - itog1;
	std::cout << hello2 << std::endl;
	std::cout << hello << std::endl;
	return (0);
}
