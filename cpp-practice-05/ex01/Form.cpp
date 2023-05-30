/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:23:02 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 16:17:39 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
:name("no name"), _isSigned(false),
	gradeRequiredToSign(0), gradeRequiredToExecute(0)
{}

Form::Form(const std::string name, const int gradeRequiredToSign,
			const int gradeRequiredToExecute)
			:name(name), _isSigned(false),
			gradeRequiredToSign(gradeRequiredToSign),
			gradeRequiredToExecute(gradeRequiredToExecute)
{}

Form::Form(const Form& src)
:gradeRequiredToSign(src.getGradeRequiredToSign()),
	gradeRequiredToExecute(src.getGradeRequiredToExecute())
{
	*this = src;
}

Form & Form::operator=(const Form& src) {
	if (&src == this)
		return *this;
	this->_isSigned = src.isSigned();
	return (*this);
}

Form::~Form() {}

const std::string Form::getName() const {return name;}
bool Form::isSigned() const {return _isSigned;}
int Form::getGradeRequiredToSign() const {return gradeRequiredToSign;}
int Form::getGradeRequiredToExecute() const {return gradeRequiredToExecute;}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");	
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
	out << b.getName() << "," << (b.isSigned() ? " " : " not ") <<
		"signed " << ", GradeRequiredToSign: " << b.getGradeRequiredToSign()
		<< ", getGradeRequiredToExecute: "
		<< b.getGradeRequiredToExecute() << "\n";
	return (out);
}