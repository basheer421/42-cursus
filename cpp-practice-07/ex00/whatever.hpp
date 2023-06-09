/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:35:55 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 22:43:41 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <class T>
T min(T a, T b)
{
	if (a > b)
		return b;
	return a;
}

template <class T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}
