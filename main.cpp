/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:09 by lleveque          #+#    #+#             */
/*   Updated: 2022/11/11 20:43:34 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT /* comment to compile with std */
#ifndef FT
# include <vector>
# include <stack>
# include <map>
# include <iterator>
# include <memory>
# define NS std
#else
# include "include/containers/vector.hpp"
# include "include/containers/stack.hpp"
# include "include/containers/map.hpp"
# define NS ft
#endif

#define __NO_CONST /* comment to try to compile with const_iterator writing */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <deque>
#include <list>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define UL "\033[4m"
#define TAB "\t"
#define SPACE "  "
#define ORANGE "\033[93m"
#define RED "\033[91m"
#define BLUE "\033[96m"
#define GREEN "\033[92m"
#define PINK "\033[95m"
#define STAR "\033[92m * \033[0m"

#define T1 int
#define T2 int
#define T3 std::string

void vector_tests();
void stack_tests();
void map_tests();
void printVec(NS::vector<T1> &vec, bool displayContainer);
void printVec(NS::vector<T3> &vec, bool displayContainer);
void printMap(NS::map<T3, T1> &map, bool displayContainer);
void printMap(NS::map<T1, T2> &map, bool displayContainer);
void printMap(NS::map<T1, T3> &map, bool displayContainer);

#define VECTOR /* comment to remove vector tests */
#define STACK /* comment to remove stack tests */
#define MAP /* comment to remove map tests */

int	main(void) {
#ifdef VECTOR
	vector_tests();
#endif
#ifdef STACK
	stack_tests();
#endif
#ifdef MAP
	map_tests();
#endif
	return 0;
}

#ifdef VECTOR
void vector_tests() {
	std::cout << BOLD << PINK << "==========================================" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==             VECTOR TESTS             ==" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==========================================" << RESET << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- CONSTRUCTORS TESTS ------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << BOLD << ORANGE << UL << "--> default:" << RESET << " vector();" << std::endl;
		{
			NS::vector<T1> vec;
			printVec(vec, 1);
		}
		std::cout << SPACE << BOLD << ORANGE << UL << "--> size:" << RESET << " vector(5);" << std::endl;
		{
			NS::vector<T1> vec(5);
			printVec(vec, 1);
		}
		std::cout << SPACE << BOLD << ORANGE<< UL << "--> size + value:" << RESET << " vector(6, 42);" << std::endl;
		{
			NS::vector<T1> vec(6, 42);
			printVec(vec, 1);
		}
		std::cout << SPACE << BOLD << ORANGE<< UL << "--> iterator range:" << RESET << " vector(InputIterator first, InputIterator last);" << std::endl;
		{
			std::cout << "\n\t-> creating a list of 10 and filling it with multiples of 3." << std::endl;
			std::list<T1> lst;

			for (int i = 0; i < 10; i++)
				lst.insert(lst.end(), i * 3);
			std::cout << "\t   -> vector<T1> vec1(list.begin(), list.end());" << std::endl;
			NS::vector<T1> vec1(lst.begin(), lst.end());
			printVec(vec1, 1);
			std::cout << SPACE << BOLD << ORANGE<< UL << "--> copy:" << RESET << " vector(const vector &other);" << std::endl;
			std::cout << "\n\t-> creating a vector using last vector with multiples of 3." << std::endl;
			std::cout << "\t   -> vector<T1> vec2(vec1);" << std::endl;
			NS::vector<T1> vec2(vec1);
			printVec(vec2, 1);
		}
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "----------- OPERATOR = TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating an empty vector vec1." << std::endl << std::endl;
		NS::vector<T1> vec1;
		std::list<T1> lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), i * 2);
		std::cout << TAB << "-> creating a vector vec2 with 10 mutliples of 2" << std::endl;
		NS::vector<T1> vec2(lst.begin(), lst.end());
		std::cout << TAB << SPACE << "-> vec1" << std::endl;
		printVec(vec1, 1);
		std::cout << TAB << SPACE << "-> vec2" << std::endl;
		printVec(vec2, 1);
		std::cout << TAB << "-> vec1 = vec2;" << std::endl;
		std::cout << TAB << SPACE << "-> vec2.begin() + 5 = 42;" << std::endl;
		vec1 = vec2;
		*(vec2.begin() + 5) = 42;
		std::cout << TAB << SPACE << "-> vec1" << std::endl;
		printVec(vec1, 1);
		std::cout << TAB << SPACE << "-> vec2" << std::endl;
		printVec(vec2, 1);
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------ ITERATORS TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a vector of 10 with multiples of 3." << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> begin():" << RESET << " vector<T1>::iterator it = vec1.begin(); && it++;" << std::endl;
		std::list<T1> lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), i * 3);
		NS::vector<T1> vec1(lst.begin(), lst.end());
		NS::vector<T1>::iterator it = vec1.begin();
		NS::vector<T1>::iterator ite = vec1.end();
		std::cout << std::endl;
		for (int i = 0; it != ite; it++) {
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *it << std::endl;
			i++;
		}
		it = vec1.begin();
		std::cout << std::endl;
		std::cout << TAB << "-> changing it value for 42 : \n" << TAB << TAB << "it = vec1.begin();" << ORANGE << " -> " << RESET << "*it = " << *it << std::endl;
		*it = 42;
		std::cout << TAB << TAB << "*it = 42;" << ORANGE << " -> " << RESET << "*it = " << *it << std::endl;
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> end():" << RESET << " vector<T1>::iterator ite = vec1.end(); && ite--;" << std::endl;
		std::cout << std::endl;
		it = vec1.begin();
		ite--;
		for (int i = vec1.size(); ite != it; ite--) {
			i--;
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *ite << std::endl;
		}
		std::cout << TAB << STAR << "vector[0]" << ORANGE << " = " << RESET << *ite << std::endl;
		NS::vector<T1>::reverse_iterator rit = vec1.rbegin();
		NS::vector<T1>::reverse_iterator rite = vec1.rend();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rbegin():" << RESET << " vector<T1>::reverse_iterator rit = vec1.rbegin(); && ++rit;" << std::endl;
		std::cout << std::endl;
		for (int i = vec1.size(); rit != rite; ++rit) {
			i--;
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *rit << std::endl;
		}
		rit = vec1.rbegin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rend():" << RESET << " vector<T1>::reverse_iterator rite = vec1.rend(); && --rite;" << std::endl;
		std::cout << std::endl;
		--rite;
		for (int i = 0; rite != rit; --rite) {
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *rite << std::endl;
			i++;
		}
		std::cout << TAB << STAR << "vector[" << vec1.size() - 1 << "]" << ORANGE << " = " << RESET << *rite << std::endl;
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------- CONST_ITERATORS TESTS ----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a vector of 10 with multiples of 3." << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> begin():" << RESET << " vector<T1>::const_iterator cit = vec1.begin(); && cit++;" << std::endl;
		std::list<T1> lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), i * 3);
		NS::vector<T1> vec1(lst.begin(), lst.end());
		NS::vector<T1>::const_iterator cit = vec1.begin();
		NS::vector<T1>::const_iterator cite = vec1.end();
		std::cout << std::endl;
		for (int i = 0; cit != cite; cit++) {
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *cit << std::endl;
			i++;
		}
		cit = vec1.begin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> end():" << RESET << " vector<T1>::const_iterator cite = vec1.end(); && cite--;" << std::endl;
		std::cout << std::endl;
		cit = vec1.begin();
		cite--;
		for (int i = vec1.size(); cite != cit; cite--) {
			i--;
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *cite << std::endl;
		}
		std::cout << TAB << STAR << "vector[0]" << ORANGE << " = " << RESET << *cite << std::endl;
		std::cout << std::endl;
		std::cout << TAB << "-> trying to change cit or cite value for 42 won't compile as they are const_iterator ! (comment __NO_CONST and see what happens)" << std::endl;
#ifndef __NO_CONST
		*cit = 42;
		*cite = 42;
