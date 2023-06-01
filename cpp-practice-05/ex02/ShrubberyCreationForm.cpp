/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:57:58 by bammar            #+#    #+#             */
/*   Updated: 2023/06/01 21:17:31 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("ShrubberyCreation", 145, 137), target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:AForm("ShrubberyCreation", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
:AForm("ShrubberyCreation", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=
	(const ShrubberyCreationForm& src)
{
	if (&src == this)
		return *this;
	this->target = src.getTarget();
	return (*this);
}

void ShrubberyCreationForm::write_tree()
{
	try
	{
		std::fstream file(std::string(this->target + "_shrubbery"),
			std::fstream::out);
		std::stringstream s;

		s << "     --     	  --	\n";
		s << "   /// \\	   //    \\	\n";
		s << "   -------    --------	\n";
		s << "     | |	....  |\"|  \n";
		s << "     |.|	..	  |'|  \n";
		s << "     |'|	..	  | |  \n";
		s << "     | |		  | |  \n";
		s << "   ........		\n";

		file << s.str();
	} catch (std::exception& exception) {
		std::cerr << exception.what() << "\n";
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void ShrubberyCreationForm::setTarget(std::string src)
{
	this->target = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
