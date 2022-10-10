/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:50:52 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/10 12:36:05 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include "../iterators/vectorIterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {


		public:
			// types:
				typedef T value_type;
				typedef std::size_t size_type;
				typedef Allocator allocator_type;
				typedef ptrdiff_t difference_type;
				typedef typename Allocator::reference reference;
				typedef typename Allocator::const_reference const_reference;
				typedef typename Allocator::pointer pointer;
				typedef typename Allocator::const_pointer const_pointer;
				typedef ft::vectorIterator<pointer> iterator;
				typedef ft::vectorIterator<const_pointer> const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			size_type _size;
			size_type _capacity;
			value_type *_tab;
			allocator_type _alloc;

		public:

			//TEMP
			void print() {
				for (size_type i = 0; i < _size; i++)
					std::cout << "vector[" << i << "] = " << _tab[i] << std::endl;
			}
			//TEMP

			// construct/copy/destroy:
				explicit vector(const allocator_type &alloc = allocator_type()) {
					_capacity = 0;
					_size = 0;
					_alloc = alloc;
					_tab = _alloc.allocate(0);
				}

				explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) {
					_capacity = n;
					_size = n;
					_alloc = alloc;
					_tab = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_tab[i], value);
				}

				template <class InputIterator>
					vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
						_alloc = alloc;
						_capacity = 0;
						_size = 0;
						_tab = _alloc.allocate(0);
						assign(first, last);
					}

				vector(const vector &other) {
					_alloc = other._alloc;
					_capacity = other._capacity;
					_size = other._size;
					_tab = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_tab[i],  other._tab[i]);
				}

				~vector() {
					clear();
					_alloc.deallocate(_tab, _capacity);
				}

				vector &operator=(const vector &src) {
					if (this == &src)
						return * this;
					clear();
					_alloc.deallocate(_tab, _capacity);
					_alloc = src._alloc;
					_capacity = src._capacity;
					_size = src._size;
					_tab = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_tab[i], src._tab[i]);
					return *this;
				}

			template <class InputIterator>
				void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
					clear();
					for (; first != last; first++)
						push_back(*first);
				}

			void assign(size_type n, const value_type &u) {
				if (n > max_size())
						throw std::length_error("cannot create std::vector larger than max_size()");
				clear();
				resize(n, u);
				for (size_type i = 0; i < _size; i++)
					_tab[i] = u;
			}

			allocator_type get_allocator() const {
				return _alloc;
			}

			// iterators:
				iterator begin() {
					return iterator(_tab);
				}

				iterator end() {
					return iterator(_tab + _size);
				}

				const_iterator begin() const {
					return const_iterator(_tab);
				}

				const_iterator end() const {
					return const_iterator(_tab + _size);
				}

				reverse_iterator rbegin() {
					return reverse_iterator(end());
				}

				reverse_iterator rend() {
					return reverse_iterator(begin());
				}

				const_reverse_iterator rbegin() const {
					return const_reverse_iterator(end());
				}

				const_reverse_iterator rend() const {
					return const_reverse_iterator(begin());
				}

			// capacity:
				bool empty() const {
					return _size == 0 ? true : false;
				}

				void reserve(size_type n) {
					value_type *newTab;

					if (n <= _capacity)
						return ;
					if (n > max_size())
						throw std::length_error("vector::reserve");
					newTab = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&newTab[i], _tab[i]);
						_alloc.destroy(&_tab[i]);
					}
					_alloc.deallocate(_tab, _capacity);
					_capacity = n;
					_tab = newTab;
				}

				void resize(size_type sz, value_type c = value_type()){
					if (sz > max_size())
						throw std::length_error("vector::_M_fill_insert");
					if (sz < _size)
						for (size_type i = sz; i < _size; i++)
							_alloc.destroy(&_tab[i]);
					else {
						reserve(sz);
						for (size_type i = _size - 1; i < sz; i++)
							_alloc.construct(&_tab[i], c);
					}
					_size = sz;
				}

				size_type size() const {
					return _size;
				}

				size_type max_size() const {
					return _alloc.max_size();
				}

				size_type capacity() const {
					return _capacity;
				}

			// element access:
				reference back() {
					return _tab[_size - 1];
				}

				reference front() {
					return _tab[0];
				}

				reference at(size_type n) {
					if (n >= _size)
						throw std::out_of_range("vector::_M_range_check: __n (which is");
					return _tab[n];
				}

				reference operator[](size_type n) {
					return _tab[n];
				}

				const_reference back() const {
					return _tab[_size - 1];
				}

				const_reference front() const {
					return _tab[0];
				}

				const_reference at(size_type n) const {
					if (n >= _size)
						throw std::out_of_range("vector::_M_range_check: __n (which is");
					return _tab[n];
				}

				const_reference operator[](size_type n) const {
					return _tab[n];
				}

			// 23.2.4.3 modifiers:
				void pop_back() {
					if (_size > 0)
						_alloc.destroy(&_tab[--_size]);
				}

				void push_back(const value_type &x) {
					if (_capacity == 0)
						reserve(1);
					if (_size + 1 > _capacity)
						reserve(_capacity * 2);
					_alloc.construct(&_tab[_size], x);
					_size++;
				}

				iterator insert(iterator position, const value_type &x) {
					size_type pos = position - begin();

					if (_size + 1 > _capacity)
						reserve(_capacity * 2);
					_alloc.construct(&_tab[_size], _tab[_size - 1]);
					for (size_type i = _size - 1; i > pos; i--)
						_tab[i] = _tab[i - 1];
					_tab[pos] = x;
					_size++;
					return begin() + pos;
				}

				void insert(iterator position, size_type n, const value_type &x) {
					size_type pos = position - begin();

					if (_size + n > _capacity)
						reserve(_capacity + n + 1);
					for (size_type i = _size; i < _size + n ; i++)
						_alloc.construct(&_tab[i + 1], _tab[i]);
					_size += n;
					for (size_type i = _size; i > pos; i--)
						_tab[i] = _tab[i - n];
					for (; n > 0; n--)
						_tab[pos + n - 1] = x;
				}

				template <class InputIterator>
					void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
						while (first != last)
							insert(position++, *first++);
					}

				// void swap(vector<value_type,Allocator>&) {
				// 	// value_type = tmp;
				// }

				iterator erase(iterator position) {
					size_type pos = position - begin();

					for (size_type i = pos; i < _size; i++)
						_tab[i] = _tab[i + 1];
					_alloc.destroy(&_tab[_size]);
					_size--;
					return begin() + pos;
				}

				iterator erase(iterator first, iterator last) {
					while (first != last)
						erase(--last);
					return last;
				}

				void clear() {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_tab[i]);
					_size = 0;
				}

	};

	template <class T, class Allocator>
		bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			if (x.size() != y.size())
				return false;
			for (size_t i = 0; i < x.size(); i++)
				if (x[i] != y[i])
					return false;
			return true;
		}

	template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			return !(x == y);
		}

	template <class T, class Allocator>
		bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}

	template <class T, class Allocator>
		bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			return y < x;
		}

	template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			if (x == y || x > y)
				return true;
			return false;
		}

	template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			if (x == y || x < y)
				return true;
			return false;
		}

// 	// specialized algorithms:
// 	template <class T, class Allocator>
// 		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}

# endif
