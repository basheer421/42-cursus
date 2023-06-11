/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:48:05 by bammar            #+#    #+#             */
/*   Updated: 2023/06/12 00:49:50 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <cstddef>

namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector
{

	private:
		T*			data;
		std::size_t	_size;
		std::size_t	_capacity;
		Alloc allocator;

	public:

		typedef T value_type;
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;

		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
		
		// iterators TODO

		explicit vector (const allocator_type& alloc = allocator_type()):
			data(NULL),
			_size(0),
			_capacity(0),
			allocator(alloc)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()); // TODO
		template <class InputIterator> vector (InputIterator first,
			InputIterator last, const allocator_type& alloc = allocator_type());
			// TODO

		~vector(); // TODO
		vector(const vector& src); // TODO
		vector& operator = (const vector& src); // TODO
		// TODO


		/* Capacity: */
		size_type size() const {return _size;}
		size_type max_size() const {return allocator.max_size();}
		// resize TODO
		size_type capacity() const {return _capacity;}
		bool empty() const {return (size == 0);}
		// reserve TODO
		// shrink_to_fit TODO


	

};

}
