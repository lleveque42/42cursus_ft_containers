/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:43:27 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/06 19:29:04 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <typename Iterator>
	class vectorIterator : public ft::iterator<ft::random_access_iterator_tag, Iterator> {

		protected:
			Iterator _current;

		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::reference reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;

			vectorIterator() : _current() {};
			explicit vectorIterator(const Iterator &i) : _current(i) {};
			vectorIterator(const vectorIterator &src) : _current(src._current) {};
			~vectorIterator() {};

			vectorIterator	operator=(vectorIterator const &src) {
				if (*this != src)
					_current = src._current;
				return *this;
			}

			reference operator*() const {
				return *_current;
			}

			pointer operator->() const {
				return _current;
			}

			const iterator_type base() const {
				return _current;
			}

			vectorIterator operator[](const difference_type &n) {
				return _current[n];
			}

			vectorIterator &operator++() {
				++_current;
				return *this;
			}

			vectorIterator &operator--() {
				--_current;
				return *this;
			}

			vectorIterator operator++(int) {
				vectorIterator old = *this;
				_current++;
				return old;
			}

			vectorIterator operator--(int) {
				vectorIterator old = *this;
				_current--;
				return old;
			}

			vectorIterator &operator+=(difference_type n) {
				_current += n;
				return *this;
			}

			vectorIterator operator+(difference_type n) const {
				return vectorIterator(_current + n);
			}

			vectorIterator &operator-=(difference_type n) {
				_current -= n;
				return *this;
			}

			vectorIterator operator-(difference_type n) const {
				return vectorIterator(_current - n);
			}
	};

	template<typename lIter, typename rIter>
		bool operator==(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() == right.base();
		}

	template<typename lIter, typename rIter>
		bool operator!=(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() != right.base();
		}

	template<typename lIter, typename rIter>
		bool operator<=(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() <= right.base();
		}

	template<typename lIter, typename rIter>
		bool operator>=(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() >= right.base();
		}

	template<typename lIter, typename rIter>
		bool operator<(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() < right.base();
		}

	template<typename lIter, typename rIter>
		bool operator>(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() > right.base();
		}

	template<typename Iter>
		vectorIterator<Iter> operator+(typename vectorIterator<Iter>::difference_type &n, const vectorIterator<Iter> &left) {
			return vectorIterator<Iter>(left.base() + n);
		}

	template< typename lIter, typename rIter>
		typename vectorIterator<lIter>::difference_type operator-(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() - right.base();
		}

	// template <typename V>
		// vectorIterator<V> operator+(vectorIterator<V> lhs, typename vectorIterator<V>::difference_type rhs) {return (vectorIterator<V>(lhs.operator->() + rhs));}
	// template <typename V>
		// vectorIterator<V> operator+(typename vectorIterator<V>::difference_type lhs, vectorIterator<V> &rhs) {return (vectorIterator<V>(rhs.operator->() + lhs));}
	// template <typename V>
		// vectorIterator<V> operator-(vectorIterator<V> lhs, typename vectorIterator<V>::difference_type rhs) {return (vectorIterator<V>(lhs.operator->() - rhs));}
	// template <typename L, typename R>
	// typename vectorIterator<L>::difference_type operator-(vectorIterator<L> lhs, vectorIterator<R> rhs) {return (lhs.operator->() - rhs.operator->());}
}

#endif
