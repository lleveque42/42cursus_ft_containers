/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/13 22:54:01 by lleveque         ###   ########.fr       */
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


#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
// # define NAMESPACE ft
# define NAMESPACE std

using namespace std;

int main()
{
	NAMESPACE::vector<string> JOHN;
	NAMESPACE::vector<string> BOB(5, "Hello");
	cout << "BOB(5, 8) : ";
	for (size_t i = 0; i < BOB.size(); i++)
		cout << BOB[i] << ' ';
	cout << '\n';
	NAMESPACE::vector<string> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;


	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;

	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, "juste some random string");
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	// RESERVE
	cout << "\nRESERVE\n";

	size_t	john_reserve = 5;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 83;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//AT
	cout << "\nAT\n";
	try
	{
		cout << MIKE.at(2) << '\n';
		cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		cout << "OOR error caught\n";
	}

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front() << '\n';
	cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	BOB.assign(42, "James BOND");

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	NAMESPACE::vector<string>	assign_range;
	assign_range.assign(8, "Covfefe");
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';
	cout << "BOB at(41) : " << BOB.at(41) << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	BOB.push_back("My name is Bond");
	cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back() << '\n';

	//INSERT
	cout << "\nINSERT\n";
	NAMESPACE::vector<string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back(std::to_string(i) + " I love hbaudet\n");
	cout << "after push_back, before at\n";
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	NAMESPACE::vector<string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, "Norminet");
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	NAMESPACE::vector<string>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it : " << std::endl;
	cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


	//INSERT
	cout << "\nINSERT\n";
	NAMESPACE::vector<string>	std_insert_in_me;
	for (size_t i = 0; i < 15; i++)
		std_insert_in_me.push_back(std::to_string(i) + " 42 ");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i) << ' ';
	cout << '\n';

	NAMESPACE::vector<string>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i) << ' ';
	cout << '\n';


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	NAMESPACE::vector<string>	insert_bis;
	for (size_t i = 0; i < 7; i++)
		insert_bis.push_back(std::to_string(3 * i));
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i] << ' ';
	cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i] << ' ';
	cout << '\n';


	//ERASE
	cout << "\nERASE\n";
	NAMESPACE::vector<string>	erase_in_me;
	for (size_t i = 0; i < 15; i++)
		erase_in_me.push_back(std::to_string(2 * i));
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
//		if (erase_in_me[i] < 10)
//			cout << ' ';
		cout << erase_in_me.at(i) << ' ';
	}
	cout << '\n';

	//SWAP
	cout << "\nSWAP\n";
	BOB.swap(MIKE);
	/*
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	MIKE.swap(JOHN);
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	/*
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	NAMESPACE::vector<string> MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	NAMESPACE::vector<string> real;
	real.assign(5, "foo");
	for (NAMESPACE::vector<string>::iterator it = real.begin(); it != real.end(); it++)
		cout << *it << " ";
	cout << '\n';

	cout << std::endl;
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



