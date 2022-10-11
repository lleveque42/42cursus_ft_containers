/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:43:27 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/11 17:38:04 by lleveque         ###   ########.fr       */
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

			vectorIterator() : _current() {}
			explicit vectorIterator(const Iterator &i) : _current(i) {}
			vectorIterator(const vectorIterator &src) : _current(src._current) {}
			~vectorIterator() {}

			template<typename Iter>
				vectorIterator(const vectorIterator<Iter> &i) : _current((iterator_type)i.operator->()) {}

			vectorIterator	&operator=(vectorIterator const &src) {
				if (*this != src)
					_current = src._current;
				return *this;
			}

			reference operator*() const {
				return *_current;
			}

			reference operator[](const difference_type &n) const {
				return _current[n];
			}

			pointer operator->() const {
				return _current;
			}

			iterator_type base() const {
				return _current;
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

			// it = it1 + n;
			vectorIterator operator+(difference_type n) const {
				return vectorIterator(_current + n);
			}

			vectorIterator &operator-=(difference_type n) {
				_current -= n;
				return *this;
			}

			// it = it1 - n;
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

	// it = n + it1;
	template<typename Iter>
		vectorIterator<Iter> operator+(typename vectorIterator<Iter>::difference_type n, const vectorIterator<Iter> &right) {
			return vectorIterator<Iter>(right.base() + n);
		}

	// it = it1 - it2;
	template< typename lIter, typename rIter>
		typename vectorIterator<lIter>::difference_type operator-(const vectorIterator<lIter> &left, const vectorIterator<rIter> &right) {
			return left.base() - right.base();
		}
}

#endif
