/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:57:58 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 17:08:18 by bammar           ###   ########.fr       */
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
