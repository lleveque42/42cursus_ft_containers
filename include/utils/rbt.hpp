/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:37 by lleveque          #+#    #+#             */
/*   Updated: 2022/11/11 11:42:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <memory>
# include "../iterators/rbtIterator.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/pair.hpp"
# include "../utils/swap.hpp"

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
			typedef Key key_type;
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
				_root->color = BLACK;
				_size = 1;
				_assignEnd();
				return ft::make_pair(iterator(_root), true);
			}

			Node *_newNode(const value_type &value = value_type()) {
				Node *node = _alloc.allocate(1);

				_alloc.construct(node, Node(value));
				return node;
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
				return "";
			}

			void _rightRotate(Node *x) {
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
				Node *p = NULL;
				Node *gp = NULL;

				if (!node || _size == 1)
					return ;
				if (node->parent && node->parent->color == RED) {
					p = node->parent;
					if (uncle && uncle->color == RED) {
						gp = p->parent;
						p->color = BLACK;
						uncle->color = BLACK;
						if (_root != gp)
							gp->color = RED;
						_fixInsert(gp);
					}
					else if (node->parent->parent) {
						gp = p->parent;
						if (gp && gp->left == p) {
							if (p->right == node) {
								node = p;
								_leftRotate(node);
								p = node->parent;
							}
							_rightRotate(gp);
							ft::swap(gp->color, p->color);
						}
						else if (gp && gp->right == p) {
							if (p->left == node) {
								node = p;
								_rightRotate(p);
								p = node->parent;
							}
							_leftRotate(gp);
							ft::swap(gp->color, p->color);
						}
						_root->color = BLACK;
						_fixInsert(node);
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

			Node *_maxNode() const {
				Node *max = _root;

				while (max && max->right != NULL && max->right != _end)
					max = max->right;
				return max;
			}

			Node *_minNode() const {
				Node *min = _root;

				while (min && min->left != NULL)
					min = min->left;
				return min;
			}

			Node *_sibling(Node *node) {
				if (!node->parent)
					return NULL;
				else if (node->parent->left == node && node->parent->right != _end)
					return node->parent->right;
				else if (node->parent->left != _end)
					return node->parent->left;
				return NULL;
			}

			Node *_maxSubTree(Node *root) const {
				if (root == _end)
					return NULL;
				Node *max = root;

				while (max && max->right != NULL && max->right != _end)
					max = max->right;
				return max;
			}

			Node *_minSubTree(Node *root) const {
				if (root == _end)
					return NULL;
				Node *min = root;

				while (min && min->left != NULL)
					min = min->left;
				return min;
			}

			Node *_find(const value_type &x) const {
				Node *root = _root;

				if (!root)
					return NULL;
				while (root) {
					if (_comp(root->data.first, x.first))
						root = root->right;
					else if (_comp(x.first, root->data.first))
						root = root->left;
					else
						return root;
				}
				return NULL;
			}

			void _switchChild(Node *child, Node *parent) {
				if (parent == _root) {
					_root = child;
					child->parent = NULL;
					return ;
				}
				child->parent = parent->parent;
				if (child->parent->left == parent)
					child->parent->left = child;
				else
					child->parent->right = child;
			}

			void _swapNodesValues(Node *x, Node *y) {
				key_type	key;
				key_type	*key1;
				key_type	*key2;
				value_type	tmp;

				key1 = const_cast<key_type *>(&x->data.first);
				key2 = const_cast<key_type *>(&y->data.first);

				key = *key1;
				*key1 = *key2;
				*key2 = key;

				tmp.second = x->data.second;
				x->data.second = y->data.second;
				y->data.second = tmp.second;
			}

			bool _hasRedChild(Node *node) {
				if (node->left)
					if (node->left->color == RED)
						return true;
				if (node->right)
					if (node->right->color == RED)
						return true;
				return false;
			}

			void _fixBlackRed(Node *sibling, Node *parent) {
				if (sibling == parent->left) {
					if (sibling->left && sibling->left->color == RED) {
						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						_rightRotate(parent);
					}
					else {
						sibling->right->color = parent->color;
						_leftRotate(sibling);
						_rightRotate(parent);
					}
				}
				else {
					if (sibling->right && sibling->right->color == RED) {
						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						_leftRotate(parent);
					}
					else {
						sibling->left->color = parent->color;
						_rightRotate(sibling);
						_leftRotate(parent);
					}
				}
				parent->color = BLACK;
			}

			void _fixDoubleBlack(Node *node) {
				if (node == _root)
					return;
				Node *sibling = _sibling(node);
				Node *parent = node->parent;

				if (!sibling)
					_fixDoubleBlack(parent);
				else if (sibling->color == BLACK) {
					if (_hasRedChild(sibling))
						_fixBlackRed(sibling, parent);
					else {
						sibling->color = RED;
						if (parent->color == BLACK)
							_fixDoubleBlack(parent);
						else
							parent->color = BLACK;
					}
				}
				else {
					parent->color = RED;
					sibling->color = BLACK;
					if (sibling == parent->left)
						_rightRotate(parent);
					else
						_leftRotate(parent);
					_fixDoubleBlack(node);
				}
			}

			Node *_successor(Node *node) {
				if (node->right && node->right != _end) {
					node = node->right;
					while (node->left)
						node = node->left;
					return node;
				}
				while (node->parent && node == node->parent->right)
					node = node->parent;
				return node->parent;
			}

			Node *_deleteNoChild(Node *node, Node *sibling, Node *parent) {
					Node *successor = _successor(node);

					if (node == _root)
						_root = NULL;
					else {
						if (node->color == BLACK)
							_fixDoubleBlack(node);
						else if (sibling)
							sibling->color = RED;
						if (node == parent->left)
							parent->left = NULL;
						else
							parent->right = NULL;
					}
					_destroyNode(node);
					--_size;
					_assignEnd();
					return successor;
			}

			Node *_deleteOneChild(Node *node, Color ogColor) {
					Node *child;

					if (!node->left) {
						child = node->right;
						_switchChild(child, node);
					}
					else {
						child = node->left;
						_switchChild(child, node);
					}
					_destroyNode(node);
					if (child != _root && ogColor == BLACK && child->color == BLACK)
						_fixDoubleBlack(child);
					else
						child->color = BLACK;
					--_size;
					_assignEnd();
					return child;
			}

			Node *_deleteNode(Node *node) {
				Node *sibling = _sibling(node);
				Node *parent = node->parent;
				Color ogColor =  node->color;

				if (!node->left && !node->right)
					return _deleteNoChild(node, sibling, parent);
				else if (!node->left || (!node->right || node->right == _end))
					return _deleteOneChild(node, ogColor);
				else {
					Node *min = _minSubTree(node->right);
					_swapNodesValues(node, min);
					_deleteNode(min);
				}
				return node;
			}

		public:

			RBT(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) {
				_alloc = alloc;
				_comp = comp;
				_size = 0;
				_end = _newNode();
				_root = _end;
			}

 /////////////////////////////////////////////////////////////////////////
			void printNode(Node *node) {
				std::cout << "node: " << node << std::endl;
				std::cout << "first: " << node->data.first << std::endl;
				std::cout << "second: " << node->data.second << std::endl;
				std::cout << "color: " << node->color << std::endl;
				std::cout << "left: " << node->left << std::endl;
				std::cout << "right: " << node->right << std::endl;
				if (node->parent)
					std::cout << "NODE PARENT OK\n";
				std::cout << "parent first: " << node->parent->data.first << std::endl;
			}
 /////////////////////////////////////////////////////////////////////////

			~RBT() {
				if (_size)
					clear();
				_destroyNode(_root);
			}

			compare_type comp() const {
				return _comp;
			}

			iterator begin() {
				return iterator(_minNode());
			}

			const_iterator begin() const {
				return const_iterator(_minNode());
			}

			iterator end() {
				return iterator(_end);
			}

			const_iterator end() const {
				return const_iterator(_end);
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

			void swapNodes(const value_type &x, const value_type &y) {
				Node *xx = _find(x);
				Node *yy = _find(y);

				_swapNodes(xx, yy);
			}

			size_type eraseUnique(const value_type &x) {
				Node *toErase;

				if (empty())
					return 0;
				toErase = _find(x);
				if (!toErase)
					return 0;
				if (_size == 1) {
					clear();
					return 1;
				}
				_deleteNode(toErase);
				return 1;
			}

			void eraseMulti(iterator first, iterator last) {
				size_type i = 0;
				Node *toDelete = first.base();

				if (first == begin() && last == end()) {
					clear();
					return ;
				}
				for (iterator it = first; it != last; ++it)
					++i;
				for (; i; --i)
					toDelete = _deleteNode(toDelete);
				// _deleteNode(toDelete);
			}

			void swap(RBT &newTree) {
				ft::swap(_root, newTree._root);
				ft::swap(_size, newTree._size);
				ft::swap(_end, newTree._end);
				ft::swap(_alloc, newTree._alloc);
				ft::swap(_comp, newTree._comp);
			}

			void clear() {
				_clear(_root);
				_root = _end;
				_size = 0;
			}

			iterator find(const value_type &x) {
				Node *to_find = _find(x);

				if (to_find)
					return iterator(to_find);
				return iterator(_end);
			}

			const_iterator find(const value_type &x) const {
				Node *to_find = _find(x);

				if (to_find)
					return const_iterator(to_find);
				return const_iterator(_end);
			}

			size_type count(const value_type &x) const {
				if (_find(x))
					return 1;
				return 0;
			}

			iterator lower_bound(const value_type &x) {
				iterator it = begin();
				iterator ite = end();

				for (; it != ite; it++)
					if (!_comp(it->first, x.first))
						return it;
				return ite;
			}

			const_iterator lower_bound(const value_type &x) const {
				const_iterator it = begin();
				const_iterator ite = end();

				for (; it != ite; it++)
					if (!_comp(it->first, x.first))
						return it;
				return ite;
			}

			iterator upper_bound(const value_type &x) {
				iterator it = begin();
				iterator ite = end();

				for (; it != ite; it++)
					if (_comp(x.first, it->first))
						return it;
				return ite;
			}

			const_iterator upper_bound(const value_type &x) const {
				const_iterator it = begin();
				const_iterator ite = end();

				for (; it != ite; it++)
					if (_comp(x.first, it->first))
						return it;
				return ite;
			}

////////////////////////////////////////////////////////////////////////////////////////

			// void	printHelper(Node *root, std::string indent, bool last) {
			// 	if (root != NULL) {
			// 		std::cout << indent;
			// 		if (last) {
			// 			std::cout << "R---- ";
			// 			indent += "   ";
			// 		}
			// 		else {
			// 			std::cout << "L---- ";
			// 			indent += "|  ";
			// 		}

			// 		std::string black = "\033[1;30mBLACK\033[0m";
			// 		std::string red = "\033[1;31mRED\033[0m";
			// 		if (root->color == RED)
			// 			std::cout << root->data.first << " (" << "\033[1;47m" << red << ")" << std::endl;
			// 		else
			// 			std::cout << root->data.first << " (" << "\033[1;47m" << black << ")" << std::endl;
			// 		printHelper(root->left, indent, false);
			// 		printHelper(root->right, indent, true);
			// 	}
			// }

			// void	printRedBlackTree() {
			// 	if (_root)
			// 		printHelper(_root, "", true);
			// }
	};
}

# endif
