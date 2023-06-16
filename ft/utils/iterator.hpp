/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:04:56 by bammar            #+#    #+#             */
/*   Updated: 2023/06/16 22:24:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

    struct output_iterator_tag {};
    struct input_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class T>
class RAI_iterator
{
    // Types
    public:
        typedef T                              value_type;
        typedef T*                             pointer;
        typedef T&                             reference;
        typedef ptrdiff_t                      difference_type;
        typedef random_access_iterator_tag     iterator_category;
    
    protected:
        pointer ptr;
        
    public:
        RAI_iterator()
            :   ptr(NULL)
        {}

        RAI_iterator(pointer data_pointer)
            :   ptr(data_pointer)
        {}

        ~RAI_iterator() {}

        template <class U>
        RAI_iterator(const RAI_iterator<U>& src)
        {
            *this = src;
        }

        template <class U>
        RAI_iterator& operator=(const RAI_iterator<U>& src)
        {
            ptr = src.getPtr();
            return *this;
        }

        pointer getPtr() const {return ptr;}

        RAI_iterator& operator++() {++ptr; return *this;}

        RAI_iterator operator++(int)
        {
            RAI_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        RAI_iterator& operator--() {--ptr; return *this;}

        RAI_iterator operator--(int)
        {
            RAI_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reference operator*() const {return *ptr;}

        pointer operator->() {return ptr;}

        RAI_iterator operator+(difference_type n) const
        {
            return RAI_iterator<T>(ptr + n);
        }
        
        RAI_iterator operator-(difference_type n) const
        {
            return RAI_iterator<T>(ptr - n);
        }

        template <class T2>
        difference_type operator-(const RAI_iterator<T2>& b) const
        {
            return (ptr - b.getPtr());
        }

        RAI_iterator& operator+=(difference_type n)
        {
            ptr += n;
            return (*this);
        }

        RAI_iterator& operator-=(difference_type n)
        {
            ptr -= n;
            return (*this);
        }

        reference operator[](difference_type n) {return (ptr[n]);}

        template <class T2>
        bool operator==(const RAI_iterator<T2>& b) const
        {
            return ptr == b.getPtr();
        }

        template <class T2>
        bool operator!=(const RAI_iterator<T2>& b) const
        {
            return ptr != b.getPtr();
        }

        template <class T2>
        bool operator<(const RAI_iterator<T2>& b) const
        {
            return ptr < b.getPtr();
        }

        template <class T2>
        bool operator<=(const RAI_iterator<T2>& b) const
        {
            return ptr <= b.getPtr();
        }

        template <class T2>
        bool operator>(const RAI_iterator<T2>& b) const
        {
            return ptr > b.getPtr();
        }

        template <class T2>
        bool operator>=(const RAI_iterator<T2>& b) const
        {
            return ptr >= b.getPtr();
        }
};

// "n + a" case
template <class T>
RAI_iterator<T> operator+(typename ft::RAI_iterator<T>::difference_type n,
                                const RAI_iterator<T> &a)
{
    return RAI_iterator<T>(a + n);
}

}
