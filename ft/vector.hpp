/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:48:05 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 23:34:18 by bammar           ###   ########.fr       */
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

namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector
{
	// Types
	public:
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;

		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;

		typedef RAI_iterator<T>								iterator;
		typedef RAI_iterator<const T>						const_iterator;

		typedef reverse_RAI_iterator<iterator>				reverse_iterator;
		typedef reverse_RAI_iterator<const_iterator>		const_reverse_iterator;


	private:
		pointer		_data;
		std::size_t	_size;
		std::size_t	_capacity;
		Alloc allocator;

	public:
		
		// iterators TODO

		allocator_type get_allocator() const {return (allocator);}

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
		
		vector(const vector& src)
			:	_data(NULL),
				_size(0),
				_capacity(0),
				allocator(src.allocator)
		{
			if (this == &src)
				return ;
			*this = src;
		}

		vector& operator = (const vector& src)
		{
			if (this == &src)
				return (*this);			
			if (_data)
			{
				clear();
				allocator.deallocate(_data, _capacity);
			}
			allocator = src.allocator;
			_capacity = 0;
			_data = NULL;
			reserve(src._capacity);
			for (size_type i = 0; i < src._size; i++)
				push_back(src[i]);
			return (*this);
		}

		template <class InputIterator>
		vector (InputIterator first,
				InputIterator last,
				const allocator_type& alloc = allocator_type());
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
		
		/**
		 * Performance idea: Maybe instead we could not construct and destroy,
		 * 	deallocate the main pointer but keep the original values
		*/
		void reserve(size_type n)
		{
			pointer tmp;
			size_type i;

			if (n <= _capacity)
				return ;
			if (!_data)
			{
				_data = allocator.allocate(n);
				_capacity = n;
				return ;
			}
			tmp = _data;
			_data = allocator.allocate(n);

			for (i = 0; i < _size; i++)
				allocator.construct(&(_data[i]), tmp[i]);
			for (i = 0; i < _size; i++)
				allocator.destroy(&(tmp[i]));
			allocator.deallocate(tmp, _capacity);
			_capacity = n;
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n == _size)
				return ;
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
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
				throw std::out_of_range("out of range");
			return (_data[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("out of range");
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

		/* --- Modifiers --- */
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type 
		assign (InputIterator first, InputIterator last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		};

		void assign(size_type n, const value_type& val)
		{
			reserve(n);
			for (size_type i = 0; i < _size; i++)
				allocator.destroy(&(_data[i]));
			for (size_type i = 0; i < n; i++)
				allocator.construct(&(_data[i]), val);
			_size = n;
		}

		iterator erase(iterator pos) {return erase(pos, pos + 1);}

		iterator erase(iterator first, iterator last)
		{
			size_type dist = 0;
			iterator it = last;
			while (first++ != last)
				++dist;
			if (dist == 0)
				return last;
			while (it != end())
			{
				*(it - dist) = *it;
				++it;
			}
			for (size_type i = 0; i < dist; i++)
				pop_back();
			return it;
		}


		void push_back(const value_type& val)
		{
			if (!_data)
				reserve(10);
			else if (_size == _capacity)
				reserve(_size * 2);
			allocator.construct(&(_data[_size++]), val);
		}

		void pop_back()
		{
			if (!_data)
				return ;
			allocator.destroy(&(_data[--_size]));
		}

		void swap(vector& x)
		{
			if (this == &x)
				return ;
			vector<value_type, allocator_type> tmp(*this);
			*this = x;
			x = tmp;
		}

		void clear() {resize(0);}

		iterator begin()
		{
			return iterator(_data);
		}

		const_iterator begin() const
		{
			return const_iterator(_data);
		}

		iterator end()
		{
			return iterator(_data + _size);
		}

		const_iterator end() const
		{
			return const_iterator(_data + _size);
		}

		reverse_iterator rbegin()
		{
			// iterator it(end() - 1);
			return reverse_iterator(end() - 1);
		}
		
		const_reverse_iterator rbegin() const
		{
			// const_iterator it(end() - 1);
			return const_reverse_iterator(end() - 1);
		}

		reverse_iterator rend()
		{
			// iterator it();
			return reverse_iterator(begin() - 1);
		}

		const_reverse_iterator rend() const
		{
			// const_iterator it();
			return const_reverse_iterator(begin() - 1);
		}

};

}