#endif
		NS::vector<T1>::const_reverse_iterator crit = vec1.rbegin();
		NS::vector<T1>::const_reverse_iterator crite = vec1.rend();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rbegin():" << RESET << " vector<T1>::const_reverse_iterator crit = vec1.rbegin(); && ++crit;" << std::endl;
		std::cout << std::endl;
		for (int i = vec1.size(); crit != crite; ++crit) {
			i--;
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *crit << std::endl;
		}
		crit = vec1.rbegin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rend():" << RESET << " vector<T1>::const_reverse_iterator crite = vec1.rend(); && --crite;" << std::endl;
		std::cout << std::endl;
		--crite;
		for (int i = 0; crite != crit; --crite) {
			std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *crite << std::endl;
			i++;
		}
		std::cout << TAB << STAR << "vector[" << vec1.size() - 1 << "]" << ORANGE << " = " << RESET << *crite << std::endl;
		std::cout << std::endl;
		std::cout << TAB << "-> trying to change crit or crite value for 42 won't compile as they are const_reverse_iterator ! (comment __NO_CONST and see what happens)" << std::endl;
#ifndef __NO_CONST
		*crit = 42;
		*crite = 42;
#endif
		std::cout << std::endl;
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------- CAPACITY TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << BOLD << ORANGE << UL << "--> size():" << RESET << " vec1.size();" << std::endl << std::endl;
		std::cout << TAB << "-> creating a vector of size 1 : vector<T1> vec1(1);" << std::endl;
		NS::vector<T1> vec1(1);
		std::cout << TAB << TAB << "vec1.size()" << ORANGE << " = " << RESET << vec1.size() << std::endl << std::endl;
		std::cout << TAB << "-> creating a vector of size 1000 : vector<T1> vec2(1000);" << std::endl;
		NS::vector<T1> vec2(1000, 5);
		std::cout << TAB << TAB << "vec2.size()" << ORANGE << " = " << RESET << vec2.size() << std::endl << std::endl;
		std::cout << TAB << "-> creating a vector of size 100000 : vector<T1> vec3(10000);" << std::endl;
		NS::vector<T1> vec3(10000);
		std::cout << TAB << TAB << "vec3.size()" << ORANGE << " = " << RESET << vec3.size() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> capacity():" << RESET << " vec1.capacity();" << std::endl << std::endl;
		std::cout << TAB << "-> using vec1 of size 1" << std::endl;
		std::cout << TAB << TAB << "vec1.capacity()" << ORANGE << " = " << RESET << vec1.capacity() << std::endl << std::endl;
		std::cout << TAB << "-> using vec2 of size 1000" << std::endl;
		std::cout << TAB << TAB << "vec2.capacity()" << ORANGE << " = " << RESET << vec2.capacity() << std::endl << std::endl;
		std::cout << TAB << "-> using vec3 of size 10000" << std::endl;
		std::cout << TAB << TAB << "vec3.capacity()" << ORANGE << " = " << RESET << vec3.capacity() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> max_size():" << RESET << " vec1.max_size();" << std::endl << std::endl;
		std::cout << TAB << "-> using vec1 of size 1" << std::endl;
		std::cout << TAB << TAB << "vec1.max_size()" << ORANGE << " = " << RESET << vec1.max_size() << std::endl << std::endl;
		std::cout << TAB << "-> using vec2 of size 1000" << std::endl;
		std::cout << TAB << TAB << "vec2.max_size()" << ORANGE << " = " << RESET << vec2.max_size() << std::endl << std::endl;
		std::cout << TAB << "-> using vec3 of size 10000" << std::endl;
		std::cout << TAB << TAB << "vec3.max_size()" << ORANGE << " = " << RESET << vec3.max_size() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> resize():" << RESET << " vec1.resize();" << std::endl << std::endl;
		std::cout << TAB << "-> using vec1 of size 1 : vec1.resize(5, 42);" << std::endl;
		vec1.resize(5, 42);
		printVec(vec1, 1);
		std::cout << TAB << "-> using vec2 of size 1000 : vec2.resize(420);" << std::endl;
		vec2.resize(420);
		printVec(vec2, 0);
		std::cout << TAB << "-> using vec3 of size 10000 : vec3.resize(0);" << std::endl;
		vec3.resize(0);
		printVec(vec3, 0);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> empty():" << RESET << " vec1.empty();" << std::endl << std::endl;
		std::cout << TAB << "-> using vec1 of size 5" << std::endl;
		std::cout << TAB << TAB << "vec1.empty()" << ORANGE << " = " << RESET << vec1.empty() << std::endl << std::endl;
		std::cout << TAB << "-> using vec2 of size 420" << std::endl;
		std::cout << TAB << TAB << "vec2.empty()" << ORANGE << " = " << RESET << vec2.empty() << std::endl << std::endl;
		std::cout << TAB << "-> using vec3 of size 0" << std::endl;
		std::cout << TAB << TAB << "vec3.empty()" << ORANGE << " = " << RESET << vec3.empty() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> reserve():" << RESET << " vec1.reserve();" << std::endl << std::endl;
		std::cout << TAB << "-> using vec1 of size 5 : vec1.reserve(10);" << std::endl;
		vec1.reserve(10);
		printVec(vec1, 0);
		std::cout << TAB << "-> using vec2 of size 420 : vec2.reserve(600);" << std::endl;
		vec2.reserve(600);
		printVec(vec2, 0);
		std::cout << TAB << "-> using vec3 of size 0 : vec3.reserve(10001);" << std::endl;
		vec3.reserve(10001);
		printVec(vec3, 0);
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- ELEMENT ACCESS TESTS ----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a vector with a list of 10 multiples of 3." << std::endl;
		std::list<T1> lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), i * 3);
		NS::vector<T1> vec1(lst.begin(), lst.end());
		printVec(vec1, 1);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> operator[]():" << RESET << " vec1[?];" << std::endl << std::endl;
		std::cout << TAB << STAR << "vec1[1]" << ORANGE << " = " << RESET << vec1[1] << std::endl;
		std::cout << TAB << STAR << "vec1[0]" << ORANGE << " = " << RESET << vec1[0] << std::endl;
		std::cout << TAB << STAR << "vec1[4]" << ORANGE << " = " << RESET << vec1[4] << std::endl;
		std::cout << TAB << STAR << "vec1[7]" << ORANGE << " = " << RESET << vec1[7] << std::endl;
		std::cout << TAB << STAR << "vec1[9]" << ORANGE << " = " << RESET << vec1[9] << std::endl << std::endl ;
		std::cout << TAB << "-> undefined behavior if out of range." << std::endl;
		std::cout << TAB << SPACE << STAR << "vec1[231]" << ORANGE << " = " << RESET << vec1[231] << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> at():" << RESET << " vec1.at();" << std::endl << std::endl;
		{
			std::cout << TAB << "-> modifying vec1 : vec1.at(4) = 42;" << std::endl;
			vec1.at(4) = 42;
			printVec(vec1, true);
			std::cout << TAB << "-> modifying vec1 by getting a value and modify it :" << std::endl;
			std::cout << TAB << SPACE << "-> T1 &value1 = vec1.at(7);" << std::endl;
			T1 &value1 = vec1.at(7);
			static_cast<void>(value1);
			std::cout << TAB << TAB << "value1" << ORANGE << " = " << RESET << value1 << std::endl;
			std::cout << TAB << SPACE << "-> value1 = 42 * 2;" << std::endl;
			value1 = 42 * 2;
			std::cout << TAB << TAB << "value1" << ORANGE << " = " << RESET << value1 << std::endl;
			printVec(vec1, 1);
			const T1 &value2 = vec1.at(9);
			static_cast<void>(value2);
			std::cout << TAB << "-> reading vec1 by getting a const value :" << std::endl;
			std::cout << TAB << SPACE << "-> const T1 &value1 = vec1.at(9);" << std::endl;
			std::cout << TAB << TAB << "value2" << ORANGE << " = " << RESET << value2 << std::endl << std::endl;
		  	std::cout << TAB << "-> trying to change value2 won't compile as value2 is a const reference from at() const ! (comment __NO_CONST and see what happens)" << std::endl << std::endl;
#ifndef __NO_CONST
			value2 = 42 * 3;
#endif
		}
		std::cout << SPACE << BOLD << ORANGE << UL << "--> front():" << RESET << " vec1.front();" << std::endl << std::endl;
		std::cout << TAB << TAB << "vec1.front()" << ORANGE << " = " << RESET << vec1.front() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> back():" << RESET << " vec1.back();" << std::endl << std::endl;
		std::cout << TAB << TAB << "vec1.back()" << ORANGE << " = " << RESET << vec1.back() << std::endl << std::endl;
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------ MODIFIERS TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a vector vec1 of 4 with multiples of 3." << std::endl;
		std::list<T1> lst;

		for (int i = 0; i < 4; i++)
			lst.insert(lst.end(), i * 3);
		NS::vector<T1> vec1(lst.begin(), lst.end());
		printVec(vec1, 1);
		std::cout << SPACE << "-> creating an empty vector vec3 of std::string." << std::endl;
		NS::vector<T3> vec3;
		printVec(vec3, 1);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> assign():" << RESET << " vec1.assign();" << std::endl << std::endl;
		std::cout << TAB << "-> assign to vec3 4 times \"Hello World!\" : vec1.assign(7, 42);" << std::endl;
		vec3.assign(4, "Hello World!");
		printVec(vec3, 1);
		std::cout << TAB << "-> assign to vec1 7 times 42 : vec1.assign(7, 42);" << std::endl;
		vec1.assign(7, 42);
		printVec(vec1, 1);
		lst.clear();
		for (int i = 0; i < 4; i++)
			lst.insert(lst.end(), i * 5);
		std::cout << TAB << "-> assign to vec1 a list of 4 mutliples of 5 : vec1.assign(lst.begin(), lst.end());" << std::endl;
		vec1.assign(lst.begin(), lst.end());
		printVec(vec1, 1);
		std::cout << TAB << "-> assign to an empty vector a list of 4 mutliples of 5 : vec2.assign(lst.begin(), lst.end());" << std::endl;
		{
			NS::vector<T1> vec2;
			vec2.assign(lst.begin(), lst.end());
			printVec(vec2, 1);
		}
		std::cout << SPACE << BOLD << ORANGE << UL << "--> push_back():" << RESET << " vec1.push_back();" << std::endl << std::endl;
		std::cout << TAB << "-> push_back 42 in vec1 : vec1.push_back(42);" << std::endl;
		vec1.push_back(42);
		printVec(vec1, 1);
		std::cout << TAB << "-> push_back 3 times 42 in vec1 : vec1.push_back(42);" << std::endl;
		for (int i = 0; i < 3;  i++)
			vec1.push_back(42);
		printVec(vec1, 1);
		std::cout << TAB << "-> push_back 42 in an empty vector : vec2.push_back(42);" << std::endl;
		{
			NS::vector<T1> vec2;
			vec2.push_back(42);
			printVec(vec2, 1);
		}
		std::cout << SPACE << BOLD << ORANGE << UL << "--> pop_back():" << RESET << " vec1.pop_back();" << std::endl << std::endl;
		std::cout << TAB << "-> pop_back vec1 : vec1.pop_back();" << std::endl;
		vec1.pop_back();
		printVec(vec1, 1);
		std::cout << TAB << "-> pop_back 3 times vec1 : vec1.pop_back();" << std::endl;
		for (int i = 0; i < 3;  i++)
			vec1.pop_back();
		printVec(vec1, 1);
		std::cout << TAB << "-> pop_back 10 times vec1 : vec1.pop_back(); (pop_back causes undefined behavior if vector is empty)" << std::endl;
		for (int i = 0; i < 4;  i++)
			vec1.pop_back();
		printVec(vec1, 1);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> insert():" << RESET << " vec1.insert();" << std::endl << std::endl;
		std::cout << TAB << "-> insert 4 multiples of 7 in vec1 at position vec1.end() : vec1.insert(vec1.end(), i * 7);" << std::endl;
		for (int i = 0; i < 4; i++)
			vec1.insert(vec1.end(), i * 7);
		printVec(vec1, 1);
		std::cout << TAB << "-> insert 3 times 42 in vec1 at position vec1.end() - 2 : vec1.insert(vec1.end() - 2, 3, 42);" << std::endl;
		vec1.insert(vec1.end() - 2, 3, 42);
		printVec(vec1, 1);
		std::cout << TAB << "-> insert 3 times 42 in vec1 at position vec1.begin() + 3 : vec1.insert(vec1.begin() + 3, vec1.begin(), vec1.end());" << std::endl;
		vec1.insert(vec1.begin() + 3, vec1.begin(), vec1.end());
		printVec(vec1, 1);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> erase():" << RESET << " vec1.erase();" << std::endl << std::endl;
		std::cout << TAB << "-> erase vec1 just inserted in vec1 at position vec1.begin() + 3 : vec1.erase(vec1.begin() + 3, vec1.end() - 6);" << std::endl;
		vec1.erase(vec1.begin() + 3, vec1.end() - 4);
		printVec(vec1, 1);
		std::cout << TAB << "-> erase 3 times vec1.begin() + 2 (42) : vec1.erase(vec1.begin() + 3);" << std::endl;
		for (int i = 0; i < 3; i++)
			vec1.erase(vec1.begin() + 2);
		printVec(vec1, 1);
		std::cout << TAB << "-> erase 4 times vec1.begin() : vec1.erase(vec1.begin());" << std::endl;
		for (int i = 0; i < 4; i++)
			vec1.erase(vec1.begin());
		printVec(vec1, 1);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> swap():" << RESET << " vec1.swap();" << std::endl << std::endl;
		std::cout << TAB << "-> creating a vector vec1 of 7 with multiples of 5." << std::endl;
		lst.clear();
		for (int i = 0; i < 7; i++)
			lst.insert(lst.end(), i * 5);
		vec1.insert(vec1.begin(), lst.begin(), lst.end());
		printVec(vec1, 1);
		lst.clear();
		{
			std::cout << TAB << "-> creating a vector vec2 of 14 with multiples of 10." << std::endl;
			for (int i = 0; i < 14; i++)
				lst.insert(lst.end(), i * 10);
			NS::vector<T1> vec2(lst.begin(), lst.end());
			printVec(vec2, 1);
			std::cout << TAB << "-> swap vec1 and vec2 : vec1.swap(vec2);" << std::endl;
			vec1.swap(vec2);
			std::cout << TAB << SPACE << "-> vec1" << std::endl;
			printVec(vec1, 1);
			std::cout << TAB << SPACE << "-> vec2" << std::endl;
			printVec(vec2, 1);
		}
		std::cout << SPACE << BOLD << ORANGE << UL << "--> clear():" << RESET << " vec1.clear();" << std::endl << std::endl;
		std::cout << TAB << "-> vec1" << std::endl;
		printVec(vec1, 1);
		std::cout << TAB << "-> clear vec1 : vec1.clear()" << std::endl;
		vec1.clear();
		printVec(vec1, 1);
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- RELATIONAL OPERATORS ----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << "-> creating a vector vec1 of 7 with multiples of 5." << std::endl;
		std::list<T1> lst;

		for (int i = 0; i < 7; i++)
			lst.insert(lst.end(), i * 5);
		NS::vector<T1> vec1(lst.begin(), lst.end());
		printVec(vec1, 1);
		lst.clear();
		std::cout << "-> creating a vector vec2 of 14 with multiples of 10." << std::endl;
		for (int i = 0; i < 14; i++)
			lst.insert(lst.end(), i * 10);
		NS::vector<T1> vec2(lst.begin(), lst.end());
		printVec(vec2, 1);
		std::cout << TAB << STAR << "vec1 " << ORANGE << "==" << RESET << " vec2 : " << (vec1 == vec2) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "!=" << RESET << " vec2 : " << (vec1 != vec2) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "<" << RESET << " vec2 : " << (vec1 < vec2) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << ">" << RESET << " vec2 : " << (vec1 > vec2) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "<=" << RESET << " vec2 : " << (vec1 <= vec2) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << ">=" << RESET << " vec2 : " << (vec1 >= vec2) << std::endl << std::endl;
		std::cout << "-> creating a vector vec3 copy of vector vec1." << std::endl;
		NS::vector<T1> vec3(vec1);
		printVec(vec3, 1);
		std::cout << TAB << STAR << "vec1 " << ORANGE << "==" << RESET << " vec3 : " << (vec1 == vec3) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "!=" << RESET << " vec3 : " << (vec1 != vec3) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "<" << RESET << " vec3 : " << (vec1 < vec3) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << ">" << RESET << " vec3 : " << (vec1 > vec3) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << "<=" << RESET << " vec3 : " << (vec1 <= vec3) << std::endl;
		std::cout << TAB << STAR << "vec1 " << ORANGE << ">=" << RESET << " vec3 : " << (vec1 >= vec3) << std::endl << std::endl;
		std::cout << BOLD << RED << "------------------------------------------" << std::endl;
		std::cout << "-------- SWAP NON-MEMBER OVERLOAD --------" << std::endl;
		std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
		std::cout << "-> swap vec1 and vec2 : swap(vec1, vec2);" << std::endl;
		swap(vec1, vec2);
		std::cout << TAB << "-> vec1" << std::endl;
		printVec(vec1, 1);
		std::cout << TAB << "-> vec2" << std::endl;
		printVec(vec2, 1);
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------------- BIG VECTOR ---------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << "-> push_back 1000000 times;" << std::endl << std::endl;
	NS::vector<T1> vec;
	for (int i = 0; i < 1000000; i++)
		vec.push_back(i);
}
#endif

