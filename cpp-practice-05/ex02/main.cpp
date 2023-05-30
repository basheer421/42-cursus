/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 16:12:49 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("a", 90);
	std::cout << a;
	Bureaucrat b("b", 30);
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

	std::cout << "--------\n";
	Form jack = Form("Jack", 50, 100);
	try {
		jack.beSigned(a);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "--------\n";
	try {
		jack.beSigned(b);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	a.signForm(jack);
	b.signForm(jack);
	
	return (0);
}
