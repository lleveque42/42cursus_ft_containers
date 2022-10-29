/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:10:33 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/27 17:24:43 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iostream>
# include "../utils/pair.hpp"
# include "../utils/rbt.hpp"
# include "../iterators/reverse_iterator.hpp"

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:
			// types:
				typedef T										mapped_type;
				typedef Key										key_type;
				typedef ft::pair<const key_type, mapped_type>	value_type;
				typedef size_t									size_type;
				typedef ptrdiff_t								difference_type;
				typedef Compare									key_compare;
				typedef Allocator								allocator_type;
				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef typename ft::RBT<value_type, key_type, key_compare, allocator_type> tree_type;
				typedef typename tree_type::iterator iterator;
				typedef typename tree_type::const_iterator const_iterator;
				typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare : public std::binary_function<value_type, value_type,bool> {

				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}

				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

		private:
			tree_type _tree;

		public:
			// 23.3.1.1 construct/copy/destroy:
				explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type()) : _tree() {
					static_cast<void>(comp);
					static_cast<void>(alloc);
				}

				// template <class InputIterator>
					// map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

				// map(const map<key_type, mapped_type, key_compare, allocator_type> &src) {
					// this =
				// }

				~map() {}

				// map<key_type, mapped_type, key_compare, allocator_type> &operator=(const map<key_type, mapped_type, key_compare, allocator_type> &src) {
					// if (*this == src)
						// return *this;
					// clear();
				// }

			// iterators:
			// 	iterator begin();
			// 	const_iterator begin() const;
			// 	iterator end();
			// 	const_iterator end() const;
			// 	reverse_iterator rbegin();
			// 	const_reverse_iterator rbegin() const;
			// 	reverse_iterator rend();
			// 	const_reverse_iterator rend() const;

			// capacity:
				bool empty() const {
					return _tree.empty();
				}

				size_type size() const {
					return _tree.size();
				}

				size_type max_size() const {
					return _tree.max_size();
				}

			// // 23.3.1.2 element access:
			// 	mapped_type& operator[](const key_type& x);

			// modifiers:
				ft::pair<iterator, bool> insert(const value_type &x) {
					return _tree.insert(x);
				}
			// 	iterator insert(iterator position, const value_type &x);
			// 	template <class InputIterator>
			// 		void insert(InputIterator first, InputIterator last);
			// 	void erase(iterator position);
			// 	size_type erase(const key_type &x);
			// 	void erase(iterator first, iterator last);
			// 	void swap(map<key_type, mapped_type, key_compare, allocator_type>&);

				void clear() {
					if (!_tree.empty())
						_tree.clear();
				}

			// // observers:
			// 	key_compare key_comp() const;
			// 	value_compare value_comp() const;

			// // 23.3.1.3 map operations:
			// 	iterator find(const key_type &x);
			// 	const_iterator find(const key_type &x) const;
			// 	size_type count(const key_type &x) const;
			// 	iterator lower_bound(const key_type &x);
			// 	const_iterator lower_bound(const key_type &x) const;
			// 	iterator upper_bound(const key_type &x);
			// 	const_iterator upper_bound(const key_type &x) const;
			// 	ft::pair<iterator,iterator> equal_range(const key_type &x);
			// 	ft::pair<const_iterator,const_iterator> equal_range(const key_type &x) const;

				void printMap() {
					_tree.print_red_black_tree();
				}
			};

	template <class Key, class T, class Compare, class Allocator>
		bool operator==(const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	template <class Key, class T, class Compare, class Allocator>
		bool operator< (const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	template <class Key, class T, class Compare, class Allocator>
		bool operator!=(const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	template <class Key, class T, class Compare, class Allocator>
		bool operator> (const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	template <class Key, class T, class Compare, class Allocator>
		bool operator>=(const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	template <class Key, class T, class Compare, class Allocator>
		bool operator<=(const map<Key,T,Compare,Allocator> &x, const map<Key,T,Compare,Allocator> &y);

	// specialized algorithms:
	template <class Key, class T, class Compare, class Allocator>
		void swap(map<Key,T,Compare,Allocator> &x, map<Key,T,Compare,Allocator> &y);
}

# endif
