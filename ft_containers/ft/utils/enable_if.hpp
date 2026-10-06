/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:29:40 by bammar            #+#    #+#             */
/*   Updated: 2023/06/19 02:07:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft
{

template <bool B, class T = void>
struct enable_if {};
 
template <class T>
struct enable_if<true, T> {typedef T type;};

struct true_type {static const bool value = true;};

struct false_type {static const bool value = false;};


template <class T> struct is_integral : public false_type {};

template<> struct is_integral<bool> : public true_type {};

template<> struct is_integral<char> : public true_type {};

template<> struct is_integral<signed char> : public true_type {};

template<> struct is_integral<unsigned char> : public true_type {};

template<> struct is_integral<short> : public true_type {};

template<> struct is_integral<unsigned short> : public true_type {};

template<> struct is_integral<int> : public true_type {};

template<> struct is_integral<unsigned int> : public true_type {};

template<> struct is_integral<long> : public true_type {};

template<> struct is_integral<unsigned long> : public true_type {};

template<> struct is_integral<long long> : public true_type {};

template<> struct is_integral<unsigned long long> : public true_type {};

template <class T> struct is_RAI : public false_type {};

template<> struct is_RAI<ft::random_access_iterator_tag> : public true_type {};

template<> struct is_RAI<std::random_access_iterator_tag> : public true_type {};

}
