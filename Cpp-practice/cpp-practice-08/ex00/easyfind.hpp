/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:39:14 by bammar            #+#    #+#             */
/*   Updated: 2023/06/11 00:55:17 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>

template <class T>
int easyfind(T& cont, int x)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), x);
	if (it == cont.end())
		return (-1);
	return (it - cont.begin());
}
