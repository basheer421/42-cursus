/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:03:29 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 20:36:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& src)
{
	(void)src;
}


Intern & Intern::Intern::operator=(const Intern& src)
{
	(void)src;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makePresidentialPardonForm(const std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm *Intern::makeRobotomyRequestForm(const std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

AForm *Intern::makeShrubberyCreationForm(const std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeFrom(const std::string formName,
	const std::string formTarget)
{
	AForm*(Intern::*formFuncs[])(const std::string) = {
		&Intern::makeRobotomyRequestForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};
	
	std::string names[] = {
		"presidential pardon", "robotomy request", "shrubbery creation"
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
			return (this->*(formFuncs[i]))(formTarget);
	}
	return (NULL);
}
