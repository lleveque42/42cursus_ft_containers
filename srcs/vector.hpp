/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:50:52 by lleveque          #+#    #+#             */
/*   Updated: 2022/09/29 19:33:41 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {


		public:
			// types:
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			// typedef implementation defined iterator; // See 23.1
			// typedef implementation defined const_iterator; // See 23.1
			typedef std::size_t size_type; // See 23.1
			// typedef implementation defined difference_type;// See 23.1
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// typedef std::reverse_iterator<iterator> reverse_iterator;
			// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			value_type *_tab;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

			size_type max_size() {
				return _alloc.max_size();
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

			// template <class InputIterator>
				// vector(InputIterator first, InputIterator last, const Allocator& = Allocator());

			// vector(const vector<T,Allocator>& x);
			~vector() {}
			// vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

			// template <class InputIterator>
			// 	void assign(InputIterator first, InputIterator last);

			// void assign(size_type n, const T& u);
			// allocator_type get_allocator() const;

			// iterators:
				// iterator begin();
				// iterator end();
				// const_iterator begin() const;
				// const_iterator end() const;
				// reverse_iterator rbegin();
				// reverse_iterator rend();
				// const_reverse_iterator rbegin() const;
				// const_reverse_iterator rend() const;

			// capacity:
				// bool empty() const;

				void reserve(size_type n) {
					value_type *new_tab;

					if (n <= _capacity)
						return ;
					if (n > max_size())
						throw std::length_error("");
					new_tab = _alloc.allocate(n);
					for (size_type i = 0; i < _capacity; i++) {
						_alloc.construct(&new_tab[i], _tab[i]);
						_alloc.destroy(&_tab[i]);
					}
					_alloc.deallocate(_tab, _capacity);
					_capacity = n;
					_tab = new_tab;
				}

				// void resize(size_type sz, T c = T());
				// size_type size() const {return _size};
				// size_type max_size() const {return };
				// size_type capacity() const {return _capacity};

			// element access:
				// reference back();
				// reference front();
				// reference at(size_type n);
				// reference operator[](size_type n);
				// const_reference back() const;
				// const_reference front() const;
				// const_reference at(size_type n) const;
				// const_reference operator[](size_type n) const;

			// 23.2.4.3 modifiers:
				// void pop_back();
				// void push_back(const T& x) {


				// }
				// void insert(iterator position, size_type n, const T& x);
				// iterator insert(iterator position, const T& x);

				// template <class InputIterator>
				// 	void insert(iterator position, InputIterator first, InputIterator last);

				// void swap(vector<T,Allocator>&);
				// iterator erase(iterator position);
				// iterator erase(iterator first, iterator last);
				// void clear();

	};

// 	template <class T, class Allocator>
// 		bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	template <class T, class Allocator>
// 		bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	template <class T, class Allocator>
// 		bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	template <class T, class Allocator>
// 		bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	template <class T, class Allocator>
// 		bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	template <class T, class Allocator>
// 		bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// 	// specialized algorithms:
// 	template <class T, class Allocator>
// 		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}

# endif
