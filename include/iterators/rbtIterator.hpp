/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:22:47 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/27 16:16:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTITERATOR_HPP
# define RBTITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <typename T, typename N>
	class RBTIterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {

		public:

			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;
			typedef N*	node_pointer;

		protected:

			node_pointer _current;

		public:

			RBTIterator() : _current() {}

			RBTIterator(node_pointer i) : _current(i) {}

			RBTIterator(const RBTIterator &src) : _current(src._current) {}

			~RBTIterator() {}

			// template<typename Iter>
				// RBTIterator(const RBTIterator<Iter> &i) : _current(i.base()) {}

			RBTIterator	&operator=(RBTIterator const &src) {
				if (*this != src)
					_current = src._current;
				return *this;
			}

			reference operator*() const {
				return _current->data;
			}

			pointer operator->() const {
				return &(_current->data);
			}

			node_pointer base() const {
				return _current;
			}

			RBTIterator &operator++() {
				if (_current && _current->right) {
					_current = _current->right;
					while (_current && _current->left)
						_current = _current->left;
				}
				else if (_current && _current->parent) {
					pointer current = _current;
					pointer tmp = _current->parent;
					while (tmp && _current == tmp->right) {
						if (tmp->parent == NULL) {
							_current = current->parent;
							return *this;
						}
						_current = tmp;
						tmp = tmp->parent;
					}
					_current = tmp;
				}
				return *this;
			}

			RBTIterator &operator--() {
				if (_current && _current->left) {
					_current = _current->left;
					while (_current && _current->right)
						_current = _current->right;
				}
				else if (_current && _current->parent) {
					pointer current = _current;
					pointer tmp = _current->parent;
					while (tmp && _current == tmp->left) {
						if (tmp->parent == NULL) {
							_current = current;
							return *this;
						}
						_current = tmp;
						tmp = tmp->parent;
					}
					_current = tmp;
				}
				return *this;
			}

			RBTIterator operator++(int) {
				RBTIterator old = *this;
				_current++;
				return old;
			}

			RBTIterator operator--(int) {
				RBTIterator old = *this;
				_current--;
				return old;
			}
	};
}

# endif
