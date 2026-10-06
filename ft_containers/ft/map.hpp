/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:34:56 by bammar            #+#    #+#             */
/*   Updated: 2023/06/24 02:15:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include "utils/iterator.hpp"
#include "utils/reverse_iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/rb_tree.hpp"

namespace ft
{

	template <
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> >
> class map
{
	// Types
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type; 
		typedef Compare key_compare;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

	private:
		ft::rb_tree<key_type, mapped_type> tree;
		size_type _size;
		allocator_type allocator;
		key_compare compare;

	public:
		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			:	_size(0),
				allocator(alloc),
				compare(comp)
		{}

		map(const map& x)
		:	_size(0),
			allocator(x.allocator),
			compare(x.compare)
		{
			if (this == &x)
				return ;
			*this = x;
		}

		map& operator=(const map& x)
		{
			if (this == &x)
				return *this;
			if (!empty())
				clear();
			this->tree = x.tree;
			this->allocator = x.allocator;
			this->compare = x.compare;
			this->_size = x.size();
			return (*this);
		}

		~map() {}

		T& at(const Key& key)
		{
			return tree.get(key);
		}

		T& operator[](const Key& key)
		{
			try {
				return (at(key));
			} catch (std::out_of_range& e) {
				tree.insert(ft::make_pair(key, T()));
				++_size;
			}
			return at(key);
		}

		bool empty() const
		{
			return (tree.get_root() == NULL);
		}

		size_type size() const
		{
			return (_size);
		}

		allocator_type get_allocator() const {return allocator;}

		size_type max_size() const
		{
			return (tree.get_allocator().max_size());
		}

		// std::pair<iterator, bool> insert(const value_type& value)
		// {
		// 	tree.insert(value);
		// }

		void clear()
		{
			~tree();
			_size = 0;
		}

		void swap(map& other)
		{
			ft::rb_tree<key_type, mapped_type> tree_tmp;
			size_type _size_tmp;
			allocator_type allocator_tmp;
			key_compare compare_tmp;

			tree_tmp = tree;
			_size_tmp = _size;
			allocator_tmp = allocator;
			compare_tmp = compare;

			tree = other.tree;
			_size = other._size;
			allocator = other.allocator;
			compare = other.compare;

			other.tree = tree_tmp;
			other._size = _size_tmp;
			other.allocator = allocator_tmp;
			other.compare = compare_tmp;
		}

};

}