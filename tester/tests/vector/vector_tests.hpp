/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:43 by bammar            #+#    #+#             */
/*   Updated: 2023/06/23 01:20:35 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * Functions throw by type of error:
 *  - fail exception
 * 
*/

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>

class FailException : public std::exception {};

template <typename T>
void print_vector(const NAMESPACE::vector<T> v)
{
	std::cout << "Size: " << v.size();
	std::cout << "\nData: \n";
	for (typename NAMESPACE::vector<T>::size_type i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i) << "\n";
    }
}

void default_constructor();
void alloc_constructor();
