/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:56 by bammar            #+#    #+#             */
/*   Updated: 2023/06/23 01:20:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

#ifdef NAMESPACE

void default_constructor()
{
    NAMESPACE::vector<int> x;
    NAMESPACE::vector<int>* new_vector = new NAMESPACE::vector<int>();
    delete new_vector;
    print_vector(x);
}


#endif
