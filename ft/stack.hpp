/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:00:22 by bammar            #+#    #+#             */
/*   Updated: 2023/06/17 00:47:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{

	// Types
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;


	protected:
		container_type c;
	
	public:
		explicit stack (const container_type& ctnr = container_type())
		:	c(ctnr)
		{}

	stack (const stack& other) : c(other.c) {}
	
	stack& operator=(const stack& other)
	{
		if (this == &other)
			return *this;
		c = other.c;
		return *this;
	}
	~stack() {}

	reference top() {return c.back();}
	const_reference top() const {return c.back();}
	bool empty() const {return c.empty();}
	size_type size() const {return c.size();}
	void push(const value_type& value) {c.push_back(value);}
	void pop() {c.pop_back();}

	template< class T2, class Cont >
	friend bool operator==( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );
	template< class T2, class Cont >
	friend bool operator!=( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );
	template< class T2, class Cont >
	friend bool operator>( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );
	template< class T2, class Cont >
	friend bool operator>=( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );
	template< class T2, class Cont >
	friend bool operator<( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );
	template< class T2, class Cont >
	friend bool operator<=( const ft::stack<T2, Cont>& lhs,
                 const ft::stack<T2, Cont>& rhs );

};

template< class T, class Container >
bool operator==( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c == rhs.c;}

template< class T, class Container >
bool operator!=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c != rhs.c;}

template< class T, class Container >
bool operator< ( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c < rhs.c;}

template< class T, class Container >
bool operator<=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c <= rhs.c;}

template< class T, class Container >
bool operator>( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c > rhs.c;}

template< class T, class Container >
bool operator>=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs )
{return lhs.c >= rhs.c;}


}