#ifdef STACK
void stack_tests() {
	std::cout << BOLD << PINK << "==========================================" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==             STACK TESTS              ==" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==========================================" << RESET << std::endl << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- CONSTRUCTORS TESTS ------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> default():" << RESET << " stack();" << std::endl << std::endl;
	NS::stack<T1> stc1;
	std::cout << TAB << STAR  << "stc1.size() " << ORANGE << "= " << RESET << stc1.size() << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> container():" << RESET << " stack(NS::vector<T1>(5, 42));" << std::endl << std::endl;
	NS::stack<T1, NS::vector<T1> > stc2(NS::vector<T1>(5, 42));
	std::cout << TAB << STAR  << "stc2.size() " << ORANGE << "= " << RESET << stc2.size() << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> container():" << RESET << " stack(std::list<T1>(3, 2013));" << std::endl << std::endl;
	NS::stack<T1, std::list<T1> > stc3(std::list<T1>(3, 2013));
	std::cout << TAB << STAR  << "stc3.size() " << ORANGE << "= " << RESET << stc3.size() << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> copy():" << RESET << " stack(stc2);" << std::endl << std::endl;
	NS::stack<T1, NS::vector<T1> > stc4(stc2);
	std::cout << TAB << STAR  << "stc4.size() " << ORANGE << "= " << RESET << stc4.size() << std::endl << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------ CAPACITY TESTS --------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> empty():" << RESET << " stack.empty();" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc1.empty()" << ORANGE << " = " << RESET << stc1.empty() << std::endl;
	std::cout << TAB << STAR << "stc2.empty()" << ORANGE << " = " << RESET << stc2.empty() << std::endl;
	std::cout << TAB << STAR << "stc3.empty()" << ORANGE << " = " << RESET << stc3.empty() << std::endl;
	std::cout << TAB << STAR << "stc4.empty()" << ORANGE << " = " << RESET << stc4.empty() << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> size():" << RESET << " stack.size();" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc1.size() " << ORANGE << "= " << RESET << stc1.size() << std::endl;
	std::cout << TAB << STAR << "stc2.size() " << ORANGE << "= " << RESET << stc2.size() << std::endl;
	std::cout << TAB << STAR << "stc3.size() " << ORANGE << "= " << RESET << stc3.size() << std::endl;
	std::cout << TAB << STAR << "stc4.size() " << ORANGE << "= " << RESET << stc4.size() << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------ ELEMENT ACCESS --------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> top():" << RESET << " stack.top();" << std::endl << std::endl;
	std::cout << TAB << STAR  << "stc2.top()" << ORANGE << " = " << RESET << stc2.top() << std::endl;
	std::cout << TAB << STAR  << "stc3.top()" << ORANGE << " = " << RESET << stc3.top() << std::endl;
	std::cout << TAB << STAR  << "stc4.top()" << ORANGE << " = " << RESET << stc4.top() << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------------- MODIFIERS ----------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> push():" << RESET << " stack.push();" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc1.size()" << ORANGE << " = " << RESET << stc1.size() << std::endl;
	std::cout << TAB << "-> stc1.push(4);" << std::endl;
	stc1.push(4);
	std::cout << TAB << STAR << "stc1.size()" << ORANGE << " = " << RESET << stc1.size() << std::endl;
	std::cout << TAB << STAR << "stc1.top()" << ORANGE << " = " << RESET << stc1.top() << std::endl << std::endl;
	std::cout << TAB << STAR << "stc2.size()" << ORANGE << " = " << RESET << stc2.size() << std::endl;
	std::cout << TAB << STAR << "stc2.top()" << ORANGE << " = " << RESET << stc2.top() << std::endl;
	std::cout << TAB << "-> stc2.push(14242);" << std::endl;
	stc2.push(14242);
	std::cout << TAB << STAR << "stc2.size()" << ORANGE << " = " << RESET << stc2.size() << std::endl;
	std::cout << TAB << STAR << "stc2.top()" << ORANGE << " = " << RESET << stc2.top() << std::endl << std::endl;
	std::cout << TAB << STAR << "stc3.size()" << ORANGE << " = " << RESET << stc3.size() << std::endl;
	std::cout << TAB << STAR << "stc3.top()" << ORANGE << " = " << RESET << stc3.top() << std::endl;
	std::cout << TAB << "-> stc3.push(142);" << std::endl;
	stc3.push(142);
	std::cout << TAB << STAR << "stc3.size()" << ORANGE << " = " << RESET << stc3.size() << std::endl;
	std::cout << TAB << STAR << "stc3.top()" << ORANGE << " = " << RESET << stc3.top() << std::endl << std::endl;
	std::cout << TAB << STAR << "stc4.size()" << ORANGE << " = " << RESET << stc4.size() << std::endl;
	std::cout << TAB << STAR << "stc4.top()" << ORANGE << " = " << RESET << stc4.top() << std::endl;
	std::cout << TAB << "-> stc4.push(4242);" << std::endl;
	stc4.push(4242);
	std::cout << TAB << STAR << "stc4.size()" << ORANGE << " = " << RESET << stc4.size() << std::endl;
	std::cout << TAB << STAR << "stc4.top()" << ORANGE << " = " << RESET << stc4.top() << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> pop():" << RESET << " stack.pop();" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc1.size()" << ORANGE << " = " << RESET << stc1.size() << std::endl;
	std::cout << TAB << STAR << "stc1.top()" << ORANGE << " = " << RESET << stc1.top() << std::endl;
	std::cout << TAB << "-> stc1.pop();" << std::endl;
	stc1.pop();
	std::cout << TAB << STAR << "stc1.size()" << ORANGE << " = " << RESET << stc1.size() << std::endl;
	std::cout << TAB << STAR << "stc2.size()" << ORANGE << " = " << RESET << stc2.size() << std::endl;
	std::cout << TAB << STAR << "stc2.top()" << ORANGE << " = " << RESET << stc2.top() << std::endl;
	std::cout << TAB << "-> stc2.pop();" << std::endl;
	stc2.pop();
	std::cout << TAB << STAR << "stc2.size()" << ORANGE << " = " << RESET << stc2.size() << std::endl;
	std::cout << TAB << STAR << "stc2.top()" << ORANGE << " = " << RESET << stc2.top() << std::endl << std::endl;
	std::cout << TAB << STAR << "stc3.size()" << ORANGE << " = " << RESET << stc3.size() << std::endl;
	std::cout << TAB << STAR << "stc3.top()" << ORANGE << " = " << RESET << stc3.top() << std::endl;
	std::cout << TAB << "-> stc3.pop();" << std::endl;
	stc3.pop();
	std::cout << TAB << STAR << "stc3.size()" << ORANGE << " = " << RESET << stc3.size() << std::endl;
	std::cout << TAB << STAR << "stc3.top()" << ORANGE << " = " << RESET << stc3.top() << std::endl << std::endl;
	std::cout << TAB << STAR << "stc4.size()" << ORANGE << " = " << RESET << stc4.size() << std::endl;
	std::cout << TAB << STAR << "stc4.top()" << ORANGE << " = " << RESET << stc4.top() << std::endl;
	std::cout << TAB << "-> stc4.pop();" << std::endl;
	stc4.pop();
	std::cout << TAB << STAR << "stc4.size()" << ORANGE << " = " << RESET << stc4.size() << std::endl;
	std::cout << TAB << STAR << "stc4.top()" << ORANGE << " = " << RESET << stc4.top() << std::endl << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- RELATIONAL OPERATORS ----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << "-> creating a stack stc5 with 5 multiples of 3" << std::endl;
	NS::stack<T1, NS::vector<T1> > stc5;
	for (int i = 0; i < 5; i++)
		stc5.push(i * 3);
	std::cout << SPACE << SPACE << "-> comparing stc2 and stc5 :" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "==" << RESET << " stc5 : " << (stc2 == stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "!=" << RESET << " stc5 : " << (stc2 != stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "<" << RESET << " stc5 : " << (stc2 < stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << ">" << RESET << " stc5 : " << (stc2 > stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "<=" << RESET << " stc5 : " << (stc2 <= stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << ">=" << RESET << " stc5 : " << (stc2 >= stc4) << std::endl << std::endl;
	std::cout << SPACE << SPACE << "-> comparing stc2 and stc4 :" << std::endl << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "==" << RESET << " stc4 : " << (stc2 == stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "!=" << RESET << " stc4 : " << (stc2 != stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "<" << RESET << " stc4 : " << (stc2 < stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << ">" << RESET << " stc4 : " << (stc2 > stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << "<=" << RESET << " stc4 : " << (stc2 <= stc4) << std::endl;
	std::cout << TAB << STAR << "stc2 " << ORANGE << ">=" << RESET << " stc4 : " << (stc2 >= stc4) << std::endl << std::endl;
}
#endif

#ifdef MAP
void map_tests() {
	std::cout << BOLD << PINK << "==========================================" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==               MAP TESTS              ==" << std::endl;
	std::cout << "==                                      ==" << std::endl;
	std::cout << "==========================================" << RESET << std::endl << std::endl;
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------- CONSTRUCTORS TESTS ------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << BOLD << ORANGE << UL << "--> default:" << RESET << " map();" << std::endl;
		{
			NS::map<T1, T2> map;
			printMap(map, 1);
		}
		std::cout << SPACE << BOLD << ORANGE<< UL << "--> iterator range:" << RESET << " map(InputIterator first, InputIterator last);" << std::endl;
		{
			std::cout << "\n\t-> creating a list of 10 and filling it with multiples of 5." << std::endl;
			std::list<NS::pair<T1, T2> > lst;

			for (int i = 0; i < 10; i++)
				lst.insert(lst.end(), NS::make_pair(i, i * 5));
			std::cout << "\t   -> map<T1, T2> map1(list.begin(), list.end());" << std::endl;
			NS::map<T1, T2> map1(lst.begin(), lst.end());
			printMap(map1, 1);
			std::cout << SPACE << BOLD << ORANGE<< UL << "--> copy:" << RESET << " map(const map &other);" << std::endl;
			std::cout << "\n\t-> creating a map using last map with multiples of 5." << std::endl;
			std::cout << "\t   -> map<T1, T2> map2(map1);" << std::endl;
			NS::map<T1, T2> map2(map1);
			printMap(map2, 1);
		}
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "----------- OPERATOR = TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating an empty map map1." << std::endl << std::endl;
		NS::map<T1, T2> map1;
		std::list<NS::pair<T1, T2> > lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), NS::make_pair(i, i * 5));
		std::cout << TAB << "-> creating a map map2 with 10 mutliples of 2" << std::endl;
		NS::map<T1, T2> map2(lst.begin(), lst.end());
		std::cout << TAB << SPACE << "-> map1" << std::endl;
		printMap(map1, 1);
		std::cout << TAB << SPACE << "-> map2" << std::endl;
		printMap(map2, 1);
		std::cout << TAB << "-> map1 = map2;" << std::endl;
		std::cout << TAB << SPACE << "-> map2.begin() + 5 = 42;" << std::endl;
		map1 = map2;
		NS::map<T1, T2>::iterator it = map2.begin();
		for (int i = 0; i < 5; i++)
			it++;
		it->second = 42;
		std::cout << TAB << SPACE << "-> map1" << std::endl;
		printMap(map1, 1);
		std::cout << TAB << SPACE << "-> map2" << std::endl;
		printMap(map2, 1);
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "----------- OPERATOR[] TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << BOLD << ORANGE << UL << "--> operator[]():" << RESET << " map[?];" << std::endl << std::endl;
		std::list<NS::pair<T1, T2> > lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), NS::make_pair(i, i * 10));
		NS::map<T1, T2> map(lst.begin(), lst.end());
		std::cout << TAB << "-> creating a map with 10 mutliples of 10" << std::endl;
		printMap(map, 1);
		std::cout << TAB << STAR << "map[1]" << ORANGE << " = " << RESET << map[1] << std::endl;
		std::cout << TAB << STAR << "map[0]" << ORANGE << " = " << RESET << map[0] << std::endl;
		std::cout << TAB << STAR << "map[4]" << ORANGE << " = " << RESET << map[4] << std::endl;
		std::cout << TAB << STAR << "map[7]" << ORANGE << " = " << RESET << map[7] << std::endl;
		std::cout << TAB << STAR << "map[9]" << ORANGE << " = " << RESET << map[9] << std::endl << std::endl ;
		std::cout << TAB << "-> undefined behavior if out of range (creates a new element)." << std::endl;
		std::cout << TAB << SPACE << STAR << "map[231]" << ORANGE << " = " << RESET << map[231] << std::endl << std::endl;
		std::cout << TAB << "-> adding to map with operator[]" << std::endl;
		std::cout << TAB << SPACE << "-> map[42] = 666;" << std::endl;
		map[42] = 666;
		std::cout << TAB << SPACE << "-> map[-21] = 42;" << std::endl;
		map[-21] = 42;
		std::cout << TAB << SPACE << "-> map[999] = 238;" << std::endl;
		map[999] = 238;
		printMap(map, 1);
		std::cout << TAB << "-> creating an empty map of std::string" << std::endl;
		NS::map<T1, T3> map2;
		printMap(map2, 1);
		std::cout << TAB << SPACE << "-> map[42] = \"les\";" << std::endl;
		map2[42] = std::string("les");
		std::cout << TAB << SPACE << "-> map[-21] = \"coucou\";" << std::endl;
		map2[-21] = std::string("coucou");
		std::cout << TAB << SPACE << "-> map[999] = \"loulous\";" << std::endl;
		map2[999] = std::string("loulous");
		std::cout << TAB << SPACE << "-> map[2147483647] = \"!!!\";" << std::endl;
		map2[2147483647] = std::string("!!!");
		printMap(map2, 1);
	}
		std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------ ITERATORS TESTS -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a map of 10 with multiples of 3." << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> begin():" << RESET << " map<T1, T2>::iterator it = map1.begin(); && it++;" << std::endl;
		std::list<NS::pair<T1, T2> > lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), NS::make_pair(i, i * 3));
		NS::map<T1, T2> map1(lst.begin(), lst.end());
		NS::map<T1, T2>::iterator it = map1.begin();
		NS::map<T1, T2>::iterator ite = map1.end();
		std::cout << std::endl;
		for (; it != ite; it++)
			std::cout << TAB << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl;
		it = map1.begin();
		std::cout << std::endl;
		std::cout << TAB << "-> changing it value for 42 : \n" << TAB << TAB << "it = map1.begin();" << ORANGE << " -> " << RESET << "it->second = " << it->second << std::endl;
		it->second = 42;
		std::cout << TAB << TAB << "it->second = 42;" << ORANGE << " -> " << RESET << "it->second = " << it->second << std::endl;
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> end():" << RESET << " map<T1, T2>::iterator ite = map1.end(); && ite--;" << std::endl;
		std::cout << std::endl;
		it = map1.begin();
		ite--;
		for (; ite != it; ite--)
			std::cout << TAB << STAR << "map[" << ite->first << "]" << ORANGE << " = " << RESET << ite->second << std::endl;
		std::cout << TAB << STAR << "map[0]" << ORANGE << " = " << RESET << ite->second << std::endl;
		NS::map<T1, T2>::reverse_iterator rit = map1.rbegin();
		NS::map<T1, T2>::reverse_iterator rite = map1.rend();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rbegin():" << RESET << " map<T1, T2>::reverse_iterator rit = map1.rbegin(); && ++rit;" << std::endl;
		std::cout << std::endl;
		for (; rit != rite; ++rit)
			std::cout << TAB << STAR << "map[" << rit->first << "]" << ORANGE << " = " << RESET << rit->second << std::endl;
		rit = map1.rbegin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rend():" << RESET << " map<T1, T2>::reverse_iterator rite = map1.rend(); && --rite;" << std::endl;
		std::cout << std::endl;
		--rite;
		for (; rite != rit; --rite)
			std::cout << TAB << STAR << "map[" << rite->first << "]" << ORANGE << " = " << RESET << rite->second << std::endl;
		std::cout << TAB << STAR << "map[" << map1.size() - 1 << "]" << ORANGE << " = " << RESET << rite->second << std::endl;
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------- CONST_ITERATORS TESTS ----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << "-> creating a map of 10 with multiples of 3." << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> begin():" << RESET << " map<T1, T2>::const_iterator cit = map1.begin(); && cit++;" << std::endl;
		std::list<NS::pair<T1, T2> > lst;

		for (int i = 0; i < 10; i++)
			lst.insert(lst.end(), NS::make_pair(i, i * 3));
		NS::map<T1, T2> map1(lst.begin(), lst.end());
		NS::map<T1, T2>::const_iterator cit = map1.begin();
		NS::map<T1, T2>::const_iterator cite = map1.end();
		std::cout << std::endl;
		for (; cit != cite; cit++)
			std::cout << TAB << STAR << "map[" << cit->first << "]" << ORANGE << " = " << RESET << cit->second << std::endl;
		cit = map1.begin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> end():" << RESET << " map<T1, T2>::const_iterator cite = map1.end(); && cite--;" << std::endl;
		std::cout << std::endl;
		cit = map1.begin();
		cite--;
		for (; cite != cit; cite--)
			std::cout << TAB << STAR << "map[" << cite->first << "]" << ORANGE << " = " << RESET << cite->second << std::endl;
		std::cout << TAB << STAR << "map[0]" << ORANGE << " = " << RESET << cite->second << std::endl;
		std::cout << std::endl;
		std::cout << TAB << "-> trying to change cit or cite value for 42 won't compile as they are const_iterator ! (comment __NO_CONST and see what happens)" << std::endl;
#ifndef __NO_CONST
		*cit->second = 42;
		*cite->second = 42;
#endif
		NS::map<T1, T2>::const_reverse_iterator crit = map1.rbegin();
		NS::map<T1, T2>::const_reverse_iterator crite = map1.rend();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rbegin():" << RESET << " map<T1, T2>::const_reverse_iterator crit = map1.rbegin(); && ++crit;" << std::endl;
		std::cout << std::endl;
		for (; crit != crite; ++crit) {
			std::cout << TAB << STAR << "map[" << crit->first << "]" << ORANGE << " = " << RESET << crit->second << std::endl;
		}
		crit = map1.rbegin();
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> rend():" << RESET << " map<T1, T2>::const_reverse_iterator crite = map1.rend(); && --crite;" << std::endl;
		std::cout << std::endl;
		--crite;
		for (; crite != crit; --crite)
			std::cout << TAB << STAR << "map[" << crite->first << "]" << ORANGE << " = " << RESET << crite->second << std::endl;
		std::cout << TAB << STAR << "map[" << map1.size() - 1 << "]" << ORANGE << " = " << RESET << crite->second << std::endl;
		std::cout << std::endl;
		std::cout << TAB << "-> trying to change crit or crite value for 42 won't compile as they are const_reverse_iterator ! (comment __NO_CONST and see what happens)" << std::endl;
#ifndef __NO_CONST
		crit->second = 42;
		crit->second = 42;
#endif
		std::cout << std::endl;
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------------- CAPACITY -----------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << SPACE << BOLD << ORANGE << UL << "--> size():" << RESET << " map.size();" << std::endl << std::endl;
		std::cout << TAB << "-> creating a map of size 1;" << std::endl;
		NS::map<T1, T1> map1;
		map1[42] = 31;
		std::cout << TAB << TAB << "map1.size()" << ORANGE << " = " << RESET << map1.size() << std::endl << std::endl;
		std::cout << TAB << "-> creating a map of size 12;" << std::endl;
		NS::map<T1, T1> map2;
		for (int i = 0; i < 12; i++)
			map2[i] = i * 2;
		std::cout << TAB << TAB << "map1.size()" << ORANGE << " = " << RESET << map2.size() << std::endl << std::endl;
		std::cout << TAB << "-> creating an empty map;" << std::endl;
		NS::map<T1, T1> map3;
		std::cout << TAB << TAB << "map3.size()" << ORANGE << " = " << RESET << map3.size() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> empty():" << RESET << " map.empty();" << std::endl << std::endl;
		std::cout << TAB << "-> using map1 of size 1" << std::endl;
		std::cout << TAB << TAB << "map1.empty()" << ORANGE << " = " << RESET << map1.empty() << std::endl << std::endl;
		std::cout << TAB << "-> using map2 of size 12" << std::endl;
		std::cout << TAB << TAB << "map2.empty()" << ORANGE << " = " << RESET << map2.empty() << std::endl << std::endl;
		std::cout << TAB << "-> using map3 of size 0" << std::endl;
		std::cout << TAB << TAB << "map3.empty()" << ORANGE << " = " << RESET << map3.empty() << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> max_size():" << RESET << " map.max_size();" << std::endl << std::endl;
		std::cout << TAB << "-> using map1 of size 1" << std::endl;
		std::cout << TAB << TAB << "map1.max_size()" << ORANGE << " = " << RESET << map1.max_size() << std::endl << std::endl;
		std::cout << TAB << "-> using map2 of size 12" << std::endl;
		std::cout << TAB << TAB << "map2.max_size()" << ORANGE << " = " << RESET << map2.max_size() << std::endl << std::endl;
		std::cout << TAB << "-> using map3 of size 0" << std::endl;
		std::cout << TAB << TAB << "map3.max_size()" << ORANGE << " = " << RESET << map3.max_size() << std::endl << std::endl;
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "-------------- MODIFIERS -----------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		{
			std::cout << SPACE << BOLD << ORANGE << UL << "--> insert():" << RESET << " map.insert();" << std::endl << std::endl;
			NS::map<T1, T1> map1;
			std::cout << TAB << "-> inserting pair(42, 2013) : map1.insert(NS::make_pair(42, 2013));" << std::endl;
			map1.insert(NS::make_pair(42, 2013));
			std::cout << TAB << "-> inserting pair(2013, 42) : map1.insert(NS::make_pair(2013, 42));" << std::endl;
			map1.insert(NS::make_pair(2013, 42));
			printMap(map1, 1);
			std::cout << TAB << "-> inserting pair(8, 2003) with position begin() : map1.insert(map1.begin(), NS::make_pair(8, 2003));" << std::endl;
			std::cout << TAB << "-> inserting pair(2100, 50) with position begin() : map1.insert(map1.begin(), NS::make_pair(2100, 50));" << std::endl;
			map1.insert(map1.begin(), NS::make_pair(8, 2003));
			map1.insert(map1.begin(), NS::make_pair(2100, 50));
			printMap(map1, 1);
			std::cout << TAB << "-> inserting with iterator range : map1.insert(lst.begin(), lst.end());" << std::endl;
			std::list<NS::pair<T1, T2> > lst;

			for (int i = 0; i < 5; i++)
				lst.insert(lst.end(), NS::make_pair(i * 23, i));
			map1.insert(lst.begin(), lst.end());
			printMap(map1, 1);
			std::cout << SPACE << BOLD << ORANGE << UL << "--> erase():" << RESET << " map.erase();" << std::endl << std::endl;
			std::cout << TAB << "-> erasing with iterator : map1.erase(map1.find(2013));" << std::endl;
			std::cout << TAB << "-> erasing with iterator : map1.erase(map1.end() - 1);" << std::endl;
			map1.erase(map1.find(2013));
			NS::map<T1, T1>::iterator it = map1.end();
			it--;
			map1.erase(it);
			printMap(map1, 1);
			std::cout << TAB << "-> erasing with key value : map1.erase(92);" << std::endl;
			std::cout << TAB << "-> erasing with key value : map1.erase(325); (nothing happens if key value is not found)" << std::endl;
			std::cout << TAB << "-> erasing with key value : map1.erase(0);" << std::endl;
			map1.erase(92);
			map1.erase(325);
			map1.erase(0);
			printMap(map1, 1);
			std::cout << TAB << "-> erasing with iterator range : map1.erase(map1.begin(), map1.end());" << std::endl;
			map1.erase(map1.begin(), map1.end());
			printMap(map1, 1);
		}
		{
			std::cout << SPACE << BOLD << ORANGE << UL << "--> swap():" << RESET << " map.swap();" << std::endl << std::endl;
			std::cout << TAB << "-> creating 2 maps with 5 and 12 pairs" << std::endl;
			NS::map<T1, T1> map1;
			NS::map<T1, T1> map2;
			std::list<NS::pair<T1, T2> > lst;

			for (int i = 0; i < 5; i++)
				lst.insert(lst.end(), NS::make_pair(i * 23, i));
			map1.insert(lst.begin(), lst.end());
			lst.clear();
			for (int i = 0; i < 12; i++)
				lst.insert(lst.end(), NS::make_pair(i * 42, i));
			map2.insert(lst.begin(), lst.end());
			std::cout << TAB << SPACE << "-> map1" << std::endl;
			printMap(map1, 1);
			std::cout << TAB << SPACE << "-> map2" << std::endl;
			printMap(map2, 1);
			std::cout << TAB << "-> swap map1 and map2 : map1.swap(map2);" << std::endl;
			map1.swap(map2);
			std::cout << TAB << SPACE << "-> map1" << std::endl;
			printMap(map1, 1);
			std::cout << TAB << SPACE << "-> map2" << std::endl;
			printMap(map2, 1);
			std::cout << SPACE << BOLD << ORANGE << UL << "--> clear():" << RESET << " map.clear();" << std::endl << std::endl;
			std::cout << TAB << "-> map1.clear()" << std::endl;
			map1.clear();
			printMap(map1, 1);
			std::cout << TAB << "-> map2.clear()" << std::endl;
			map2.clear();
			printMap(map2, 1);
		}
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------------- LOOK-UP ------------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << TAB << "-> creating a map that looks like this :" << std::endl;
		NS::map<T1, T1> map;
		map[42] = 2013;
		map[2022] = 12;
		map[0] = -42;
		map[-42] = 2013;
		map[-2147483648] = 2147483647;
		map[2147483647] = -2147483648;
		map[12] = 8;
		map[11] = 2022;
		map[15] = 11;
		printMap(map, true);
		std::cout << SPACE << BOLD << ORANGE << UL << "--> count():" << RESET << " map.count();" << std::endl << std::endl;
		std::cout << TAB << "-> looking for 42 : map.count(42);" << std::endl;
		std::cout << TAB << STAR << "map.count(42)" << ORANGE << " = " << RESET << map.count(42) << std::endl << std::endl;
		std::cout << TAB << "-> looking for -42 : map.count(-42);" << std::endl;
		std::cout << TAB << STAR << "map.count(-42)" << ORANGE << " = " << RESET << map.count(-42) << std::endl << std::endl;
		std::cout << TAB << "-> looking for 2147483647 : map.count(-2147483648);" << std::endl;
		std::cout << TAB << STAR << "map.count(2147483647)" << ORANGE << " = " << RESET << map.count(2147483647) << std::endl << std::endl;
		std::cout << TAB << "-> looking for -2147483648 : map.count(2147483647);" << std::endl;
		std::cout << TAB << STAR << "map.count(-2147483648)" << ORANGE << " = " << RESET << map.count(-2147483648) << std::endl << std::endl;
		std::cout << TAB << "-> looking for 2212 : map.count(2212);" << std::endl;
		std::cout << TAB << STAR << "map.count(2212)" << ORANGE << " = " << RESET << map.count(2212) << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> find():" << RESET << " map.find();" << std::endl << std::endl;
		NS::map<T1, T1>::iterator it = map.find(42);
		std::cout << TAB << "-> NS::map<T1, T1>::iterator it = map.find(42); : map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl;
		std::cout << TAB << SPACE << "-> modify it : it->second = 1999;" << std::endl;
		it->second = 1999;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl;
		printMap(map, true);
		it = map.find(23132);
		std::cout << TAB << "-> map.find(23132) : it == map.end() ? (when an element is not found, find() return end())" << std::endl;
		std::cout << TAB << SPACE << "-> it == map.end() : " << (it == map.end()) << std::endl << std::endl;
		NS::map<T1, T1>::const_iterator cit = map.find(12);
		std::cout << TAB << "-> NS::map<T1, T1>::const_iterator cit = map.find(12); with const_iterator : map[" << cit->first << "]" << ORANGE << " = " << RESET << cit->second << std::endl;
		std::cout << TAB << SPACE << "-> trying to change cit or crite value won't compile as cit is const_iterator ! (comment __NO_CONST and see what happens)" << std::endl << std::endl;
#ifndef __NO_CONST
		cit->second = 1999;
#endif
		std::cout << SPACE << BOLD << ORANGE << UL << "--> equal_range():" << RESET << " map.equal_range();" << std::endl << std::endl;
		NS::pair<NS::map<int, int>::iterator, NS::map<int, int>::iterator> pair = map.equal_range(42);
		std::cout << TAB << "-> NS::pair<NS::map<int, int>::iterator, NS::map<int, int>::iterator> pair = map.equal_range(42);" << std::endl;
		std::cout << TAB << STAR  << "pair.first" << ORANGE << " : " << RESET << "map[" << pair.first->first << "]" << ORANGE << " = " << RESET << pair.first->second << std::endl;
		std::cout << TAB << STAR  << "pair.second" << ORANGE << " : " << RESET << "map[" << pair.second->first << "]" << ORANGE << " = " << RESET << pair.second->second << std::endl << std::endl;
		pair = map.equal_range(322);
		std::cout << TAB << "-> pair = map.equal_range(322);" << std::endl;
		std::cout << TAB << STAR  << "pair.first" << ORANGE << " : " << RESET << "map[" << pair.first->first << "]" << ORANGE << " = " << RESET << pair.first->second << std::endl;
		std::cout << TAB << STAR  << "pair.second" << ORANGE << " : " << RESET << "map[" << pair.second->first << "]" << ORANGE << " = " << RESET << pair.second->second << std::endl << std::endl;
		pair = map.equal_range(-2147483648);
		std::cout << TAB << "-> pair = map.equal_range(-2147483648);" << std::endl;
		std::cout << TAB << STAR  << "pair.first" << ORANGE << " : " << RESET << "map[" << pair.first->first << "]" << ORANGE << " = " << RESET << pair.first->second << std::endl;
		std::cout << TAB << STAR  << "pair.second" << ORANGE << " : " << RESET << "map[" << pair.second->first << "]" << ORANGE << " = " << RESET << pair.second->second << std::endl << std::endl;
		pair = map.equal_range(2147483647);
		std::cout << TAB << "-> pair = map.equal_range(2147483647);" << std::endl;
		std::cout << TAB << STAR  << "pair.first" << ORANGE << " : " << RESET << "map[" << pair.first->first << "]" << ORANGE << " = " << RESET << pair.first->second << std::endl;
		std::cout << TAB << STAR  << "pair.second == map.end()" << ORANGE << " ? " << RESET << (pair.second == map.end()) << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> lower_bound:" << RESET << " map.lower_bound();" << std::endl;
		printMap(map, true);
		it = map.lower_bound(-42);
		std::cout << TAB << "-> it = map.lower_bound(-42);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.lower_bound(422);
		std::cout << TAB << "-> it = map.lower_bound(422);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.lower_bound(0);
		std::cout << TAB << "-> it = map.lower_bound(0);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.lower_bound(-1);
		std::cout << TAB << "-> it = map.lower_bound(-1);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> upper_bound():" << RESET << " map.upper_bound();" << std::endl << std::endl;
		it = map.upper_bound(-42);
		std::cout << TAB << "-> it = map.upper_bound(-42);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.upper_bound(422);
		std::cout << TAB << "-> it = map.upper_bound(422);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.upper_bound(0);
		std::cout << TAB << "-> it = map.upper_bound(0);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
		it = map.upper_bound(-1);
		std::cout << TAB << "-> it = map.upper_bound(-1);" << std::endl;
		std::cout << TAB << SPACE << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl << std::endl;
	}
	std::cout << std::endl << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "--------- RELATIONAL OPERATORS -----------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	{
		NS::map<T3, T1> map1;
		NS::map<T3, T1> map2;
		map1["numero 1"] = 100;
		map1["test"] = 200;
		map1["test2"] = 221;
		map1["coucou"] = 42;
		map2["bonjour"] = 10;
		map2["numero 2"] = 1000;
		map2["salut"] = 1111;
		map2["au revoir"] = 32310;
		map2["a bientot"] = 3242;
		map2["adieu"] = 422;
		std::cout << TAB << "-> map1" << std::endl;
		printMap(map1, 1);
		std::cout << TAB << "-> map2" << std::endl;
		printMap(map2, 1);
		std::cout << TAB << "-> operators :" << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "==" << RESET << " map2 : " << (map1 == map2) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "!=" << RESET << " map2 : " << (map1 != map2) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "<" << RESET << " map2 : " << (map1 < map2) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << ">" << RESET << " map2 : " << (map1 > map2) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "<=" << RESET << " map2 : " << (map1 <= map2) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << ">=" << RESET << " map2 : " << (map1 >= map2) << std::endl << std::endl;
		std::cout << "-> creating a map3 copy of map1." << std::endl;
		NS::map<T3, T1> map3(map1);
		printMap(map3, 1);
		std::cout << TAB << "-> operators :" << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "==" << RESET << " map3 : " << (map1 == map3) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "!=" << RESET << " map3 : " << (map1 != map3) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "<" << RESET << " map3 : " << (map1 < map3) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << ">" << RESET << " map3 : " << (map1 > map3) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << "<=" << RESET << " map3 : " << (map1 <= map3) << std::endl;
		std::cout << TAB << STAR << "map1 " << ORANGE << ">=" << RESET << " map3 : " << (map1 >= map3) << std::endl << std::endl;
		std::cout << BOLD << RED << "------------------------------------------" << std::endl;
		std::cout << "-------- SWAP NON-MEMBER OVERLOAD --------" << std::endl;
		std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
		std::cout << "-> swap map1 and map2 : swap(map1, map2);" << std::endl;
		swap(map1, map2);
		std::cout << TAB << "-> map1" << std::endl;
		printMap(map1, 1);
		std::cout << TAB << "-> map2" << std::endl;
		printMap(map2, 1);
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "------------- OBSERVERS TEST -------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << SPACE << BOLD << ORANGE << UL << "--> key_comp:" << RESET << " map.key_comp();" << std::endl;
	{
		NS::map<T3, T1> map;
		NS::map<T3, T1>::key_compare comp = map.key_comp();
		map["a"] = 1;
		map["bb"] = 22;
		map["ccc"] = 333;
		map["dddd"] = 4444;
		map["eeeee"] = 55555;
		printMap(map, 1);
		NS::map<T3, T1>::iterator it = map.begin();
		for (int i = 0; i < 3; i++)
			it++;
		T3 toFind = it->first;
		std::cout << TAB << "-> toFind : " << toFind << " (while it->first != toFind display it->first, it->second)" << std::endl;
		it = map.begin();
		for(; comp(it->first, toFind); it++)
			std::cout << TAB << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl;
		std::cout << std::endl;
		std::cout << SPACE << BOLD << ORANGE << UL << "--> value_comp:" << RESET << " map.value_comp();" << std::endl << std::endl;
		it = map.begin();
		for (int i = 0; i < 4; i++)
			it++;
		NS::pair<T3, T1> toFind2 = NS::make_pair(it->first, it->second);
		it = map.begin();
		std::cout << TAB << "-> toFind : " << toFind2.second << " (while it->first != toFind display it->first, it->second)" << std::endl;
		for(; map.value_comp()(*it, toFind2); it++)
			std::cout << TAB << SPACE << STAR << "map[" << it->first << "]" << ORANGE << " = " << RESET << it->second << std::endl;
		std::cout << std::endl;
	}
	std::cout << BOLD << RED << "------------------------------------------" << std::endl;
	std::cout << "---------------- BIG MAP -----------------" << std::endl;
	std::cout << "------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << "-> insert 1000000 times;" << std::endl << std::endl;
	NS::map<T1, T1> map;
	for (int i = 0; i < 1000000; i++)
		map[i] = i;
}
#endif

