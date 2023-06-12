/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:48:05 by bammar            #+#    #+#             */
/*   Updated: 2023/06/12 16:51:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <cstddef>
#include <stdexcept>

namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	// Types
	public:
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;

		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;

	private:
		pointer			_data;
		std::size_t	_size;
		std::size_t	_capacity;
		Alloc allocator;


		class out_of_range : public std::exception {};

	public:
		
		// iterators TODO

		explicit vector (const allocator_type& alloc = allocator_type()):
			_data(NULL),
			_size(0),
			_capacity(0),
			allocator(alloc)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
			:	_size(n),
				_capacity(n),
				allocator(alloc)
		{
			_data = allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				allocator.construct(&(_data[i]), val);
		}
		
		vector(const vector& src); // TODO

		vector& operator = (const vector& src); // TODO
		// TODO

		template <class InputIterator> vector (InputIterator first,
			InputIterator last, const allocator_type& alloc = allocator_type());
			// TODO

		~vector()
		{
			if (!_data)
				return ;
			for (size_type i = 0; i < _size; i++)
				allocator.destroy(&(_data[i]));
			allocator.deallocate(_data, _size);
		}


		/* --- Capacity: --- */
		size_type size() const {return _size;}
		
		size_type max_size() const {return allocator.max_size();}
		
		void reserve(size_type n)
		{
			pointer tmp;
			size_type i;

			if (n <= _capacity)
				return ;
			tmp = _data;
			_data = allocator.allocate(n);	
			for (i = 0; i < _size; i++)
				_data[i] = tmp[i];
			allocator.deallocate(tmp, _capacity);
			_capacity = n;
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n == _size)
				return ;
			if (n < _size)
			{
				for (size_type i = n - 1; i < _size; i++)
					allocator.destroy(&(_data[i]));
				_size = n;
				return ;
			}
			reserve(n);
			for (size_type i = _size; i < n; i++)
				allocator.construct(&(_data[i]), val);
			_size = n;
		}

		size_type capacity() const {return _capacity;}

		bool empty() const {return (_size == 0);}

		/* --- Element access --- */
		reference operator[](size_type n)
		{
			return (_data[n]);
		}

		const_reference operator[](size_type n) const
		{
			return (_data[n]);
		}

		reference at(size_type n)
		{
			if (n >= size())
				throw out_of_range();
			return (_data[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= size())
				throw out_of_range();
			return (_data[n]);
		}

		reference front()
		{
			return (_data[0]);
		}

		const_reference front() const
		{
			return (_data[0]);
		}

		reference back()
		{
			return (_data[_size - 1]);
		}

		const_reference back() const
		{
			return (_data[_size - 1]);
		}

		value_type* data()
		{
			return (_data);
		}

		const value_type* data() const
		{
			return (_data);
		}
};

}
