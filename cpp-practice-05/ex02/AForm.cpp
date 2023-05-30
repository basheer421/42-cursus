/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:23:02 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 16:17:39 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
:name("no name"), _isSigned(false),
	gradeRequiredToSign(0), gradeRequiredToExecute(0)
{}

AForm::AForm(const std::string name, const int gradeRequiredToSign,
			const int gradeRequiredToExecute)
			:name(name), _isSigned(false),
			gradeRequiredToSign(gradeRequiredToSign),
			gradeRequiredToExecute(gradeRequiredToExecute)
{}

AForm::AForm(const AForm& src)
:gradeRequiredToSign(src.getGradeRequiredToSign()),
	gradeRequiredToExecute(src.getGradeRequiredToExecute())
{
	*this = src;
}

AForm & AForm::operator=(const AForm& src) {
	if (&src == this)
		return *this;
	this->_isSigned = src.isSigned();
	return (*this);
}

AForm::~AForm() {}

const std::string AForm::getName() const {return name;}
bool AForm::isSigned() const {return _isSigned;}
int AForm::getGradeRequiredToSign() const {return gradeRequiredToSign;}
int AForm::getGradeRequiredToExecute() const {return gradeRequiredToExecute;}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > getGradeRequiredToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");	
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
	out << b.getName() << "," << (b.isSigned() ? " " : " not ") <<
		"signed " << ", GradeRequiredToSign: " << b.getGradeRequiredToSign()
		<< ", getGradeRequiredToExecute: "
		<< b.getGradeRequiredToExecute() << "\n";
	return (out);
}