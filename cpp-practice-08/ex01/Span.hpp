/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:43:07 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 02:44:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int> vec;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& src);
		Span& operator = (const Span& src);
		
		void addNumber(int num);
		
		template <typename iterator>
		void addRange(iterator first, iterator last);
		int shortestSpan();
		int longestSpan();
};
