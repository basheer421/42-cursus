/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:56 by bammar            #+#    #+#             */
/*   Updated: 2023/06/22 22:44:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

#ifdef NAMESPACE

void default_constructor()
{
    NAMESPACE::vector<int> x;
    NAMESPACE::vector<int>* new_vector = new NAMESPACE::vector<int>();
    x.push_back(3);
    std::cout << x.capacity() << "\n";
    delete new_vector;
}

#endif
