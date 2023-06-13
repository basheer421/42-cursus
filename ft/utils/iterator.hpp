/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:08:39 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 02:20:49 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

namespace ft
{
    /**
     * Empty classes/structs (tags) to identify the category of an iterator.
    */
    struct output_iterator_tag {};
    struct input_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
// class iterator
// {
//     // Types    
//     public:
//         typedef T         value_type;
//         typedef Distance  difference_type;
//         typedef Pointer   pointer;
//         typedef Reference reference;
//         typedef Category  iterator_category;
// };

}
