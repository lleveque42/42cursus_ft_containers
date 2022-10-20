/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/19 16:21:24 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>

namespace ft {


	template<typename T, class Compare, class Alloc = std::allocator<T> >
	class RBT {

		public:

			enum Color {RED, BLACK};
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef Compare compare_type;
			typedef size_t size_type;
			typedef typename allocator_type::template rebind<Node>::other node_allocator;

		private:

			struct Node {
				value_type data;
				Color color;
				Node *left;
				Node *right;
				Node *parent;

				Node(const value_type& p = value_type()) : data(p), left(NULL), right(NULL), parent(NULL) {}
			};

			Node *_root;
			Node *_last;
			size_type _size;
			node_allocator _alloc;
			compare_type _comp;

		public:

			RBT(compare_type &comp = compare_type() , allocator_type &alloc = allocator_type()) {
				_alloc = alloc;
				_comp = comp;
				_size = 0;
				_root = NULL;
				_last = NULL;
			}

			~RBT() {
				if (_size)
					// clear();

			}

			RBT search();

			ft::pair<iterator, bool> insert(const value_type &value) {
				if (!_size)
					_emptyInsert(createNode);
			}

			void erase(iterator position);


	};
}

# endif
