/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/29 15:50:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>
# include "../iterators/rbtIterator.hpp"

enum Color {RED, BLACK};

namespace ft {

	template<typename T, typename Key, class Compare = std::less<Key>, class Alloc = std::allocator<T> >
	class RBT {

		private:

			struct Node {
				T data;
				Color color;
				Node *left;
				Node *right;
				Node *parent;

				Node(const T &p = T()) : data(p), color(RED), left(NULL), right(NULL), parent(NULL) {}
			};

		public:

			typedef T value_type;
			typedef Alloc allocator_type;
			typedef Compare compare_type;
			typedef size_t size_type;
			typedef typename allocator_type::template rebind<Node>::other node_allocator;
			typedef ft::RBTIterator<value_type, Node> iterator;
			typedef ft::RBTIterator<const value_type, Node> const_iterator;

			Node *_root;
			Node *_end;
			size_type _size;
			node_allocator _alloc;
			compare_type _comp;

		private:

			ft::pair<iterator, bool> _emptyInsert(Node *newNode) {
				_root = newNode;
				_root->right = _end;
				_root->left = NULL;
				_end->parent = _root;
				_root->color = BLACK;
				_size = 1;
				return ft::make_pair(iterator(_root), true);
			}

			Node *_newNode(const value_type &value = value_type()) {
				Node *node = _alloc.allocate(1);

				_alloc.construct(node, Node(value));
				return node;
			}

			Node *_maxNode() {
				Node *tmp = _root;

				while (tmp && tmp->right != NULL && tmp->right != _end)
					tmp = tmp->right;
				return tmp;
			}

			Node *_getUncle(Node *node) {
				if (!node)
					return NULL;
				if (node->parent && node->parent->parent) {
					if (node->parent == node->parent->parent->right)
						return node->parent->parent->left;
					if (node->parent->parent->right != _end)
						return node->parent->parent->right;
				}
				return NULL;
			}

			std::string _insertCase(Node *node) {
				if (node->parent->parent && node->parent->parent->left == node->parent) {
					if (node->parent->left == node)
						return "LLC";
					else
						return "LRC";
				}
				else if (node->parent->parent && node->parent->parent->right == node->parent) {
					if (node->parent->right == node)
						return "RRC";
					else
						return "RLC";
				}
				return "OK";
			}

