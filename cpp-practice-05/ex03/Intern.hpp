/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:48:37 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 20:27:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern;

typedef AForm *(Intern::*formFuncs)(const std::string formTarget);

class Intern
{	
	private:
		AForm *makePresidentialPardonForm(const std::string formTarget);
		AForm *makeRobotomyRequestForm(const std::string formTarget);
		AForm *makeShrubberyCreationForm(const std::string formTarget);
	public:
		Intern();
		Intern(const Intern& src);
		Intern & operator = (const Intern& src);
		~Intern();
		AForm* makeFrom(const std::string formName,
			const std::string formTarget);
		
};

std::ostream &operator<<(std::ostream &out, const Intern &Intern);
