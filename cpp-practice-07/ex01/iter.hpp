/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:49:19 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 22:56:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void iter(T *arr, unsigned int length, void (*func)(T& param))
{
	for (unsigned int i = 0; i < length; i++)
		func(arr[i]);
}
