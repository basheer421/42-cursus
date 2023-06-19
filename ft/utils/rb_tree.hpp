/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:46:25 by bammar            #+#    #+#             */
/*   Updated: 2023/06/20 02:30:03 by bammar           ###   ########.fr       */
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
		~rb_tree() {} // remmber to deallocate

		Node* get_root() const {return root;}
		allocator_type get_allocator() const {return (allocator);}

	private:

		

		Node* root;
		allocator_type allocator;

		void flip_color(Node* node)
		{
			node->color = !node->color;
			node->left->color = !node->left->color;
			node->right->color = !node->right->color;
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
			node->pr = make_pair(key, value);
			node->color = RED;
			node->left = NULL;
			node->right = NULL;
			return node;
		}


};

}