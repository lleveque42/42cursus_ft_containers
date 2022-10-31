/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:35 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/31 20:32:40 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair {

		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second() {}

		pair(const first_type &x, const second_type &y) : first(x), second(y) {}

		template<class U, class V>
			pair(const pair<U, V> &p) : first(p.first), second(p.second) {}

		pair &operator=(const pair& pr) {
			if (*this != pr) {
				first = pr.first;
				second = pr.second;
			}
			return *this;
		}
	};

	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y) {
			return (pair<T1,T2>(x,y));
		}

	template< class T1, class T2 >
		bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}

	template< class T1, class T2 >
		bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			return !(lhs == rhs);
		}

	template< class T1, class T2 >
		bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			if (lhs.first != lhs.first)
				return lhs.first < lhs.first;
			return lhs.second < rhs.second;
		}

	template< class T1, class T2 >
		bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			return rhs < lhs;
		}

	template< class T1, class T2 >
		bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			return !(lhs > rhs);
		}

	template< class T1, class T2 >
		bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs) {
			return !(lhs < rhs);
		}
}

#endif
