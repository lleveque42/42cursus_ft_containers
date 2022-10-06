/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/06 19:33:53 by lleveque         ###   ########.fr       */
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
	ft::vector<int>::iterator ittest = vide.begin() + itvide;
	std::cout << *ittest << std::endl;
	return (0);
}
