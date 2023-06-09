/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:03:04 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 23:55:56 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
	private:
		T *data;
		unsigned int length;

	public:
		Array():data(NULL), length(0) {}
		Array(unsigned int n):data(new T[n]), length(n) {}
		~Array() {if (data) delete[] data;}
		Array(const Array& src)
		{
			if (this == &src)
				return ;
			*this = src;
		}
		Array& operator = (const Array& src)
		{
			if (this == &src)
				return *this;
			if (data)
				delete data;
			if (!src.data)
			{
				data = NULL;
				return *this;
			}
			data = new T[src.length];
			unsigned int n = static_cast<unsigned int>(src.length);
			for (unsigned int i = 0; i < n; i++)
				data[i] = src.data[i];
			return (*this);
		}

		T& operator [](unsigned int index)
		{
			if (index >= length)
				throw std::exception();
			return (data[index]);
		}

		const T& operator [](unsigned int index) const
		{
			if (index >= length)
				throw std::exception();
			return (data[index]);
		}

		unsigned int size() const {return length;}
};
