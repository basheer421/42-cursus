/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:28:52 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 16:31:15 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("PresidentialPardon", 25, 5), target("")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("PresidentialPardon", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
:AForm("PresidentialPardon", 25, 5)
{
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=
	(const PresidentialPardonForm& src)
{
	if (&src == this)
		return *this;
	this->target = src.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::setTarget(std::string src)
{
	this->target = src;
}

void PresidentialPardonForm::inform() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	throwIfNotExecuter(executor);
	inform();
}

PresidentialPardonForm::~PresidentialPardonForm() {}