void printVec(NS::vector<T1> &vec, bool displayContainer) {
	std::cout << std::endl;
	std::cout << TAB << BOLD << BLUE << "====== PRINT VECTOR ======" << RESET << std::endl;
	std::cout << TAB << STAR << "size()" << ORANGE << " = " << RESET << vec.size() << std::endl;
	std::cout << TAB << STAR << "capacity()" << ORANGE << " = " << RESET << vec.capacity() << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	if (displayContainer) {
		if (vec.empty())
			std::cout << TAB << "        Vec's empty !" << std::endl;
		else {
			NS::vector<T1>::iterator it = vec.begin();
			NS::vector<T1>::iterator ite = vec.end();
			for (int i = 0; it != ite; it++) {
				std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *it << std::endl;
				i++;
			}
		}
		std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	}
	std::cout << std::endl;
}

void printVec(NS::vector<T3> &vec, bool displayContainer) {
	std::cout << std::endl;
	std::cout << TAB << BOLD << BLUE << "====== PRINT VECTOR ======" << RESET << std::endl;
	std::cout << TAB << STAR << "size()" << ORANGE << " = " << RESET << vec.size() << std::endl;
	std::cout << TAB << STAR << "capacity()" << ORANGE << " = " << RESET << vec.capacity() << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	if (displayContainer) {
		if (vec.empty())
			std::cout << TAB << "        Vec's empty !" << std::endl;
		else {
			NS::vector<T3>::iterator it = vec.begin();
			NS::vector<T3>::iterator ite = vec.end();
			for (int i = 0; it != ite; it++) {
				std::cout << TAB << STAR << "vector[" << i << "]" << ORANGE << " = " << RESET << *it << std::endl;
				i++;
			}
		}
		std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	}
	std::cout << std::endl;
}


