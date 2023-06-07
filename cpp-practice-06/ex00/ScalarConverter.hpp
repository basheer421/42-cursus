/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:24:34 by bammar            #+#    #+#             */
/*   Updated: 2023/06/05 19:09:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "ScalarSet.hpp"

class ScalarConverter
{
	
	private:
		typedef enum {
			INT,
			CHAR,
			DOUBLE,
			FLOAT,
			NONE
		} t_type;

		ScalarConverter();
		static t_type getType(std::string& s);
		static void stripSpaces(std::string& s);

	protected:
		class NonDisplayableException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ImpossibleConversionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

	public:
		static ScalarSet convert(const std::string s);
};
