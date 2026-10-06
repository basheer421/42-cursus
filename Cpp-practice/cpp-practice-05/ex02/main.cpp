/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 17:28:37 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a("A", 130); // lazy
	std::cout << a;
	Bureaucrat b("B", 3); // smart

	
	std::cout << "--------\n";
	PresidentialPardonForm pForm("pForm");
	RobotomyRequestForm rForm("rForm");
	ShrubberyCreationForm sForm("sForm");
	
	try {
		pForm.execute(a);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 35\n";
	}
	try {
		pForm.execute(b);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 41\n";
	}

	std::cout << "--------\n";

	try {
		sForm.execute(a);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 50\n";
	}
	try {
		sForm.execute(b);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 56\n";
	}

	std::cout << "--------\n";

	try {
		rForm.execute(a);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 65\n";
	}
	try {
		rForm.execute(b);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
		std::cerr << "line 71\n";
	}

	std::cout << "--------\n";
	
	a.executeForm(pForm);
	b.executeForm(pForm);
	std::cout << "--------\n";
	a.executeForm(rForm);
	b.executeForm(rForm);
	std::cout << "--------\n";
	a.executeForm(sForm);
	b.executeForm(sForm);
	std::cout << "--------\n";
	a.signForm(pForm);
	std::cout << (pForm.isSigned() ? "a is signed" : "a is not signed") << "\n";
	std::cout << "--------\n";

	return (0);
}
