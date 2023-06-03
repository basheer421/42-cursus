/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:57:58 by bammar            #+#    #+#             */
/*   Updated: 2023/06/03 14:34:39 by bammar           ###   ########.fr       */
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

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void ShrubberyCreationForm::setTarget(std::string src)
{
	this->target = src;
}

void ShrubberyCreationForm::write_tree() const
{
	try
	{
		std::fstream file(std::string(this->target + "_shrubbery").c_str(),
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
		file.close();
	} catch (std::exception& exception) {
		std::cerr << exception.what() << "\n";
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	throwIfNotExecuter(executor);
	write_tree();
	write_tree();
	write_tree();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
