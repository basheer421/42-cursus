/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:28:17 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 16:29:27 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

		void inform() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm & operator = (const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void setTarget(std::string src);

		void execute(Bureaucrat const & executor) const;
};