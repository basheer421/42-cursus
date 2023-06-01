/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:36 by bammar            #+#    #+#             */
/*   Updated: 2023/06/01 21:16:34 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat a("a", 90);
	std::cout << a;
	Bureaucrat b("b", 30);
	std::cout << "--------\n";
	AForm jack = AForm("Jack", 50, 100);
	ShrubberyCreationForm c("file1");
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
