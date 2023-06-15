/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:10:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/15 13:36:44 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"

namespace ft
{

template <class Iter>
class reverse_RAI_iterator
{
    public:
        typedef Iter                                        iterator_type;
        typedef typename iterator_type::value_type          value_type;
        typedef typename iterator_type::pointer             pointer;
        typedef typename iterator_type::reference           reference;
        typedef typename iterator_type::difference_type     difference_type;
        typedef typename iterator_type::iterator_category   iterator_category;
    
    private:
        iterator_type current;

    public:
        reverse_RAI_iterator():current(NULL) {}

        explicit reverse_RAI_iterator(iterator_type x):current(x) {}

        template <class U>
        reverse_RAI_iterator(const reverse_RAI_iterator<U>& src)
        {
            if (this == &src)
                return ;
            *this = src;
        }

        template <class U>
        reverse_RAI_iterator& operator=(const reverse_RAI_iterator<U>& src)
        {
            if (this == &src)
                return *this;
            current = src.current;
            return *this;
        }

        iterator_type base() const {return current;}

        reference operator*() const {return *current;}

        pointer operator->() const {return &(operator*());}

        reference operator[](difference_type n) const {return *(current - n);}

        reverse_RAI_iterator& operator++() {--current; return *this;}

        reverse_RAI_iterator operator++(int)
        {
            reverse_RAI_iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        
        reverse_RAI_iterator& operator--() {++current; return *this;}

        reverse_RAI_iterator operator--(int)
        {
            reverse_RAI_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reverse_RAI_iterator operator+(difference_type n) const
        {
            return reverse_RAI_iterator((current - n));
        }

        reverse_RAI_iterator operator-(difference_type n) const
        {
            return reverse_RAI_iterator((current + n));
        }

        reverse_RAI_iterator& operator+=(difference_type n)
        {
            current -= n;
            return *this;
        }

        reverse_RAI_iterator& operator-=(difference_type n)
        {
            current += n;
            return *this;
        }

};

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_RAI_iterator<Iterator1>& lhs,
                 const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_RAI_iterator<Iterator1>& lhs,
                 const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<( const reverse_RAI_iterator<Iterator1>& lhs,
                const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs > rhs);
}

template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_RAI_iterator<Iterator1>& lhs,
                 const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>( const reverse_RAI_iterator<Iterator1>& lhs,
                const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_RAI_iterator<Iterator1>& lhs,
                const reverse_RAI_iterator<Iterator2>& rhs )
{
    return (lhs.base() <= rhs.base());
}


// "n + a" case
template <class It>
reverse_RAI_iterator<It> operator+(typename ft::reverse_RAI_iterator<It>::difference_type n,
                                const reverse_RAI_iterator<It> &a)
{
    return reverse_RAI_iterator<It>(a + n);
}

}
