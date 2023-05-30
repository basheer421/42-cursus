/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 14:09:01 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("a", 90);
	std::cout << a;
	Bureaucrat b("b", 150);
	try {
		Bureaucrat c("c", 0);
		std::cout << c;
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << b;
	try {
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << b;
	b.incrementGrade();
	std::cout << b;
	b.decrementGrade();
	std::cout << b;
	try {
		b.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
