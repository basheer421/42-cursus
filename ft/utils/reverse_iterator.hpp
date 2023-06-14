/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:10:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 23:33:53 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"

namespace ft
{

template <class It>
class reverse_RAI_iterator
{
    // Types
    public:
        typedef It                              value_type;
        typedef It*                             pointer;
        typedef It&                             reference;
        typedef ptrdiff_t                      difference_type;
        typedef random_access_iterator_tag     iterator_category;
    
    private:
        RAI_iterator<It> normal_it;
    
    public:
        reverse_RAI_iterator()
            :   normal_it(NULL)
        {}

        reverse_RAI_iterator(It value)
            :   normal_it(value)
        {}
    
        // reverse_RAI_iterator(const RAI_iterator<It> normal_iterator)
        //     :   normal_it(normal_iterator)
        // {}

        ~reverse_RAI_iterator() {}

        reverse_RAI_iterator(const reverse_RAI_iterator& src)
        {
            if (this == &src)
                return ;
            *this = src;
        }

        reverse_RAI_iterator& operator=(const reverse_RAI_iterator& src)
        {
            if (this == &src)
                return *this;
            normal_it = src.normal_it;
            return *this;
        }

        RAI_iterator base() const {return normal_it;}

        reference operator*() const {return *normal_it;}

        pointer operator->() const {return &(operator*());}

        reverse_RAI_iterator& operator++() {--normal_it; return *this;}

        reverse_RAI_iterator operator++(int)
        {
            reverse_RAI_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reverse_RAI_iterator& operator--() {++normal_it; return *this;}

        reverse_RAI_iterator operator--(int)
        {
            reverse_RAI_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reverse_RAI_iterator operator+(difference_type n) const
        {
            return reverse_RAI_iterator<It>(normal_it - n);
        }
        
        reverse_RAI_iterator operator-(difference_type n) const
        {
            return reverse_RAI_iterator<It>(normal_it + n);
        }

        template <class T2>
        reverse_RAI_iterator operator-(const reverse_RAI_iterator<T2>& b) const
        {
            return reverse_RAI_iterator<It>(normal_it + b);
        }

        reverse_RAI_iterator& operator+=(difference_type n)
        {
            normal_it -= n;
            return (*this);
        }

        reverse_RAI_iterator& operator-=(difference_type n)
        {
            normal_it += n;
            return (*this);
        }

        reference operator[](difference_type n) {return *(normal_it - n);}

        template <class T2>
        bool operator==(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it == b.base();
        }

        template <class T2>
        bool operator!=(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it != b.base();
        }

        template <class T2>
        bool operator<(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it > b.base();
        }

        template <class T2>
        bool operator<=(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it >= b.base();
        }

        template <class T2>
        bool operator>(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it < b.base();
        }

        template <class T2>
        bool operator>=(const reverse_RAI_iterator<T2>& b) const
        {
            return normal_it <= b.base();
        }
};

// "n + a" case
template <class It>
reverse_RAI_iterator<It> operator+(typename ft::reverse_RAI_iterator<It>::difference_type n,
                                const reverse_RAI_iterator<It> &a)
{
    return reverse_RAI_iterator<It>(n - a);
}

// "n - a" case
template <class It>
reverse_RAI_iterator<It> operator-(typename ft::reverse_RAI_iterator<It>::difference_type n,
                                const reverse_RAI_iterator<It> &a)
{
    return reverse_RAI_iterator<It>(n + a);
}

}
