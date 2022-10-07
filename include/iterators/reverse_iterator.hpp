/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:37:16 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/07 15:25:17 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

# include "iterator_traits.hpp"

namespace ft {

	template <typename Iterator>
	class reverse_iterator {

		protected:
			Iterator _current;

		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::reference reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;

			reverse_iterator() : _current() {}
			explicit reverse_iterator(const Iterator &i) : _current(i) {}
			reverse_iterator(const reverse_iterator &src) : _current(src._current) {}
			~reverse_iterator() {}

			template<typename Iter>
				reverse_iterator(const reverse_iterator<Iter> &i) : _current(i.base()) {}

			reverse_iterator	operator=(reverse_iterator const &src) {
				if (*this != src)
					_current = src._current;
				return *this;
			}

			reference operator*() const {
				iterator_type _tmp = _current;
				return *--_tmp;
			}

			pointer operator->() const {
				return &(operator*());
			}

			iterator_type base() const {
				return _current;
			}

			reverse_iterator operator[](const difference_type &n) {
				return _current[-n - 1];
			}

			reverse_iterator &operator++() {
				--_current;
				return *this;
			}

			reverse_iterator &operator--() {
				++_current;
				return *this;
			}

			reverse_iterator operator++(int) {
				reverse_iterator old = *this;
				_current--;
				return old;
			}

			reverse_iterator operator--(int) {
				reverse_iterator old = *this;
				_current++;
				return old;
			}

			reverse_iterator &operator+=(difference_type n) {
				_current -= n;
				return *this;
			}

			// it = it1 + n;
			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(_current - n);
			}

			reverse_iterator &operator-=(difference_type n) {
				_current += n;
				return *this;
			}

			// it = it1 - n;
			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(_current + n);
			}
	};

	template<typename lIter, typename rIter>
		bool operator==(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() == right.base();
		}

	template<typename lIter, typename rIter>
		bool operator!=(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() != right.base();
		}

	template<typename lIter, typename rIter>
		bool operator<=(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() >= right.base();
		}

	template<typename lIter, typename rIter>
		bool operator>=(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() <= right.base();
		}

	template<typename lIter, typename rIter>
		bool operator<(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() > right.base();
		}

	template<typename lIter, typename rIter>
		bool operator>(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() < right.base();
		}

	// it = n + it1;
	template<typename Iter>
		reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &right) {
			return reverse_iterator<Iter>(right.base() - n);
		}

	// it = it1 - it2;
	template< typename lIter, typename rIter>
		typename reverse_iterator<lIter>::difference_type operator-(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
			return left.base() - right.base();
		}
}

#endif
