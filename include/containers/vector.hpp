/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:50:52 by lleveque          #+#    #+#             */
/*   Updated: 2022/11/11 20:46:55 by lleveque         ###   ########.fr       */
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
# include "../utils/swap.hpp"

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {

		public:
			// types:
				typedef T										value_type;
				typedef size_t									size_type;
				typedef Allocator								allocator_type;
				typedef ptrdiff_t								difference_type;
				typedef typename Allocator::reference			reference;
				typedef typename Allocator::const_reference		const_reference;
				typedef typename Allocator::pointer				pointer;
				typedef typename Allocator::const_pointer		const_pointer;
				typedef ft::vectorIterator<pointer>				iterator;
				typedef ft::vectorIterator<const_pointer>		const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			size_type _size;
			size_type _capacity;
			value_type *_tab;
			allocator_type _alloc;

			size_type _newSize(size_type more) {
				more += _size;
				if (more > _capacity * 2)
					return more;
				else
					return _capacity * 2;
			}

		public:

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
						insert(begin(), first, last);
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
					if (*this == src)
						return *this;
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
						throw std::length_error("vector::assign");
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
					return _size == 0;
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
						throw std::length_error("vector::resize");
					if (sz < _size)
						for (size_type i = sz; i < _size; i++)
							_alloc.destroy(&_tab[i]);
					else {
						if (_size * 2 > sz)
							reserve(_size * 2);
						else
							reserve(sz);
						for (size_type i = _size; i < sz; i++)
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
						throw std::out_of_range("vector::at");
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
						throw std::out_of_range("vector::at");
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
					if (_size == _capacity)
						reserve(_newSize(1));
					_alloc.construct(&_tab[_size], x);
					_size++;
				}

				iterator insert(iterator position, const value_type &x) {
					size_type pos = position - begin();

					if (_size + 1 > _capacity)
						reserve(_newSize(1));
					if (_size > 0) {
						_alloc.construct(&_tab[_size], _tab[_size - 1]);
						for (size_type i = _size - 1; i > pos; i--)
							_tab[i] = _tab[i - 1];
						_tab[pos] = x;
					}
					else
						_alloc.construct(&_tab[0],  x);
					_size++;
					return begin() + pos;
				}

				void insert(iterator position, size_type n, const value_type &x) {
					size_type pos = position - begin();

					if (n < 1)
						return ;
					if (_size + n > _capacity)
						reserve(_newSize(n));
					for (size_type i = _size - 1; i < _size + n - 1; ++i)
						_alloc.construct(&_tab[i + 1], _tab[i - n + 1]);
					_size += n;
					for (size_type i = _size - n - 1; i >= pos + n; i--)
						_tab[i] = _tab[i - n];
					for (; n > 0; n--)
						_tab[pos + n - 1] = x;
				}

				template <class InputIterator>
					void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
						size_type pos = position - begin();
						size_type diff = 0;
						size_type toMove = 0;

						for (InputIterator tmp = first; tmp != last; tmp++)
							diff++;
						if (_size + diff > _capacity)
							reserve(_size + diff);
						if (_size > 0) {
							for (size_type i = _size; i < _size + diff; ++i)
								_alloc.construct(&_tab[i], _tab[i - 1]);
							toMove = _size - pos;
							_size += diff;
							for (size_type i = 1; toMove > 0; --toMove) {
								_tab[_size - i] = _tab[_size - diff - i];
								++i;
							}
							last--;
							for (size_type i = diff - 1; i != 0; i--)
								_tab[pos + i] = *last--;
							_tab[pos] = *last--;
						}
						else {
							for (size_type i = 0; i < diff; i++)
								_alloc.construct(&_tab[i], *first++);
							_size += diff;
						}
					}

				void swap(vector &x) {
					if (*this != x) {
						ft::swap(_size, x._size);
						ft::swap(_capacity, x._capacity);
						ft::swap(_tab, x._tab);
					}
				}

				iterator erase(iterator position) {
					size_type pos = position - begin();
					size_type toMove = 0;

					if (position + 1 == end()) {
						pop_back();
						return end();
					}
					toMove = _size - pos;
					_alloc.destroy(&_tab[pos]);
					_alloc.construct(&_tab[pos], _tab[pos + 1]);
					toMove--;
					for (size_type i = pos + 1; toMove > 1; toMove--) {
						_tab[i] = _tab[i + 1];
						i++;
					}
					_alloc.destroy(&_tab[_size - 1]);
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
			return !(x < y);
		}

	template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			return !(y < x);
		}

	// specialized algorithms:
		template <class T, class Allocator>
			void swap(vector<T, Allocator>& x, vector<T, Allocator>& y) {
				x.swap(y);
			}
}

# endif
