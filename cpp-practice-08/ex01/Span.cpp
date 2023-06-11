/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:47:55 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 04:07:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():max_size(10) {}

Span::Span(unsigned int N):max_size(N)
{}

Span::~Span(){}

Span::Span(const Span& src)
{
	if (this == &src)
		return ;
	*this = src;
}

Span& Span::operator = (const Span& src)
{
	if (this == &src)
		return *this;
	vec = src.vec;
	max_size = src.max_size;
	return (*this);
}

void Span::addNumber(int num)
{
	if (vec.size() == max_size)
		throw NoCapacityException();
	vec.push_back(num);
}

int Span::shortestSpan()
{
	if (vec.size() < 2)
		return -1;
	std::sort(vec.begin(), vec.end());

	int min = INT_MAX;
	for (int i = 1; i < static_cast<int>(vec.size()); i++)
	{
		int x = vec[i] - vec[i - 1];
		if (x < min)
			min = x;
	}
	return min;
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		return -1;
	std::sort(vec.begin(), vec.end());
	return (vec[vec.size() - 1] - vec[0]);
}