void printMap(NS::map<T3, T1> &map, bool displayContainer) {
	std::cout << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	std::cout << TAB << STAR << "size() : " << map.size() << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	if (displayContainer) {
		if (map.empty())
			std::cout << TAB << "       Map's empty !" << std::endl;
		else {
			NS::map<T3, T1>::iterator it = map.begin();
			NS::map<T3, T1>::iterator ite = map.end();
			for (; it != ite; it++)
				std::cout << TAB << STAR << "map[" << it->first << "] " << ORANGE << "= " << RESET << it->second << std::endl;
		}
	}
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl << std::endl;
}

void printMap(NS::map<T1, T2> &map, bool displayContainer) {
	std::cout << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	std::cout << TAB << STAR << "size() : " << map.size() << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	if (displayContainer) {
		if (map.empty())
			std::cout << TAB << "       Map's empty !" << std::endl;
		else {
			NS::map<T1, T2>::iterator it = map.begin();
			NS::map<T1, T2>::iterator ite = map.end();
			for (; it != ite; it++)
				std::cout << TAB << STAR << "map[" << it->first << "] " << ORANGE << "= " << RESET << it->second << std::endl;
		}
	}
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl << std::endl;
}

void printMap(NS::map<T1, T3> &map, bool displayContainer) {
	std::cout << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	std::cout << TAB << STAR << "size() : " << map.size() << std::endl;
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl;
	if (displayContainer) {
		if (map.empty())
			std::cout << TAB << "       Map's empty !" << std::endl;
		else {
			NS::map<T1, T3>::iterator it = map.begin();
			NS::map<T1, T3>::iterator ite = map.end();
			for (; it != ite; it++)
				std::cout << TAB << STAR << "map[" << it->first << "] " << ORANGE << "= " << RESET << it->second << std::endl;
		}
	}
	std::cout << TAB << BOLD << BLUE  << "==========================" << RESET << std::endl << std::endl;
}






































