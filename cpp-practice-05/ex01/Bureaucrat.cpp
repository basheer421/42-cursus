/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:31 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 15:36:01 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("no name")
{
	this->grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade):name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src):name(src.name)
{
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& src) {
	if (&src == this)
		return *this;
	this->grade = src.grade;
	return (*this);
}

int Bureaucrat::getGrade() const {return grade;}
const std::string Bureaucrat::getName() const {return name;}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form& form)
{
	std::string reason;

	try {
		form.beSigned(*this);
		std::cout << this->getName() <<  " signed "  << form.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << this->getName() <<  " couldn't sign "  << form.getName()
			<< " because " << e.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");	
}

Bureaucrat::~Bureaucrat() {};