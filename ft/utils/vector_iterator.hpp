/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:09:00 by bammar            #+#    #+#             */
/*   Updated: 2023/06/14 01:57:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"

namespace ft
{

template <class T>
class vector_iterator : public iterator<random_access_iterator_tag>
{
    private:
        pointer ptr;
        
    public:
        vector_iterator()
            :   ptr(NULL)
        {}

        vector_iterator(pointer iterator_pointer)
            :   ptr(iterator_pointer)
        {}

        ~vector_iterator() {}

        vector_iterator(const vector_iterator& src)
        {
            if (this == &src)
                return ;
            *this = src;
        }

        vector_iterator& operator=(const vector_iterator& src)
        {
            if (this == &src)
                return *this;
            ptr = src.getPtr();
            return *this;
        }

        pointer getPtr() const {return ptr;}

        vector_iterator& operator++() {++ptr; return *this;}

        vector_iterator operator++(int)
        {
            vector_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        vector_iterator& operator--() {--ptr; return *this;}

        vector_iterator operator--(int)
        {
            vector_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reference operator*() const {return *ptr;}

        pointer operator->() {return ptr;}

        vector_iterator operator+(difference_type n) const
        {
            return vector_iterator<T>(ptr + n);
        }
        
        vector_iterator operator-(difference_type n) const
        {
            return vector_iterator<T>(ptr - n);
        }

        template <class T2>
        vector_iterator operator-(const vector_iterator<T2>& b) const
        {
            return vector_iterator<T>(ptr - b.getPtr());
        }

        vector_iterator& operator+=(difference_type n)
        {
            ptr += n;
            return (*this);
        }

        vector_iterator& operator-=(difference_type n)
        {
            ptr -= n;
            return (*this);
        }

        reference operator[](difference_type n) {return (ptr[n]);}

        template <class T2>
        bool operator==(const vector_iterator<T2>& b) const
        {
            return ptr == b.getPtr();
        }

        template <class T2>
        bool operator!=(const vector_iterator<T2>& b) const
        {
            return ptr != b.getPtr();
        }

        template <class T2>
        bool operator<(const vector_iterator<T2>& b) const
        {
            return ptr < b.getPtr();
        }

        template <class T2>
        bool operator<=(const vector_iterator<T2>& b) const
        {
            return ptr <= b.getPtr();
        }

        template <class T2>
        bool operator>(const vector_iterator<T2>& b) const
        {
            return ptr > b.getPtr();
        }

        template <class T2>
        bool operator>=(const vector_iterator<T2>& b) const
        {
            return ptr >= b.getPtr();
        }
};

// "n + a" case
template <class T>
vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n,
                                const vector_iterator<T> &a)
{
    return vector_iterator<T>(a + n);
}

}
