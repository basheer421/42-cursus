/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:56 by bammar            #+#    #+#             */
/*   Updated: 2023/06/23 01:52:18 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

#ifdef NAMESPACE

void default_constructor()
{
    NAMESPACE::vector<int> x1;
    NAMESPACE::vector<std::string> x2;
    NAMESPACE::vector<int>* new_vector = new NAMESPACE::vector<int>();
    NAMESPACE::vector<std::string>* new_vector2 = new NAMESPACE::vector<std::string>();
    
    print_vector(x1);
    print_vector(x2);
    print_vector(*new_vector);
    print_vector(*new_vector2);

    delete new_vector;
    delete new_vector2;
    
}

void alloc_constructor()
{
}

#endif
