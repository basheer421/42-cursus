/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:09:00 by bammar            #+#    #+#             */
/*   Updated: 2023/06/13 20:09:48 by bammar           ###   ########.fr       */
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

        ~vector_iterator() {}

        vector_iterator(const vector_iterator& src)
        {
            if (this == &src)
                return ;
            *this = src;
        }

        vector_iterator& operator =(const vector_iterator& src)
        {
            if (this == &src)
                return *this;
            ptr = src.getPtr();
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

        reference operator *() const {return *ptr;}

        pointer operator ->() {return ptr;}

        vector_iterator operator +(difference_type n) const {return (ptr + n);}
        
        vector_iterator operator -(difference_type n) const {return (ptr - n);}

        vector_iterator& operator +=(difference_type n)
        {
            ptr += n;
            return (*this);
        }

        vector_iterator& operator -=(difference_type n)
        {
            ptr -= n;
            return (*this);
        }

        reference operator[](difference_type n) {return (*(ptr + num));}

};

}
