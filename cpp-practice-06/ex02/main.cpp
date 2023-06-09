/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:43:35 by bammar            #+#    #+#             */
/*   Updated: 2023/06/09 20:14:03 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base *generate(void)
{
	int n;

	n = std::rand() % 3;
	if (n == 0)
		return (new A());
	if (n == 1)
		return (new B());
	return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "class A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "class B\n";
	else
		std::cout << "class C\n";
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "class A\n";
		return ;
	} catch (std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "class B\n";
		return ;
	} catch (std::exception& e) {}
	std::cout << "class C\n";
}

int main(void)
{
	A a;
	B b;
	C c;

	identify(a);
	identify(c);
	identify(b);
	identify(a);

	std::cout << "------\n";

	identify(&b);
	identify(&c);
	identify(&a);
	identify(&b);

	std::cout << "-------\n";
	
	std::srand(std::time(NULL));
	Base *base;
	for (int i = 0; i < 5; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		delete (base);
		std::cout << "--\n";
	}
	return (0);
}
