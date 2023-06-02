/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:45:15 by bammar            #+#    #+#             */
/*   Updated: 2023/06/02 15:50:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

		void write_tree() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void setTarget(std::string src);

		void execute(Bureaucrat const & executor) const;
};