			void _rightRotate(Node *x) {
				std::cout << "right rotate\n";
				Node *y = x->left;

				x->left = y->right;
				if (x->left != NULL)
					x->left->parent = x;
				y->parent = x->parent;
				if (y->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					y->parent->right = y;
				else if (x == x->parent->left)
					y->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void _leftRotate(Node *x) {
				std::cout << "left rotate\n";
				Node *y = x->right;

				x->right = y->left;
				if (x->right != NULL)
					x->right->parent = x;
				y->parent = x->parent;
				if (y->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					y->parent->right = y;
				else if (x == x->parent->left)
					y->parent->left = y;
				y->left = x;
				x->parent = y;
			}

			void _fixInsert(Node *node) {
				Node *uncle = _getUncle(node);
				std::cout << "fix insert" << std::endl;
				if (!node || _size == 1)
					return ;
				if (node->parent && node->parent->color == RED) {
					if (uncle && uncle->color == RED) {
						node->parent->color = BLACK;
						uncle->color = BLACK;
						node->parent->parent->color = RED;
						// _root->color = BLACK;
						// node = node->parent->parent;
						_fixInsert(node->parent->parent);
					}
					else {
						std::string insertCase = _insertCase(node);
						if (insertCase == "LLC") {
							std::cout << "LLC" << std::endl;
							_rightRotate(node->parent->parent);
							ft::swap(node->parent->color, node->parent->right->color);
						}
						else if (insertCase == "LRC") {
							std::cout << "LRC" << std::endl;
							_leftRotate(node->parent);
							_rightRotate(node->parent);
							ft::swap(node->color, node->right->color);
						}
						else if (insertCase == "RRC") {
							std::cout << "RRC" << std::endl;
							_leftRotate(node->parent->parent);
							ft::swap(node->parent->color, node->parent->left->color);
						}
						else if (insertCase == "RLC") {
							std::cout << "RLC" << std::endl;
							_rightRotate(node->parent);
							_leftRotate(node->parent);
							ft::swap(node->color, node->left->color);
						}
						// _root->color = BLACK;
						if (insertCase != "OK")
							_fixInsert(node->parent);
					}
				}
				_root->color = BLACK;
			}

			void _assignEnd() {
				Node *maxNode = _maxNode();
				maxNode->right = _end;
				_end->parent = maxNode;
				_end->right = NULL;
				_end->left = NULL;
				_end->color = BLACK;
			}

			void _destroyNode(Node *destroyed) {
				_alloc.destroy(destroyed);
				_alloc.deallocate(destroyed, 1);
			}

			void _clear(Node *destroyed) {
				if (!destroyed || destroyed == _end)
					return ;
				_clear(destroyed->left);
				_clear(destroyed->right);
				_destroyNode(destroyed);
			}

		public:

			RBT(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) {
				_alloc = alloc;
				_comp = comp;
				_size = 0;
				_end = _newNode();
				_root = _end;
			}

			void printNode(Node *node) {
				std::cout << "node: " << node << std::endl;
				std::cout << "first: " << node->data.first << std::endl;
				std::cout << "second: " << node->data.second << std::endl;
				std::cout << "color: " << node->color << std::endl;
				std::cout << "left: " << node->left << std::endl;
				std::cout << "right: " << node->right << std::endl;
			}

			~RBT() {
				if (_size)
					clear();
				_destroyNode(_root);
			}

			bool empty() const {
				return _size == 0;
			}

			size_type size() const {
				return _size;
			}

			size_type max_size() const {
				return _alloc.max_size();
			}

			ft::pair<iterator, bool> insert(const value_type &value) {
				Node *newNode = _newNode(value);
				Node *root = _root;
				Node *newParent = NULL;

				if (empty())
					return _emptyInsert(newNode);
				while (root != NULL && root != _end) {
					newParent = root;
					if (_comp(root->data.first, value.first))
						root = root->right;
					else if (_comp(value.first, root->data.first))
						root = root->left;
					else {
						_destroyNode(newNode);
						_assignEnd();
						return ft::make_pair(iterator(root), false);
					}
				}
				newNode->parent = newParent;
				if (_comp(newParent->data.first, value.first))
					newParent->right = newNode;
				else if (_comp(value.first, newParent->data.first))
					newParent->left = newNode;
				_fixInsert(newNode);
				_assignEnd();
				_size++;
				return ft::make_pair(iterator(newNode), true);
			}

			// iterator insert(iterator position, const value_type &x);
			// template <class InputIterator>
			// 	void insert(InputIterator first, InputIterator last);
			// void erase(iterator position);
			// size_type erase(const key_type &x);
			// void erase(iterator first, iterator last);
			// void swap(map<key_type, mapped_type, key_compare, allocator_type>&);

			void clear() {
				// printNode(_root);
				_clear(_root);
				_root = _end;
				_size = 0;
			}

////////////////////////////////////////////////////////////////////////////////////////

			void	printHelper(Node *root, std::string indent, bool last) {
				if (root != NULL) {
					std::cout << indent;
					if (last) {
						std::cout << "R---- ";
						indent += "   ";
					}
					else {
						std::cout << "L---- ";
						indent += "|  ";
					}

					std::string black = "\033[1;30mBLACK\033[0m";
					std::string red = "\033[1;31mRED\033[0m";
					if (root->color == RED)
						std::cout << root->data.first << " (" << "\033[1;47m" << red << ")" << std::endl;
					else
						std::cout << root->data.first << " (" << "\033[1;47m" << black << ")" << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
			}

			void	print_red_black_tree() {
				if (_root)
					printHelper(_root, "", true);
			}
	};
}

# endif
