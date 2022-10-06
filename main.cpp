/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/05 19:21:20 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/containers/vector.hpp"
# include <iostream>
# include <vector>

int main(void) {

	ft::vector<int> my(10, 2);
	std::vector<int> og(10, 2);

	my.push_back(21);

	og.push_back(21);
	my.print();
	ft::vector<int>::iterator it = my.begin();
	ft::vector<int>::iterator ite = my.end();
	std::vector<int>::iterator ogit = og.begin();
	for (; ogit != og.end(); ogit++)
		std::cout << *ogit << std::endl;
	std::cout << my.size() << std::endl;
	std::cout << og.size() << std::endl;
	std::cout << *my.end() << std::endl;
	std::cout << *og.end() << std::endl;
	ft::vector<int> my2(it, ite);
	// my2.print();
	return (0);
}
