/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:00:45 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/13 23:41:04 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef Container container_type;

		protected:
			container_type c;

		public:
			explicit stack(const container_type &container = container_type()) : c(container) {}

			stack(const stack &other) : c(other.c) {}

			~stack() {}

			stack &operator=(const stack &other) {
				if (*this != other)
					c = other.c;
				return *this;
			}

			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			value_type &top() {
				return c.back();
			}

			const value_type &top() const {
				return c.back();
			}

			void push(const value_type &x) {
				c.push_back(x);
			}

			void pop() {
				c.pop_back();
			}

			friend bool operator==(const stack<T, Container> &x, const stack<T, Container> &y);
	};

	template <class T, class Container>
		bool operator==(const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c == y.c;
		}

	template <class T, class Container>
		bool operator< (const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c < y.c;
		}

	template <class T, class Container>
		bool operator!=(const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c != y.c;
		}

	template <class T, class Container>
		bool operator> (const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c > y.c;
		}

	template <class T, class Container>
		bool operator>=(const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c >= y.c;
		}

	template <class T, class Container>
		bool operator<=(const stack<T, Container> &x, const stack<T, Container> &y) {
			return x.c <= y.c;
		}
}

# endif
