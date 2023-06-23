/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:46:25 by bammar            #+#    #+#             */
/*   Updated: 2023/06/23 14:24:51 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * This is a left leaning red-black tree in c++ (c++98).
 * It is made to fit the needs of a std::map clone implementation.
*/

#pragma once

#include <memory>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

namespace ft
{

enum COLOR {BLACK, RED};

template <typename Key, typename T>
struct Node
{
	ft::pair<Key, T> pr; // pair
	COLOR color;
	Node* left;
	Node* right;
};

template <
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator< ft::Node<Key, T> >
> // remember to add compare for iterator
class rb_tree
{
	// Types
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::size_type	size_type;
		typedef ft::Node<key_type, mapped_type> Node;

		rb_tree(const allocator_type& alloc = allocator_type())
		:	root(NULL),
			allocator(alloc)
		{}
		
		rb_tree(const rb_tree& src):root(src.root), allocator(src.allocator) {}
		
		rb_tree& operator=(const rb_tree& src)
		{
			if (this == &src)
				return *this;
			root = src.get_root();
			allocator = src.get_allocator();

		}
		
		~rb_tree() {destroy_tree(root);}

		Node* get_root() const {return root;}
		allocator_type get_allocator() const {return (allocator);}

		mapped_type get(key_type key)
		{
			mapped_type* value = get(root, key);
			if (value)
				return value;
			throw std::out_of_range("Not inside");
		}

		bool containes(key_type key) const
		{
			return (get(root, key) != NULL);
		}

		void insert(ft::pair<key_type, mapped_type> h)
		{
			root = insert_node(root, h.first, h.second);
			if (root)
				root->color = BLACK;
		}

		void remove(Node* node, key_type key)
		{
			// if (!containes(root, key))
			// 	return ;
			// if (!is_red(root->left) && !is_red(root->right))
			// 	root->color = RED;
			node = remove_node(node, key);
			if (node)
				node->color = BLACK;
		}


		// FOR DEBUGGING
		void printInorder() {
			inorderTraversal(root);
		}

		// Inorder traversal to print the tree
		void inorderTraversal(Node* node) {
			if (node == NULL)
				return;
			inorderTraversal(node->left);
			std::cout << "(" << node->pr.first << ", " << node->pr.second << ")\n";
			inorderTraversal(node->right);
		}

	private:

		Node* root;
		allocator_type allocator;

		bool is_less(key_type k1, key_type k2)
		{
			Compare cmp = Compare();
			return cmp(k1, k2);
		}


		mapped_type* get(Node* h, mapped_type key) const
		{
			while (h)
			{
				if (h->pr.first == key)
					return (&(h->pr.second));
				if (is_less(key, h->pr.first))
					h = h->left;
				else
					h = h->right;
			}
			return (NULL);
		}

		void flip_color(Node* node)
		{
			node->color = (node->color == RED ? BLACK : RED);
			node->left->color = (node->left->color == RED ? BLACK : RED);
			node->right->color = (node->right->color == RED ? BLACK : RED);
		}

		Node* rotate_left(Node* left)
		{
			Node *right;

			if (!left)
				return NULL;
			right = left->right;
			left->right = right->left;
			right->left = left;
			right->color = left->color;
			left->color = RED;
			return (right);
		}

		Node* rotate_right(Node* right)
		{
			Node* left;

			if (!right)
				return (NULL);
			left = right->left;
			right->left = left->right;
			left->right = right;
			left->color = right->color;
			right->color = RED;
			return (left);
		}

		Node* make_node(key_type key, mapped_type value)
		{
			Node* node;

			node = allocator.allocate(1);
			allocator.construct(node, Node());
			node->pr = ft::make_pair(key, value);
			node->color = RED;
			node->left = NULL;
			node->right = NULL;
			return node;
		}

		bool is_red(Node* h)
		{
			if (h == NULL)
				return false;
			return (h->color == RED);
		}

		Node* insert_node(Node* h, key_type key, mapped_type value)
		{
			// Normal BST insertion.
			if (h == NULL)
				return make_node(key, value);
			key_type k = h->pr.first;
			if (key < k)
				h->left = insert_node(h->left, key, value);
			else if (key > k)
				h->right = insert_node(h->right, key, value);
			else
				return h;

			// LLRB tree part
			if (is_red(h->right) && !is_red(h->left))
				h = rotate_left(h);
			if (is_red(h->left) && is_red(h->left->left))
				h = rotate_right(h);
			if (is_red(h->left) && is_red(h->right))
				flip_color(h);
			return h;
    	}

		Node* move_red_left(Node* h)
		{
			flip_color(h);
			if (h && h->right && is_red(h->right->left))
			{
				h->right = rotate_right(h->right);
				h = rotate_left(h);
				flip_color(h);
			}
			return h;
		}

		Node* move_red_right(Node* h)
		{
			flip_color(h);
			if (h && h->left && is_red(h->left->left))
			{
				h = rotate_right(h);
				flip_color(h);
			}
			return h;
		}
		
		Node* fix(Node* h)
		{
			if (is_red(h->right))
				h = rotate_left(h);
			if (is_red(h->left) && is_red(h->left->left))
				h = rotate_right(h);
			if (is_red(h->left) && is_red(h->right))
				flip_color(h);
			return h;
		}

		Node* find_min(Node* h)
		{
			if (!h)
				return NULL;
			while (h->left)
				h = h->left;
			return h;
		}

		Node*  delete_min(Node* h)
		{
			if (!h->left)
				return (NULL);
			if (!h->left)
			{
				allocator.destroy(h);
				allocator.deallocate(h, 1);
				return (NULL);
			}
			if (!is_red(h->left) && !is_red(h->left->left))
				h = move_red_left(h);
			h->left = delete_min(h->left);
			return fix(h);
		}

		Node* remove_node(Node* h, key_type key)
		{
			if (!h)
				return NULL;
			if (key < h->pr.first)
			{
				if (h->left)
				{
					if (!is_red(h->left) && !is_red(h->left->left))
						h = move_red_left(h);
					h->left = remove_node(h->left, key);
				}
			}
			else
			{
				if (is_red(h->left))
					h = rotate_right(h);


				if (key == h->pr.first && !h->right)
				{
					allocator.destroy(h);
					allocator.deallocate(h, 1);
					return NULL;
				}
				if (h->right)
				{
					if (!is_red(h->right) && !is_red(h->right->left))
						h = move_red_right(h);

					if (key == h->pr.first)
					{
						Node* tmp = find_min(h->right);
						h->pr.first = tmp->pr.first;
						h->pr.second = tmp->pr.second;
						h->right = delete_min(h->right);
					}
					else
						h->right = remove_node(h->right, key);
				}
			}
			return fix(h);
		}

		void destroy_tree(Node* node)
		{
			if (!node)
				return ;
			destroy_tree(node->left);
			destroy_tree(node->right);
			allocator.destroy(node);
			allocator.deallocate(node, 1);
		}

};

}