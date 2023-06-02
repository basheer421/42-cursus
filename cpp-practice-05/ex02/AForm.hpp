/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:10:51 by bammar            #+#    #+#             */
/*   Updated: 2023/05/30 16:45:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool _isSigned;
		const int gradeRequiredToSign;
		const int gradeRequiredToExecute;

	protected:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		void throwIfNotExecuter(Bureaucrat const & b) const;
	
	public:
		AForm();
		AForm(const std::string name, const int gradeRequiredToSign,
			const int gradeRequiredToExecute);
		AForm(const AForm& src);
		AForm & operator = (const AForm& src);
		virtual ~AForm();

		const std::string getName() const;
		bool isSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

		void beSigned(Bureaucrat& b);
		
		virtual void execute(Bureaucrat const & executor) const = 0;

		
		
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
