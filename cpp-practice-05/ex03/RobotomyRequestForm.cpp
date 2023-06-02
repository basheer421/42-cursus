/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:53:10 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 17:15:55 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyCreation", 72, 45), target("")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("RobotomyCreation", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
:AForm("RobotomyCreation", 72, 45)
{
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=
	(const RobotomyRequestForm& src)
{
	if (&src == this)
		return *this;
	this->target = src.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (target);
}

void RobotomyRequestForm::setTarget(std::string src)
{
	this->target = src;
}

void RobotomyRequestForm::makeNoise() const
{
	std::cout << "(drilling noises)\n";
	std::cout << "zzzzzzzzzzzzz\n";
	std::cout << "zzzzzzzzzzzzz\n";
}

void RobotomyRequestForm::inform() const
{
	int			n;
	std::string	s;

	std::srand(time(0));
	n = std::rand();
	if (n % 2 == 0)
	{
		s = this->getTarget() + " has been robotomized successfully";
	} else {
		s = "The robotomy of " + this->getTarget() + " has failed";
	}
	std::cout << s << "\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	throwIfNotExecuter(executor);
	makeNoise();
	inform();
}

RobotomyRequestForm::~RobotomyRequestForm() {}
