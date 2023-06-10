/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:47:55 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 02:54:24 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N):vec(N)
{}

Span::~Span(){}

Span::Span(const Span& src)
{
	if (this == &src)
		return ;
	vec = src.vec;
}

Span& Span::operator = (const Span& src)
{
	if (this == &src)
		return *this;
	vec = src.vec;
	return (*this);
}

void Span::addNumber(int num)
{
	if (vec.size() == vec.capacity())
		throw std::exception();
	vec.push_back(num);
}

int Span::shortestSpan()
{
	if (vec.size() < 2)
		return -1;
	std::sort(vec.begin(), vec.end());

	int min = -1;
	for (int i = 1; i < vec.size(); i++)
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

template <typename iterator>
void Span::addRange(iterator first, iterator last)
{
	if (std::distance(first, last) + vec.size() > vec.capacity())
		throw std::exception();
	while (first != last)
	{
		vec.push_back(*first);
		first++;
	}
}
